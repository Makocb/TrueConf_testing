#pragma once

#include "Array.h";

#include <iostream>

#include <vector>

#include "Globals.h"

class Container
{
private:
	//Length of the vector
	int len;

	//Vector itself (originVector)
	std::vector<int> orgnVector;
public:
	virtual ~Container() {};
	//Default constructor
	virtual void WrapperConstructor(const int& length) = 0;
	//Container(const int& len = localConstants::defaultSize);

	//This function fills orgnVector with random numbers >= roof and <= floor 
	virtual void randFill(const int& floor = localConstants::defaultFloor, const int& roof = localConstants::defaultRoof) = 0;

	virtual void erase(const int& length, bool flag = true) = 0;

	virtual void output() = 0;

	virtual void contentSize(int& size) = 0;

	virtual void valueCount(int& count, int& value) = 0;

	virtual void getKey(const int& pos, int& rtrn) = 0;
};

