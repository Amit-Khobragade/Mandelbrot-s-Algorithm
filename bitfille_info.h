#pragma once
#include <cstdint>

#pragma pack(push,2)							//to make sure that the size of the struct remains constant
namespace bitm {
	struct bitmap_info {
		int32_t header_size{ 40 };      //size of all the elements in this structure
		int32_t width{};
		int32_t height{};
		int16_t plane{ 1 };             //single frame  
		int16_t bits_per_pixel{ 24 };   //1byte per color of the pixel that is 8*3 i.e., 24
		int32_t compression{ 0 };
		int32_t data_size{ 0 };
		int32_t horizontal_resolution{ 2400 };
		int32_t vertical_resolution{ 2400 };
		int32_t colors{ 0 };
		int32_t important_colors{ 0 };
	};
}

#pragma pack(pop)