#pragma once
#include <deque>






namespace file {

	// modification of deque to be fixed with limited functions access

	template<typename T, size_t Size>
	class static_deque : std::deque<T>
	{
		// deleting some function 
		// or hiding by redefinintion 
		size_t				_size;

		void load_deque(const T(&arg)[Size]) {
			int i{};
			for (const auto& e : arg) {
				this->at(i) = e;
				++i;
			}
		}

	public:

		static_deque(const T(&arg)[Size])
			: _size(Size)
		{
			this->resize(_size);
			load_deque(arg);
		}

		// access element redifine
		using std::deque<T>::at;

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


	template<typename T, size_t N>
	void print_deque(const static_deque<T, N>& deq, std::string_view comment) {
		std::cout << comment << '\n';
		for (int i = 0 ; i < N ; ++i)
			std::cout << deq.at(i) << "  ";
		std::cout << '\n';
	}

}



