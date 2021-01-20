
#include "Synchronize.h"

#include "VectorWrapper.h"

#include "MapWrapper.h"

int main()
{
	//we can choose as a template type any class which is child to Container class
	Synchronize<VectorWrapper, MapWrapper>* sinc = new Synchronize<VectorWrapper, MapWrapper>();
	sinc->calculateBeforeSync();
	sinc->print();
	sinc->sinchronize();
	sinc->print();
	delete sinc;
}
