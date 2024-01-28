#include <iostream>
#include "MyLib/Console_Library/escape_code.h"

template<typename T>
struct message {
	T  data;
	std::vector<uint8_t> body;

	size_t size() const {
		return sizeof(T) + body.size();
	}

	// Override for std::cout  compatibility - produces friendly description of message
	friend std::ostream& operator << (std::ostream& os, const message<T>& msg) {
		os << "size : " << msg.size() << " Data : [" << msg.data << "]";
		return os;
	}

	// Pushes any POD-like data into message buffer
	template<typename Tdata>
	friend message<T>& operator << (message<T>& msg, const Tdata& _data) {

		// Check that type
		static_assert(std::is_trivially_copyable_v<Tdata>, "Data type should be not complex");

		// Check current size of vector, as this will be the point we insert the data
		size_t i = msg.body.size();

		// Resize the vector by the size of the data being pushed
		msg.body.resize(msg.body.size() + sizeof(Tdata));

		// Physically copy the data into the newly allocated vector space
		std::memcpy(msg.body.data() + i, &_data, sizeof(Tdata));

		return msg;
	}
};

template<typename T>
std::ostream& operator << (std::ostream& os, const std::vector<T>&vec) {
	for (const auto& e : vec)
		os << (int)e << " ";

	return os;
}


int main()
{
	message<std::string>  msg;

	msg.data = "hello";
	msg.body = { 3,4,7 };

	print_ << msg << end_;
	print_ << msg.body << end_;

	msg << 34 << 67 << 56.56f;

	print_ << msg << end_;
	print_ << msg.body << end_;



	std::cin.get();
	return 0;
}