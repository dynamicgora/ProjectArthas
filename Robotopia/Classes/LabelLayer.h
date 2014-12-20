/************************************************************************/
/*
CLASS			: LabelLayer
Author			: �����
����			: Label ����
���� ��������	: 2014-11-30
���� ������		: �����
���� ��������	: Label type ����
Comment			:
*/
/************************************************************************/

#pragma once
#include "Util.h"
#include "UILayer.h"

class LabelLayer : public UILayer
{
public:
	OVERRIDE bool			init();
	OVERRIDE void			update(float dTime);

	CREATE_FUNC (LabelLayer);

	void					setLabelContents(bool isLocked);
	void					setLabelPosition(cocos2d::Point labelPosition, bool rectDirDown);

private:
	float					m_LabelWidth = 0.0f;
	float					m_LabelHeight = 0.0f;
	cocos2d::Sprite*		m_LabelFrame = nullptr;
	cocos2d::Label*			m_LabelText = nullptr;

};