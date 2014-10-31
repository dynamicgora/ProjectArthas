/************************************************************************/
/*
	CLASS			: Tile
	Author			: �迬��
	����				: Tile���� �߻� class
	���� ��������	: 2014-10-29
	���� ������		:
	���� ��������	:
	Comment			: ����� �ݵ�� setRect�� ��!
*/
/************************************************************************/
#pragma once
#include "Component.h"
#include "Util.h"

BEGIN_NS_AT

class Tile : public Component
{
public:
	OVERRIDE bool init();
	OVERRIDE void update(float dTime) = 0;
	OVERRIDE void enter() = 0;
	OVERRIDE void exit() = 0;

	ABSTRACT void initTile( float x, float y, float width, float height );
	ABSTRACT void initTile( cocos2d::Rect rect );
	
protected:
	cocos2d::Rect m_BoxRect;
	ResourceType m_SpriteType;
};

END_NS_AT