#pragma once
#include "BaseClass.h"
#include "Stage.h"
#include "Input.h"

class Game : public BaseClass {
public:
	Game( Stage* stage, Input* input );
	virtual ~Game( );
public:
	void update( ) override;
	bool isGameOver( ) const;
private:
	void init( );
	void gameProcessing( );
	void stageUpProcessing( );
	void add( int& num1, int& num2 );
private:
	Stage* _stage;
	Input* _input;
	bool _is_game_over;
};

