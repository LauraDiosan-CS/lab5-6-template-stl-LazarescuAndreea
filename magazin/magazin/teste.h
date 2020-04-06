#pragma once
#include "service.h"

class TestServiceTemplate
{
private:
	Service s;
public:
	TestServiceTemplate();
	void runTests();
	~TestServiceTemplate();
};
