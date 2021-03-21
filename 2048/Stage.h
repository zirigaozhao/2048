#pragma once
#include "Define.h"
#include <array>

class Stage {
public:
	Stage( );
	virtual ~Stage( );
public:
	int& getNumOfStage( int& x, int& y );
	int& getNumOfStage( int& idx );
	void setNum( );
	bool isHaveNum( int& idx );
	//キーUp
	int getUpReverseAcquistionOfNum( int& x, int& y ) const;
	int getUpReverseAcquistionOfNextNum( int& x, int& y ) const;
	int& setUpReverseAcquistionOfNum( int& x, int& y );
	int& setUpReverseAcquistionOfNextNum( int& x, int& y );
	//キーDown
	int getDownReverseAcquistionOfNum( int& x, int& y ) const;
	int getDownReverseAcquistionOfNextNum( int& x, int& y ) const;
	int& setDownReverseAcquistionOfNum( int& x, int& y );
	int& setDownReverseAcquistionOfNextNum( int& x, int& y );
	//キーLeft
	int getLeftReverseAcquistionOfNum( int& x, int& y ) const;
	int getLeftReverseAcquistionOfNextNum( int& x, int& y ) const;
	//キーRight
	int getRightReverseAcquistionOfNum( int& x, int& y ) const;
	int getRightReverseAcquistionOfNextNum( int& x, int& y ) const;
private:
	void init( );
private:
	std::array< int, SIZE_OF_STAGE* SIZE_OF_STAGE > _stage;
};

