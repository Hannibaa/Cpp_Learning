// 1. calculate file size
// 2. calculate portion to be loaded 
// 3. use deque for loading and unloading portion

#include <iostream>
#include <fstream>
#include <filesystem>
#include <deque>


#define end_     '\n'

namespace fs = std::filesystem;


// define buffer for typed of size size
template<typename T>
requires std::is_pod_v<T>
struct Buffer :  std::vector<T> {
	
};

template<typename T>
size_t load_file(std::fstream& fstream, Buffer<T>& buffer, size_t position,  size_t size) {
	// suppose every thing is ok
	size = (size / sizeof(T)) * sizeof(T);

	buffer.resize(size);

	fstream.seekg(position)
		   .read(reinterpret_cast<char*>(buffer.data(), size);

	return size;
}

template<typename T>
void print_buffer(const Buffer<T> buffer, std::string_view comment) {
	std::cout << comment << end_;
	for (const auto& e : buffer)
		std::cout << e << " ";
	std::cout << end_;
}

// making fixed size deque to 

template<typename T, size_t Size>
class FDeque :  std::deque<T>
{
	// deleting some function 
	// or hiding by redefinintion 
	size_t				_size;

	void load_deque(const T (&arg)[Size]) {
		int i{};
		for (const auto& e : arg) {
			this->at(i) = e;
			++i;
		}
	}

public:

	FDeque(const T (&arg)[Size] )
		: _size(Size)
	{
		this->resize(_size);
		load_deque(arg);
	}

	size_t count() const {
		return this->size();
	}

	void push(const T& arg) {
		this->push_front(arg);
		this->pop_back();
		this->resize(Size);
	}

	T front() const {
		return this->at(0);
	}

	T& front() {
		return this->at(0);
	}

	T back() const {
		return this->at(Size - 1);
	}

	T& back() {
		return this->at(Size - 1);
	}
};

template<size_t _Size>
class BufferManager {
	FDeque<Buffer, _Size>	_deqBuffers;
	std::fstream			_pStream;
	size_t					_sizeDeque;
	size_t					_MaxSize;
	size_t					_MaxAcceptSize;

public:



};



int main() {
	// testing new deque
	FDeque<int, 4>   d{ {23,45,66,77} };

	std::cout << "front " << d.front() << std::endl;
	std::cout << "back  " << d.back() << std::endl;

	d.push(444);

	std::cout << "front " << d.front() << std::endl;
	std::cout << "back  " << d.back() << std::endl;
	std::cout << "size  " << d.count() << std::endl;

	// for third time
	d.push(1000);

	std::cout << "front " << d.front() << std::endl;
	std::cout << "back  " << d.back() << std::endl;
	std::cout << "size  " << d.count() << std::endl;



	return 0;
}