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
#include "Util.h"
#include "EquipmentAbstract.h"

class EquipmentHead : public EquipmentAbstract
{
public:
	struct HeadInfo : public EquipmentInfo
	{
		HeadList	m_HeadType = HL_START;
		float		m_SkillCoolTimeDown = 0.f;
		float		m_MainMemory = 0.f;
	};

	OVERRIDE bool				init();
	OVERRIDE void				update(float dTime);
	OVERRIDE void				enter();
	OVERRIDE void				exit();
	OVERRIDE bool				onContactBegin(cocos2d::PhysicsContact& contact);
	OVERRIDE void				onContactSeparate(cocos2d::PhysicsContact& contact);

	CREATE_FUNC(EquipmentHead);

	void						setEquipment(HeadInfo headInfo);
	void						setEquipment(EquipmentType equipmentType, HeadList headType, int level, int kWatt,
											 int upgradePrice, bool isLock, float skillCoolTimeDown, float mainMemory);
	
	HeadInfo					getEquipmentInfo();

private:
	HeadInfo					m_HeadInfo;

};
