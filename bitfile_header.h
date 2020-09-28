#pragma once
#include <cstdint>

#pragma pack(push,2)
namespace bitm {
	struct bitfile_head {
		char header[2]{ 'B','M' };
		int32_t file_size{};
		int32_t data_offset{};
		int32_t reserved{ 0 };
	};
}

#pragma pack(pop)