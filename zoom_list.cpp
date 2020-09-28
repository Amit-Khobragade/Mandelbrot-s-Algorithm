#include "zoom_list.h"

void zoom_list::pushback( const zoom& z ) {
	zoom_vec.push_back( z );

	x_centre += (z.x - width / 2) * scale;
	y_centre += (z.y - height / 2) * scale;
	scale *= z.scale;
}
