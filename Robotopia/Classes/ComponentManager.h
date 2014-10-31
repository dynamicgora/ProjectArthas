/************************************************************************/
/*
	CLASS			: ComponentManager
	Author			: �迬��
	����				: ���� ������Ʈ�� �������ִ� �Ŵ���.
	���� ��������	: 2014-10-31
	���� ������		:
	���� ��������	:
	Comment			: ������Ʈ ������� Component* newComp = createComponent<Class>();
*/
/************************************************************************/

#pragma once
#include "Util.h"

BEGIN_NS_AT

class Component;
class ComponentManager
{
public:
	ComponentManager();
	~ComponentManager();

	bool init();

	template<class T>
	Component* createComponent();

private:
};

template<class T>
Component* Arthas::ComponentManager::createComponent()
{
	Component* newComponent = T::create();
	return newComponent;
}

END_NS_AT