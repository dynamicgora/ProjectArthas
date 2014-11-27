/************************************************************************/
/*
CLASS			: ItemAbstact
Author			: �輺��
����				: ��� �������� �߻� Ŭ����, ���丮 ����, equipment, kit ����
���� ��������		: 2014-11-27
���� ������		:
���� ��������		:
Comment			:
/************************************************************************/

#pragma once

#include "BaseComponent.h"

class ItemAbstract : public BaseComponent
{
	OVERRIDE bool				init();
	OVERRIDE void				update(float dTime);
	OVERRIDE void				enter();
	OVERRIDE void				exit();
	OVERRIDE bool				onContactBegin(cocos2d::PhysicsContact& contact);
	OVERRIDE void				onContactSeparate(cocos2d::PhysicsContact& contact);


protected:
	
};

