#include "pch.h"
#include "MonsterStand.h"
#include "SpriteComponent.h"
#include "GameManager.h"
#include "ComponentManager.h"
#include "PhysicsComponent.h"
#include "AnimationComponent.h"

#define COOLTIME  5.f
#define REPEATEATTACKNUM 2

bool MonsterStand::init()
{
	if (!BaseComponent::init())
	{
		return false;
	}
	
	m_Type = OT_MONSTER_STAND_SHOT;
	setInfo(COOLTIME, REPEATEATTACKNUM);

	//���� �ʱ�ȭ
	auto physics = GET_COMPONENT_MANAGER()->createComponent<PhysicsComponent>();
	addComponent(physics);
	physics->initPhysics(cocos2d::Rect(0, 0, 50, 60), false, 0, 0, 0, PHYC_ALL, PHYC_ALL, PHYC_ALL);

	//���׸����ϰ� �׳� �����ϰ� �����ٸ����� �𸣰ڴµ�. 
	auto meterial = cocos2d::PhysicsMaterial(0, 0, 0);
	m_Body = cocos2d::PhysicsBody::createBox(cocos2d::Size(32, 32), meterial, cocos2d::Point(0, 0));
	m_Body->setContactTestBitmask(PHYC_PLAYER);
	m_Body->setCategoryBitmask(PHYC_NONE);
	m_Body->setCollisionBitmask(PHYC_BLOCK | PHYC_BLOCK);
	m_Body->setMass(10);
	m_Body->setRotationEnable(false);
	m_Body->setVelocityLimit(1000);
	setPhysicsBody(m_Body);

	auto contactListener = cocos2d::EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(MonsterStand::onContactBegin, this);
	contactListener->onContactSeperate = CC_CALLBACK_1(MonsterStand::onContactSeparate, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

	//FSM �ʱ�ȭ
	initFSM(1);
	m_States[0] = STAT_IDLE;

	//0���� attackFSM
	m_FSMs[0].resize(STAT_NUM);
	//attack���� 0�� �Լ��� IDLE�ε� �̶� �Ұ� ����.
	m_FSMs[0][STAT_IDLE] = nullptr;
	//attack���� 1�� �Լ���  Attack�ε� �̶��� ������ �ؾ��Ѵ�. 
	m_FSMs[0][STAT_ATTACK] = attack;

	//0�� �� attackFSM�� ���� Ʈ������
	m_Transitions[0].resize(STAT_NUM);
	//�� �Լ����� idle���� attack���� �Ѿ�� ��찡 �ְ���
	m_Transitions[0][STAT_IDLE] = idleTransition;
	//attack���� idle�� ���� ��� ���� 
	m_Transitions[0][STAT_ATTACK] = attackTransition;

	//0�� fsm�� ���� �׸��� ��� �׸� ���ΰ�. 
	m_Renders[0].resize(STAT_NUM);
	m_Renders[0][STAT_IDLE] = GET_COMPONENT_MANAGER()->createComponent<AnimationComponent>();
	((AnimationComponent*)m_Renders[0][STAT_IDLE])->setAnimation(AT_MONSTER_STAND_SHOT_IDLE, this);
	m_Renders[0][STAT_MOVE] = GET_COMPONENT_MANAGER()->createComponent<AnimationComponent>();
	((AnimationComponent*)m_Renders[0][STAT_ATTACK])->setAnimation(AT_MONSTER_STAND_SHOT_ATTACK, this);

	for (int i = 0; i < m_Renders[0].size(); i++)
	{
		addComponent(m_Renders[0][i]);
	}

}

void MonsterStand::setInfo(float coolTime /*= 5*/, int repeatAttackNum /*= 2*/,
						   Direction dir /*= DIR_RIGHT*/, int damage /*= 20*/, int maxHp /*= 100*/, int curHp /*= 100*/,
						   ComponentType missileType /*= OT_MISSILE_PLAYER_LINEAR */)
{
	m_Info.coolTime = coolTime;
	m_Info.repeatAttackNum = repeatAttackNum;
	m_Info.dir = dir;
	m_Info.damage = damage;
	m_Info.maxHp = maxHp;
	m_Info.curHp = 100;
	m_Info.missileType = missileType;
}

void MonsterStand::attack(Thing* target, double dTime, int idx)
{
	
}

void MonsterStand::enterAttack(Thing* target, double dTime, int idx)
{

}

void MonsterStand::exitAttack(Thing* target, double dTime, int idx)
{

}

void MonsterStand::attackTransition(Thing* target, double dTime, int idx)
{
	((MonsterStand*)target)->m_CurAttackNum++;
}

void MonsterStand::idleTransition(Thing* target, double dTime, int idx)
{

}

void MonsterStand::update(float dTime)
{

}

void MonsterStand::enter()
{
}

void MonsterStand::exit()
{
}

bool MonsterStand::onContactBegin(cocos2d::PhysicsContact& contact)
{
	return true;
}

void MonsterStand::onContactSeparate(cocos2d::PhysicsContact& contact)
{
	
}

cocos2d::PhysicsBody* MonsterStand::getBody()
{
	return m_Body;
}







