#include <iostream>
#include <cstdint>
#include <memory>
#include <math.h>
#include "fractal_creator.h"

using namespace std;


int main() {
	const int width{ 800 }, height{ 600 };
	fractal_creator fractal{ width,height };
	
	fractal.push_colour_range( 0.0, rgb( 0, 0, 0 ) );
	fractal.push_colour_range( 0.1, rgb( 128, 0, 255 ) );
	fractal.push_colour_range( 0.5, rgb( 255, 255, 255 ) );
	fractal.push_colour_range( 1.0, rgb( 0, 255, 0 ) );
	//fractal.get_results();
	fractal.zoom_in( 295, 202, 0.1 );
	fractal.zoom_in( 312, 304, 0.1 );

	//fractal.zoom_in( 588, 355, 0.1 );
	fractal.get_results();
}

