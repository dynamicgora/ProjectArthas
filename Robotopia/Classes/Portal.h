/************************************************************************/
/*
CLASS			: Portal
Author			: �迬��
����				: ���ᰡ���ϸ� ������ �ƴϸ� ������ Ÿ��
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

class Portal : public Tile
{
public:
	OVERRIDE bool init();
	OVERRIDE void update(float dTime);
	OVERRIDE void enter();
	OVERRIDE void exit();

	OVERRIDE void initTile(cocos2d::Point origin, cocos2d::Size physicalSize, cocos2d::Size spriteSize);


	CREATE_FUNC(Portal);

private:
	void		stateChange(ComponentType currentState);
	void		open();
	void		close();

	int			m_PositionIndex;
};

END_NS_AT