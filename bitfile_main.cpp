#include "bitfile_main.h"

using namespace bitm;

namespace bitm {
	bool bitmap::write( std::string file_name ) {
		bitfile_head head;
		bitmap_info info;
		head.data_offset = sizeof(bitfile_head)+sizeof(bitmap_info);
		head.file_size = head.data_offset + width * height * 3;
		info.width = width;
		info.height = height;
		std::ofstream of{ file_name, std::ios::out | std::ios::binary };
		if (!of)
			return false;
		of.write( ( char* )(&head), sizeof( head ) );
		of.write( ( char* )(&info), sizeof( info ) );
		of.write( ( char* )(pixel.get()), (static_cast< std::streamsize >(width) * height * 3) );
		of.close();
		if (!of)
			return false;
		return true;
	}
	void bitmap::set_pixel( int x, int y, uint8_t red, uint8_t green, uint8_t blue ) {
		auto temp_ptr = pixel.get();
		temp_ptr += y * 3 * width + x * 3;

		temp_ptr[0] = blue;
		temp_ptr[1] = green;
		temp_ptr[2] = red;
	}
}