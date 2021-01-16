#include <iostream>
#include <map>
#include <vector>
#include <ctime>
#include <algorithm>

namespace localConstants 
{
	const int defaultSize = 20;
	const int defaultFloor = 1;
	const int defaultRoof = 9;
	const int defaultCutRoof = 15;
}

class myVector
{
public:
	int len;
	std::vector<int> orgnVector;

	myVector(const int& len = localConstants::defaultSize)
	{
		this->len = len;
	}

	void randFill(const int& floor = localConstants::defaultFloor, const int& roof = localConstants::defaultRoof)
	{
		for (int i = 0; i < len; i++) {
			this->orgnVector.push_back(static_cast<int>(rand() % roof + floor));
		}

	}

	void randLenCut() {
		int floor = 0;
		int roof = localConstants::defaultCutRoof;
		this->orgnVector.erase(this->orgnVector.begin(), this->orgnVector.begin()+ static_cast<int>(rand() % roof + floor));
		len = orgnVector.size();
	}

	friend std::ostream& operator<<(std::ostream& str, const myVector& inpVector) {
		for (auto it = inpVector.orgnVector.begin(); it != inpVector.orgnVector.end(); it++) {
			str << (int)*it << " ";
		}
		str << std::endl;
		return str;
	}
};

class myMap
{
public:
	int len;
	std::map<int, int> orgnMap;

	myMap(const int& len = localConstants::defaultSize)
	{
		this->len = len;
	}

	void randFill(const int& floor = localConstants::defaultFloor, const int& roof = localConstants::defaultRoof)
	{
		for (int i = 0; i < len; i++) {
			int inpValue = static_cast<int>(rand() % roof + floor);
			this->orgnMap.emplace(std::pair<int, int>(i + 1, inpValue));
		}
	}

	void randLenCut() {
		int floor = 0;
		int roof = localConstants::defaultCutRoof;
		int deleteCount = static_cast<int>(rand() % roof + floor);
		this->orgnMap.erase(this->orgnMap.begin(), this->orgnMap.find(deleteCount));
	}

	friend std::ostream& operator<<(std::ostream& str,myMap& inpMap) {
		for (int i = 1; i < inpMap.len + 1; i++) {
			if (inpMap.orgnMap[i]!=0)
				str << inpMap.orgnMap[i] << " ";
		}
		str << std::endl;
		return str;
	}

	int findKey(int value) {
		int key=-1;
		for (auto& i : orgnMap) {
			if (i.second == value) {
				key = i.first;
				break;
			}
		}
		return key;
	}

	int valueCount(int value) {
		int count = 0;
		for (auto& i : orgnMap) {
			if (i.second == value) {
				count++;
			}
		}
		return count;
	}

};

void sinchronize(myVector& inpVector, myMap& inpMap)
{
	std::vector<int> ignoreTable;
	for (int it = 0; it < inpVector.orgnVector.size(); it++)
	{
		if (inpMap.valueCount(inpVector.orgnVector[it]) != 0) {
			int key = inpMap.findKey(inpVector.orgnVector[it]);
			for (int i = 1; i< inpMap.len + 1; i++) {
				if (inpMap.orgnMap[i] == inpVector.orgnVector[it]) {
					if (std::find(ignoreTable.begin(), ignoreTable.end(), i) == ignoreTable.end())
					ignoreTable.push_back(i);
				}
			}
		}
		else if (inpMap.valueCount(inpVector.orgnVector[it]) == 0) {
			inpVector.orgnVector.erase(inpVector.orgnVector.begin() + it);
		}
		
	}

	for (int i = 1; i < inpMap.len + 1; i++) {
		bool flag = true;
		for (int j = 0; j < ignoreTable.size(); j++) {
			if (i == ignoreTable[j]) {
				flag = false;
			}
		}
		if (flag)
			inpMap.orgnMap.erase(i);
	}

}

int main()
{
	srand((unsigned int)time(NULL));
	myVector* vec1 = new myVector();
	vec1->randFill();
	vec1->randLenCut();
	myMap* map1 = new myMap();
	map1->randFill();
	map1->randLenCut();
	std::cout << "Before sinchronizing" << std::endl;
	std::cout << "Vector Output" << std::endl << *vec1 << std::endl;
	std::cout << "Map Output" << std::endl << *map1<< std::endl;
	sinchronize(*vec1, *map1);
	std::cout << "After sinchronizing" << std::endl;
	std::cout << "Vector Output" << std::endl << *vec1<< std::endl;
	std::cout << "Map Output" << std::endl << *map1;
	delete vec1;
	delete map1;
}
