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

class SpriteComponent;
class AnimationComponent;
class VendingMachine : public NPC
{
public:
	enum Status
	{
		STAT_IDLE,
		STAT_USABLE,
		STAT_UNUSABLE,
		STAT_NUM,
	};
	virtual bool				init();
	virtual void				update(float dTime);
	virtual void				enter();
	virtual void				exit();
	virtual void				dead();
	void						initFSMAndTransition();


	CREATE_FUNC(VendingMachine);

private:
	AllStatus				m_Info;
	bool					m_SoundId = 0;
	int						m_KitNum = 0;
	bool					m_PrevContact = false;
	AnimationComponent*		m_ContactAni = nullptr;
	AnimationComponent*     m_SeperateAni = nullptr;
	SpriteComponent*		m_FirstSprite = nullptr;
};

