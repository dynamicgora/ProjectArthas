/************************************************************************/
/*
CLASS			: IconLayer
Author			: �����
����			: Icon ��ȣ �ۿ뿡 ����
���� ��������	: 2014-11-28
���� ������		: �����
���� ��������	: �ű�
Comment			:
*/
/************************************************************************/

#pragma once
#include "Util.h"
#include "UILayer.h"

class LabelLayer;

class IconLayer : public UILayer
{
public:
	OVERRIDE bool			init();
	OVERRIDE void			update(float dTime);

	CREATE_FUNC (IconLayer);

	void					setIconProperties(IconType iconType, cocos2d::Sprite* iconSprite, cocos2d::Point parentAnchorPoint, cocos2d::Point iconPosition);
	
	void					setIconDefault();
	void					setIconSelect();

private:
	bool					m_Selected = false;
	
	IconType				m_IconType = NO_ICON;
	LabelLayer*				m_IconLabel;
	cocos2d::Sprite*		m_IconFrame = nullptr;
	cocos2d::Sprite*		m_IconContents = nullptr;
	cocos2d::Rect			m_IconRect = cocos2d::Rect();

	void					setIconRect(cocos2d::Point parentAnchorPoint);

	
};