#include <iostream>
#include <cstdint>
#include "letter_funcs.h"

#define NO_INLINE __declspec(noinline)

NO_INLINE void zero_number(int index)
{
	int numbers[] = { 1,2,3,4 };

	numbers[index] = 0;

	for (int num : numbers)
	{
		std::cout << num << '\n';
	}
}


NO_INLINE void func4(int arg)
{
	int num_to_zero = 0;
	std::cout << "Pick a number to zero: ";
	std::cin >> num_to_zero;
	zero_number(num_to_zero);
	std::cout << "Arg was 0x" << std::hex << arg << '\n';
}


NO_INLINE int func3(int arg)
{
	func4(arg + 0x1000);
	return arg;
}

NO_INLINE int func2(int arg)
{
	func3(arg + 0x100);
	return arg;
}

NO_INLINE int func1(const int & arg)
{
	func2(arg + 0x10);
	return arg;
}

int main(int argc, char* argv[])
{
	// funcA();
	for (int iter_num = 1; iter_num < 10; ++iter_num)
	{
		func1(iter_num);
	}
}