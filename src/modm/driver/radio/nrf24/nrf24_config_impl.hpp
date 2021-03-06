/*
 * Copyright (c) 2014-2015, Daniel Krebs
 * Copyright (c) 2015, Sascha Schade
 *
 * This file is part of the modm project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
// ----------------------------------------------------------------------------

#ifndef MODM_NRF24_CONFIG_HPP
#   error "Don't include this file directly, use 'nrf24_config.hpp' instead!"
#endif

#include "nrf24_config.hpp"
#include "nrf24_definitions.hpp"

#include <stdint.h>

// --------------------------------------------------------------------------------------------------------------------

template<typename Nrf24Phy>
void
modm::Nrf24Config<Nrf24Phy>::setMode(Mode mode)
{
	Nrf24Phy::clearInterrupt(InterruptFlag::ALL);

	if(mode == Mode::Rx)
	{
		MODM_LOG_DEBUG << "Set mode Rx" << modm::endl;

		Nrf24Phy::flushRxFifo();
		Nrf24Phy::setBits(NrfRegister::CONFIG, Config::PRIM_RX);
	} else
	{
		MODM_LOG_DEBUG << "Set mode Tx" << modm::endl;

		Nrf24Phy::clearInterrupt(Nrf24Phy::InterruptFlag::ALL);		// Not sure if needed
		Nrf24Phy::clearBits(NrfRegister::CONFIG, Config::PRIM_RX);

		// pulsing CE seems to be necessary to enter TX mode
		Nrf24Phy::pulseCe();
	}

	// don't go to standby
	Nrf24Phy::setCe();
}

// --------------------------------------------------------------------------------------------------------------------

template<typename Nrf24Phy>
void
modm::Nrf24Config<Nrf24Phy>::setSpeed(Speed speed)
{
	switch (speed)
	{
	case Speed::kBps250:
		Nrf24Phy::clearBits(NrfRegister::RF_SETUP, RfSetup::RF_DR_HIGH);
		Nrf24Phy::setBits  (NrfRegister::RF_SETUP, RfSetup::RF_DR_LOW);
		break;
	case Speed::MBps1:
		Nrf24Phy::clearBits(NrfRegister::RF_SETUP, RfSetup::RF_DR_LOW);
		Nrf24Phy::clearBits(NrfRegister::RF_SETUP, RfSetup::RF_DR_HIGH);
		break;
	case Speed::MBps2:
		Nrf24Phy::setBits  (NrfRegister::RF_SETUP, RfSetup::RF_DR_HIGH);
		Nrf24Phy::clearBits(NrfRegister::RF_SETUP, RfSetup::RF_DR_LOW);
		break;
	}
}

// --------------------------------------------------------------------------------------------------------------------

template<typename Nrf24Phy>
void modm::Nrf24Config<Nrf24Phy>::setCrc(Crc crc)
{
	if(crc == Crc::NoCrc)
	{
		Nrf24Phy::clearBits(NrfRegister::CONFIG, Config::EN_CRC);

	} else
	{
		Nrf24Phy::setBits(NrfRegister::CONFIG, Config::EN_CRC);

		if (crc == Crc::Crc1Byte)
		{
			Nrf24Phy::clearBits(NrfRegister::CONFIG, Config::CRC0);
		}
		else if (crc == Crc::Crc2Byte)
		{
			Nrf24Phy::setBits(NrfRegister::CONFIG, Config::CRC0);
		}
	}
}

// --------------------------------------------------------------------------------------------------------------------

template<typename Nrf24Phy>
void modm::Nrf24Config<Nrf24Phy>::setRfPower(RfPower power)
{
	uint8_t reg = Nrf24Phy::readRegister(NrfRegister::RF_SETUP);
	reg &= ~(static_cast<uint8_t>(RfSetup::RF_PWR));	// Clear bits
	reg |=  ((static_cast<uint8_t>(power)) << 1); 		// Set bits
	Nrf24Phy::writeRegister(NrfRegister::RF_SETUP, reg);
}

// --------------------------------------------------------------------------------------------------------------------

template<typename Nrf24Phy>
void modm::Nrf24Config<Nrf24Phy>::setAutoRetransmitDelay(AutoRetransmitDelay delay)
{
	uint8_t reg = Nrf24Phy::readRegister(NrfRegister::SETUP_RETR);
	reg &= ~(static_cast<uint8_t>(SetupRetr::ARD));		// Clear bits
	reg |=  ((static_cast<uint8_t>(delay)) << 4); 		// Set bits
	Nrf24Phy::writeRegister(NrfRegister::SETUP_RETR, reg);
}

// --------------------------------------------------------------------------------------------------------------------

template<typename Nrf24Phy>
void modm::Nrf24Config<Nrf24Phy>::setAutoRetransmitCount(AutoRetransmitCount count)
{
	uint8_t reg = Nrf24Phy::readRegister(NrfRegister::SETUP_RETR);
	reg &= ~(static_cast<uint8_t>(SetupRetr::ARC));		// Clear bits
	reg |=  (static_cast<uint8_t>(count)); 				// Set bits
	Nrf24Phy::writeRegister(NrfRegister::SETUP_RETR, reg);
}

// --------------------------------------------------------------------------------------------------------------------

template<typename Nrf24Phy>
void
modm::Nrf24Config<Nrf24Phy>::enablePipe(Pipe_t pipe, bool enableAutoAck)
{

	uint16_t payload_length = Nrf24Phy::getPayloadLength();

	NrfRegister_t reg = NrfRegister::RX_PW_P0;
	reg.value += pipe.value;

	/* Set payload width for pipe */
	Nrf24Phy::writeRegister(reg, payload_length);


	Flags_t pipe_flag = static_cast<Flags_t>(1 << pipe.value);

	/* Enable or disable auto acknowledgment for this pipe */
	if(enableAutoAck)
	{
		Nrf24Phy::setBits(NrfRegister::EN_AA, pipe_flag);
	} else
	{
		Nrf24Phy::clearBits(NrfRegister::EN_AA, pipe_flag);
	}

	/* enable pipe */
	Nrf24Phy::setBits(NrfRegister::EN_RX_ADDR, pipe_flag);
}

// --------------------------------------------------------------------------------------------------------------------

template<typename Nrf24Phy>
typename modm::Nrf24Config<Nrf24Phy>::Pipe_t
modm::Nrf24Config<Nrf24Phy>::getPayloadPipe()
{
	uint8_t status = Nrf24Phy::readStatus();

	return static_cast<Pipe_t>((status & (uint8_t)Status::RX_P_NO) >> 1);
}
