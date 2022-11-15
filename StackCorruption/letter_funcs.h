#include <iostream>

#define NO_INLINE __declspec(noinline)

NO_INLINE static bool funcE(int * arr)
{
	return arr[0] == 0;
}

NO_INLINE static bool funcD(int * arr)
{
	return funcE(arr) == false;
}

NO_INLINE static bool funcC(int * arr)
{
	return funcD(arr) == false;
}


NO_INLINE static bool funcB(int * arr)
{
	return funcC(arr) == false;
}

NO_INLINE static void funcA()
{
	int arr[8];
	if (funcB(arr))
		std::cout << std::flush;
}