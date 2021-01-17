#include "VectorWrapper.h"
#include "Globals.h"

auto VectorWrapper::itStart() 
{
	return this->orgnVector.begin();
}

auto VectorWrapper::itEnd() 
{
	return this->orgnVector.end();
}

void VectorWrapper::contentSize(int& size)
{
	size = this->len;
}

VectorWrapper::VectorWrapper(const int& size)
{
	this->len = size;
}

void VectorWrapper::valueCount(int& count, int& value)
{
	contentSize(count);
	contentSize(value);
}

void VectorWrapper::getKey(const int& pos, int& rtrn)
{
	rtrn = this->orgnVector[pos];
}

void VectorWrapper::WrapperConstructor(const int & length) 
{
	this->len = length;
}

void VectorWrapper::randFill(const int& floor, const int& roof) {
	for (int i = 0; i < this->len; i++)
	{
		this->orgnVector.push_back(round(rand() % roof + floor));
	}
}

void VectorWrapper::erase(const int& length, bool flag)
{
	if (flag) {
		this->orgnVector.erase(this->orgnVector.begin(), this->orgnVector.begin() + length);
		this->len = orgnVector.size();
	}else if(!flag)
		this->orgnVector.erase(this->orgnVector.begin() + length);
}

void VectorWrapper::output()
{
	for (auto it = this->orgnVector.begin(); it != this->orgnVector.end(); it++)
	{
		std::cout << (int)* it << " ";
	}
	std::cout << std::endl;
}


