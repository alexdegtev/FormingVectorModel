#include "Array.h"

MyObjects::Array::Array(int size) : size(size)
{
	data = new int[size];
}

MyObjects::Array::~Array()
{
	delete data;
}

int MyObjects::Array::get(int index)
{
	return data[index];
}

void MyObjects::Array::set(int index, int value)
{
	data[index] = value;
}
