/************************************************************************/
/*
CLASS			: EquipmentHead
Author			: �輺��
����				: head ��� Ŭ���� 
���� ��������		: 2014-11-27
���� ������		:
���� ��������		:
Comment			:
/************************************************************************/

#pragma once

#include "EquipmentAbstract.h"

class EquipmentHead : public EquipmentAbstract
{
public:
	OVERRIDE bool				init();
	OVERRIDE void				update(float dTime);
	OVERRIDE void				enter();
	OVERRIDE void				exit();
	OVERRIDE bool				onContactBegin(cocos2d::PhysicsContact& contact);
	OVERRIDE void				onContactSeparate(cocos2d::PhysicsContact& contact);
	OVERRIDE void				initEquipment();



	struct HeadInfo : public EquipmentInfo
	{
		//HeadListType m_HeadType = HEADTYPE_NONE;
		float m_SkillCoolTime = 0.f;
		float m_MainMemory = 0.f;
	};

private:
	HeadInfo m_HeadInfo;

};
