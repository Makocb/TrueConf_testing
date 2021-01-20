#pragma once
#include "Globals.h"
#include <iostream>

class Array
{
protected:
	virtual ~Array() {};
public: 

	//Default constructor
	//virtual Array(const int& len = localConstants::defaultSize) = 0;

	//This function fills orgnVector with random numbers >= roof and <= floor 
	virtual void randFill(const int& floor = localConstants::defaultFloor, const int& roof = localConstants::defaultRoof) = 0;

	//Function which deletes random amount of numbers (<15)
	virtual void randLenCut() = 0;

	//Function, which combines 2 previous functions
	virtual void calculate(const int& floor = localConstants::defaultFloor, const int& roof = localConstants::defaultRoof) = 0;

	virtual void output() = 0;

	virtual void erase(const int& length, bool flag = true) = 0;

	virtual void contentSize(int& size) = 0;

	virtual void valueCount(int& count, int& value) = 0;

	virtual void getKey(const int& pos, int& rtrn) = 0;
};

