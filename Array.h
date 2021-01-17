#pragma once
#include "Globals.h"
#include <iostream>

class Array
{
private:
	//virtual ~Array() {};
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


};

