/************************************************************************/
/*
CLASS			: MapWindowLayer
Author			: �����
����			: MŰ�� ������ �� ���� �����ش�!
���� ��������	: 2014-11-14
���� ������		: �����
���� ��������	: �ű�
Comment			:
*/
/************************************************************************/

#pragma once
#include "Util.h"
#include "MapLayer.h"



class MapWindowLayer : public MapLayer
{
public:
	MapWindowLayer();
	~MapWindowLayer();

	OVERRIDE bool			init();
	OVERRIDE void			update(float dTime);

	CREATE_FUNC(MapWindowLayer);

	void					showMapWIn();
	void					hideMapWin();

private:
	cocos2d::Sprite*		m_MapWinFrame;
	cocos2d::Sprite*		m_MapWinTrigger;
	float					FitToWin();

};

