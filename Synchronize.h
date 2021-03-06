#pragma once

#include <map>

#include <vector>

#include "Globals.h"

#include "Container.h"

#include "VectorWrapper.h"

#include "MapWrapper.h"

#include "Interface.h"

#include <ctime>

template<typename T>
using ptr = std::shared_ptr<T>;

template <typename T, typename S>
class Synchronize
{
private:
	ptr<Interface<T>> content1;
	ptr<Interface<S>> content2;
public:
	Synchronize()
	{

		srand((unsigned int)time(NULL));

		Interface<T>* contentPrototype1 = new Interface<T>();
		Interface<S>* contentPrototype2 = new Interface<S>();

		content1 = std::make_shared<Interface<T>>(*contentPrototype1);
		content2 = std::make_shared<Interface<S>>(*contentPrototype2);

		delete contentPrototype1;
		delete contentPrototype2;
	}

	void print()
	{
		content1->output();
		content2->output();
	}

	void calculateBeforeSync()
	{
		content1->calculate();
		content2->calculate();
	}

	Synchronize(ptr<Container> inpContent1, ptr<Container> inpContent2)
	{
		content1 = inpContent1;
		content2 = inpContent2;
	}

	~Synchronize() 
	{
		content1.reset();
		content2.reset();
	}

	//Sinchronizes Vectorand Map values
	void sinchronize()
	{
		int size1=0;
		int size2=0;
		content1->contentSize(size1);
		content2->contentSize(size2);
		//Vector, which contains the table of keys from inpMap,
		//which "points" to the values, that already exist in inpVector
		std::vector<int> ignoreTable;

		//it - is not iterator
		for (int it = 0; it < size1; ++it)
		{
			//Condition, which checks if values from vector exist in inpMap
			int pos1 = 0;  int pos2 = 0;
			content1->getKey(it, pos1);
			int count = 0;
			content2->valueCount(count, pos1);
			if (count != 0)
			{
				//Cycle which determines keys, beeing copied to ignoreTable
				for (int i = 1; i < size2 + 1; i++)
				{
					int temp1 = 0;  int temp2 = 0;
					content2->getKey(i,temp2);
					content1->getKey(it, temp1);
					if (temp1 == temp2)
					{
						//Condition, which does not allow to cpy similar keys to ignoreTable
						if (std::find(ignoreTable.begin(), ignoreTable.end(), i) == ignoreTable.end())
							ignoreTable.push_back(i);
					}
				}
			}
			//if values from vector do not exist in map then erase that value from inpVector
			else if (count == 0)
			{
				content1->erase(it,false);
				it--;
				size1--;

			}
		}

		//This cycle determines what pairs are deleted from inpMap
		for (int i = 1; i < size2 + 1; i++)
		{
			//if even once time i matches any key from ignoreTable then flags becomes false
			bool flag = true;
			for (int j = 0; j < ignoreTable.size(); j++)
			{
				if (i == ignoreTable[j])
				{
					flag = false;
				}
			}
			//if flag is true the appropriate pair from the map is deleted
			if (flag) {
				content2->erase(i,false);
			}
		}

	}

};

