/************************************************************************/
/*
	CLASS			: UILayer
	Author			: �����
	����			: Scene�� �´� UILayer���� �������� ���� �Լ��� ���� ���� ���̾�
	���� ��������	: 2014-10-31
	���� ������		: �����
	���� ��������	: ���� ������!!!
	Comment			: 
*/
/************************************************************************/

#pragma once
#include "cocos2d.h"
#include "GameManager.h"
#include "Util.h"

BEGIN_NS_AT

class UILayer : public cocos2d::Layer
{
public:
	OVERRIDE bool			init();
	OVERRIDE void			update( float dTime );

	CREATE_FUNC( UILayer );
protected:
	void	setUIProperties(cocos2d::Sprite* sprite, cocos2d::Point anchorPoint,
		cocos2d::Point positionPoint, float scale, bool visible);
};

END_NS_AT