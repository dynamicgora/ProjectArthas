#include "pch.h"
#include "AssemblyUILayer.h"
#include "GameManager.h"
#include "StageManager.h"
#include "DataManager.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include "AssemblyLineLayer.h"
#include "EquipmentStatusLayer.h"
#include "AssemblyDisplayLayer.h"
#include "SkillLineLayer.h"
#include "ButtonLayer.h"
#include "IconLayer.h"

AssemblyUILayer::AssemblyUILayer()
{
	m_viewChangeRect.setRect(1235 * RESOLUTION, 310 * RESOLUTION, 25 * RESOLUTION, 100 * RESOLUTION);
}

AssemblyUILayer::~AssemblyUILayer()
{
}

bool AssemblyUILayer::init()
{
	if (!cocos2d::Layer::init())
	{
		return false;
	}
	m_IsStarted = false;

	m_AssemblyLineLayer = AssemblyLineLayer::create();
	m_StatusLayer = EquipmentStatusLayer::create();
	m_DisplayLayer = AssemblyDisplayLayer::create();
	m_SkillLineLayer = SkillLineLayer::create();

	m_AssemblyBackground = GET_RESOURCE_MANAGER()->createSprite(ST_ASSEMBLY_BACKGROUND);
	m_AssemblyFrame = GET_RESOURCE_MANAGER()->createSprite(ST_ASSEMBLY_FRAME);
	m_ViewChangeArrow = GET_RESOURCE_MANAGER()->createSprite(ST_ASSEMBLY_ARROW);
	m_EquipmentRect.setRect(190 * RESOLUTION, 40 * RESOLUTION, 390 * RESOLUTION, 580 * RESOLUTION);

	setUIProperties(m_AssemblyBackground, cocos2d::Point::ZERO, cocos2d::Point::ZERO, RESOLUTION, true, 0);
	setUIProperties(m_AssemblyFrame, cocos2d::Point::ZERO, cocos2d::Point::ZERO, RESOLUTION, true, 0);
	setUIProperties(m_ViewChangeArrow, cocos2d::Point(0.5, 0.5), cocos2d::Point(1055, 360), 1.0f, true, 1);
	assemblyLayerButtonInit();

	m_CurrentAssembly = ASSEMBLY_VIEW;

	this->addChild(m_AssemblyBackground);
	m_AssemblyBackground->addChild(m_AssemblyLineLayer);
	m_AssemblyBackground->addChild(m_DisplayLayer);
	m_AssemblyBackground->addChild(m_SkillLineLayer);
	this->addChild(m_AssemblyFrame);
	m_AssemblyFrame->addChild(m_ViewChangeArrow);
	m_AssemblyFrame->addChild(m_StatusLayer);
	return true;
}

void AssemblyUILayer::update(float dTime)
{
	MouseInfo mouseInput = GET_INPUT_MANAGER()->getMouseInfo();
	if (m_CurrentAssembly == ASSEMBLY_VIEW)
	{	
		m_StatusLayer->update(dTime);
		if (m_EquipmentRect.containsPoint(mouseInput.m_MouseMove))
		{
			m_AssemblyLineLayer->updateEquipments(dTime);
			m_AssemblyLineLayer->containerScroll(mouseInput.m_ScollValue, mouseInput.m_MouseMove);
			GET_INPUT_MANAGER()->resetMouseWheel();
			
			if (mouseInput.m_MouseState == MS_LEFT_UP)
			{
				m_AssemblyLineLayer->setClickedItem(mouseInput.m_MouseEnd[LEFT_CLICK_POINT]);
				GET_INPUT_MANAGER()->resetMousePoints();
			}
			if (mouseInput.m_DoubleClick)
			{
				m_AssemblyLineLayer->updateDoubleClickIcon(mouseInput.m_MouseEnd[LEFT_CLICK_POINT]);
				m_AssemblyLineLayer->setConfirmSet(mouseInput.m_MouseEnd[LEFT_CLICK_POINT]);
				m_DisplayLayer->update(dTime);
				GET_INPUT_MANAGER()->resetMouseDoubleClick();
			}
		}
		else
		{
			m_AssemblyLineLayer->hideLabelLayer();
			if (mouseInput.m_ScollValue < 0)
			{
				viewChange(SKILL_VIEW);
			}
			else if (mouseInput.m_ScollValue > 0)
			{
				GET_INPUT_MANAGER()->resetMouseWheel();
			}
			
			//meaningless double click error exception
			if (mouseInput.m_DoubleClick)
			{
				GET_INPUT_MANAGER()->resetMouseDoubleClick();
			}
		}
		
		//view change arrow
		if (m_viewChangeRect.containsPoint(mouseInput.m_MouseEnd[LEFT_CLICK_POINT]))
		{
			viewChange(SKILL_VIEW);
		}
	}
	else if (m_CurrentAssembly == SKILL_VIEW)
	{
		if (m_SkillRect.containsPoint(mouseInput.m_MouseMove))
		{
			if (mouseInput.m_DoubleClick)
			{
				m_DisplayLayer->update(dTime);
				GET_INPUT_MANAGER()->resetMouseDoubleClick();
			}
		}
		else
		{
			if (mouseInput.m_ScollValue > 0)
			{
				viewChange(ASSEMBLY_VIEW);
			}
			else if (mouseInput.m_ScollValue < 0)
			{
				GET_INPUT_MANAGER()->resetMouseWheel();
			}
		}

		//view change arrow
		if (m_viewChangeRect.containsPoint(mouseInput.m_MouseEnd[LEFT_CLICK_POINT]))
		{
			viewChange(ASSEMBLY_VIEW);
		}
		m_StatusLayer->update(dTime);
		m_SkillLineLayer->update(dTime);
		m_ButtonConfirm->update(dTime);
		m_ButtonCancel->update(dTime);
	}
}

void AssemblyUILayer::viewChange(AssemblyLayerType moveViewTo)
{
	if (m_AssemblyBackground->getNumberOfRunningActions() == 0)
	{
		cocos2d::ActionInterval* moveAction0;
		cocos2d::ActionInterval* moveAction1;
		if (moveViewTo == SKILL_VIEW)
		{
			moveAction0 = cocos2d::MoveTo::create(1.0f, cocos2d::Point(-830 * RESOLUTION, 0));
			moveAction1 = cocos2d::MoveTo::create(1.2f, cocos2d::Point(-830 * RESOLUTION, 0));
			m_viewChangeRect.setRect(20 * RESOLUTION, 310 * RESOLUTION, 25 * RESOLUTION, 100 * RESOLUTION);
			m_ViewChangeArrow->setRotation(180);
			m_ButtonConfirm->setButtonRect(cocos2d::Point(-830 * RESOLUTION, 0));
			m_ButtonCancel->setButtonRect(cocos2d::Point(-830 * RESOLUTION, 0));
			m_AssemblyLineLayer->setVisible(false);
			m_CurrentAssembly = SKILL_VIEW;
		}
		else
		{
			moveAction0 = cocos2d::MoveTo::create(1.0f, cocos2d::Point(0, 0));
			moveAction1 = cocos2d::MoveTo::create(1.2f, cocos2d::Point(0, 0));
			m_viewChangeRect.setRect(1235 * RESOLUTION, 310 * RESOLUTION, 25 * RESOLUTION, 100 * RESOLUTION);
			m_ViewChangeArrow->setRotation(0);
			m_ButtonConfirm->setButtonRect(cocos2d::Point(0 * RESOLUTION, 0));
			m_ButtonCancel->setButtonRect(cocos2d::Point(0 * RESOLUTION, 0));
			m_AssemblyLineLayer->setVisible(true);
			m_CurrentAssembly = ASSEMBLY_VIEW;
		}
		cocos2d::Action* action0 = cocos2d::EaseExponentialOut::create(moveAction0);
		cocos2d::Action* action1 = cocos2d::EaseExponentialOut::create(moveAction1);
		m_AssemblyFrame->runAction(action0);
		m_AssemblyBackground->runAction(action1);
	}
	GET_INPUT_MANAGER()->resetMousePoints();
	GET_INPUT_MANAGER()->resetMouseWheel();
}

void AssemblyUILayer::assemblyLayerButtonInit()
{
	m_ButtonConfirm = ButtonLayer::create();
	m_ButtonCancel = ButtonLayer::create();
	
	m_ButtonConfirm->setButtonProperties(BUTTON_ASSEMBLY, cocos2d::Point(0 * RESOLUTION, 0), cocos2d::Point(1670, 90), "Confirm");
	m_ButtonCancel->setButtonProperties(BUTTON_ASSEMBLY, cocos2d::Point(0 * RESOLUTION, 0), cocos2d::Point(1900, 90), "Cancel");
	
	m_ButtonConfirm->setButtonFunc(std::bind(&AssemblyUILayer::confirmAssembly, this));
	m_ButtonCancel->setButtonFunc(std::bind(&AssemblyUILayer::toTitleScene, this));
	
	m_AssemblyFrame->addChild(m_ButtonConfirm);
	m_AssemblyFrame->addChild(m_ButtonCancel);
}

void AssemblyUILayer::moveContainer(bool moveLeft, cocos2d::Node* container, cocos2d::Rect containerRect)
{
	if (moveLeft)
	{
		if (container->getBoundingBox().getMaxX() - 110 > containerRect.getMaxX())
		{
			container->setPosition(cocos2d::Point(container->getPosition().x - 15, container->getPosition().y));
		}
		GET_INPUT_MANAGER()->resetMouseWheel();
	}
	else
	{
		if (container->getBoundingBox().getMinX() * RESOLUTION - 15 < containerRect.getMinX())
		{
			container->setPosition(cocos2d::Point(container->getPosition().x + 15, container->getPosition().y));
		}
		GET_INPUT_MANAGER()->resetMouseWheel();
	}
}

void AssemblyUILayer::confirmAssembly()
{
	if (checkAssemblyComplete(m_AssemblyLineLayer->getConfirmSet()))
	{
		if (!m_IsStarted)
		{
			m_IsStarted = true;
			GET_DATA_MANAGER()->initWorldData();
			GET_INPUT_MANAGER()->resetMouseInfo();
			GET_GAME_MANAGER()->changeScene(GET_STAGE_MANAGER()->getGameScene(), GAME_SCENE);
			GET_STAGE_MANAGER()->start();
		}
	}
	else
	{
		//�̿ϼ� �޽��� ���!
	}
}

void AssemblyUILayer::toTitleScene()
{
	exit(0);
}

bool AssemblyUILayer::checkAssemblyComplete(ConfirmSet confirmSet)
{
// 	if (confirmSet.m_Head == HL_START || confirmSet.m_Engine == EL_START ||
// 		confirmSet.m_Armor == AL_START || confirmSet.m_Melee == ML_START ||
// 		confirmSet.m_Range == RL_START || confirmSet.m_Steam == SCL_START || confirmSet.m_Leg == LL_START)
// 	{
// 		return false;
// 	}
// 	else
// 	{
// 		return true;
// 	}
	return true;
}

