#include "PhysicsComponent.h"
#include "GameManager.h"
#include "TriggerManager.h"
#include "ContactTrigger.h"
#include "SeparateTrigger.h"
#include "ObserverComponent.h"

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
	m_Body->setContactTestBitmask( ContactTestBitmask );
	m_Body->setCategoryBitmask( CategoryBitmask );
	m_Body->setCollisionBitmask( CollisionBitmask );
	m_Body->setTag( (int)m_Parent->getType() );
	m_Body->setDynamic( isDynamic );
	m_Body->setPositionOffset(cocos2d::Point(rect.size.width/2, rect.size.height/2));
	m_Parent->setPhysicsBody( m_Body );

	auto contactListener = cocos2d::EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(PhysicsComponent::onContactBegin, this);
	contactListener->onContactSeperate = CC_CALLBACK_1(PhysicsComponent::onContactSeparate, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener,this);
}

bool Arthas::PhysicsComponent::onContactBegin(cocos2d::PhysicsContact& contact)
{
	int tagA = contact.getShapeA()->getBody()->getTag();
	int tagB = contact.getShapeB()->getBody()->getTag();
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

	auto trigger = GET_TRIGGER_MANAGER()->createTrigger<ContactTrigger>();

	trigger->initContactingComponents((ComponentType)tagA, (ComponentType)tagB, dir);

	ObserverComponent* observer = (ObserverComponent*)m_Parent->getComponent(CT_OBSERVER);

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

	auto trigger = GET_TRIGGER_MANAGER()->createTrigger<SeparateTrigger>();

	trigger->initSeparatingComponents((ComponentType)tagA, (ComponentType)tagB, dir);

	ObserverComponent* observer = (ObserverComponent*)m_Parent->getComponent(CT_OBSERVER);

	if(observer!=nullptr)
		observer->addTrigger(trigger);
}

