/************************************************************************/
/*
	CLASS			: Block
	Author			: �迬��
	����				: Ÿ���� ���� Block Class
	���� ��������	: 2014-10-29
	���� ������		:
	���� ��������	:
	Comment			:
*/
/************************************************************************/
#pragma once
#include "Component.h"
#include "Util.h"

BEGIN_NS_AT

class Block : public Component
{
public:
	OVERRIDE bool init();
	OVERRIDE void update( float dTime );
	OVERRIDE void enter();
	OVERRIDE void exit();

	CREATE_FUNC( Block );

private:
	cocos2d::Rect m_BoxRect;
};

END_NS_AT