#include <iostream>
#include "../FormingVectorModel/Core/Common/Types/Array.hpp"
#include "../FormingVectorModel/Core/Common/Types/Matrix.hpp"
#include <vector>
#include <algorithm>
using namespace std;
using namespace FVM::Core::Common::Types;

void array_test()
{
	int n = 10;
	Array<int> *a = new Array<int>(n);

	for (int i = 0; i < n; i++)
		(*a)(i) = 0;

	for (int i = 0; i < n; i++)
		cout << (*a)(i) << " ";
	cout << endl;

	Array<int> *b = new Array<int>(n + 1);
	for (int i = 0; i < n + 1; i++)
		(*b)(i) = 1;

	for (int i = 0; i < n + 1; i++)
		cout << (*b)(i) << " ";
	cout << endl;


	(*a) = (*b);

	for (int i = 0; i < n + 1; i++)
		cout << (*a)(i) << " ";
	cout << endl;

	(*a)(3) = 0;

	for (int i = 0; i < n + 1; i++)
		cout << (*a)(i) << " ";
	cout << endl;

	for (int i = 0; i < n + 1; i++)
		cout << (*b)(i) << " ";
	cout << endl;

	delete a;
	delete b;
}

void matrix_test()
{
	Matrix<int> *m = new Matrix<int>(2, 2);

	cout << (*m)(0, 0) << endl;
	(*m)(0, 0) = 10;
	cout << (*m)(0, 0) << endl;

	delete m;
}

int main()
{
	vector<int> a = { 1, 2, 3 };
	for(int i=0;i<a.size();i++)
	{
		if(a[i] == 2)
		{
			a.erase(a.begin() + i);
			break;
		}
	}


	return 0;
}