#include <iostream>
#include <thread>

#define end_    '\n'
#define line_   std::cout << "---------------------------------------------------------------------\n"
#define wait_   std::cin.get()
#define print_  std::cout 

using namespace std;

struct Vertex
{
	float x, y, z;
};

struct VertexLike {
	int a, b, c;
	operator Vertex() { return Vertex{ (float)a,(float)b,(float)c }; };
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
	stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
	return stream;
}

class ContinueLoop {
	std::string id;
	unsigned int i;
	std::thread t1;

	void loop() {
		while (true) {
			i++;
			std::cout << id << i << '\r';
		}
	}

public:

	ContinueLoop(const std::string& _id) 
		: id{_id}, i{}
		, t1(&ContinueLoop::loop,this)
	{
		
	}

	unsigned int get() const { return i; }

	void join() { if (!t1.joinable()) t1.join(); }

	~ContinueLoop() { if (!t1.joinable()) t1.join(); }
};


int main()
{
	ContinueLoop loop1("first One");
	ContinueLoop loop2("second Two");

	print_ << "hello world\n";

	while (loop1.get() > 10000) loop1.join();
	while (loop2.get() > 20000) loop2.join();

	loop1.join();
	loop2.join();
	cin.get();
	return 0;
}