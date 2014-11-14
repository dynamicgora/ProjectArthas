#include "pch.h"
#include "GameManager.h"
#include "PhysicsComponent.h"
#include "MissilePlayerMelee.h"
#include "ComponentManager.h"
#include "ObserverComponent.h"
#include "TriggerManager.h"
#include "PhysicsTrigger.h"
#include "AnimationComponent.h"
#include "DataManager.h"
#include "StageManager.h"



void Arthas::MissilePlayerMelee::initMissile()
{
	m_IsPlayerMissile = true;
	m_IsUsable = true;
	m_Type = OT_MISSILE_PLAYER_MELEE;
	
	setAnchorPoint(cocos2d::Point::ANCHOR_MIDDLE);

	auto observer = GET_COMPONENT_MANAGER()->createComponent<ObserverComponent>();
	addComponent(observer);


	auto physics = GET_COMPONENT_MANAGER()->createComponent<PhysicsComponent>();
	addComponent(physics);
	//���Ͷ� �ε����� �Ǵµ� ���� ���Ϳ� ���� phyc�� ����. 
	//���� ����� �ε����� �ؾ��� 
	physics->initPhysics(cocos2d::Rect(0, 0, 60, 45), false, 0, 0, 0, PHYC_ALL, PHYC_NONE, PHYC_NONE);
	//�ϴ� ���� body ���� '�θ� �� ���ش�.' 
	physics->setEnabled(false);
	
	auto animation = GET_COMPONENT_MANAGER()->createComponent<AnimationCompnent>();
	addComponent(animation);
	animation->setAnimation(AT_MISSILE_PLAYER_MELEE, this, 1);
	

}
	
void Arthas::MissilePlayerMelee::setAttribute(cocos2d::Point pos, Direction attackDir,
											  float damage, cocos2d::Size contentsSize,
											  cocos2d::Vec2 velocity,
											  cocos2d::Point targetPos)
{
	//setAttribute�� Manager���� �θ� �� �Ѵ�.
	//�� �� ���� ��� ����
	m_Velocity = velocity;
	m_Damage = damage;
	m_AttackDir = attackDir;
	m_TargetPos = targetPos;
	cocos2d::Point setPos;
	float rotation = 0.f;
	if (attackDir == DIR_LEFT)
	{
		rotation = 180.f;
	}


	setPos.x = pos.x + cos(rotation / 90 * MATH_PIOVER2)*contentsSize.width;
	setPos.y = pos.y + sin(rotation / 90 * MATH_PIOVER2)*contentsSize.height;

	setPosition(setPos);
	setRotation(rotation);

	//���⼭ physics�� �Ѿ߰ڴ�. 
	auto physicsCompo = (PhysicsComponent*)getComponent(CT_PHYSICS);
	physicsCompo->setEnabled(true);
	auto body = physicsCompo->getBody();

	
	auto animationCompo = (AnimationCompnent*)getComponent(CT_ANIMATION);
	animationCompo->enter();

	
	

	m_IsUsable = false;
}

void Arthas::MissilePlayerMelee::update(float dTime)
{
	for (auto& component : getChildren())
	{
		component->update(dTime);
	}

	auto observer = (ObserverComponent*)this->getComponent(CT_OBSERVER);
	if (observer)
	{
		m_Triggers = observer->getTriggers();
	}

	for (auto pTrigger : m_Triggers)
	{
		if (pTrigger)
		{
			auto physicsCompo = (PhysicsComponent*)getComponent(CT_PHYSICS);
			physicsCompo->setEnabled(false);
			removeFromParent();
		}
	}

}

bool Arthas::MissilePlayerMelee::init()
{
	if (!Missile::init())
	{
		return false;
	}

	return true;
}
void Arthas::MissilePlayerMelee::enter()
{
}

void Arthas::MissilePlayerMelee::exit()
{
}