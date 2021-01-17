#pragma once

#include "Array.h"

#include <iostream>

#include <map>

#include <vector>

#include <algorithm>

#include "Container.h"

class MapWrapper;

class VectorWrapper:public Container
{
private:
	//Length of the vector
	int len;

	//Vector itself (originVector)
	std::vector<int> orgnVector;
public:
	auto itStart();

	auto itEnd();

	void WrapperConstructor(const int& length) override;

	void randFill(const int& floor, const int& roof) override;

	void erase(const int& length, bool flag = true) override;

	void contentSize(int& size) override;

	void valueCount(int& count, int& value) override;

	void getKey(const int& pos, int& rtrn) override;

	void output() override;

	VectorWrapper(const int& size = localConstants::defaultSize);
};

