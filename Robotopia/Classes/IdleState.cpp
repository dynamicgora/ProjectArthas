#include "IdleState.h"


bool Arthas::IdleState::init()
{
	if (!StateComponent::init())
	{
		return false;
	}




	return true;
}

void Arthas::IdleState::enter()
{
	//���� �� ����� �Ǵ°� sprite �ٲٴ� ����. 
	//m_Parent�ΰ��� ���� ������Ʈ�� ���� ���� ���ּ��� �ؾ߰ڳ�. 
}

void Arthas::IdleState::exit()
{
	//��������Ʈ �ִϸ��̼� ���°��� 
}

void Arthas::IdleState::update(int dTime)
{

}

