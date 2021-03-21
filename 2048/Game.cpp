#include "Game.h"

Game::Game( Stage* stage, Input* input ) :
	_stage( stage ),
	_input( input ) {
	init( );
}

Game::~Game( ) {
}

void Game::update( ) {
	gameProcessing( );
}

bool Game::isGameOver( ) const {
	return _is_game_over;
}

void Game::init( ) {
	_is_game_over = false;

	//“ñ‚Â‚Ì‚Q‚ğo‚·
	for ( int i = 0; i < 2; i++ ) {
		_stage->setNum( );
	}
}

void Game::gameProcessing( ) {
	switch ( _input->getKeyInput( ) ) {
	case Input::KEY_TYPE::UP:

		break;
	default:
		break;
	}
}

void Game::stageUpProcessing( ) {
	for ( int i = 0; i < SIZE_OF_STAGE; i++ ) {
		for ( int j = 0; j < SIZE_OF_STAGE; j++ ) {
			int idx = SIZE_OF_STAGE * ( SIZE_OF_STAGE - i ) - j - 1;
		}
	}
}

void Game::add( int& num1, int& num2 ) {
	int number = 0;
	number = num1 + num2;
	num2 = number;
	num1 = 0;
}