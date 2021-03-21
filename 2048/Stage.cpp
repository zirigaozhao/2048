#include "Stage.h"
#include "stdlib.h"
#include "time.h"

Stage::Stage( ) {
	init( );
}

Stage::~Stage( ) {

}

int& Stage::getNumOfStage( const int& x, const int& y ) {
	int idx = x * SIZE_OF_STAGE + y;
	return _stage[ idx ];
}

int& Stage::getNumOfStage( const int& idx ) {
	return _stage[ idx ];
}

int& Stage::setNumForStage( const int& idx ) {
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

bool Stage::isHaveNum( const int& idx ) {
	if ( getNumOfStage( idx ) != 0 ) {
		return true;
	}
	return false;
}
/*//up
//****
//****
//****
//***Å™
*/
int Stage::getUpReverseAcquistionOfNum( const int& y, const int& x ) const {
	int idx = SIZE_OF_STAGE * ( SIZE_OF_STAGE - x - 1 ) + y;
	return _stage[ idx ];
}

int& Stage::setUpReverseAcquistionOfNum( const int& y, const int& x ) {
	int idx = SIZE_OF_STAGE * ( SIZE_OF_STAGE - x - 1 ) + y;
	return _stage[ idx ];
}

void Stage::lessUp( ) {
	for ( int i = 0; i < SIZE_OF_STAGE; i++ ) {
		for ( int j = 0; j < SIZE_OF_STAGE; j++ ) {
			for ( int k = 0; k < SIZE_OF_STAGE - 1; k++ ) {
				if ( getUpReverseAcquistionOfNum( i, k ) != 0 &&
					 getUpReverseAcquistionOfNum( i, k + 1 ) == 0 ) {
					changeNum( setUpReverseAcquistionOfNum( i, k ),
							   setUpReverseAcquistionOfNum( i, k + 1 ) );
				}
			}
		}
	}
}

/*//down
//Å´***
// ****
// ****
// ****
*/
int Stage::getDownReverseAcquistionOfNum( const int& y, const int& x ) const {
	int idx = SIZE_OF_STAGE * x + y;
	return _stage[ idx ];
}

int& Stage::setDownReverseAcquistionOfNum( const int& y, const int& x ) {
	int idx = SIZE_OF_STAGE * x + y;
	return _stage[ idx ];
}

void Stage::lessDown( ) {
	for ( int i = 0; i < SIZE_OF_STAGE; i++ ) {
		for ( int j = 0; j < SIZE_OF_STAGE; j++ ) {
			for ( int k = 0; k < SIZE_OF_STAGE - 1; k++ ) {
				if ( getDownReverseAcquistionOfNum( i, k ) != 0 &&
					 getDownReverseAcquistionOfNum( i, k + 1 ) == 0 ) {
					changeNum( setDownReverseAcquistionOfNum( i, k ),
							   setDownReverseAcquistionOfNum( i, k + 1 ) );
				}
			}
		}
	}
}

/*//left
//***Å©
//****
//****
//****
*/
int Stage::getLeftReverseAcquistionOfNum( const int& y, const int& x ) const {
	int idx = SIZE_OF_STAGE * y + 4 - x - 1;
	return _stage[ idx ];
}

int& Stage::setLeftReverseAcquistionOfNum( const int& y, const int& x ) {
	int idx = SIZE_OF_STAGE * y + 4 - x - 1;
	return _stage[ idx ];
}

void Stage::lessLeft( ) {
	for ( int i = 0; i < SIZE_OF_STAGE; i++ ) {
		for ( int j = 0; j < SIZE_OF_STAGE; j++ ) {
			for ( int k = 0; k < SIZE_OF_STAGE - 1; k++ ) {
				if ( getLeftReverseAcquistionOfNum( i, k ) != 0 &&
					 getLeftReverseAcquistionOfNum( i, k + 1 ) == 0 ) {
					changeNum( setLeftReverseAcquistionOfNum( i, k ),
							   setLeftReverseAcquistionOfNum( i, k + 1 ) );
				}
			}
		}
	}
}

/*//right
//Å®***
// ****
// ****
// ****
*/
int Stage::getRightReverseAcquistionOfNum( const int& y, const int& x ) const {
	int idx = SIZE_OF_STAGE * y + x;
	return _stage[ idx ];
}

int& Stage::setRightReverseAcquistionOfNum( const int& y, const int& x ) {
	int idx = SIZE_OF_STAGE * y + x;
	return _stage[ idx ];
}

void Stage::lessRight( ) {
	for ( int i = 0; i < SIZE_OF_STAGE; i++ ) {
		for ( int j = 0; j < SIZE_OF_STAGE; j++ ) {
			for ( int k = 0; k < SIZE_OF_STAGE - 1; k++ ) {
				if ( getRightReverseAcquistionOfNum( i, k ) != 0 &&
					 getRightReverseAcquistionOfNum( i, k + 1 ) == 0 ) {
					changeNum( setRightReverseAcquistionOfNum( i, k ),
							   setRightReverseAcquistionOfNum( i, k + 1 ) );
				}
			}
		}
	}
}

void Stage::init( ) {
	for ( int i = 0; i < SIZE_OF_STAGE; i++ ) {
		for ( int j = 0; j < SIZE_OF_STAGE; j++ ) {
			int idx = i * SIZE_OF_STAGE + j;
			getNumOfStage( i, j ) = 0;
		}
	}
}

void Stage::changeNum( int& num1, int& num2 ) {
	int temp = num1;
	num1 = num2;
	num2 = temp;
}
