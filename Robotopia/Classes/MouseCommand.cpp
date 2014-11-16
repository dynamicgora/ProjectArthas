#include "pch.h"
#include "GameManager.h"
#include "TriggerManager.h"
#include "InputManager.h"
#include "MouseCommand.h"
#include "ObserverComponent.h"
#include "MouseTrigger.h"

bool MouseCommand::init()
{
	if (!CommandComponent::init())
	{
		return false;
	}
	return true;
}

void MouseCommand::update(float dTime)
{
	auto observer = getObserverComponent();
	if (observer != nullptr)
	{
		auto mouseInfo = GET_INPUT_MANAGER()->getMouseInfo();
		if (mouseInfo.mouseState != MS_NONE)
		{
//			auto mouseTrigger = (MouseTrigger*)GET_TRIGGER_MANAGER()->createTrigger<MouseTrigger>();
//			keyTrigger->initKeyCode((KeyCode)keyCode, keyState);
//			observer->addTrigger((Trigger*)mouseTrigger);
			//resetMouseInfo ȣ���� �ʿ��� �� ����
		}
		if (mouseInfo.doubleClick)
		{
			//����Ŭ������ �ؾ��� �ϵ��� ó���ؾ��ϴµ� ��� ���� ��� �� �ٸ� ������ �ű� ���� ����
			//resetMouseInfo ȣ���� �ʿ��� �� ����
		}
	}
}

void MouseCommand::enter()
{

}

void MouseCommand::exit()
{

}
