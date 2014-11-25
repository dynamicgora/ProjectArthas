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



class BaseComponent;
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
T* ComponentManager::createComponent()
{
	//BaseComponent���� �´��� Ȯ���ϴ� �ڵ�
	BaseComponent* newComponent = T::create();

	///�̷� �뵵�δ� is_base_of ���.

	return (T*)newComponent;
	//���߿� �޸� Ǯ�����ϴ� �ڵ� �߰�
}

