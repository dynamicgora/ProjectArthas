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



class RoomLayer;
class Portal : public Tile
{
public:
	OVERRIDE bool init();
	OVERRIDE void update(float dTime);
	OVERRIDE void enter();
	OVERRIDE void exit();

	OVERRIDE void initTile(cocos2d::Rect tileRect);
	void		  setRoom(RoomLayer* room);
	CREATE_FUNC(Portal);

private:
	void		stateChange(ComponentType currentState);
	void		open();
	void		close();

	int			m_PositionIndex;
	RoomLayer*	m_Room;
};

