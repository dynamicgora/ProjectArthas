/************************************************************************/
/*
CLASS			: SkillLineLayer
Author			: �����
����			: ��ų�� �����ϰ� �����Ѵ�.
���� ��������	: 2014-12-02
���� ������		: �����
���� ��������	: �ű�
Comment			:
*/
/************************************************************************/

#pragma once
#include "Util.h"
#include "AssemblyUILayer.h"

class SkillLineLayer : public AssemblyUILayer
{
public:
	OVERRIDE bool			init();
	OVERRIDE void			update(float dTime);

	CREATE_FUNC(SkillLineLayer);

private:
	cocos2d::Node*			m_BearSkillContainer = nullptr;
	cocos2d::Node*			m_MonkeySkillContainer = nullptr;
	cocos2d::Node*			m_EagleSkillContainer = nullptr;
	cocos2d::Node*			m_CommonSkillContainer = nullptr;

	cocos2d::Rect			m_BearSkillRect = cocos2d::Rect();
	cocos2d::Rect			m_MonkeySkillRect = cocos2d::Rect();
	cocos2d::Rect			m_EagleSkillRect = cocos2d::Rect();
	cocos2d::Rect			m_CommonSkillRect = cocos2d::Rect();

};