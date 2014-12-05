/************************************************************************/
/*
CLASS			: EquipmentLeg
Author			: �輺��
����				: Leg ��� Ŭ����
���� ��������		: 2014-11-28
���� ������		:
���� ��������		:
Comment			:
/************************************************************************/

#pragma once
#include "Util.h"
#include "EquipmentAbstract.h"

struct LegInfo : public EquipmentInfo
{
	virtual LegInfo* clone();
	LegInfo();
	LegInfo(const LegInfo& other);
	float   m_MoveSpeed = 0.f;
	float   m_jumpPower = 0.f;
};

class EquipmentLeg : public EquipmentAbstract
{
public:
	

	OVERRIDE bool				init();
	OVERRIDE void				update(float dTime);
	OVERRIDE void				enter();
	OVERRIDE void				exit();
	OVERRIDE bool				onContactBegin(cocos2d::PhysicsContact& contact);
	OVERRIDE void				onContactSeparate(cocos2d::PhysicsContact& contact);

	CREATE_FUNC(EquipmentLeg);

	void						setEquipment(LegInfo legInfo);
	void						setEquipment(EquipmentType equipmentType, LegList legType, int level, int kWatt,
											 int upgradePrice, bool isLock, float moveSpeed, float jumpPower,
											 SpriteType front = ST_START, SpriteType outLine = ST_START, 
											 SpriteType icon = ST_START);

	LegInfo						getEquipmentInfo();

private:
	LegInfo m_LegInfo;

};
