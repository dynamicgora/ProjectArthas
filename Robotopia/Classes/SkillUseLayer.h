/************************************************************************/
/*
CLASS			: SkillUseLayer
Author			: �����
����			: GameScene���� Skill ��� �� UI
���� ��������	: 2014-12-16
���� ������		:
���� ��������	:
Comment			:
*/
/************************************************************************/

#pragma once
#include "Util.h"
#include "GameSceneUILayer.h"

class SkillUseLayer : public GameSceneUILayer
{
public:

	OVERRIDE bool			init();
	OVERRIDE void			update(float dTime);

	CREATE_FUNC(SkillUseLayer);

private:
	cocos2d::Sprite*		m_GearSkillFrame = nullptr;
	cocos2d::Sprite*		m_BearSkill = nullptr;
	cocos2d::Sprite*		m_MonkeySkill = nullptr;
	cocos2d::Sprite*		m_EagleSkill = nullptr;
	cocos2d::Sprite*		m_GearSkillCoolDown = nullptr;

	cocos2d::Sprite*		m_CommonSkillFrame = nullptr;
	cocos2d::Sprite*		m_CommonSkill = nullptr;
	cocos2d::Sprite*		m_CommonSkillCoolDown = nullptr;

	SkillSet				m_SkillSet = SkillSet();
	GearType				m_PrevGear = GEAR_NONE;

	void					changeSkillByGear(GearType newGear);
};