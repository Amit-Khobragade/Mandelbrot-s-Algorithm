#pragma once
#include <vector>
#include <iostream>
#include "zoom.h"
class zoom_list {
private:
	double x_centre{ 0.0 };
	double y_centre{ 0.0 };
	double scale{ 1.0 };

	double width{ 0 };
	double height{ 0 };
	std::vector<zoom> zoom_vec;
public:
	zoom_list(double width,double height)
		:width{width},height{height}
	{}
	void pushback( const zoom& z );
	inline std::pair<double, double> scaling( double x, double y ) {
		double x_coordinate{ (x - width / 2) * scale + x_centre };
		double y_coordinate{ (y - height / 2) * scale + y_centre };
		return std::make_pair( x_coordinate, y_coordinate );
	}
};

