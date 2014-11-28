/************************************************************************/
/*
CLASS			: EquipmentRange
Author			: �輺��
����				: Range ��� Ŭ����
���� ��������		: 2014-11-28
���� ������		:
���� ��������		:
Comment			:
/************************************************************************/

#pragma once
#include "Util.h"
#include "EquipmentAbstract.h"

class EquipmentRange : public EquipmentAbstract
{
public:
	OVERRIDE bool				init();
	OVERRIDE void				update(float dTime);
	OVERRIDE void				enter();
	OVERRIDE void				exit();
	OVERRIDE bool				onContactBegin(cocos2d::PhysicsContact& contact);
	OVERRIDE void				onContactSeparate(cocos2d::PhysicsContact& contact);
	void						setEquipment(EquipmentType equipmentType, RangeList rangeType, int level, int kWatt,
											 int upgradePrice, bool isLock, float attackDamage, float attackSpeed,
											 float attackRange);


	struct RangeInfo : public EquipmentInfo
	{
		RangeList m_RangeType = RL_START;
		float	  m_AttackDamage = 0.f;
		float	  m_AttackSpeed = 0.f;
		float	  m_AttackRange = 0.f;
	};

	CREATE_FUNC(EquipmentRange);

private:
	RangeInfo m_RangeInfo;

};
