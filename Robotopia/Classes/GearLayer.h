/************************************************************************ /
/*
CLASS			: GearLayer
Author			: �����
����			: Gear ��ȯ�� �����ش�.
���� ��������	: 2014-11-14
���� ������		: �����
���� ��������	: �ű�
Comment			:
*/
/************************************************************************/

#pragma once
#include "cocos2d.h"
#include "Util.h"
#include "GameSceneUILayer.h"

BEGIN_NS_AT

class GearLayer : public GameSceneUILayer
{
public:
	GearLayer();
	~GearLayer();

	OVERRIDE bool			init();
	OVERRIDE void			update(float dTime);

	CREATE_FUNC(GearLayer);

private:

};

END_NS_AT