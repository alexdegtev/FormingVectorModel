#pragma once
#include "../../Core/IO/Path.h"
#include "../../Core/Objects/Visual/IImage.h"

class VectorizationTests
{
public:
	VectorizationTests();

	std::vector<Core::Objects::Geometric::IObject*> vectorization(Core::Objects::Visual::IImage* image, Core::IO::Path path);

	bool test1();
	bool test2();
	bool test3();
	bool test4();
	bool test5();
	bool test6();
	bool test7();
	bool test8();
	bool test9();
	bool test10();
	bool test11();

	void run_all_tests();
};