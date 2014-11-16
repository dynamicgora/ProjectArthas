/************************************************************************/
/*
CLASS			: MinimapLayer
Author			: �����
����			: Minimap�� �����ְ�, MŰ�� ������ �� Ȯ�� ����� �����ش�!
���� ��������	: 2014-11-05
���� ������		:
���� ��������	:
Comment			: 
*/
/************************************************************************/

#pragma once
#include "Util.h"
#include "MapLayer.h"



class MinimapLayer : public MapLayer
{
public:
	MinimapLayer();
	~MinimapLayer();

	OVERRIDE bool			init();
	OVERRIDE void			update(float dTime);

	CREATE_FUNC(MinimapLayer);

private:
	cocos2d::Sprite*		m_MinimapRotate0;
	cocos2d::Sprite*		m_MinimapRotate1;
	cocos2d::Sprite*		m_MinimapRotate2;
	cocos2d::Sprite*		m_MinimapMask;

	void					drawMiniMap();

};





