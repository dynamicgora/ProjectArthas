/************************************************************************/
/*
CLASS			: SteamLayer
Author			: �����
����			: SteamLayer�� �����ش�.
���� ��������	: 2014-11-14
���� ������		: �����
���� ��������	: �ű�
Comment			:
*/
/************************************************************************/

#pragma once
#include "Util.h"
#include "GameSceneUILayer.h"
#include "CommonInfo.h"



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

	CommonInfo::Info		m_Info;

	void					setClippingMask(cocos2d::Sprite* steam, cocos2d::Sprite* steamMask);
};

