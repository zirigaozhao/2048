#pragma once
#include <list>
#include "BaseClass.h"

class Controller {
public:
	Controller( );
	virtual ~Controller( );
public:
	void update( );
	void getClass( BaseClass* _class );
private:
	std::list< BaseClass* > _list;
};

