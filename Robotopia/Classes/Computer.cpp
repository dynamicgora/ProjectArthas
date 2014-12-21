#include "pch.h"
#include "Computer.h"
#include "GameManager.h"
#include "ComponentManager.h"
#include "InputManager.h"
#include "SpriteComponent.h"
#include "GaugeBarContainer.h"
#include "EffectManager.h"
#include "Effect.h"
#include "SoundManager.h"
#include "StageManager.h"
#include "Player.h"
#include "DataManager.h"

bool Computer::init()
{
	if(!NPC::init())
	{
		return false;
	}
	m_Type = OT_COMPUTER;
	m_Info.m_Size = cocos2d::Size(COMPUTER_WIDTH, COMPUTER_HEIGHT);
	bodyInit(m_Info.m_Size);
	initFSMAndTransition();
	m_Bar = GaugeBarContainer::create();
	m_Bar->initBarContainer(this, ST_BAR_CONTAINER, ST_BAR, cocos2d::Point(0, LOADING_BAR_HEIGHT));
	addComponent(m_Bar);
	setLoadingTime(3.f);
	return true;
}

void Computer::update(float dTime)
{
	Creature::update(dTime);
}

void Computer::exit()
{
	removeFromParent();
}

void Computer::enter()
{
	resume();
}

void Computer::available(Creature* target, double dTime, int idx)
{

}

void Computer::loading(Creature* target, double dTime, int idx)
{
	if(GET_INPUT_MANAGER()->getKeyState(KC_UP) == KS_HOLD)
	{
		float curPercent = m_Bar->getBarPercent();
		if(curPercent < 100)
		{
			m_Bar->setBarPercent(curPercent + dTime * m_LoadingSpeed);
		}
		else
		{
			m_IsComplete = true;
		}
	}
}

void Computer::complete(Creature* target, double dTime, int idx)
{

}

void Computer::idleTransition(Creature* target, double dTime, int idx)
{
	if(m_OnContact)
	{
		availableEnter(dTime, idx);
		setState(idx, Computer::STAT_AVAILABLE);
	}
}

void Computer::availableTransition(Creature* target, double dTime, int idx)
{
	if(!m_OnContact)
	{
		availableExit(dTime, idx);
		setState(idx, Computer::STAT_IDLE);
	}
	else if(GET_INPUT_MANAGER()->getKeyState(KC_UP) == KS_PRESS)
	{
		GET_SOUND_MANAGER()->createSound(SoundManager::CHARGEGAGE, false);
		availableExit(dTime, idx);
		loadingEnter(dTime, idx);
		setState(idx, Computer::STAT_LOADING);
	}
}

void Computer::loadingTransition(Creature* target, double dTime, int idx)
{
	if(!m_OnContact)
	{
		loadingExit(dTime, idx);
		setState(idx, Computer::STAT_IDLE);
	}
	else if(GET_INPUT_MANAGER()->getKeyState(KC_UP) == KS_RELEASE)
	{
		loadingExit(dTime, idx);
		availableEnter(dTime, idx);
		setState(idx, Computer::STAT_AVAILABLE);
	}
	else if(m_IsComplete)
	{
		loadingExit(dTime, idx);
		GET_SOUND_MANAGER()->createSound(SoundManager::GETMONEY, false);
		completeEnter(dTime, idx);
		setState(idx, Computer::STAT_COMPLETE);
	}
}

void Computer::completeTransition(Creature* target, double dTime, int idx)
{
}

void Computer::availableEnter(double dTime, int idx)
{
}

void Computer::availableExit(double dTime, int idx)
{
}

void Computer::loadingEnter(double dTime, int idx)
{
	m_Bar->enter();
}

void Computer::loadingExit(double dTime, int idx)
{
	m_Bar->exit();
	m_Bar->setBarPercent(0.f);
}

void Computer::completeEnter(double dTime, int idx)
{
	pause();
	GET_EFFECT_MANAGER()->createEffect(ET_COIN, getPosition() + cocos2d::Point(0, m_Info.m_Size.height / 2))->enter();
	auto player = GET_STAGE_MANAGER()->getPlayer();
	auto info = player->getInfo();

	//��Ʈ���� ȹ��
	if (rand() % 100 < 90)
	{
		info.m_BitCoin += 100;

		player->setInfo(info);
	}
	else
	{
		SkillType category;
		int type;
		int typeNum[SKILL_NUM] = { 0, };

		typeNum[SKILL_BEAR] = BEAR_END;
		typeNum[SKILL_MONKEY] = MONKEY_END;
		typeNum[SKILL_EAGLE] = EAGLE_END;
		typeNum[SKILL_COMMON] = COMMON_END;
		//10% Ȯ���� ���� ���� ���� ���� ��ų �ϳ� ȹ��.
		do
		{
			category = static_cast<SkillType>(rand() %SKILL_NUM);
			type = rand() % typeNum[category];
		} while (!GET_DATA_MANAGER()->getSkillInfo(category, type)->m_IsLock);

		GET_DATA_MANAGER()->setSkillLock(category, type, false);
	}

	setEnabled(false);
}

void Computer::completeExit(double dTime, int idx)
{

}
void Computer::initFSMAndTransition()
{
	initFSM(1);
	m_States[0] = STAT_IDLE;

	//0���� attackFSM
	m_FSMs[0].resize(STAT_NUM);
	m_FSMs[0][STAT_IDLE] = nullptr;
	m_FSMs[0][STAT_AVAILABLE] = FSM_CALLBACK(Computer::available, this);
	m_FSMs[0][STAT_LOADING] = FSM_CALLBACK(Computer::loading, this);
	m_FSMs[0][STAT_COMPLETE] = FSM_CALLBACK(Computer::complete, this);

	m_Transitions[0].resize(STAT_NUM);
	m_Transitions[0][STAT_IDLE] = FSM_CALLBACK(Computer::idleTransition, this);
	m_Transitions[0][STAT_AVAILABLE] = FSM_CALLBACK(Computer::availableTransition, this);
	m_Transitions[0][STAT_LOADING] = FSM_CALLBACK(Computer::loadingTransition, this);
	m_Transitions[0][STAT_COMPLETE] = FSM_CALLBACK(Computer::completeTransition, this);

	m_Renders[0].resize(STAT_NUM);
	m_Renders[0][STAT_IDLE] = GET_COMPONENT_MANAGER()->createComponent<SpriteComponent>();
	m_Renders[0][STAT_IDLE]->initSprite(ST_COMPUTER_NORMAL, this);

	m_Renders[0][STAT_AVAILABLE] = GET_COMPONENT_MANAGER()->createComponent<SpriteComponent>();
	m_Renders[0][STAT_AVAILABLE]->initSprite(ST_COMPUTER_HEATED_01, this);

	m_Renders[0][STAT_LOADING] = GET_COMPONENT_MANAGER()->createComponent<SpriteComponent>();
	m_Renders[0][STAT_LOADING]->initSprite(ST_COMPUTER_HEATED_01, this);

	m_Renders[0][STAT_COMPLETE] = GET_COMPONENT_MANAGER()->createComponent<SpriteComponent>();
	m_Renders[0][STAT_COMPLETE]->initSprite(ST_COMPUTER_EMPTY, this);


	for(int i = 0; i < m_Renders[0].size(); i++)
	{
		addComponent(m_Renders[0][i]);
	}

}

void Computer::setLoadingTime(float sec)
{
	m_LoadingSpeed = ( sec != 0 ) ? 100 / sec : 0.f;
}



