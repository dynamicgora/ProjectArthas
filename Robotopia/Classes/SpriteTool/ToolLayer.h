/************************************************************************/
/*
CLASS			: ToolLayer
Author			: �輺��
����				: Tool���� ���Ǵ� Sprite�� ���� ���̾�
���� ��������		: 2014-11-05
���� ������		:
���� ��������		:
Comment			: 
/************************************************************************/

#pragma once
#include "cocos2d.h"
#include "Util.h"


BEGIN_NS_AT


class ToolLayer : public cocos2d::LayerColor
{
public:
	OVERRIDE bool					init();
	OVERRIDE void					update(float dTime);
	void							setPhysicsWorld(cocos2d::PhysicsWorld* physicsWorld);

	CREATE_FUNC(ToolLayer);

private:
	cocos2d::PhysicsWorld*		m_PhysicsWorld;
	
	
};

END_NS_AT