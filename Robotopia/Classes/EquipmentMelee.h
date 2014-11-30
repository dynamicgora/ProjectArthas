/************************************************************************/
/*
CLASS			: EquipmentMelee
Author			: �輺��
����				: Melee ��� Ŭ����
���� ��������		: 2014-11-28
���� ������		:
���� ��������		:
Comment			:
/************************************************************************/

#pragma once
#include "Util.h"
#include "EquipmentAbstract.h"

class EquipmentMelee : public EquipmentAbstract
{
public:
	OVERRIDE bool				init();
	OVERRIDE void				update(float dTime);
	OVERRIDE void				enter();
	OVERRIDE void				exit();
	OVERRIDE bool				onContactBegin(cocos2d::PhysicsContact& contact);
	OVERRIDE void				onContactSeparate(cocos2d::PhysicsContact& contact);
	
	CREATE_FUNC(EquipmentMelee);
	
	void						setEquipment(EquipmentType equipmentType, MeleeList meleeType, int level, int kWatt,
											 int upgradePrice, bool isLock, float attackDamage, float attackSpeed);


	struct MeleeInfo : public EquipmentInfo
	{
		MeleeList m_MeleeType = ML_END;
		float	  m_AttackDamage = 0.f;
		float	  m_AttackSpeed = 0.f;
	};
	MeleeInfo					getEquipmentInfo();

private:
	MeleeInfo m_MeleeInfo;

};
