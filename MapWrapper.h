#pragma once

#include "Array.h"

#include <iostream>

#include <map>

#include <vector>

#include <algorithm>

#include "Container.h"

class MapWrapper: public Container
{
private:
	//Length of the map
	int len;

	//Map itself (originMap)
	std::map<int, int> orgnMap;
public:

	//Default constructor
	void WrapperConstructor(const int& length) override;

	//This function fills orgnMap with random numbers >= roof and <= floor
	void randFill(const int& floor = localConstants::defaultFloor, const int& roof = localConstants::defaultRoof) override;
	
	void erase(const int& length, bool flag = true) override;

	void output() override;

	void contentSize(int& size) override;

	void valueCount(int& count, int& value) override;

	void getKey(const int& pos, int& rtrn) override;

	MapWrapper(const int& size = localConstants::defaultSize);
};

