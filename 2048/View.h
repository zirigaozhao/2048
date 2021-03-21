#pragma once
#include "BaseClass.h"
#include "Stage.h"
#include "Game.h"

class View : public BaseClass {
public:
	View( Stage* stage, Game* game );
	virtual ~View( );
public:
	void update( ) override;
private:
	void drawStage( );
	void drawGameOver( );
private:
	Stage* _stage;
	Game* _game;
};

