/************************************************************************/
/*
CLASS			: EquipmentArmor
Author			: �輺��
����				: Engine ��� Ŭ����
���� ��������		: 2014-11-28
���� ������		:
���� ��������		:
Comment			:
/************************************************************************/

#pragma once
#include "Util.h"
#include "EquipmentAbstract.h"

class EquipmentArmor : public EquipmentAbstract
{
public:
	struct ArmorInfo : public EquipmentInfo
	{
		ArmorList m_ArmorType = AL_START;
		float m_DefensivePower = 0.f;
		float m_AntiSlow = 0.f;
	};

	OVERRIDE bool				init();
	OVERRIDE void				update(float dTime);
	OVERRIDE void				enter();
	OVERRIDE void				exit();
	OVERRIDE bool				onContactBegin(cocos2d::PhysicsContact& contact);
	OVERRIDE void				onContactSeparate(cocos2d::PhysicsContact& contact);

	CREATE_FUNC(EquipmentArmor);

	void						setEquipment(ArmorInfo armorInfo);
	void						setEquipment(EquipmentType equipmentType, ArmorList armorType, int level, int kWatt,
											 int upgradePrice, bool isLock, float defensivePower, float antiSlow);


	ArmorInfo					getEquipmentInfo();

private:
	ArmorInfo m_ArmorInfo;

};
