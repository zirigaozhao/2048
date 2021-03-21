#pragma once
#include "Define.h"
#include <array>

class Stage {
public:
	Stage( );
	virtual ~Stage( );
public:
	int& getNumOfStage( const int& x, const int& y );
	int& getNumOfStage( const int& idx );
	int& setNumForStage( const int& idx );
	void setNum( );
	bool isHaveNum( const int& idx );
	//�L�[Up
	int getUpReverseAcquistionOfNum( const int& y, const int& x ) const;
	int& setUpReverseAcquistionOfNum( const int& y, const int& x );
	void lessUp( );
	//�L�[Down
	int getDownReverseAcquistionOfNum( const int& y, const int& x ) const;
	int& setDownReverseAcquistionOfNum( const int& y, const int& x );
	void lessDown( );
	//�L�[Left
	int getLeftReverseAcquistionOfNum( const int& y, const int& x ) const;
	int& setLeftReverseAcquistionOfNum( const int& y, const int& x );
	void lessLeft( );
	//�L�[Right
	int getRightReverseAcquistionOfNum( const int& y, const int& x ) const;
	int& setRightReverseAcquistionOfNum( const int& y, const int& x );
	void lessRight( );
private:
	void init( );
	void changeNum( int& num1, int& num2 );
private:
	std::array< int, SIZE_OF_STAGE* SIZE_OF_STAGE > _stage;
};

