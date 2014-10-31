/************************************************************************/
/*
	CLASS			: ComponentManager
	Author			: �迬��
	����				: ���� ������Ʈ�� �������ִ� �Ŵ���.
	���� ��������	: 2014-10-31
	���� ������		:
	���� ��������	:
	Comment			: ������Ʈ ������� Class* newComp = createComponent<Class>();
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
	T* createComponent();

private:
};

template<class T>
T* Arthas::ComponentManager::createComponent()
{
	//Component���� �´��� Ȯ���ϴ� �ڵ�
	Component* newComponent = T::create();
	return (T*)newComponent;
	//���߿� �޸� Ǯ�����ϴ� �ڵ� �߰�
}

END_NS_AT