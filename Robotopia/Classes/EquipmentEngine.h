/************************************************************************/
/*
CLASS			: EquipmentEngine
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

class EquipmentEngine : public EquipmentAbstract
{
public:
	OVERRIDE bool				init();
	OVERRIDE void				update(float dTime);
	OVERRIDE void				enter();
	OVERRIDE void				exit();
	OVERRIDE bool				onContactBegin(cocos2d::PhysicsContact& contact);
	OVERRIDE void				onContactSeparate(cocos2d::PhysicsContact& contact);
	void						setEquipment(EquipmentType equipmentType, EngineList engineType, int level, int kWatt,
											 int upgradePrice, bool isLock, float electronicPower, float steamEffectiveness);


	struct EngineInfo : public EquipmentInfo
	{
		EngineList m_EngineType = EL_START;
		float m_ElectronicPower = 0.f;
		float m_SteamEffectiveness = 0.f;
	};

	CREATE_FUNC(EquipmentEngine);

private:
	EngineInfo m_EngineInfo;

};
