// LestaInternCPPTest.cpp : Defines the entry point for the application.
//

#include "LestaInternCPPTest.h"
#include "DivisionByTwo.h"
#include "CircularBuffArray.h"

using namespace std;

int main()
{
	cout << "Hello CMake." << endl;
    const auto numberOfElements = 2;
    NumWrap initial(1);
    CircularBuffArray<NumWrap> buffer_(numberOfElements, initial);
    NumWrap first(3);
    NumWrap second(2);
    buffer_.push(first);
    buffer_.push(second);

	isEven(3);
	return 0;
}