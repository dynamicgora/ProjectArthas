/************************************************************************/
/*
	CLASS			: Floor
	Author			: �迬��
	����				: �Ʒ� �浹�� �ϴ� Ÿ�� Floor
	���� ��������	: 2014-11-09
	���� ������		:
	���� ��������	:
	Comment			:
*/
/************************************************************************/
#pragma once
#include "Tile.h"
#include "Util.h"

BEGIN_NS_AT

class Floor : public Tile
{
public:
	OVERRIDE bool init();
	OVERRIDE void update(float dTime);
	OVERRIDE void enter();
	OVERRIDE void exit();

	OVERRIDE void initTile(cocos2d::Rect tileRect);
	CREATE_FUNC(Floor);

private:

};

END_NS_AT