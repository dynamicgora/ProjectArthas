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
#include "cocos2d.h"
#include "Util.h"
#include "GameSceneUILayer.h"

BEGIN_NS_AT

class MinimapLayer : public GameSceneUILayer
{
public:
	MinimapLayer();
	~MinimapLayer();

	OVERRIDE bool			init();
	OVERRIDE void			update(float dTime);

	CREATE_FUNC(MinimapLayer);

private:


};

END_NS_AT