/************************************************************************/
/*
CLASS			: MovingBlock
Author			: �迬��
����				: ���� Ʈ�� ���
���� ��������	: 2014-12-06
���� ������		:
���� ��������	:
Comment			:
*/
/************************************************************************/

#pragma once
#include "Tile.h"
#define ELECTRIC_VELOCITY 200

class Electric;
class ElectricTrap : public Tile
{
public:
	virtual bool	init();
	virtual void	update(float dTime);
	virtual void	enter();
	virtual void	exit();

	virtual void	initTile(cocos2d::Rect tileRect);
	virtual void	setEnabled(bool enable);

	CREATE_FUNC(ElectricTrap);

private:
	bool					m_IsLeftMoving = true;
	cocos2d::Vec2			m_MovingVelocity;
	cocos2d::Rect			m_ActivateRect;
	Electric*				m_Electric;
};

