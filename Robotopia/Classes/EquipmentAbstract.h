/************************************************************************/
/*
CLASS			: EquipmentAbstract
Author			: �輺��
����				: ��� ����� �������� �߻� Ŭ���� 
���� ��������		: 2014-11-27
���� ������		:
���� ��������		:
Comment			: 
/************************************************************************/

#pragma once
#include "Util.h"
#include "ItemAbstract.h"

class IconLayer;

struct EquipmentInfo
{
	EquipmentInfo();
	virtual EquipmentInfo* clone();
	EquipmentInfo(const EquipmentInfo& other);
	EquipmentType			m_EquipmentType = EMT_START;
	int						m_Type = 0;
	SpriteType				m_FrontSprite = ST_IMAGE_NONE;
	SpriteType				m_FrontOutline = ST_IMAGE_NONE;
	SpriteType				m_IconSprite = ST_IMAGE_NONE;
	
	int						m_Level = 0;
	int						m_KWatt = 0;
	bool					m_IsLock = true;
	int						m_UpgradePrice = 0;
};

class EquipmentAbstract : public ItemAbstract
{
public:
	OVERRIDE bool				init();
	OVERRIDE void				update(float dTime);
	OVERRIDE void				enter();
	OVERRIDE void				exit();
	OVERRIDE bool				onContactBegin(cocos2d::PhysicsContact& contact);
	OVERRIDE void				onContactSeparate(cocos2d::PhysicsContact& contact);

	void						setEquipmentSprite(SpriteType front, SpriteType frontOutLine,
												   SpriteType icon);
	void						setEquipmentIcon(IconState iconState);
	void						setEquipmentDescription(std::string description);

	IconLayer*					getEquipmentIcon();
	IconState					getEquipmentIconState();

protected:
	cocos2d::Sprite*			m_FrontSpr = nullptr;
	cocos2d::Sprite*			m_FrontOutlineSpr = nullptr;
	IconLayer*					m_Icon = nullptr;

	std::string					m_Name = "";
	std::string					m_Description = "";

private:
};
