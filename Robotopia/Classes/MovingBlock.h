/************************************************************************/
/*
CLASS			: MovingBlock
Author			: �迬��
����			: �����̴� Ÿ�� MovingBlock
���� ��������	: 2014-11-05
���� ������		:
���� ��������	:
Comment			:
*/
/************************************************************************/

#pragma once
#include "Block.h"
#include "Util.h"



class MovingBlock : public Tile
{
public:
	OVERRIDE bool	init();
	OVERRIDE void	update(float dTime);
	OVERRIDE void	enter();
	OVERRIDE void	exit();

	OVERRIDE void	initTile(cocos2d::Rect tileRect);
	
	CREATE_FUNC(MovingBlock);

private:
	void			initFSM(cocos2d::Point leftPoint, cocos2d::Point rightPoint, float time);
	void			move(float dTime);
};

