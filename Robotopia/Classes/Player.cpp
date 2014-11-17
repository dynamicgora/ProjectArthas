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

	auto physicsInfo = GET_COMPONENT_MANAGER()->createComponent<PhysicsInfo>();

	addComponent(physicsInfo);

	m_Type = OT_PLAYER;

	auto physics = GET_COMPONENT_MANAGER()->createComponent<PhysicsComponent>();
	addComponent(physics);
	physics->initPhysics(cocos2d::Rect(0, 0, 32, 32), true, 0, 0, 0, PHYC_ALL, PHYC_PLAYER, PHYC_ALL);
	physics->addIgnoreCollision(OT_FLOOR, DIR_UP);

	initFSM(1);

	m_States[0] = MS_IDLE;

	m_FSMFunctions[0].push_back(nullptr);
	m_FSMFunctions[0].push_back(move);
	m_FSMFunctions[0].push_back(jump);

	m_FSMTransitions[0].push_back(idleTransition);
	m_FSMTransitions[0].push_back(moveTransition);
	m_FSMTransitions[0].push_back(jumpTransition);

	return true;
}

void Player::enter()
{
	resume();
}

void Player::exit()
{
	auto physicsInfo = (PhysicsInfo*)getComponent(IT_PHYSICS);

	physicsInfo->getInfo()->contactObjects.clear();
}

void Player::idleTransition(Thing* target, double dTime, int idx)
{
	//�ٿ� ���� ���·� ����

	//���� ���·� ����
	if (GET_INPUT_MANAGER()->getKeyState(KC_JUMP) == KS_PRESS)
	{
		//������ ���ϰ� ���� ���·� ����
		auto body = ((PhysicsComponent*)target->getComponent(CT_PHYSICS))->getBody();
		auto velocity = body->getVelocity();
		//�ӽ÷� 500����
		velocity.y = 500;
		body->setVelocity(velocity);

		target->setState(idx, MS_JUMP);
		return;
	}
	
	//���� ���·� ����
	if (GET_INPUT_MANAGER()->getKeyState(KC_LEFT) == KS_HOLD ||
		GET_INPUT_MANAGER()->getKeyState(KC_RIGHT) == KS_HOLD)
	{
		//�����ϱ��� �ӵ� ����
		float speed;

		if (GET_INPUT_MANAGER()->getKeyState(KC_LEFT) == KS_HOLD)
		{
			speed = -200;
		}
		else if (GET_INPUT_MANAGER()->getKeyState(KC_RIGHT) == KS_HOLD)
		{
			speed = 200;
		}

		auto body = ((PhysicsComponent*)target->getComponent(CT_PHYSICS))->getBody();
		auto velocity = body->getVelocity();
		velocity.x = speed;
		body->setVelocity(velocity);

		target->setState(idx, MS_MOVE);
		return;
	}
}

void Player::move(Thing* target, double dTime, int idx)
{
	float speed;

	if (GET_INPUT_MANAGER()->getKeyState(KC_LEFT) == KS_HOLD)
	{
		speed = -200;
	}
	else if (GET_INPUT_MANAGER()->getKeyState(KC_RIGHT) == KS_HOLD)
	{
		speed = 200;
	}
	else
	{
		speed = 0;
	}

	PhysicsInfo* infoComponent = (PhysicsInfo*)target->getComponent(IT_PHYSICS);

	if (infoComponent != nullptr)
	{
		auto info = infoComponent->getInfo();
		cocos2d::PhysicsBody* physicsBody = ((PhysicsComponent*)target->getComponent(CT_PHYSICS))->getBody();
		cocos2d::Vect velocity = physicsBody->getVelocity();

		//speed�� 0�̸� �ȵǴµ� 0�� ��Ȳ ( -> ���� �ε����� ���� ��Ȳ ������ �ӵ��� 0�� �� ���)
		if (info->contactDirections == DIR_NONE)
		{
			auto velocity = physicsBody->getVelocity();
			velocity.x = speed;
			physicsBody->setVelocity(velocity);
		}
	}
}

void Player::jump(Thing* target, double dTime, int idx)
{
	move(target, dTime, idx);
}

void Player::moveTransition(Thing* target, double dTime, int idx)
{
	//move->move ����
	if (GET_INPUT_MANAGER()->getKeyState(KC_LEFT) == KS_HOLD ||
		GET_INPUT_MANAGER()->getKeyState(KC_RIGHT) == KS_HOLD)
	{
		float speed;
		CommonInfo* infoComponent = (CommonInfo*)target->getComponent(IT_COMMON);
		auto info = infoComponent->getInfo();

		if (GET_INPUT_MANAGER()->getKeyState(KC_LEFT) == KS_HOLD && info.dir == DIR_RIGHT)
		{
			speed = -200;
			info.dir = DIR_LEFT;

			infoComponent->setInfo(info);
			auto body = ((PhysicsComponent*)target->getComponent(CT_PHYSICS))->getBody();
			auto velocity = body->getVelocity();
			velocity.x = speed;
			body->setVelocity(velocity);
		}
		else if (GET_INPUT_MANAGER()->getKeyState(KC_RIGHT) == KS_HOLD && info.dir == DIR_LEFT)
		{
			speed = 200;
			info.dir = DIR_RIGHT;

			infoComponent->setInfo(info);
			auto body = ((PhysicsComponent*)target->getComponent(CT_PHYSICS))->getBody();
			auto velocity = body->getVelocity();
			velocity.x = speed;
			body->setVelocity(velocity);
		}
	}


	//���� ���·� ����
	if (GET_INPUT_MANAGER()->getKeyState(KC_JUMP) == KS_PRESS)
	{
		//������ ���ϰ� ���� ���·� ����
		auto body = ((PhysicsComponent*)target->getComponent(CT_PHYSICS))->getBody();
		auto velocity = body->getVelocity();
		//�ӽ÷� 500����
		velocity.y = 500;
		body->setVelocity(velocity);

		target->setState(idx, MS_JUMP);
		return;
	}

	//idle ���·� ����

	if (GET_INPUT_MANAGER()->getKeyState(KC_LEFT) == KS_NONE &&
		GET_INPUT_MANAGER()->getKeyState(KC_RIGHT) == KS_NONE)
	{
		//x�� �ӵ� 0���� ����
		auto body = ((PhysicsComponent*)target->getComponent(CT_PHYSICS))->getBody();
		auto velocity = body->getVelocity();
		velocity.x = 0;
		body->setVelocity(velocity);

		target->setState(idx, MS_IDLE);
	}
}

void Player::jumpTransition(Thing* target, double dTime, int idx)
{
	PhysicsInfo* infoComponent = (PhysicsInfo*)target->getComponent(IT_PHYSICS);

	if (infoComponent != nullptr)
	{
		auto info = infoComponent->getInfo();

		//�Ʒ��� �浹�� -> jump ����
		if (info->contactDirections & DIR_DOWN)
		{
			target->setState(idx, MS_IDLE);
		}
	}
}
