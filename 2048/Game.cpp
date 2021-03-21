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
	if ( _input->getKeyInput( ) == Input::KEY_TYPE::NONE ) {
		return;
	}
	switch ( _input->getKeyInput( ) ) {
	case Input::KEY_TYPE::UP:
		stageUpProcessing( );
		_stage->lessUp( );
		break;
	case Input::KEY_TYPE::DOWN:
		stageDownProcessing( );
		_stage->lessDown( );
		break;
	case Input::KEY_TYPE::LEFT:
		stageLeftProcessing( );
		_stage->lessLeft( );
		break;
	case Input::KEY_TYPE::RIGHT:
		stageRightProcessing( );
		_stage->lessRight( );
		break;
	default:
		break;
	}
	_stage->setNum( );
}

void Game::stageUpProcessing( ) {
	for ( int i = 0; i < SIZE_OF_STAGE; i++ ) {
		for ( int j = 0; j < SIZE_OF_STAGE - 1; j++ ) {
			if ( _stage->getUpReverseAcquistionOfNum( i, j ) == 0 ) {
				continue;
			}
			for ( int k = j; k < SIZE_OF_STAGE - 1; k++ ) {
				if ( _stage->getUpReverseAcquistionOfNum( i, k + 1 ) == 0 ) { 
					continue;
				}
				if ( _stage->getUpReverseAcquistionOfNum( i, j ) !=
					 _stage->getUpReverseAcquistionOfNum( i, k + 1 ) ) {
					break;
				}
					add( _stage->setUpReverseAcquistionOfNum( i, j ),
						 _stage->setUpReverseAcquistionOfNum( i, k + 1 ) );
			}
		}
	}
}

void Game::stageDownProcessing( ) {
	for ( int i = 0; i < SIZE_OF_STAGE; i++ ) {
		for ( int j = 0; j < SIZE_OF_STAGE - 1; j++ ) {
			if ( _stage->getDownReverseAcquistionOfNum( i, j ) == 0 ) {
				continue;
			}
			for ( int k = j; k < SIZE_OF_STAGE - 1; k++ ) {
				if ( _stage->getDownReverseAcquistionOfNum( i, k + 1 ) == 0 ) {
					continue;
				}
				if ( _stage->getDownReverseAcquistionOfNum( i, j ) !=
					 _stage->getDownReverseAcquistionOfNum( i, k + 1 ) ) {
					break;
				}
				add( _stage->setDownReverseAcquistionOfNum( i, j ),
					 _stage->setDownReverseAcquistionOfNum( i, k + 1 ) );
			}
		}
	}
}

void Game::stageLeftProcessing( ) {
	for ( int i = 0; i < SIZE_OF_STAGE; i++ ) {
		for ( int j = 0; j < SIZE_OF_STAGE - 1; j++ ) {
			if ( _stage->getLeftReverseAcquistionOfNum( i, j ) == 0 ) {
				continue;
			}
			for ( int k = j; k < SIZE_OF_STAGE - 1; k++ ) {
				if ( _stage->getLeftReverseAcquistionOfNum( i, k + 1 ) == 0 ) {
					continue;
				}
				if ( _stage->getLeftReverseAcquistionOfNum( i, j ) !=
					 _stage->getLeftReverseAcquistionOfNum( i, k + 1 ) ) {
					break;
				}
				add( _stage->setLeftReverseAcquistionOfNum( i, j ),
					 _stage->setLeftReverseAcquistionOfNum( i, k + 1 ) );
			}
		}
	}
}

void Game::stageRightProcessing( ) {
	for ( int i = 0; i < SIZE_OF_STAGE; i++ ) {
		for ( int j = 0; j < SIZE_OF_STAGE - 1; j++ ) {
			if ( _stage->getRightReverseAcquistionOfNum( i, j ) == 0 ) {
				continue;
			}
			for ( int k = j; k < SIZE_OF_STAGE - 1; k++ ) {
				if ( _stage->getRightReverseAcquistionOfNum( i, k + 1 ) == 0 ) {
					continue;
				}
				if ( _stage->getRightReverseAcquistionOfNum( i, j ) !=
					 _stage->getRightReverseAcquistionOfNum( i, k + 1 ) ) {
					break;
				}
				add( _stage->setRightReverseAcquistionOfNum( i, j ),
					 _stage->setRightReverseAcquistionOfNum( i, k + 1 ) );
			}
		}
	}
}

void Game::add( int& num1, int& num2 ) {
	if ( num1 == 0 ) {
		return;
	}
	int number = 0;
	number = num1 + num2;
	num1 = number;
	num2 = 0;
}

void Game::checkStage( ) {
	if ( corssCheck( ) ||
		 verticalCheck( ) ) {
		_is_game_over = true;
	}
}

//True‚Í‚ ‚é”š‚Ì‰¡‚Í“¯‚¶”š‚ª‚ ‚è‚Ü‚·
bool Game::corssCheck( ) {
	for ( int i = 0; i < SIZE_OF_STAGE; i++ ) {
		for ( int j = 0; j < SIZE_OF_STAGE - 1; j++ ) {
			if ( _stage->getRightReverseAcquistionOfNum( i, j ) == 0 ) {
				return true;
			}
			for ( int k = j; k < SIZE_OF_STAGE - 1; k++ ) {
				if ( _stage->getRightReverseAcquistionOfNum( i, j ) ==
					 _stage->getRightReverseAcquistionOfNum( i, k + 1 ) ) {
					return true;
				}
			}
		}
	}
	return false;
}

//True‚Í‚ ‚é”š‚Ìc‚Í“¯‚¶”š‚ª‚ ‚è‚Ü‚·
bool Game::verticalCheck( ) {
	for ( int i = 0; i < SIZE_OF_STAGE; i++ ) {
		for ( int j = 0; j < SIZE_OF_STAGE - 1; j++ ) {
			if ( _stage->getDownReverseAcquistionOfNum( i, j ) == 0 ) {
				return true;
			}
			for ( int k = j; k < SIZE_OF_STAGE - 1; k++ ) {
				if ( _stage->getDownReverseAcquistionOfNum( i, j ) ==
					 _stage->getDownReverseAcquistionOfNum( i, k + 1 ) ) {
					return true;
				}
			}
		}
	}
	return false;
}
