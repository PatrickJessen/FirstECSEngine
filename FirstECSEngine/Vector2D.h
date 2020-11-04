#pragma once
#include <iostream>

template<typename T>
struct Vector2D
{
public:

	T x;
	T y;

	Vector2D()
	{
		this->x = 0;
		this->y = 0;
	}

	Vector2D(T x, T y)
	{
		this->x = x;
		this->y = y;
	}

	inline Vector2D<T> operator+(const Vector2D<T>& v2) const
	{
		return Vector2D<T>(x + v2.x, y + v2.y);
	}

	inline friend Vector2D<T>& operator+=(Vector2D<T>& v1, const Vector2D<T>& v2)
	{
		v1.x += v2.x;
		v1.y += v2.y;
		return v1;
	}

	inline Vector2D<T> operator-(const Vector2D<T>& v2) const
	{
		return Vector2D<T>(x - v2.x, y - v2.y);
	}

	inline friend Vector2D<T>& operator-=(Vector2D<T>& v1, const Vector2D<T>& v2)
	{
		v1.x -= v2.x;
		v1.y -= v2.y;
		return v1;
	}

	inline Vector2D<T> operator*(const T scale) const
	{
		return Vector2D<T>(x * scale, y * scale);
	}

	inline Vector2D<T> operator/(const T d) const
	{
		return (d != 0 ? Vector2D<T>(x / d, y / d) : Vector2D<T>());
	}

	inline Vector2D<T>& zero()
	{
		this->x = 0;
		this->y = 0;
		return *this;
	}

	inline Vector2D<T>& ones()
	{
		this->x = 1;
		this->y = 1;
		return *this;
	}

	inline friend std::ostream& operator<<(std::ostream& stream, const Vector2D<T>& v)
	{
		stream << "(" << v.x << "," << v.y << ")";
		return stream;
	}

};
using Vector2DI = Vector2D<int>;
using Vector2DU = Vector2D<unsigned int>;
using Vector2DF = Vector2D<float>;
using Vector2DD = Vector2D<double>;