#pragma once
#include "BaseClass.h"
#include "Stage.h"

class ViewStage : public BaseClass {
public:
	ViewStage( Stage* stage );
	virtual ~ViewStage( );
public:
	void update( ) override;
private:
	void drawStage( );
private:
	Stage* _stage;
};

