#include "Controller.h"

Controller::Controller( ) {
}

Controller::~Controller( ) {
}

void Controller::update( ) {
	std::list< BaseClass* >::iterator iter = _list.begin( );
	for ( ; iter != _list.end( ); ++iter ) {
		( *iter )->update( );
	}
}

void Controller::getClass( BaseClass* _class ) {
	_list.push_back( _class );
}
