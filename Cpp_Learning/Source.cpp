#include <iostream>
#include <string>
#include <vector>

struct Vertex { float x, y, z; };

using namespace std;

int main()
{
	vector<Vertex> v;
	v.push_back({ 3,2,1 });
	v.push_back({ 45,45,3 });

	cout << v.size() << endl;
	cout << "Print vectors\n";
	cout << v[0] << "      " << v[1] << endl;






	std::cin.get();

	return 0;

}