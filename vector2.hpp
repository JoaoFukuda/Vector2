/*
 * MIT License
 *
 * Copyright (c) 2020 João Francisco Cocca Fukuda
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#pragma once

#include <cmath>
#include <ostream>

template<class T>
struct Vector2
{
	T x, y;

	Vector2<T> operator+(const Vector2<T> &other) const
	{
		return {x + other.x, y + other.y};
	}

	void operator+=(const Vector2<T> &other)
	{
		x += other.x;
		y += other.y;
	}

	Vector2<T> operator-(const Vector2<T> &other) const
	{
		return {x - other.x, y - other.y};
	}

	void operator-=(const Vector2<T> &other)
	{
		x -= other.x;
		y -= other.y;
	}

	Vector2<T> operator*(double value) const
	{
		return {static_cast<T>(x * value), static_cast<T>(y * value)};
	}

	void operator*=(double value)
	{
		x *= value;
		y *= value;
	}

	Vector2<T> operator/(double value) const
	{
		return {static_cast<T>(x / value), static_cast<T>(y / value)};
	}

	void operator/=(double value)
	{
		x /= value;
		y /= value;
	}

	template <class U>
	operator Vector2<U>() const
	{
		return {static_cast<U>(x), static_cast<U>(y)};
	}

	double DotProduct(const Vector2<T> &other = *this) const
	{
		return (x * other.x) + (y * other.y);
	}

	double Distance(const Vector2<T> &other = {0, 0}) const
	{
		Vector2<T> difference {other.x - x, other.y - y};
		return sqrt(difference.DotProduct());
	}
};

template <class T>
std::ostream &operator<<(std::ostream &stream, const Vector2<T> &vector2)
{
	stream << "(" << vector2.x << ", " << vector2.y << ")";
	return stream;
}

