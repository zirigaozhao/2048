#include <iostream>
#include "Stage.h"
#include "View.h"
#include "Controller.h"
#include "Input.h"
#include "Game.h"

int main( void ) {
	//init
	Stage* stage = new Stage( );
	Input* input = new Input( );
	Game* game = new Game( stage, input );
	View* view = new View( stage, game );
	Controller* controller = new Controller( );
	//W’†ŠÇ—
	controller->getClass( input );
	controller->getClass( game );
	controller->getClass( view );

	while ( !input->isHitEsc( ) ) {
		system( "cls" );
		controller->update( );
	}

	delete stage;
	delete input;
	delete game;
	delete view;
	delete controller;

	system( "pause" );
	return 0;
}