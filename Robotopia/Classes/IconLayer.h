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

	void					setIconProperties(IconType iconType, cocos2d::Sprite* iconSprite);
	void					setIconRect(cocos2d::Point parentAnchorPoint, cocos2d::Point iconPosition);
	void					setIconLocked();

private:
	bool					m_Selected = false;
	bool					m_Locked = false;
	bool					m_DragOn = false;

	IconType				m_IconType = NO_ICON;
	LabelLayer*				m_IconLabel;
	cocos2d::Sprite*		m_IconFrame = nullptr;
	cocos2d::Sprite*		m_IconContents = nullptr;
	cocos2d::Rect			m_IconRect = cocos2d::Rect();
	cocos2d::Point			m_PrevPoint;

	void					setIconDefault();
	void					setIconSelect();	
};