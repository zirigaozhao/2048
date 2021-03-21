#include <iostream>
#include "Stage.h"
#include "ViewStage.h"
#include "Controller.h"
#include "Input.h"
#include "Game.h"

int main( void ) {
	//init
	Stage* stage = new Stage( );
	Input* input = new Input( );
	Game* game = new Game( stage, input );
	ViewStage* view_stage = new ViewStage( stage );
	Controller* controller = new Controller( );
	//W’†ŠÇ—
	controller->getClass( input );
	controller->getClass( game );
	controller->getClass( view_stage );

	while ( !input->isHitEsc( ) ) {
		system( "cls" );
		controller->update( );
	}
	system( "pause" );
	return 0;
}