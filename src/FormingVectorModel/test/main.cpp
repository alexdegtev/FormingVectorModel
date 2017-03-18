#include <iostream>
#include <array>
#include <vector>

int main()
{
	//size_t size = 1000000000;

	//int *a = new int[size];
	//system("pause");
	//delete[] a;


	//std::vector<int> b;
	//for (size_t i = 0; i < size; i++)
	//	b.push_back(0);
	//system("pause");
	//b.clear();

	int size = 10;
	int *a = new int[size];
	for (int i = 0; i < size; i++)
		a[i] = i;

	for (int i = 0; i < size; i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;

	int *b = new int[size + 1];
	std::copy(a, a + size, b);
	delete[] a;
	b[size] = size;



	for (int i = 0; i < size + 1; i++)
		std::cout << b[i] << " ";
	std::cout << std::endl;


	//std::copy(std::begin(src), std::end(src), std::begin(dest));
	return 0;
}
