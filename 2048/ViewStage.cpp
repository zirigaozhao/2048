#include "ViewStage.h"
#include <iostream>
#include <iomanip>

ViewStage::ViewStage( Stage* stage ) :
_stage( stage ) {
	
}

ViewStage::~ViewStage( ) {
}

void ViewStage::update( ) {
	drawStage( );
}

void ViewStage::drawStage( ) {
	using namespace std;
	for ( int i = 0; i < SIZE_OF_STAGE; i++ ) {
		for ( int j = 0; j < SIZE_OF_STAGE; j++ ) {
			cout << setw(4) << setfill(' ') << _stage->getNumOfStage( i, j );
		}
		cout << "\n";
	}
}
