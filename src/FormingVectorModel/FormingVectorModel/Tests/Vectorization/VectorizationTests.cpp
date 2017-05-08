#include "VectorizationTests.h"
#include <iostream>
#include "../../Core/IO/Writer.h"
#include "../../Core/IO/Reader.h"
#include "../../Core/Objects/Geometric/ILine.h"
#include "../../Core/Objects/Geometric/Point.h"
#include "../../Core/Objects/Geometric/Line.h"
#include "../../Core/Vectorization/Vectorization.h"
#include "../../Core/Objects/Visual/Color.h"

using namespace Core::Objects::Geometric;
using namespace Core::IO;
using namespace Core::Objects::Visual;

VectorizationTests::VectorizationTests()
{
}

std::vector<IObject*> VectorizationTests::vectorization(IImage* image, Path path)
{
	return image->vectorize(new Core::Vectorization::Vectorization);
}

bool VectorizationTests::test1()
{
	Path path("../../../data/vectorization/1.png");
	IImage* image = Reader::read(path);
	bool result = false;


	std::vector<IObject*> objects = vectorization(image, path);
	if(objects.size() == 1)
	{
		ILine* l = (ILine*)objects[0];

		if (l && *(l) == Line(Point(1, 1), Point(3, 1)))
		{
			result = true;
		}
	}


	for(auto i : objects)
	{
		delete i;
	}

	delete image;

	return result;
}

bool VectorizationTests::test2()
{
	Path path("../../../data/vectorization/2.png");
	IImage* image = Reader::read(path);
	bool result = false;


	std::vector<IObject*> objects = vectorization(image, path);
	if (objects.size() == 1)
	{
		ILine* l = (ILine*)objects[0];
		if(l && *(l) == Line(Point(1, 1), Point(3, 3)))
		{
			result = true;
		}
	}


	for (auto i : objects)
	{
		delete i;
	}

	delete image;

	return result;
}

bool VectorizationTests::test3()
{
	Path path("../../../data/vectorization/3.png");
	IImage* image = Reader::read(path);
	bool result = false;


	std::vector<IObject*> objects = vectorization(image, path);
	if (objects.size() == 1)
	{
		ILine* l = (ILine*)objects[0];
		if(l && *(l) == Line(Point(1, 1), Point(1, 3)))
		{
			result = true;
		}
	}


	for (auto i : objects)
	{
		delete i;
	}

	delete image;

	return result;
}

bool VectorizationTests::test4()
{
	Path path("../../../data/vectorization/4.png");
	IImage* image = Reader::read(path);
	bool result = false;


	std::vector<IObject*> objects = vectorization(image, path);
	if (objects.size() == 2)
	{
		ILine* l1 = (ILine*)objects[0];
		ILine* l2 = (ILine*)objects[1];
		if (l1 && l2 &&
			*(l1) == Line(Point(1, 1), Point(3, 1)) &&
			*(l2) == Line(Point(1, 3), Point(3, 3)))
		{
			result = true;
		}
	}


	for (auto i : objects)
	{
		delete i;
	}

	delete image;

	return result;
}

bool VectorizationTests::test5()
{
	Path path("../../../data/vectorization/5.png");
	IImage* image = Reader::read(path);
	bool result = false;


	std::vector<IObject*> objects = vectorization(image, path);
	if (objects.size() == 2)
	{
		ILine* l1 = (ILine*)objects[0];
		ILine* l2 = (ILine*)objects[1];
		if (l1 && l2 &&
			*(l1) == Line(Point(1, 1), Point(3, 1)) &&
			*(l2) == Line(Point(3, 1), Point(3, 3)))
		{
			result = true;
		}
	}
	// TODO: It's not good. Must be previous variant.
	if (objects.size() == 3)
	{
		ILine* l1 = (ILine*)objects[0];
		ILine* l2 = (ILine*)objects[1];
		ILine* l3 = (ILine*)objects[2];
		if (l1 && l2 && l3 &&
			*(l1) == Line(Point(1, 1), Point(3, 1)) &&
			*(l2) == Line(Point(2, 1), Point(3, 2)) &&
			*(l3) == Line(Point(3, 2), Point(3, 3)))
		{
			result = true;
		}
	}


	for (auto i : objects)
	{
		delete i;
	}

	delete image;

	return result;
}

bool VectorizationTests::test6()
{
	Path path("../../../data/vectorization/6.png");
	IImage* image = Reader::read(path);
	bool result = false;


	std::vector<IObject*> objects = vectorization(image, path);
	if (objects.size() == 2)
	{
		ILine* l1 = (ILine*)objects[0];
		ILine* l2 = (ILine*)objects[1];
		if (l1 && l2 &&
			*(l1) == Line(Point(1, 1), Point(3, 1)) &&
			*(l2) == Line(Point(3, 1), Point(5, 3)))
		{
			result = true;
		}
	}


	for (auto i : objects)
	{
		delete i;
	}

	delete image;

	return result;
}

bool VectorizationTests::test7()
{
	Path path("../../../data/vectorization/7.png");
	IImage* image = Reader::read(path);
	bool result = false;


	std::vector<IObject*> objects = vectorization(image, path);
	if (objects.size() == 3)
	{
		ILine* l1 = (ILine*)objects[0];
		ILine* l2 = (ILine*)objects[1];
		ILine* l3 = (ILine*)objects[2];
		if (l1 && l2 && l3 &&
			*(l1) == Line(Point(1, 1), Point(2, 1)) &&
			*(l2) == Line(Point(2, 1), Point(3, 2)) &&
			*(l3) == Line(Point(3, 2), Point(3, 3)))
		{
			result = true;
		}
	}


	for (auto i : objects)
	{
		delete i;
	}

	delete image;

	return result;
}

bool VectorizationTests::test8()
{
	Path path("../../../data/vectorization/8.png");
	IImage* image = Reader::read(path);
	bool result = false;


	std::vector<IObject*> objects = vectorization(image, path);
	if (objects.size() == 2)
	{
		ILine* l1 = (ILine*)objects[0];
		ILine* l2 = (ILine*)objects[1];
		if (l1 && l2 &&
			*(l1) == Line(Point(1, 1), Point(5, 1)) &&
			*(l2) == Line(Point(3, 1), Point(3, 3)))
		{
			result = true;
		}
	}
	// TODO: It's not good. Must be previous variant.
	if (objects.size() == 3)
	{
		ILine* l1 = (ILine*)objects[0];
		ILine* l2 = (ILine*)objects[1];
		ILine* l3 = (ILine*)objects[2];
		if (l1 && l2 &&
			*(l1) == Line(Point(1, 1), Point(5, 1)) &&
			*(l2) == Line(Point(2, 1), Point(3, 2)) &&
			*(l3) == Line(Point(3, 2), Point(3, 3)))
		{
			result = true;
		}
	}


	for (auto i : objects)
	{
		delete i;
	}

	delete image;

	return result;
}

bool VectorizationTests::test9()
{
	Path path("../../../data/vectorization/9.png");
	IImage* image = Reader::read(path);
	bool result = false;


	std::vector<IObject*> objects = vectorization(image, path);
	if (objects.size() == 2)
	{
		ILine* l1 = (ILine*)objects[0];
		ILine* l2 = (ILine*)objects[1];
		if (l1 && l2 &&
			*(l1) == Line(Point(1, 1), Point(2, 1)) &&
			*(l2) == Line(Point(2, 1), Point(2, 2)))
		{
			result = true;
		}
	}
	// TODO: It's not good. Must be previous variant.
	if (objects.size() == 2)
	{
		ILine* l1 = (ILine*)objects[0];
		ILine* l2 = (ILine*)objects[1];
		if (l1 && l2 &&
			*(l1) == Line(Point(1, 1), Point(2, 1)) &&
			*(l2) == Line(Point(1, 1), Point(2, 2)))
		{
			result = true;
		}
	}


	for (auto i : objects)
	{
		delete i;
	}

	delete image;

	return result;
}

bool VectorizationTests::test10()
{
	Path path("../../../data/vectorization/10.png");
	IImage* image = Reader::read(path);
	bool result = false;


	std::vector<IObject*> objects = vectorization(image, path);
	if (objects.size() == 3)
	{
		ILine* l1 = (ILine*)objects[0];
		ILine* l2 = (ILine*)objects[1];
		ILine* l3 = (ILine*)objects[2];
		if (l1 && l2 && l3 &&
			(*(l1) == Line(Point(1, 2), Point(2, 2)) &&
			*(l2) == Line(Point(2, 2), Point(3, 1)) &&
			*(l3) == Line(Point(2, 2), Point(3, 3)) || 

			*(l1) == Line(Point(1, 2), Point(2, 2)) &&
			*(l2) == Line(Point(2, 2), Point(3, 3)) &&
			*(l3) == Line(Point(2, 2), Point(3, 1))))
		{
			result = true;
		}
	}


	for (auto i : objects)
	{
		delete i;
	}

	delete image;

	return result;
}

bool VectorizationTests::test11()
{
	Path path("../../../data/vectorization/11.png");
	IImage* image = Reader::read(path);
	bool result = false;


	std::vector<IObject*> objects = vectorization(image, path);
	if (objects.size() == 2)
	{
		ILine* l1 = (ILine*)objects[0];
		ILine* l2 = (ILine*)objects[1];
		if (l1 && l2 &&
			*(l1) == Line(Point(0, 0), Point(8, 8)) &&
			*(l2) == Line(Point(0, 8), Point(8, 0)))
		{
			result = true;
		}
	}


	for (auto i : objects)
	{
		delete i;
	}

	delete image;

	return result;
}

bool VectorizationTests::test12()
{
	Path path("../../../data/vectorization/12.png");
	IImage* image = Reader::read(path);
	bool result = false;


	std::vector<IObject*> objects = vectorization(image, path);

	// TODO: Add implementation of checking
	result = true;


	for (auto i : objects)
	{
		delete i;
	}

	delete image;

	return result;
}


void VectorizationTests::run_all_tests()
{
	std::cout << "VectorizationTests begin" << std::endl;
	int i = 1;
	std::cout << i++ << ": " << "[ " << (test1() ? "OK" : "FAIL") << " ]" << std::endl;
	std::cout << i++ << ": " << "[ " << (test2() ? "OK" : "FAIL") << " ]" << std::endl;
	std::cout << i++ << ": " << "[ " << (test3() ? "OK" : "FAIL") << " ]" << std::endl;
	std::cout << i++ << ": " << "[ " << (test4() ? "OK" : "FAIL") << " ]" << std::endl;
	std::cout << i++ << ": " << "[ " << (test5() ? "OK" : "FAIL") << " ]" << std::endl;
	std::cout << i++ << ": " << "[ " << (test6() ? "OK" : "FAIL") << " ]" << std::endl;
	std::cout << i++ << ": " << "[ " << (test7() ? "OK" : "FAIL") << " ]" << std::endl;
	std::cout << i++ << ": " << "[ " << (test8() ? "OK" : "FAIL") << " ]" << std::endl;
	std::cout << i++ << ": " << "[ " << (test9() ? "OK" : "FAIL") << " ]" << std::endl;
	std::cout << i++ << ": " << "[ " << (test10() ? "OK" : "FAIL") << " ]" << std::endl;
	std::cout << i++ << ": " << "[ " << (test11() ? "OK" : "FAIL") << " ]" << std::endl;
	std::cout << i++ << ": " << "[ " << (test12() ? "OK" : "FAIL") << " ]" << std::endl;

	std::cout << "VectorizationTests end" << std::endl;
}
