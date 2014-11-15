#include "pch.h"
#include "PhysicsComponent.h"
#include "GameManager.h"
#include "TriggerManager.h"
#include "PhysicsTrigger.h"
#include "ObserverComponent.h"

Arthas::PhysicsComponent::~PhysicsComponent()
{
	m_Body->release();
}

bool Arthas::PhysicsComponent::init()
{
	if(!Component::init())
	{
		return false;
	}
	m_Body = nullptr;
	m_Type = Arthas::ComponentType::CT_PHYSICS;
	return true;
}
void Arthas::PhysicsComponent::update( float dTime )
{

}

void Arthas::PhysicsComponent::enter()
{

}

void Arthas::PhysicsComponent::exit()
{

}



cocos2d::PhysicsBody* Arthas::PhysicsComponent::getBody()
{
	return	m_Body;
}

//���� �ٵ� ���� rect(�ٵ� ��ġ�� ������), isDynamic(�����̳�?), density(���Կ� ����), Restitution(ź�� ����), Frinction(������),
//��Ʈ����ũ�� http://cafe.naver.com/cocos2dxusers/19578 ����
void Arthas::PhysicsComponent::initPhysics( cocos2d::Rect rect, bool isDynamic,
										float density /*= 0.0f */, float Restitution /*= 0.0f*/, float Friction /*= 0.0f*/,
										int ContactTestBitmask /*= 0x00000000*/, int CategoryBitmask /*= 0xffffffff*/, int CollisionBitmask /*= 0xffffffff*/ )
{
	auto material = cocos2d::PhysicsMaterial( density, Restitution, Friction );
	m_Body = cocos2d::PhysicsBody::createBox( rect.size, material );
	m_Body->setPositionOffset(rect.origin);
	m_Body->setContactTestBitmask( ContactTestBitmask );
	m_Body->setCategoryBitmask( CategoryBitmask );
	m_Body->setCollisionBitmask( CollisionBitmask );
	m_Body->setTag( (int)GET_COMP_PARENT()->getType() );
	m_Body->setDynamic( isDynamic );
	m_Body->setMass(10);
	m_Body->setRotationEnable(false);
	m_Body->setVelocityLimit(1000);
	m_Body->retain();
	GET_COMP_PARENT()->setPhysicsBody( m_Body );

	auto contactListener = cocos2d::EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(PhysicsComponent::onContactBegin, this);
	contactListener->onContactSeperate = CC_CALLBACK_1(PhysicsComponent::onContactSeparate, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener,this);
}

bool Arthas::PhysicsComponent::onContactBegin(cocos2d::PhysicsContact& contact)
{
	auto bodyA = contact.getShapeA()->getBody();
	auto bodyB = contact.getShapeB()->getBody();
	int tagA = bodyA->getTag();
	int tagB = bodyB->getTag();
	Direction dir = DIR_NONE;
	
	if (contact.getContactData()->normal.y > 0)
	{
		dir |= DIR_UP;
	}
	else if(contact.getContactData()->normal.y < 0)
	{
		dir |= DIR_DOWN;
	}

	if (contact.getContactData()->normal.x > 0)
	{
		dir |= DIR_RIGHT;
	}

	else if(contact.getContactData()->normal.x < 0)
	{
		dir |= DIR_LEFT;
	}

	//�����ؾ��ϴ� �浹�� ��� �����Ѵ�.
	PhysicsComponent* physicsA = (PhysicsComponent* )((Component*)bodyA->getNode())->getComponent(CT_PHYSICS);
	PhysicsComponent* physicsB = (PhysicsComponent*)((Component*)bodyB->getNode())->getComponent(CT_PHYSICS);

	if (physicsA->isIgnoreCollision((ComponentType)tagB, dir) ||
		physicsB->isIgnoreCollision((ComponentType)tagA, dir))
	{
		return false;
	}

	auto trigger = GET_TRIGGER_MANAGER()->createTrigger<PhysicsTrigger>();

	trigger->initTrigger((ComponentType)tagA, (ComponentType)tagB, dir, CTT_CONTACT);
	trigger->setContactData(*contact.getContactData());

	ObserverComponent* observer = (ObserverComponent*)GET_COMP_PARENT()->getComponent(CT_OBSERVER);

	if (observer != nullptr)
		observer->addTrigger(trigger);

	return true;
}

void Arthas::PhysicsComponent::onContactSeparate(cocos2d::PhysicsContact& contact)
{
	int tagA = contact.getShapeA()->getBody()->getTag();
	int tagB = contact.getShapeB()->getBody()->getTag();
	Direction dir = DIR_NONE;

	if (contact.getContactData()->normal.y > 0)
	{
		dir |= DIR_UP;
	}
	else
	{
		dir |= DIR_DOWN;
	}

	if (contact.getContactData()->normal.x > 0)
	{
		dir |= DIR_RIGHT;
	}
	else
	{
		dir |= DIR_LEFT;
	}

	auto trigger = GET_TRIGGER_MANAGER()->createTrigger<PhysicsTrigger>();

	trigger->initTrigger((ComponentType)tagA, (ComponentType)tagB, dir, CTT_SEPARATE);
	trigger->setContactData(*contact.getContactData());

	ObserverComponent* observer = (ObserverComponent*)GET_COMP_PARENT()->getComponent(CT_OBSERVER);

	if(observer!=nullptr)
		observer->addTrigger(trigger);
}

void Arthas::PhysicsComponent::addIgnoreCollision(ComponentType otherType, Direction collisionDir)
{
	m_IgnoreCollisions[otherType] = collisionDir;
}

bool Arthas::PhysicsComponent::isIgnoreCollision(ComponentType otherType, Direction collisionDir)
{
	if (m_IgnoreCollisions.find(otherType) != m_IgnoreCollisions.end())
	{
		if ((m_IgnoreCollisions[otherType] & collisionDir) != 0)
			return true;
	}

	return false;
}

void Arthas::PhysicsComponent::setEnabled(bool enable)
{
	if (enable == true)
	{
		GET_COMP_PARENT()->setPhysicsBody(m_Body);
	}
	else
	{
		GET_COMP_PARENT()->setPhysicsBody(nullptr);
		m_Body->removeFromWorld();
	}
}
