// coding: utf-8
// ----------------------------------------------------------------------------
/* Copyright (c) 2011, Roboterclub Aachen e.V.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Roboterclub Aachen e.V. nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY ROBOTERCLUB AACHEN E.V. ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ROBOTERCLUB AACHEN E.V. BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * $Id$
 */
// ----------------------------------------------------------------------------

#ifndef XPCC_POINTS__POINT4_HPP
#define XPCC_POINTS__POINT4_HPP

#include <stdint.h>
#include "point.hpp"

namespace xpcc {
	/**
	 * \brief	Class for handling common point operations
	 *	+ : addition of points
	 *	- : different of points
	 *	* : dot product or scalar multiplication
	 *	/ : scalar division
	 *	~ : perpendicular
	 *
	 * Adapted from the implementation of Gaspard Petit (gaspardpetit@gmail.com).
	 *
	 * \see <a href"http://www-etud.iro.umontreal.ca/~petitg/cpp/point.html">Homepage</a>
	 * 
	 * \ingroup	points
	 * \author Niklas Hauser
	 */
	template<typename T>
	class Point<T, 4>
	{
	public:
		Point();
		
		explicit Point(T inVal);
		Point(T inX, T inY, T inZ, T inW);
		
		Point(const Point<T, 1> &inX, const Point<T, 1> &inY, const Point<T, 1> &inZ, const Point<T, 1> &inW);
		Point(const Point<T, 1> &inX, const Point<T, 1> &inY, const Point<T, 1> &inZ, const T &inW);
		Point(const Point<T, 1> &inX, const Point<T, 1> &inY, const T &inZ, const T &inW);
		Point(const Point<T, 1> &inX, const T &inY, const Point<T, 1> &inZ, const T &inW);
		Point(const T &inX, const Point<T, 1> &inY, const Point<T, 1> &inZ, const T &inW);
		Point(const Point<T, 1> &inX, const T &inY, const T &inZ, const T &inW);
		Point(const T &inX, const Point<T, 1> &inY, const T &inZ, const T &inW);
		Point(const Point<T, 1> &inX, const Point<T, 1> &inY, const T &inZ, const Point<T, 1> &inW);
		Point(const Point<T, 1> &inX, const T &inY, const T &inZ, const Point<T, 1> &inW);
		Point(const T &inX, const Point<T, 1> &inY, const T &inZ, const Point<T, 1> &inW);
		Point(const T &inX, const T &inY, const T &inZ, const Point<T, 1> &inW);
		Point(const Point<T, 1> &inX, const T &inY, const Point<T, 1> &inZ, const Point<T, 1> &inW);
		Point(const T &inX, const T &inY, const Point<T, 1> &inZ, const Point<T, 1> &inW);
		Point(const T &inX, const Point<T, 1> &inY, const Point<T, 1> &inZ, const Point<T, 1> &inW);
		
		Point(const Point<T, 2> &inXY, const Point<T, 1> &inZ, const Point<T, 1> &inW);
		Point(const Point<T, 2> &inXY, const Point<T, 1> &inZ, const T &inW);
		Point(const Point<T, 2> &inXY, const T &inZ, const T &inW);
		Point(const Point<T, 2> &inXY, const T &inZ, const Point<T, 1> &inW);
		
		Point(const Point<T, 1> &inX, const Point<T, 2> &inYZ, const Point<T, 1> &inW);
		Point(const Point<T, 1> &inX, const Point<T, 2> &inYZ, const T &inW);
		Point(const T &inX, const Point<T, 2> &inYZ, const T &inW);
		Point(const T &inX, const Point<T, 2> &inYZ, const Point<T, 1> &inW);
		
		Point(const Point<T, 1> &inX, const Point<T, 1> &inY, const Point<T, 2> &inZW);
		Point(const Point<T, 1> &inX, const T &inY, const Point<T, 2> &inZW);
		Point(const T &inX, const T &inY, const Point<T, 2> &inZW);
		Point(const T &inX, const Point<T, 1> &inY, const Point<T, 2> &inZW);
		
		Point(const Point<T, 2> &inXY, const Point<T, 2> &inZW);
		
		Point(const Point<T, 3> &inXYZ, const Point<T, 1> &inW);
		Point(const Point<T, 3> &inXYZ, const T &inW);
		
		Point(const Point<T, 1> &inX, const Point<T, 3> &inYZW);
		Point(const T &inX, const Point<T, 3> &inYZW);
		
		
		Point(const Matrix<T, 1, 4> &rhs);
		Point(const Point &rhs);
		Point& operator = (const Matrix<T, 1, 4> &rhs);
		Point& operator = (const Point &rhs);
		bool operator == (const Point &rhs) const;
		bool operator != (const Point &rhs) const;
		bool operator < (const Point &rhs) const;
		bool operator <= (const Point &rhs) const;
		bool operator > (const Point &rhs) const;
		bool operator >= (const Point &rhs) const;
		const T& operator [] (uint8_t index) const;
		T& operator [] (uint8_t index);
		
		T* ptr();
		const T* ptr() const;
		
		Point operator + (const Point &rhs) const;
		Point operator - (const Point &rhs) const;
		T operator * (const Point &rhs) const;
		Point operator * (const T &rhs) const;
		Point operator / (const T &rhs) const;
		Point& operator += (const Point &rhs);
		Point& operator -= (const Point &rhs);
		Point& operator *= (const T &rhs);
		Point& operator /= (const T &rhs);
		Point& operator - ();
		float length() const;
		float length2() const;
		void scale(float newLength);
		Point scaled(float newLength) const;
		void normalize();
		Point normalized() const;
		Matrix<T, 4, 1>& asMatrix();
		Matrix<T, 1, 4>& asTMatrix();
		const Matrix<T, 4, 1>& asMatrix() const;
		const Matrix<T, 1, 4>& asTMatrix() const;
		
		IMPLEMENT_POINT_ACCESSOR2(x,x)	IMPLEMENT_POINT_ACCESSOR2(x,y)	IMPLEMENT_POINT_ACCESSOR2(x,z)	IMPLEMENT_POINT_ACCESSOR2(x,w)
		IMPLEMENT_POINT_ACCESSOR2(y,x)	IMPLEMENT_POINT_ACCESSOR2(y,y)	IMPLEMENT_POINT_ACCESSOR2(y,z)	IMPLEMENT_POINT_ACCESSOR2(y,w)
		IMPLEMENT_POINT_ACCESSOR2(z,x)	IMPLEMENT_POINT_ACCESSOR2(z,y)	IMPLEMENT_POINT_ACCESSOR2(z,z)	IMPLEMENT_POINT_ACCESSOR2(z,w)
		IMPLEMENT_POINT_ACCESSOR2(w,x)	IMPLEMENT_POINT_ACCESSOR2(w,y)	IMPLEMENT_POINT_ACCESSOR2(w,z)	IMPLEMENT_POINT_ACCESSOR2(w,w)
		
		IMPLEMENT_POINT_ACCESSOR3(x,x,x) IMPLEMENT_POINT_ACCESSOR3(x,x,y) IMPLEMENT_POINT_ACCESSOR3(x,x,z) IMPLEMENT_POINT_ACCESSOR3(x,x,w)
		IMPLEMENT_POINT_ACCESSOR3(x,y,x) IMPLEMENT_POINT_ACCESSOR3(x,y,y) IMPLEMENT_POINT_ACCESSOR3(x,y,z) IMPLEMENT_POINT_ACCESSOR3(x,y,w)
		IMPLEMENT_POINT_ACCESSOR3(x,z,x) IMPLEMENT_POINT_ACCESSOR3(x,z,y) IMPLEMENT_POINT_ACCESSOR3(x,z,z) IMPLEMENT_POINT_ACCESSOR3(x,z,w)
		IMPLEMENT_POINT_ACCESSOR3(y,x,x) IMPLEMENT_POINT_ACCESSOR3(y,x,y) IMPLEMENT_POINT_ACCESSOR3(y,x,z) IMPLEMENT_POINT_ACCESSOR3(y,x,w)
		IMPLEMENT_POINT_ACCESSOR3(y,y,x) IMPLEMENT_POINT_ACCESSOR3(y,y,y) IMPLEMENT_POINT_ACCESSOR3(y,y,z) IMPLEMENT_POINT_ACCESSOR3(y,y,w)
		IMPLEMENT_POINT_ACCESSOR3(y,z,x) IMPLEMENT_POINT_ACCESSOR3(y,z,y) IMPLEMENT_POINT_ACCESSOR3(y,z,z) IMPLEMENT_POINT_ACCESSOR3(y,z,w)
		IMPLEMENT_POINT_ACCESSOR3(z,x,x) IMPLEMENT_POINT_ACCESSOR3(z,x,y) IMPLEMENT_POINT_ACCESSOR3(z,x,z) IMPLEMENT_POINT_ACCESSOR3(z,x,w)
		IMPLEMENT_POINT_ACCESSOR3(z,y,x) IMPLEMENT_POINT_ACCESSOR3(z,y,y) IMPLEMENT_POINT_ACCESSOR3(z,y,z) IMPLEMENT_POINT_ACCESSOR3(z,y,w)
		IMPLEMENT_POINT_ACCESSOR3(z,z,x) IMPLEMENT_POINT_ACCESSOR3(z,z,y) IMPLEMENT_POINT_ACCESSOR3(z,z,z) IMPLEMENT_POINT_ACCESSOR3(z,z,w)
		IMPLEMENT_POINT_ACCESSOR3(w,x,x) IMPLEMENT_POINT_ACCESSOR3(w,x,y) IMPLEMENT_POINT_ACCESSOR3(w,x,z) IMPLEMENT_POINT_ACCESSOR3(w,x,w)
		IMPLEMENT_POINT_ACCESSOR3(w,y,x) IMPLEMENT_POINT_ACCESSOR3(w,y,y) IMPLEMENT_POINT_ACCESSOR3(w,y,z) IMPLEMENT_POINT_ACCESSOR3(w,y,w)
		IMPLEMENT_POINT_ACCESSOR3(w,z,x) IMPLEMENT_POINT_ACCESSOR3(w,z,y) IMPLEMENT_POINT_ACCESSOR3(w,z,z) IMPLEMENT_POINT_ACCESSOR3(w,z,w) 
		
		IMPLEMENT_POINT_ACCESSOR4(x,x,x,x) IMPLEMENT_POINT_ACCESSOR4(x,x,x,y) IMPLEMENT_POINT_ACCESSOR4(x,x,x,z) IMPLEMENT_POINT_ACCESSOR4(x,x,x,w)
		IMPLEMENT_POINT_ACCESSOR4(x,x,y,x) IMPLEMENT_POINT_ACCESSOR4(x,x,y,y) IMPLEMENT_POINT_ACCESSOR4(x,x,y,z) IMPLEMENT_POINT_ACCESSOR4(x,x,y,w)
		IMPLEMENT_POINT_ACCESSOR4(x,x,z,x) IMPLEMENT_POINT_ACCESSOR4(x,x,z,y) IMPLEMENT_POINT_ACCESSOR4(x,x,z,z) IMPLEMENT_POINT_ACCESSOR4(x,x,z,w)
		IMPLEMENT_POINT_ACCESSOR4(x,y,x,x) IMPLEMENT_POINT_ACCESSOR4(x,y,x,y) IMPLEMENT_POINT_ACCESSOR4(x,y,x,z) IMPLEMENT_POINT_ACCESSOR4(x,y,x,w)
		IMPLEMENT_POINT_ACCESSOR4(x,y,y,x) IMPLEMENT_POINT_ACCESSOR4(x,y,y,y) IMPLEMENT_POINT_ACCESSOR4(x,y,y,z) IMPLEMENT_POINT_ACCESSOR4(x,y,y,w)
		IMPLEMENT_POINT_ACCESSOR4(x,y,z,x) IMPLEMENT_POINT_ACCESSOR4(x,y,z,y) IMPLEMENT_POINT_ACCESSOR4(x,y,z,z) IMPLEMENT_POINT_ACCESSOR4(x,y,z,w)
		IMPLEMENT_POINT_ACCESSOR4(x,z,x,x) IMPLEMENT_POINT_ACCESSOR4(x,z,x,y) IMPLEMENT_POINT_ACCESSOR4(x,z,x,z) IMPLEMENT_POINT_ACCESSOR4(x,z,x,w)
		IMPLEMENT_POINT_ACCESSOR4(x,z,y,x) IMPLEMENT_POINT_ACCESSOR4(x,z,y,y) IMPLEMENT_POINT_ACCESSOR4(x,z,y,z) IMPLEMENT_POINT_ACCESSOR4(x,z,y,w)
		IMPLEMENT_POINT_ACCESSOR4(x,z,z,x) IMPLEMENT_POINT_ACCESSOR4(x,z,z,y) IMPLEMENT_POINT_ACCESSOR4(x,z,z,z) IMPLEMENT_POINT_ACCESSOR4(x,z,z,w)
		IMPLEMENT_POINT_ACCESSOR4(x,w,x,x) IMPLEMENT_POINT_ACCESSOR4(x,w,x,y) IMPLEMENT_POINT_ACCESSOR4(x,w,x,z) IMPLEMENT_POINT_ACCESSOR4(x,w,x,w)
		IMPLEMENT_POINT_ACCESSOR4(x,w,y,x) IMPLEMENT_POINT_ACCESSOR4(x,w,y,y) IMPLEMENT_POINT_ACCESSOR4(x,w,y,z) IMPLEMENT_POINT_ACCESSOR4(x,w,y,w)
		IMPLEMENT_POINT_ACCESSOR4(x,w,z,x) IMPLEMENT_POINT_ACCESSOR4(x,w,z,y) IMPLEMENT_POINT_ACCESSOR4(x,w,z,z) IMPLEMENT_POINT_ACCESSOR4(x,w,z,w)
		
		IMPLEMENT_POINT_ACCESSOR4(y,x,x,x) IMPLEMENT_POINT_ACCESSOR4(y,x,x,y) IMPLEMENT_POINT_ACCESSOR4(y,x,x,z) IMPLEMENT_POINT_ACCESSOR4(y,x,x,w)
		IMPLEMENT_POINT_ACCESSOR4(y,x,y,x) IMPLEMENT_POINT_ACCESSOR4(y,x,y,y) IMPLEMENT_POINT_ACCESSOR4(y,x,y,z) IMPLEMENT_POINT_ACCESSOR4(y,x,y,w)
		IMPLEMENT_POINT_ACCESSOR4(y,x,z,x) IMPLEMENT_POINT_ACCESSOR4(y,x,z,y) IMPLEMENT_POINT_ACCESSOR4(y,x,z,z) IMPLEMENT_POINT_ACCESSOR4(y,x,z,w)
		IMPLEMENT_POINT_ACCESSOR4(y,y,x,x) IMPLEMENT_POINT_ACCESSOR4(y,y,x,y) IMPLEMENT_POINT_ACCESSOR4(y,y,x,z) IMPLEMENT_POINT_ACCESSOR4(y,y,x,w)
		IMPLEMENT_POINT_ACCESSOR4(y,y,y,x) IMPLEMENT_POINT_ACCESSOR4(y,y,y,y) IMPLEMENT_POINT_ACCESSOR4(y,y,y,z) IMPLEMENT_POINT_ACCESSOR4(y,y,y,w)
		IMPLEMENT_POINT_ACCESSOR4(y,y,z,x) IMPLEMENT_POINT_ACCESSOR4(y,y,z,y) IMPLEMENT_POINT_ACCESSOR4(y,y,z,z) IMPLEMENT_POINT_ACCESSOR4(y,y,z,w)
		IMPLEMENT_POINT_ACCESSOR4(y,z,x,x) IMPLEMENT_POINT_ACCESSOR4(y,z,x,y) IMPLEMENT_POINT_ACCESSOR4(y,z,x,z) IMPLEMENT_POINT_ACCESSOR4(y,z,x,w)
		IMPLEMENT_POINT_ACCESSOR4(y,z,y,x) IMPLEMENT_POINT_ACCESSOR4(y,z,y,y) IMPLEMENT_POINT_ACCESSOR4(y,z,y,z) IMPLEMENT_POINT_ACCESSOR4(y,z,y,w)
		IMPLEMENT_POINT_ACCESSOR4(y,z,z,x) IMPLEMENT_POINT_ACCESSOR4(y,z,z,y) IMPLEMENT_POINT_ACCESSOR4(y,z,z,z) IMPLEMENT_POINT_ACCESSOR4(y,z,z,w)
		IMPLEMENT_POINT_ACCESSOR4(y,w,x,x) IMPLEMENT_POINT_ACCESSOR4(y,w,x,y) IMPLEMENT_POINT_ACCESSOR4(y,w,x,z) IMPLEMENT_POINT_ACCESSOR4(y,w,x,w)
		IMPLEMENT_POINT_ACCESSOR4(y,w,y,x) IMPLEMENT_POINT_ACCESSOR4(y,w,y,y) IMPLEMENT_POINT_ACCESSOR4(y,w,y,z) IMPLEMENT_POINT_ACCESSOR4(y,w,y,w)
		IMPLEMENT_POINT_ACCESSOR4(y,w,z,x) IMPLEMENT_POINT_ACCESSOR4(y,w,z,y) IMPLEMENT_POINT_ACCESSOR4(y,w,z,z) IMPLEMENT_POINT_ACCESSOR4(y,w,z,w)
		
		IMPLEMENT_POINT_ACCESSOR4(z,x,x,x) IMPLEMENT_POINT_ACCESSOR4(z,x,x,y) IMPLEMENT_POINT_ACCESSOR4(z,x,x,z) IMPLEMENT_POINT_ACCESSOR4(z,x,x,w)
		IMPLEMENT_POINT_ACCESSOR4(z,x,y,x) IMPLEMENT_POINT_ACCESSOR4(z,x,y,y) IMPLEMENT_POINT_ACCESSOR4(z,x,y,z) IMPLEMENT_POINT_ACCESSOR4(z,x,y,w)
		IMPLEMENT_POINT_ACCESSOR4(z,x,z,x) IMPLEMENT_POINT_ACCESSOR4(z,x,z,y) IMPLEMENT_POINT_ACCESSOR4(z,x,z,z) IMPLEMENT_POINT_ACCESSOR4(z,x,z,w)
		IMPLEMENT_POINT_ACCESSOR4(z,y,x,x) IMPLEMENT_POINT_ACCESSOR4(z,y,x,y) IMPLEMENT_POINT_ACCESSOR4(z,y,x,z) IMPLEMENT_POINT_ACCESSOR4(z,y,x,w)
		IMPLEMENT_POINT_ACCESSOR4(z,y,y,x) IMPLEMENT_POINT_ACCESSOR4(z,y,y,y) IMPLEMENT_POINT_ACCESSOR4(z,y,y,z) IMPLEMENT_POINT_ACCESSOR4(z,y,y,w)
		IMPLEMENT_POINT_ACCESSOR4(z,y,z,x) IMPLEMENT_POINT_ACCESSOR4(z,y,z,y) IMPLEMENT_POINT_ACCESSOR4(z,y,z,z) IMPLEMENT_POINT_ACCESSOR4(z,y,z,w)
		IMPLEMENT_POINT_ACCESSOR4(z,z,x,x) IMPLEMENT_POINT_ACCESSOR4(z,z,x,y) IMPLEMENT_POINT_ACCESSOR4(z,z,x,z) IMPLEMENT_POINT_ACCESSOR4(z,z,x,w)
		IMPLEMENT_POINT_ACCESSOR4(z,z,y,x) IMPLEMENT_POINT_ACCESSOR4(z,z,y,y) IMPLEMENT_POINT_ACCESSOR4(z,z,y,z) IMPLEMENT_POINT_ACCESSOR4(z,z,y,w)
		IMPLEMENT_POINT_ACCESSOR4(z,z,z,x) IMPLEMENT_POINT_ACCESSOR4(z,z,z,y) IMPLEMENT_POINT_ACCESSOR4(z,z,z,z) IMPLEMENT_POINT_ACCESSOR4(z,z,z,w)
		IMPLEMENT_POINT_ACCESSOR4(z,w,x,x) IMPLEMENT_POINT_ACCESSOR4(z,w,x,y) IMPLEMENT_POINT_ACCESSOR4(z,w,x,z) IMPLEMENT_POINT_ACCESSOR4(z,w,x,w)
		IMPLEMENT_POINT_ACCESSOR4(z,w,y,x) IMPLEMENT_POINT_ACCESSOR4(z,w,y,y) IMPLEMENT_POINT_ACCESSOR4(z,w,y,z) IMPLEMENT_POINT_ACCESSOR4(z,w,y,w)
		IMPLEMENT_POINT_ACCESSOR4(z,w,z,x) IMPLEMENT_POINT_ACCESSOR4(z,w,z,y) IMPLEMENT_POINT_ACCESSOR4(z,w,z,z) IMPLEMENT_POINT_ACCESSOR4(z,w,z,w)
		
		IMPLEMENT_POINT_ACCESSOR4(w,x,x,x) IMPLEMENT_POINT_ACCESSOR4(w,x,x,y) IMPLEMENT_POINT_ACCESSOR4(w,x,x,z) IMPLEMENT_POINT_ACCESSOR4(w,x,x,w)
		IMPLEMENT_POINT_ACCESSOR4(w,x,y,x) IMPLEMENT_POINT_ACCESSOR4(w,x,y,y) IMPLEMENT_POINT_ACCESSOR4(w,x,y,z) IMPLEMENT_POINT_ACCESSOR4(w,x,y,w)
		IMPLEMENT_POINT_ACCESSOR4(w,x,z,x) IMPLEMENT_POINT_ACCESSOR4(w,x,z,y) IMPLEMENT_POINT_ACCESSOR4(w,x,z,z) IMPLEMENT_POINT_ACCESSOR4(w,x,z,w)
		IMPLEMENT_POINT_ACCESSOR4(w,y,x,x) IMPLEMENT_POINT_ACCESSOR4(w,y,x,y) IMPLEMENT_POINT_ACCESSOR4(w,y,x,z) IMPLEMENT_POINT_ACCESSOR4(w,y,x,w)
		IMPLEMENT_POINT_ACCESSOR4(w,y,y,x) IMPLEMENT_POINT_ACCESSOR4(w,y,y,y) IMPLEMENT_POINT_ACCESSOR4(w,y,y,z) IMPLEMENT_POINT_ACCESSOR4(w,y,y,w)
		IMPLEMENT_POINT_ACCESSOR4(w,y,z,x) IMPLEMENT_POINT_ACCESSOR4(w,y,z,y) IMPLEMENT_POINT_ACCESSOR4(w,y,z,z) IMPLEMENT_POINT_ACCESSOR4(w,y,z,w)
		IMPLEMENT_POINT_ACCESSOR4(w,z,x,x) IMPLEMENT_POINT_ACCESSOR4(w,z,x,y) IMPLEMENT_POINT_ACCESSOR4(w,z,x,z) IMPLEMENT_POINT_ACCESSOR4(w,z,x,w)
		IMPLEMENT_POINT_ACCESSOR4(w,z,y,x) IMPLEMENT_POINT_ACCESSOR4(w,z,y,y) IMPLEMENT_POINT_ACCESSOR4(w,z,y,z) IMPLEMENT_POINT_ACCESSOR4(w,z,y,w)
		IMPLEMENT_POINT_ACCESSOR4(w,z,z,x) IMPLEMENT_POINT_ACCESSOR4(w,z,z,y) IMPLEMENT_POINT_ACCESSOR4(w,z,z,z) IMPLEMENT_POINT_ACCESSOR4(w,z,z,w)
		IMPLEMENT_POINT_ACCESSOR4(w,w,x,x) IMPLEMENT_POINT_ACCESSOR4(w,w,x,y) IMPLEMENT_POINT_ACCESSOR4(w,w,x,z) IMPLEMENT_POINT_ACCESSOR4(w,w,x,w)
		IMPLEMENT_POINT_ACCESSOR4(w,w,y,x) IMPLEMENT_POINT_ACCESSOR4(w,w,y,y) IMPLEMENT_POINT_ACCESSOR4(w,w,y,z) IMPLEMENT_POINT_ACCESSOR4(w,w,y,w)
		IMPLEMENT_POINT_ACCESSOR4(w,w,z,x) IMPLEMENT_POINT_ACCESSOR4(w,w,z,y) IMPLEMENT_POINT_ACCESSOR4(w,w,z,z) IMPLEMENT_POINT_ACCESSOR4(w,w,z,w)
		
	public:
		T x;
		T y;
		T z;
		T w;
	};
	
	template<typename T>
	static inline Point<T,4> operator * (const T &lhs, const Point<T,4> &rhs);
	
	template<typename T, typename U>
	static inline Point<U,4> operator * (const Matrix<T, 4, 4> &lhs, const Point<U,4> &rhs);
	
	typedef Point<float, 4> 	Point4f;
	typedef Point<int8_t, 4>	Point4i;
}

#include "point4_impl.hpp"

#endif // XPCC_POINTS__POINT4_HPP