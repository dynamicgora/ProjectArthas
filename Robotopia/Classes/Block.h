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
#include "Tile.h"
#include "Util.h"

BEGIN_NS_AT

class Block : public Tile
{
public:
	OVERRIDE bool init();
	OVERRIDE void update( float dTime );
	OVERRIDE void enter();
	OVERRIDE void exit();

	ABSTRACT void initTile( float x, float y, float width, float height );
	ABSTRACT void initTile( cocos2d::Rect rect );

	CREATE_FUNC( Block );

private:
	
};

END_NS_AT