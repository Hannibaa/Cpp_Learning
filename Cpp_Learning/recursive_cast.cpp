#include <iostream>
#include "c:\Users\Acer\source\MyLib/Console_Library/escape_code.h"
#include "get_first_type.h"

using namespace std;

template<typename T, typename ...Ts>
typename first_type<Ts...>::type Cast(T x) {

	return (typename first_type<Ts...>::type)(Cast < T, ;

}

int main()
{
	print_ << "****** " << RED_FG << " KADDA Aoues Small Software " << RESETMODE << " ******* \n";

	print_ << "casting " << Cast<int, int>(100) << end_;


	cin.get();
	return 0;
}