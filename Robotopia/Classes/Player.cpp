#include "pch.h"
#include "Player.h"
#include "SpriteComponent.h"
#include "PlayerMoveFSM.h"
#include "PlayerJumpFSM.h"
#include "GameManager.h"
#include "ComponentManager.h"
#include "KeyboardCommand.h"
#include "ObserverComponent.h"
#include "PhysicsComponent.h"
#include "PlayerRender.h"
#include "CommonInfo.h"
#include "PlayerAttackFSM.h"
#include "PhysicsInfo.h"
#include "InputManager.h"
#include "ResourceManager.h"
#include "AnimationComponent.h"

bool Player::init()
{
	if (!BaseComponent::init())
	{
		return false;
	}

	auto info = GET_COMPONENT_MANAGER()->createComponent<CommonInfo>();
	addComponent(info);

	CommonInfo::Info tmp;
	tmp.dir = DIR_RIGHT;
	tmp.speed = 200;
	tmp.jumpSpeed = 500;
	tmp.size.width = 32.f;
	tmp.size.height = 32.f;
	tmp.maxHp = 100;
	tmp.maxSteam = 100;
	tmp.currentHp = 100;
	tmp.currentSteam = 100;

	info->setInfo(tmp);

	m_Type = OT_PLAYER;

	//���� �ʱ�ȭ
	auto physics = GET_COMPONENT_MANAGER()->createComponent<PhysicsComponent>();
	addComponent(physics);
	physics->initPhysics(cocos2d::Rect(0, 0, 32, 32), true, 0, 0, 0, PHYC_ALL, PHYC_ALL, PHYC_ALL);
	physics->addIgnoreCollision(OT_FLOOR, DIR_UP);

	auto meterial = cocos2d::PhysicsMaterial(0, 0, 0);
	m_Body = cocos2d::PhysicsBody::createBox(cocos2d::Size(32, 32), meterial, cocos2d::Point(0, 0));
	m_Body->setContactTestBitmask(PHYC_ALL);
	m_Body->setCategoryBitmask(PHYC_PLAYER);
	m_Body->setMass(10);
	m_Body->setRotationEnable(false);
	m_Body->setVelocityLimit(1000);
	setPhysicsBody(m_Body);

	auto contactListener = cocos2d::EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(Player::onContactBegin, this);
	contactListener->onContactSeperate = CC_CALLBACK_1(Player::onContactSeparate, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

	//FSM �ʱ�ȭ
	initFSM(1);
	m_States[0] = STAT_IDLE;

	m_FSMs[0].resize(STAT_NUM);
	m_FSMs[0][STAT_IDLE] = nullptr;
	m_FSMs[0][STAT_MOVE] = move;
	m_FSMs[0][STAT_JUMP] = jump;

	m_Transitions[0].resize(STAT_NUM);
	m_Transitions[0][STAT_IDLE] = idleTransition;
	m_Transitions[0][STAT_MOVE] = moveTransition;
	m_Transitions[0][STAT_JUMP] = jumpTransition;

	m_Renders[0].resize(STAT_NUM);
	m_Renders[0][STAT_IDLE] = GET_COMPONENT_MANAGER()->createComponent<AnimationComponent>();
	((AnimationComponent*)m_Renders[0][STAT_IDLE])->setAnimation(AT_PLAYER_IDLE, this);
	m_Renders[0][STAT_MOVE] = GET_COMPONENT_MANAGER()->createComponent<AnimationComponent>();
	((AnimationComponent*)m_Renders[0][STAT_MOVE])->setAnimation(AT_PLAYER_MOVE, this);
	m_Renders[0][STAT_JUMP] = GET_COMPONENT_MANAGER()->createComponent<AnimationComponent>();
	((AnimationComponent*)m_Renders[0][STAT_JUMP])->setAnimation(AT_PLAYER_JUMP, this);

	for (int i = 0; i < m_Renders[0].size(); i++)
	{
		addComponent(m_Renders[0][i]);
	}

	//info ����

	m_Info.speed = 200;
	m_Info.jumpSpeed = 500;
	m_Info.dir = DIR_RIGHT;
	m_Info.size = cocos2d::Size(32, 32);

	return true;
}

void Player::enter()
{
	resume();
}

void Player::exit()
{
}

void Player::idleTransition(Thing* target, double dTime, int idx)
{
	//->move
	if (GET_INPUT_MANAGER()->getKeyState(KC_LEFT) == KS_HOLD ||
		GET_INPUT_MANAGER()->getKeyState(KC_RIGHT) == KS_HOLD)
	{
		if (GET_INPUT_MANAGER()->getKeyState(KC_LEFT) == KS_HOLD)
		{
			enterMove(target, dTime, DIR_LEFT);
		}
		else
		{
			enterMove(target, dTime, DIR_RIGHT);
		}

		target->setState(idx, Player::STAT_MOVE);
	}

	//->jump
	if (GET_INPUT_MANAGER()->getKeyState(KC_JUMP) == KS_PRESS)
	{
		enterJump(target, dTime, false);
		target->setState(idx, Player::STAT_JUMP);
	}
}

void Player::move(Thing* target, double dTime, int idx)
{
	cocos2d::Rect rect = cocos2d::Rect(target->getPositionX(), target->getPositionY(), 
						((Player*)target)->getInfo().size.width, ((Player*)target)->getInfo().size.height);
	
	auto velocity = ((Player*)target)->getBody()->getVelocity();

	//���� �����̰� ���ʿ� �ƹ��͵� ����.
	cocos2d::log("left : %d right : %d up : %d down : %d", GET_GAME_MANAGER()->getContactComponentType(target, rect, DIR_LEFT),
		GET_GAME_MANAGER()->getContactComponentType(target, rect, DIR_RIGHT),
		GET_GAME_MANAGER()->getContactComponentType(target, rect, DIR_UP),
		GET_GAME_MANAGER()->getContactComponentType(target, rect, DIR_DOWN));

	if (GET_GAME_MANAGER()->getContactComponentType(target, rect, DIR_LEFT) == CT_NONE &&
		GET_INPUT_MANAGER()->getKeyState(KC_LEFT) == KS_HOLD)
	{
		((Player*)target)->setDirection(DIR_LEFT);
		velocity.x = -200;
	}
	else if (GET_GAME_MANAGER()->getContactComponentType(target, rect, DIR_RIGHT) == CT_NONE &&
		GET_INPUT_MANAGER()->getKeyState(KC_RIGHT) == KS_HOLD)
	{
		((Player*)target)->setDirection(DIR_RIGHT);
		velocity.x = 200;
	}
	else
	{
		velocity.x = 0;
	}

	((Player*)target)->getBody()->setVelocity(velocity);
}

void Player::jump(Thing* target, double dTime, int idx)
{
	move(target, dTime, idx);
}

void Player::enterMove(Thing* target, double dTime,Direction dir)
{
	auto velocity = ((Player*)target)->getBody()->getVelocity();

	((Player*)target)->setDirection(dir);

	//�ӵ� �ӽ÷� ����.
	if (dir == DIR_LEFT)
	{
		velocity.x = -200;
	}
	else if (dir == DIR_RIGHT)
	{
		velocity.x = 200;
	}

	((Player*)target)->getBody()->setVelocity(velocity);
}

void Player::enterJump(Thing* target, double dTime, bool isFall)
{
	auto velocity = ((Player*)target)->getBody()->getVelocity();

	//�ӵ� �ӽ÷� ����.
	if (!isFall)
	{
		velocity.y = 500;
	}

	((Player*)target)->getBody()->setVelocity(velocity);
}

void Player::moveTransition(Thing* target, double dTime, int idx)
{
	//->idle
	if (GET_INPUT_MANAGER()->getKeyState(KC_LEFT) == KS_NONE &&
		GET_INPUT_MANAGER()->getKeyState(KC_RIGHT) == KS_NONE)
	{
		exitMove(target, dTime);
		target->setState(idx, Player::STAT_IDLE);
	}

	//->jump
	if (GET_INPUT_MANAGER()->getKeyState(KC_JUMP) == KS_PRESS)
	{
		exitMove(target, dTime);
		enterJump(target, dTime, false);
		target->setState(idx, Player::STAT_JUMP);
	}

	//->fall
	cocos2d::Rect rect = cocos2d::Rect(target->getPositionX(), target->getPositionY(), 32, 32);
	if (GET_GAME_MANAGER()->getContactComponentType(target, rect, DIR_DOWN) == CT_NONE)
	{
		exitMove(target, dTime);
		enterJump(target, dTime, true);
		target->setState(idx, Player::STAT_JUMP);
	}
}

void Player::jumpTransition(Thing* target, double dTime, int idx)
{
	auto player = (Player*)target;

	//->idle
	cocos2d::Rect rect = cocos2d::Rect(target->getPositionX(), target->getPositionY(), 32, 32);
	if (GET_GAME_MANAGER()->getContactComponentType(target, rect, DIR_DOWN) != CT_NONE)
	{
		target->setState(idx, Player::STAT_IDLE);
	}
}

void Player::exitMove(Thing* target, double dTime)
{
	auto velocity = ((Player*)target)->getBody()->getVelocity();

	velocity.x = 0;

	((Player*)target)->getBody()->setVelocity(velocity);
}

bool Player::onContactBegin(cocos2d::PhysicsContact& contact)
{
	return true;
}


void Player::onContactSeparate(cocos2d::PhysicsContact& contact)
{
}

cocos2d::PhysicsBody* Player::getBody()
{
	return m_Body;
}

const PlayerInfo& Player::getInfo()
{
	return m_Info;
}

void Player::update(float dTime)
{
	if (m_Info.dir == DIR_LEFT)
	{
		for (int i = 0; i < m_Renders[0].size(); i++)
		{
			m_Renders[0][i]->setFlippedX(true);
		}
	}
	else
	{
		for (int i = 0; i < m_Renders[0].size(); i++)
		{
			m_Renders[0][i]->setFlippedX(false);
		}
	}

	Thing::update(dTime);
}

void Player::setDirection(Direction dir)
{
	m_Info.dir = dir;
}
