#pragma once
struct zoom {
	double x{ 0 };
	double y{ 0 };
	double scale{ 0.0 };

	zoom() = default;

	zoom( double x, double y, double scale )
		:x{ x }, y{ y }, scale{ scale }
	{}

};

