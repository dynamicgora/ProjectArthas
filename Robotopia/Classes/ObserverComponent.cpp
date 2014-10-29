#include "ObserverComponent.h"

Arthas::ObserverComponent::~ObserverComponent()
{
	removeCurrentTrigger();
	for( auto trigger : m_NextTriggers )
	{
		if( trigger != nullptr )
		{
			delete trigger;
			trigger = nullptr;
		}
	}
	m_NextTriggers.clear();
}

bool Arthas::ObserverComponent::init()
{
	if( !Component::init())
	{
		return false;
	}
	m_Type = 0;
	return true;
}

void Arthas::ObserverComponent::update( float dTime )
{
	removeCurrentTrigger();
	m_Triggers.swap( m_NextTriggers );
}

void Arthas::ObserverComponent::enter()
{

}

void Arthas::ObserverComponent::exit()
{

}

void Arthas::ObserverComponent::addTrigger( Trigger* trigger )
{
	m_NextTriggers.push_back( trigger );
}

void Arthas::ObserverComponent::removeTrigger( Trigger* trigger )
{
	auto triggerIter = std::find( m_Triggers.begin() , m_Triggers.end() , trigger );
	delete trigger;
	m_Triggers.erase( triggerIter );
}

void Arthas::ObserverComponent::removeCurrentTrigger()
{
	for( auto trigger : m_Triggers )
	{
		if( trigger != nullptr )
		{
			delete trigger;
			trigger = nullptr;
		}
	}
	m_Triggers.clear();
}

std::vector<Arthas::Trigger*>& Arthas::ObserverComponent::getTriggers()
{
	return m_Triggers;
}


