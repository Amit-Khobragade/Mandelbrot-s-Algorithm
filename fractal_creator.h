#pragma once
#include <memory>
#include <vector>
#include "bitfile_main.h"
#include "mandelbrot.h"
#include "zoom_list.h"
#include "rgb.h"

class fractal_creator {
private:
	double height{ 0.0 };
	double width{ 0.0 };
	bitm::bitmap B;
	zoom_list zl; 
	std::unique_ptr<int[]> iterationsperpixel;
	std::unique_ptr<std::unique_ptr<int[]>[]> iteration;
	std::vector<std::pair<double, rgb>> range_of_colours;
	std::vector<int> total_ranges;
	bool first_range_got;

	//private member functions fragile mustn't be tampered with
	void make_fractal();
	void write();
	int get_range( int iteration ) const;
	int calculate_total_range();


public:
	//constructor
	fractal_creator( double width, double height )
		:width{ width }, height{ height }, B{ static_cast< int >(width),static_cast< int >(height) } , zl{ width,height }
	, iterationsperpixel{ std::make_unique<int[]>( mandelbrot::max_iteration ) }
	, iteration{ std::make_unique<std::unique_ptr<int[]>[]>( static_cast< size_t >(width) ) }
	, first_range_got{ false }
	{
		for (int i = 0; i < width; ++i)
			iteration[i] = std::make_unique<int[]>( static_cast< size_t >(height) );

		zoom_in( width / 2, height / 2, 4.0 / width );
	}


	bool push_colour_range( double range_end, rgb colour );


	inline void zoom_in( double x, double y, double scale ) {
		zl.pushback( zoom( x, height - y, scale ) );
	}


	inline void get_results() {
		make_fractal();
		calculate_total_range();
		write();
	}
};

