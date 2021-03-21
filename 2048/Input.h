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
	//���͂��ꂽ�̃L�[�𔻒f����
	void determineTheKey( int& key_num );
	//�L�[�{�[�h������͂����邩�ǂ���
	bool isGetKeyIn( );
private:
	int _input_key;
	KEY_TYPE _type_key_input;
};

