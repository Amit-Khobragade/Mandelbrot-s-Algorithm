#include "fractal_creator.h"


void fractal_creator::make_fractal() {
	mandelbrot m;
	for (int x{ 0 }; x < width; ++x)
		for (int y{ 0 }; y < height; ++y) {
			auto coordinates = zl.scaling( x, y );
			iteration[x][y] = m.optimized_get_iteration( coordinates.first, coordinates.second );		//optimized function doesn't use complex numbers 
			if (iteration[x][y] != mandelbrot::max_iteration)
				iterationsperpixel[iteration[x][y]]++;
		}
	int total{ 0 };
	for (int iteration{ 0 }; iteration < mandelbrot::max_iteration; iteration++) {
		total += iterationsperpixel[iteration];
	}
}


void fractal_creator::write() {
	rgb start{ 0,0,0 };
	rgb end{ 0,255,0 };
	auto diff = end - start;
	int total{ 0 };
	for (int i = 0; i < mandelbrot::max_iteration; ++i)
		total += iterationsperpixel[i];

	for (int x{ 0 }; x < width; ++x)
		for (int y{ 0 }; y < height; ++y) {
			//important initializations 
			int range = get_range( iteration[x][y] );
			int total_range = total_ranges.at( range );
			double range_start= range_of_colours.at( range ).first;
			rgb& start = range_of_colours.at( range ).second;
			rgb& end = range_of_colours.at( range + 1 ).second;
			auto diff = end - start;



			if (iteration[x][y] != mandelbrot::max_iteration) {
				int total_pixels{ 0 };
				for (int i = static_cast< int >(range_start); i < iteration[x][y]; ++i)
					total_pixels += iterationsperpixel[i];
				uint8_t red{ static_cast< uint8_t >(start.r + diff.r * total_pixels / total_range) };
				uint8_t green{ static_cast< uint8_t >(start.g + diff.g * total_pixels / total_range) };
				uint8_t blue{ static_cast< uint8_t >(start.b + diff.b * total_pixels / total_range) };
				B.set_pixel( x, y, red, green, blue );
			}
		}

	B.write( "xyz.bmp" );
}


int fractal_creator::get_range( int iteration ) const {
	if (iteration >= mandelbrot::max_iteration)
		return (range_of_colours.size() - 2);
	if ( iteration < 0) 
		return -1;
	
	for (size_t i{ 0 }; i < range_of_colours.size(); ++i) {
		auto& rnc = range_of_colours.at( i );
		if (rnc.first > static_cast< double >(iteration))
			return i-1;
	}
	return -2;
}


int fractal_creator::calculate_total_range() {
	int index{ 0 };
	for (int i{ 0 }; i < mandelbrot::max_iteration; ++i) {
		int pixel = iterationsperpixel[i];
		if (static_cast< double >(i) >= range_of_colours.at( index + 1 ).first)
			index++;
		total_ranges.at( index ) += pixel;
	}

	return 0;
}


bool fractal_creator::push_colour_range( double range_end, rgb colour ) {
	//to check wheather the range exists or not 
	if (range_end > 1.0 || range_end < 0.0) {
		std::cerr << "error: colour range incorrect ";
		return 0;
	}
	for(const auto& rnc:range_of_colours)
		if (rnc.first == range_end) {
			std::cerr << "error: colour range already exists ";
			return 0;
		}


	range_of_colours.push_back( std::make_pair( range_end * mandelbrot::max_iteration, colour ) );
	//to sort the input
	for (size_t i = range_of_colours.size() - 1; i > 0; --i) {
		if (range_of_colours.at( i ).first > range_of_colours.at( i - 1 ).first)
			break;
		std::swap( range_of_colours.at( i ), range_of_colours.at( i - 1 ) );
	}


	//to avoid the first inp
	if (first_range_got)
		total_ranges.push_back( 0 );
	first_range_got = true;
	return 1;  
}