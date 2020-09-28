#pragma once
struct rgb {

	double r;
	double g;
	double b;
	rgb( double r, double g, double b )
		:r{ r }, g{ g }, b{ b }
	{}
	
	rgb operator-(  const rgb& other ) const {	
		double r = this->r - other.r;
		double b = this->b - other.b;
		double g = this->g - other.g;
		return rgb( r, g, b );
	}


};

