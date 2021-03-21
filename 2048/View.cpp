#include "View.h"
#include <iostream>
#include <iomanip>
using namespace std;

View::View( Stage* stage, Game* game ) :
_stage( stage ),
_game( game ) {
	
}

View::~View( ) {
}

void View::update( ) {
	if ( _game->isGameOver( ) ) {
		drawGameOver( );
		return;
	}
	drawStage( );
}

void View::drawStage( ) {
	for ( int i = 0; i < SIZE_OF_STAGE; i++ ) {
		for ( int j = 0; j < SIZE_OF_STAGE; j++ ) {
			cout << " " << setw( INTERVAL_FOR_NUM_TO_NUM ) << setfill(' ') << _stage->getNumOfStage( i, j );
		}
		cout << "\n";
	}
}

void View::drawGameOver( ) {
	cout << "/*****\n";
	cout << "YOU LOSE\n";
	cout << "/*****";
}
