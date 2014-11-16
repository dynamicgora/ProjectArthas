/************************************************************************/
/*
CLASS			: TrapUnderground
Author			: �輺��
����				: ������ �ֱ������� �����ϴ� Ÿ��
���� ��������		: 2014-11-13
���� ������		:
���� ��������		:
Comment			: ����ϱ� ���� initTile�� �� �θ��ÿ�
*/
/************************************************************************/

#pragma once
#include "Tile.h"



class TrapUnderground : public Tile
{
public:
	OVERRIDE bool init();
	OVERRIDE void update(float dTime);
	OVERRIDE void enter();
	OVERRIDE void exit();

	OVERRIDE void initTile(cocos2d::Point origin, cocos2d::Size physicalSize, cocos2d::Size spriteSize);

private:
	long	m_StartTime;
	long	m_AccumulatedTime;
	long	m_Duration;
	bool	m_IsPrevTimeCheck;



};

