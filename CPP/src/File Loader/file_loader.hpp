#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>

#include "buffer.hpp"
#include "static_deque.hpp"

namespace fs = std::filesystem;


namespace file {
	// function for general use of loading portion of file to buffer with type T
	// input parameter without inspection limit.
	template<typename T>
	size_t load_file(std::fstream& fstream, Buffer<T>& buffer, size_t position, size_t size) {
		// resize buffer
		buffer.resize(size );
		// goto position
		fstream.seekg(position);
		// read data: in buffer
		fstream.read(reinterpret_cast<char*>(buffer.data()), size * sizeof(T));

		return size;
	}

	// function to upload buffer to special location
	template<typename T>
	requires std::is_pod_v<T>
	void upload_file(std::fstream& fstream, const Buffer<T>& buffer, size_t position, size_t size)
	{
		fstream.seekg(position);
		fstream.write(reinterpret_cast<const char*>(buffer.data()), size * sizeof(T));
	}


	  

	// file loader manager
	template<size_t _Size, typename T>
	class Manager {
		static_deque<Buffer<T>, _Size>	_deqBuffers;
		std::fstream				_Stream;
		fs::path					_file_name;
		size_t						_sizeDeque;
		size_t						_MaxSize;
		size_t						_MaxAcceptSize;

	public:
		using value_type = T;

		Manager(const fs::path& file_name)
			:_file_name(file_name)
			,_Stream(_file_name.c_str(), std::ios::in | std::ios::out | std::ios::binary)
		{
			if (!_Stream.is_open()) {
				// stop and throw exception
				throw std::runtime_error("");
			}
		}

	};



}
