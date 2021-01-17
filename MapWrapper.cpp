#include "MapWrapper.h"

void MapWrapper::WrapperConstructor(const int& length = localConstants::defaultSize)
{
	this->len = length;
}

//This function fills orgnMap with random numbers >= roof and <= floor
void MapWrapper::randFill(const int& floor, const int& roof)
{
	for (int i = 0; i < len; i++)
	{
		//Innitiating a value, which will be stored by Map
		int inpValue = round(rand() % roof + floor);

		//Each value gets its key, which is determined by i
		this->orgnMap.emplace(std::pair<int, int>(i + 1, inpValue));
	}
}

void MapWrapper::erase(const int& length, bool flag)
{
	if (flag) {
		this->orgnMap.erase(this->orgnMap.begin(), this->orgnMap.find(length));
	}
	else if (!flag) {
		this->orgnMap.erase(this->orgnMap.find(length));
	}
}

void MapWrapper::output() 
{
	for (int i = 1; i < this->len + 1; i++)
	{
		//This condition is neccesary because if there is no key, whe are calling for, then map returns us 0
		//which we dont want to show in output
		if (this->orgnMap[i] != 0)
			std::cout << this->orgnMap[i] << " ";
	}
	std::cout << std::endl;
}

void MapWrapper::contentSize(int& size)
{
	size = this->len;
}

void MapWrapper::valueCount(int& count, int& value)
{
		count = 0;
		for (auto& i : orgnMap)
		{
			if (i.second == value)
			{
				count++;
			}
		}
}

void MapWrapper::getKey(const int& pos, int& rtrn)
{
	rtrn = this->orgnMap[pos];
}

MapWrapper::MapWrapper(const int& size)
{
	this->len = size;
}