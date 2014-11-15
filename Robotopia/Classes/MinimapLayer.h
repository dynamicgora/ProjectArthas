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

BEGIN_NS_AT

class MinimapLayer : public MapLayer
{
public:
	MinimapLayer();
	~MinimapLayer();

	OVERRIDE bool			init();
	OVERRIDE void			update(float dTime);

	CREATE_FUNC(MinimapLayer);

private:
	//Map Window
	cocos2d::DrawNode*		m_Map;
	
	//Minimap
	cocos2d::Sprite*		m_MinimapFrame;
	cocos2d::Sprite*		m_MinimapMask;

	void					drawMiniMap();

};

END_NS_AT



