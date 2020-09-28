#pragma once
#include <cstdint>
#include <memory>
#include <string>
#include <fstream>
#include "bitfile_header.h"
#include "bitfille_info.h"

namespace bitm {
	class bitmap {
	private:
		int width{ 0 };
		int height{ 0 };
		std::unique_ptr<uint8_t[]> pixel{ nullptr };
	public:
		bitmap( int _width, int _height )
			:width{ _width }, height{ _height }
		{
			pixel = std::make_unique<uint8_t[]>( _width * _height * 3 ); //height * width *number of colors
			memset( pixel.get(), 0, _width* _height * 3 );               // to asign every value to 0
		}
		bool write( std::string file_name );
		void set_pixel( int x, int y, uint8_t red, uint8_t green, uint8_t blue );
		
	};

}