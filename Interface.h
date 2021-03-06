#pragma once

#include <iostream>

#include <map>

#include <vector>

#include "Globals.h"

#include "Container.h"

template <class T>
using ptr = std::shared_ptr<T>;

template <typename T>
class Interface: public Array
{
private:
	ptr<Container> content;
public:
	~Interface() { content.reset(); };

	//Default constructor

	Interface() 
	{
		T* wrap1 = new T();

		std::shared_ptr<T> contentPrototype = std::make_shared<T>(*wrap1);
		this->content = contentPrototype;

		delete wrap1;
		contentPrototype.reset();

		content->WrapperConstructor(localConstants::defaultSize);
	}

	Interface(ptr<Container> inner, const int& len = localConstants::defaultSize)
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

	void erase(const int& length, bool flag = true) override
	{
		content->erase(length, flag);
	}

	void contentSize(int& size) override
	{
		content->contentSize(size);
	}

	void valueCount(int& count, int& value) override 
	{
		content->valueCount(count, value);
	}

	void getKey(const int& pos, int& rtrn) override 
	{
		content->getKey(pos, rtrn);
	}
};

