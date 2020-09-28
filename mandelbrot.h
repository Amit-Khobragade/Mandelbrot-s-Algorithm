#pragma once
#include "complex_numbers.h"
#include "zoom_list.h"


class mandelbrot {
public:
	static const int max_iteration{ 1000 };
	int get_iteration( double x0, double y0 );
	int optimized_get_iteration( double x0, double y0 );

};
