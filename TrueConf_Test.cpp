
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
	
	std::shared_ptr<VectorWrapper> content1 = std::make_shared<VectorWrapper>(*wrap1);
	std::shared_ptr<MapWrapper> content2 = std::make_shared<MapWrapper>(*wrap2);
	
	Interface* interf1 = new Interface(content1);
	Interface* interf2 = new Interface(content2);
	
	interf1->calculate();
	interf1->output();
	interf2->calculate();
	interf2->output();
	
	Synchronize* sinc = new Synchronize(content1, content2);
	
	delete wrap1;
	delete wrap2;
	
	sinc->sinchronize();

	interf1->output();
	interf2->output();
	
	delete sinc;
	delete interf1;
	delete interf2;
	
	content1.reset();
	content2.reset();
	
}
