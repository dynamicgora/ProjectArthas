/************************************************************************/
/*
CLASS			: RobotAssemblyLayer
Author			: �����
����			: GameScene ���� �� �κ� ����â�� ������
���� ��������	: 2014-11-23
���� ������		: �����
���� ��������	: �ű�
Comment			:
*/
/************************************************************************/

#pragma once
#include "Util.h"
#include "UILayer.h"

class ButtonLayer;
class IconLayer;
class EquipmentStatusLayer;
class AssemblyDisplayLayer;
class AssemblyLineLayer;
class SkillLineLayer;

class AssemblyUILayer : public UILayer
{
public:
	AssemblyUILayer();
	~AssemblyUILayer();

	OVERRIDE bool			init();
	OVERRIDE void			update(float dTime);

	CREATE_FUNC(AssemblyUILayer);

protected:
	void					moveContainer(bool moveLeft, cocos2d::Node* container, cocos2d::Rect containerRect);

private:
	bool					m_IsStarted = false;

	cocos2d::Sprite*		m_AssemblyBackground = nullptr;
	cocos2d::Sprite*		m_AssemblyFrame = nullptr;
	cocos2d::Sprite*		m_ViewChangeArrow = nullptr;

	cocos2d::Rect			m_viewChangeRect = cocos2d::Rect();
	cocos2d::Rect			m_EquipmentRect = cocos2d::Rect();
	cocos2d::Rect			m_SkillRect = cocos2d::Rect();

	AssemblyLineLayer*		m_AssemblyLineLayer;
	EquipmentStatusLayer*	m_StatusLayer;
	AssemblyDisplayLayer*	m_DisplayLayer;
	SkillLineLayer*			m_SkillLineLayer;

	AssemblyLayerType		m_CurrentAssembly = NO_ASSEMBLY_LAYER;

	ButtonLayer*			m_ButtonConfirm = nullptr;
	ButtonLayer*			m_ButtonCancel = nullptr;

	void					assemblyLayerButtonInit();
	void					viewChange(AssemblyLayerType moveViewTo);

	void					confirmAssembly();
	void					toTitleScene();
};

