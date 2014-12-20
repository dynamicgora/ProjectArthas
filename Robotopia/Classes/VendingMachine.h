/************************************************************************/
/*
CLASS			: VendingMachin
Author			: �輺��
����				: �������� ������ ü�� ŰƮ������ VendingMAchin
���� ��������		: 2014-12-20
���� ������		:
���� ��������		:
Comment			:
*/
/************************************************************************/
#pragma once
#include "NPC.h"

class AnimationComponent;
class VendingMachine : public NPC
{
public:

	virtual bool				init();
	virtual void				update(float dTime);
	virtual void				enter();
	virtual void				exit();
	virtual bool				onContactBegin(cocos2d::PhysicsContact& contact);
	virtual void				onContactSeparate(cocos2d::PhysicsContact& contact);


	CREATE_FUNC(VendingMachine);

private:
	AllStatus				m_Info;
	bool					m_SoundId = 0;
	int						m_KitNum = 0;
	AnimationComponent*		m_ContactAni = nullptr;
	AnimationComponent*     m_SeperateAni = nullptr;
};

