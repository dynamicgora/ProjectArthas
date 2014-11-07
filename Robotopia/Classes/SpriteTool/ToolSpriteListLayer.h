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

class ToolSpriteListLayer : public cocos2d::Layer
{
public:
	OVERRIDE bool init();
	

private:
	std::vector<AnimationInfo*> m_SpriteList;
	
};

END_NS_AT

//
//struct AnimationInfo
//{
//	ResourceType type;
//	char animationName[MAX_FRAME][MAX_LEN];
//	int frameNum;
//	float delay;
//};