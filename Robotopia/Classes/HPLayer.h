/************************************************************************/
/*
CLASS			: HPLayer
Author			: �����
����			: Player ü���� �����ش�.
���� ��������	: 2014-11-18
���� ������		: �����
���� ��������	: �ű�
Comment			:
*/
/************************************************************************/

#pragma once
#include "Util.h"
#include "GameSceneUILayer.h"

class HPLayer : public GameSceneUILayer
{
public:
	HPLayer();
	~HPLayer();

	OVERRIDE bool			init();
	OVERRIDE void			update(float dTime);

	CREATE_FUNC(HPLayer);
private:
	cocos2d::Sprite*		m_HPbar;
	cocos2d::Sprite*		m_HPMask;

	int						m_MaxHP;
	int						m_CurrentHP;

	void					controlHP();
	void					setHPMask(cocos2d::Sprite* hpBar, cocos2d::Sprite* hpMask);

};
