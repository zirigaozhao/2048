#include "Input.h"
#include "conio.h"

Input::Input( ) {
	initInputKey( );
}

Input::~Input( ) {

}

Input::KEY_TYPE Input::getKeyInput( ) const {
	return _type_key_input;
}

bool Input::isHitEsc( ) {
	return getKeyInput( ) == KEY_TYPE::EXIT;
}

void Input::update( ) {
	initInputKey( );
	if ( !isGetKeyIn( ) ) {
		return;
	}
	inputProcessing( );
}

void Input::initInputKey( ) {
	_type_key_input = KEY_TYPE::NONE;
	_input_key = -1;
}

void Input::inputProcessing( ) {
	_input_key = _getch( );
	determineTheKey( _input_key );
}

void Input::determineTheKey( int& key_num ) {
	switch ( key_num ) {
	case ( int )KEY_TYPE::UP:
		_type_key_input = KEY_TYPE::UP;
		break;
	case ( int )KEY_TYPE::DOWN:
		_type_key_input = KEY_TYPE::DOWN;
		break;
	case ( int )KEY_TYPE::LEFT:
		_type_key_input = KEY_TYPE::LEFT;
		break;
	case ( int ) KEY_TYPE::RIGHT:
		_type_key_input = KEY_TYPE::RIGHT;
		break;
	case ( int ) KEY_TYPE::EXIT:
		_type_key_input = KEY_TYPE::EXIT;
		break;
	default:
		break;
	}
}

bool Input::isGetKeyIn( ) {
	return _kbhit( );
}
