#include <iostream>

#include <map>

#include <vector>

#include <ctime>

#include <algorithm>

namespace localConstants
{
	//Default size of arrays
	const int defaultSize = 20;
	
	//Default lowest number for random number generator
	const int defaultFloor = 1;
	
	//Default highest number for random number generator
	const int defaultRoof = 9;

	//Default number of objects beeing removed
	const int defaultCutRoof = 15;
}

//Class, which containts std::vector and custom methods for it
class VectorWrapper
{
public:
	//Length of the vector
	int len;

	//Vector itself (originVector)
	std::vector<int> orgnVector;

	//Default constructor
	VectorWrapper(const int& len = localConstants::defaultSize)
	{
		this->len = len;
	}

	//This function fills orgnVector with random numbers >= roof and <= floor 
	void randFill(const int& floor = localConstants::defaultFloor, const int& roof = localConstants::defaultRoof)
	{
		for (int i = 0; i < len; i++)
		{
			this->orgnVector.push_back(round(rand() % roof + floor));
		}
	}

	//Function which deletes random amount of numbers (<15)
	void randLenCut()
	{
		//Number generator boundaries
		int floor = 0;
		int roof = localConstants::defaultCutRoof;
		
		//Erase first roof amount of elements
		this->orgnVector.erase(this->orgnVector.begin(), this->orgnVector.begin() + round(rand() % roof + floor));
		len = orgnVector.size();
	}

	//Function, which combines 2 previous functions
	void calculate(const int& floor = localConstants::defaultFloor, const int& roof = localConstants::defaultRoof) 
	{
		randFill(floor, roof);
		randLenCut();
	}

	//This operator overloading function determins the output of << VectorWrapper
	friend std::ostream& operator <<(std::ostream& str, const VectorWrapper& inpVector)
	{
		for (auto it = inpVector.orgnVector.begin(); it != inpVector.orgnVector.end(); it++)
		{
			str << (int)* it << " ";
		}
		str << std::endl;
		return str;
	}
};

//Clas, which contains map and custom methods for working with it
class MapWrapper
{
public:

	//Length of the map
	int len;

	//Map itself (originMap)
	std::map<int, int> orgnMap;

	//Default constructor
	MapWrapper(const int& len = localConstants::defaultSize)
	{
		this->len = len;
	}

	//This function fills orgnMap with random numbers >= roof and <= floor
	void randFill(const int& floor = localConstants::defaultFloor, const int& roof = localConstants::defaultRoof)
	{
		for (int i = 0; i < len; i++)
		{
			//Innitiating a value, which will be stored by Map
			int inpValue = round(rand() % roof + floor);

			//Each value gets its key, which is determined by i
			this->orgnMap.emplace(std::pair<int, int>(i + 1, inpValue));
		}
	}

	//This function deletes random amount of pairs from the map (<15)
	void randLenCut()
	{
		//Determining the boundaries
		int floor = 0;
		int roof = localConstants::defaultCutRoof;

		//From the point we start deleting elements from std::map, we can no longer use iterators for it
		//due to iterator structure malfunction erase method does
		int deleteCount = static_cast<int>(rand() % roof + floor);
		this->orgnMap.erase(this->orgnMap.begin(), this->orgnMap.find(deleteCount));
	}
	
	//Function, which combines 2 previous functions
	void calculate(const int& floor = localConstants::defaultFloor, const int& roof = localConstants::defaultRoof)
	{
		randFill(floor, roof);
		randLenCut();
	}

	//This operator overloading function determins the output of << MapWrapper
	friend std::ostream& operator <<(std::ostream& str, MapWrapper& inpMap)
	{
		for (int i = 1; i < inpMap.len + 1; i++)
		{
			//This condition is neccesary because if there is no key, whe are calling for, then map returns us 0
			//which we dont want to show in output
			if (inpMap.orgnMap[i] != 0)
				str << inpMap.orgnMap[i] << " ";
		}
		str << std::endl;
		return str;
	}

	//this function allows to count the pair amount by their value
	int valueCount(int value)
	{
		int count = 0;
		for (auto& i : orgnMap)
		{
			if (i.second == value)
			{
				count++;
			}
		}
		return count;
	}
};

//Sinchronizes Vector and Map values
void sinchronize(VectorWrapper& inpVector, MapWrapper& inpMap)
{
	//Vector, which contains the table of keys from inpMap,
	//which "points" to the values, that already exist in inpVector
	std::vector<int> ignoreTable;

	//it - is not iterator
	for (int it = 0; it < inpVector.orgnVector.size(); it++)
	{
		//Condition, which checks if values from vector exist in inpMap
		if (inpMap.valueCount(inpVector.orgnVector[it]) != 0)
		{
			//Cycle which determines keys, beeing copied to ignoreTable
			for (int i = 1; i < inpMap.len + 1; i++)
			{
				if (inpMap.orgnMap[i] == inpVector.orgnVector[it])
				{
					//Condition, which does not allow to cpy similar keys to ignoreTable
					if (std::find(ignoreTable.begin(), ignoreTable.end(), i) == ignoreTable.end())
						ignoreTable.push_back(i);
				}
			}
		}
		//if values from vector do not exist in map then erase that value from inpVector
		else if (inpMap.valueCount(inpVector.orgnVector[it]) == 0)
		{
			inpVector.orgnVector.erase(inpVector.orgnVector.begin() + it);
			it--;
		}
	}

	//This cycle determines what pairs are deleted from inpMap
	for (int i = 1; i < inpMap.len + 1; i++)
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
			inpMap.orgnMap.erase(i);
		}
	}
}

int main()
{
	//Generates the seed for random number generator
	srand((unsigned int)time(NULL));

	//VectorWrapper and MapWrapper innitiation
	VectorWrapper* vec1 = new VectorWrapper();
	MapWrapper* map1 = new MapWrapper();

	//Giving both objects inner elements values
	vec1->calculate();
	map1->calculate();

	//Output before synchronization
	std::cout << "Before sinchronizing" << std::endl;
	std::cout << "Vector Output" << std::endl << *vec1 << std::endl;
	std::cout << "Map Output" << std::endl << *map1 << std::endl;
	
	//Synchronization
	sinchronize(*vec1, *map1);

	//Output after sinchronization
	std::cout << "After sinchronizing" << std::endl;
	std::cout << "Vector Output" << std::endl << *vec1 << std::endl;
	std::cout << "Map Output" << std::endl << *map1;

	//Deleting temporary objects
	delete vec1;
	delete map1;
}
