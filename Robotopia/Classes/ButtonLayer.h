/************************************************************************/
/*
CLASS			: ButtonLayer
Author			: �����
����			: UI�� �ʿ��� ��ư
���� ��������	: 2014-11-22
���� ������		: �����
���� ��������	: �ű�
Comment			: Button�� ����� �ݵ�� setButtonProperties�� �ؾ� �� �� ����.
*/
/************************************************************************/

#pragma once
#include "Util.h"
#include "UILayer.h"

class ButtonLayer : public UILayer
{
public:
	ButtonLayer();
	~ButtonLayer();

	OVERRIDE bool			init();
	OVERRIDE void			update();

	CREATE_FUNC(ButtonLayer);

	void					setButtonProperties(ButtonType buttonType, std::string buttonLabel, int buttonValue);
	void					setButtonOver(bool onButton);

private:
	ButtonType				m_ButtonType;
	int						m_ButtonValue;
	cocos2d::Sprite*		m_ButtonSprite;
	cocos2d::Rect			m_ButtonRect;
	cocos2d::Label*			m_ButtonLabel;

	void					getButtonRect();
};