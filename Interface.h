#pragma once

#include <iostream>

#include <map>

#include <vector>

#include "Globals.h"

#include "Container.h"

//template <class T>
//using ptr = std::shared_ptr<T>;
template <class T>
class Interface: public Array
{
private:
	std::shared_ptr<T> content;
public:
	~Interface() { content.reset(); };

	//Default constructor
	Interface(std::shared_ptr<T> inner, const int& len = localConstants::defaultSize)
	{
		content = inner;
		content->WrapperConstructor(len);
	}

	//This function fills orgnVector with random numbers >= roof and <= floor 
	void randFill(const int& floor = localConstants::defaultFloor, const int& roof = localConstants::defaultRoof) override
	{
			content->randFill(floor, roof);
	}
	//Function which deletes random amount of numbers (<15)
	void randLenCut() override
	{
		//Number generator boundaries
		int floor = 1;
		int roof = localConstants::defaultCutRoof;

		//Erase first roof amount of elements
		content->erase(round(rand() % roof + floor));
	}

	//Function, which combines 2 previous functions
	void calculate(const int& floor = localConstants::defaultFloor, const int& roof = localConstants::defaultRoof) override
	{
		randFill(floor, roof);
		randLenCut();
	}

	void output()override
	{
		content->output();
	}
};

