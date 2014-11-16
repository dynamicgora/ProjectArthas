/************************************************************************/
/*
CLASS				: ResourceManager
Author				: �����
����				: Sprite �� Animation ��û �� ���� �� ����
���� ��������		: 2014-10-31
���� ������			: �����
���� ��������		: ���ҽ� �Ŵ��� ����
Comment				: ���ҽ� ����� ����(�� ���) �״�� �� ������ ���� �� ����. 
*/
/************************************************************************/

#pragma once
#include "Util.h"
#include "cocos2d.h"



class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();

	bool					init();
	cocos2d::Animation*		createAnimation(ResourceType type);
	cocos2d::Sprite*		createSprite(ResourceType type);

private:
// 	std::map <ResourceType, cocos2d::Sprite*>		m_Sprites;
// 	std::map <ResourceType, cocos2d::Animation*>	m_Animations;
	
};

