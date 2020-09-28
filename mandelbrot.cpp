#include "mandelbrot.h"

int mandelbrot::get_iteration( double x, double y ) {
	//x+iy=z
	//z2=x2+(2*xyi)-y2
	//c=x0+iy0
	//x0&y0=scaled x and y coordinates
	complex::complex_numbers z;
	complex::complex_numbers c{ x,y };
	int iteration{ 0 };
	while (iteration < max_iteration) {
		z = z * z + c;
		if (mod_sq( z ) > 4)   //use mod_sq for a lesser defined pic
			break;
		iteration++;
	}

	return iteration;
}

int mandelbrot::optimized_get_iteration( double x0, double y0 ) {
	//z=x+yi    //x=0,y=0
	//c=x0+y0i  //x=scaled(px),y=scaled(py)
	//do
	//z2=x2+(2*xy)i-y2
	//z=z2+c   //z=x2-y2+x0+(2*xy+y0)i
	//x=x2-y2+x0   //y=2*xy+y0
	//x2=x*x	   //y2=y*y
	//if(sqrt(x2+y2)<2 )
	// break
	//iteration++
	//while( iteration<max_iteration)

	double  x{ 0 };
	double  y{ 0 };
	double x2{ 0 }, y2{ 0 };
	//z=x+iy		c=x0+iy0
	int iteration{ 0 };
	while (iteration < max_iteration) {
		x2 = x * x;				y2 = y * y;
		y = 2 * x * y + y0;     x = x2  + x0 - y2;
		x2 = (x * x);			y2 = (y * y);
		if (x2 + y2 > 4)
			break;
		iteration++;
	}

	return iteration;
}