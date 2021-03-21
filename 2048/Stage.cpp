#include "Stage.h"
#include "stdlib.h"
#include "time.h"

Stage::Stage( ) {
	init( );
}

Stage::~Stage( ) {

}

int& Stage::getNumOfStage( int& x, int& y ) {
	int idx = x * SIZE_OF_STAGE + y;
	return _stage[ idx ];
}

int& Stage::getNumOfStage( int& idx ) {
	return _stage[ idx ];
}

void Stage::setNum( ) {
	srand( ( unsigned int )time( NULL ) );
	int idx = rand( ) % ( SIZE_OF_STAGE * SIZE_OF_STAGE );
	while ( isHaveNum( idx ) ) {
		idx = rand( ) % ( SIZE_OF_STAGE * SIZE_OF_STAGE );
	}
	getNumOfStage( idx ) = 2;
}

bool Stage::isHaveNum( int& idx ) {
	if ( getNumOfStage( idx ) != 0 ) {
		return true;
	}
	return false;
}

int Stage::getUpReverseAcquistionOfNum( int& x, int& y ) const {
	int idx = SIZE_OF_STAGE * ( SIZE_OF_STAGE - x ) - y - 1;
	return _stage[ idx ];
}

int Stage::getUpReverseAcquistionOfNextNum( int& x, int& y ) const {
	int idx = SIZE_OF_STAGE * ( SIZE_OF_STAGE - 2 -x + 1) - 1 - y;
	return _stage[ idx ];
}

int& Stage::setUpReverseAcquistionOfNum( int& x, int& y ) {
	int idx = SIZE_OF_STAGE * ( SIZE_OF_STAGE - x ) - y - 1;
	return _stage[ idx ];
}

int& Stage::setUpReverseAcquistionOfNextNum( int& x, int& y ) {
	int idx = SIZE_OF_STAGE * ( SIZE_OF_STAGE - 2 - x + 1 ) - 1 - y;
	return _stage[ idx ];
}

int Stage::getDownReverseAcquistionOfNum( int& x, int& y ) const {
	int idx = SIZE_OF_STAGE * y + x;
	return _stage[ idx ];
}

int Stage::getDownReverseAcquistionOfNextNum( int& x, int& y ) const {
	int idx = SIZE_OF_STAGE * ( y + 1 ) + x;
	return _stage[ idx ];
}

int& Stage::setDownReverseAcquistionOfNum( int& x, int& y ) {
	int idx = SIZE_OF_STAGE * y + x;
	return _stage[ idx ];
}

int& Stage::setDownReverseAcquistionOfNextNum( int& x, int& y ) {
	int idx = SIZE_OF_STAGE * ( y + 1 ) + x;
	return _stage[ idx ];
}

void Stage::init( ) {
	for ( int i = 0; i < SIZE_OF_STAGE; i++ ) {
		for ( int j = 0; j < SIZE_OF_STAGE; j++ ) {
			int idx = i * SIZE_OF_STAGE + j;
			getNumOfStage( i, j ) = 0;
		}
	}
}
