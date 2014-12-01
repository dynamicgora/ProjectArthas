/************************************************************************/
/*
CLASS			: EquipmentSteamContainer
Author			: �輺��
����				: SteamContainer ��� Ŭ����
���� ��������		: 2014-11-28
���� ������		:
���� ��������		:
Comment			:
/************************************************************************/

#pragma once
#include "Util.h"
#include "EquipmentAbstract.h"

class EquipmentSteamContainer : public EquipmentAbstract
{
public:
	struct SteamContainerInfo : public EquipmentInfo
	{
		SteamContainerList m_SteamContainerType = SCL_END;
		float			   m_MaxSteam = 0.f;
		float			   m_AbsorbEffectiveness = 0.f;
	};

	OVERRIDE bool				init();
	OVERRIDE void				update(float dTime);
	OVERRIDE void				enter();
	OVERRIDE void				exit();
	OVERRIDE bool				onContactBegin(cocos2d::PhysicsContact& contact);
	OVERRIDE void				onContactSeparate(cocos2d::PhysicsContact& contact);
	
	CREATE_FUNC(EquipmentSteamContainer);
	
	void						setEquipment(SteamContainerInfo steamContainerInfo);
	void						setEquipment(EquipmentType equipmentType, SteamContainerList steamContainerType,
											 int level, int kWatt, int upgradePrice, bool isLock, 
											 float maxSteam, float AbsorbEffectiveness);


	SteamContainerInfo			getEquipmentInfo();

private:
	SteamContainerInfo m_SteamContainerInfo;

};
