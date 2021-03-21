#pragma once
#include "BaseClass.h"

class Input : public BaseClass {
public:
	enum class KEY_TYPE {
		NONE,
		UP = 72,
		DOWN = 80,
		LEFT = 75,
		RIGHT = 77,
		EXIT,
	};
public:
	Input( );
	virtual ~Input( );
public:
	KEY_TYPE getKeyInput( ) const;
	bool isHitEsc( );
	void update( ) override;
private:
	void initInputKey( );
	void inputProcessing( );
	//入力されたのキーを判断する
	void determineTheKey( int& key_num );
	//キーボードから入力があるかどうか
	bool isGetKeyIn( );
private:
	int _input_key;
	KEY_TYPE _type_key_input;
};

