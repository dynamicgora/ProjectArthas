/************************************************************************/
/*
CLASS			: ToolSpriteListLayer
Author			: �輺��
����				: ���� ����� Sprite�� list �� ������ �����ִ� ���̾�
���� ��������		: 2014-11-08
���� ������		:
���� ��������		:
Comment			:
*/
/************************************************************************/
#pragma once
#include "cocos2d.h"
#include "Util.h"
#include <vector>

BEGIN_NS_AT

class ToolAniPlayLayer : public cocos2d::Layer
{
public:
	OVERRIDE bool init();
	void		  sprCallBack(cocos2d::Ref* sender);
	void		  playCallBack(cocos2d::Ref* sender);
	void		  stopCallBack(cocos2d::Ref* sender);
	void		  flipCallBack(cocos2d::Ref* sender);

	CREATE_FUNC(ToolAniPlayLayer);

private:
	cocos2d::Sprite*		   m_MainSpr;
	bool					   isFlipped;
	AnimationInfo			   m_AniInfo;
	SpriteInfo				   m_SprInfo;
	
};

END_NS_AT

