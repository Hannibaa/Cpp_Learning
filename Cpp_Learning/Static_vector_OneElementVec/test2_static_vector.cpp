#include <iostream>
#include <future>
#include <thread>
#include "MyLib/Console_Library/escape_code.h"
#include "MyLib/static_vector.h"
#include "MyLib/container_utility.h"

// we have before created another type of sizeof
// se we see ostream size of char out
template<typename T>
size_t Sizeof(T& t) {
	// we can specifie that T sould be streamable
	std::stringstream ss;
	ss << t;
	return ss.str().size();
}


// this buffer of recieved data from out side host

struct Buffer : std::vector<int8_t>  {

	size_t                _size;

	Buffer()
		: _size{}
	{}

	size_t size() const {
		return this->size();
	}

	template<typename T>
	friend Buffer& operator << (Buffer& vec, const T& _data) {
		

		// get localization-memorization in vector data
		size_t l = vec.size();

		// expand vector to new size
		vec.resize(l + sizeof(T));

		// recopy all data as bytes
		std::memcpy(vec.data() + l, &_data, sizeof(T));

		_size = vec.size();

		return vec;
	}
};


int main()
{



	wait_;
	return 0;
}