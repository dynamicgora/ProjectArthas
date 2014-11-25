﻿/************************************************************************/
/*
CLASS			: SteamLayer
Author			: 우재우
역할			: SteamLayer를 보여준다.
최종 수정일자	: 2014-11-18
최종 수정자		: 우재우
최종 수정사유	: 스팀 이미지 변경 및 기어와 반응
Comment			:
*/
/************************************************************************/

#pragma once
#include "Util.h"
#include "GameSceneUILayer.h"

class SteamLayer : public GameSceneUILayer
{
public:
	SteamLayer();
	~SteamLayer();

	OVERRIDE bool			init();
	OVERRIDE void			update(float dTime);

	CREATE_FUNC(SteamLayer);

private:
	cocos2d::Sprite*		m_Steam0;
	cocos2d::Sprite*		m_Steam1;
	cocos2d::Sprite*		m_Steam2;
	cocos2d::Sprite*		m_Steam3;
	cocos2d::Sprite*		m_Steam4;
	cocos2d::Sprite*		m_Steam5;

	cocos2d::Sprite*		m_SteamMask0;
	cocos2d::Sprite*		m_SteamMask1;
	cocos2d::Sprite*		m_SteamMask2;
	cocos2d::Sprite*		m_SteamMask3;
	cocos2d::Sprite*		m_SteamMask4;
	cocos2d::Sprite*		m_SteamMask5;
	cocos2d::Sprite*		m_SteamTest;

	GearType				m_CurrentGear;
	bool					m_Test;
	int						m_SteamLevel;
	int						m_MaxSteam;
	int						m_CurrentSteam;

	void					setSteamMask(cocos2d::Sprite* steam, cocos2d::Sprite* steamMask);
	void					controlSteam();
	void					controlSteamColor();
	void					changeSteamColor(GearType gear);
};

