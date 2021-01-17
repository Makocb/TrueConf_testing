
#include <ctime>

#include "Synchronize.h"

#include "Interface.h"

#include "MapWrapper.h"

#include "VectorWrapper.h"

int main()
{
	//Generates the seed for random number generator
	srand((unsigned int)time(NULL));
	VectorWrapper* wrap1 = new VectorWrapper();
	MapWrapper* wrap2 = new MapWrapper();
	std::shared_ptr<VectorWrapper> content1(wrap1);
	std::shared_ptr<MapWrapper> content2(wrap2);
	Interface<VectorWrapper> interf1(content1);
	Interface<MapWrapper> interf2(content2);
	interf1.calculate();
	interf1.output();
	interf2.calculate();
	interf2.output();
	Synchronize<VectorWrapper, MapWrapper> sinc(content1, content2);
	sinc.sinchronize();
	interf1.output();
	interf2.output();
}
