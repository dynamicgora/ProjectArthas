/************************************************************************/
/*
CLASS			: Trigger
Author			: �迬��
����				: Ʈ���ŵ��� �ֻ��� Ŭ����.
���� ��������	: 2014-10-29
���� ������		: ������
���� ��������	: BaseComponent ��� �޴� ���� ������ �����ϱ� ���� �� �մϴ�.
Comment			: ���� ���� - == �տ� ���� ���� ���ǿ� �ش��ϴ� trigger�� �ڿ� ���� ���� ���� �߻��� trigger�Դϴ�. 
					A == B�� B == A �� �ٸ� �� �ֱ� ������ �� ���� �����ؼ� �ڵ� �ۼ� ���.
*/
/************************************************************************/
#pragma once
#include "Util.h"



class Trigger
{
public:
	Trigger();
	~Trigger();

	int getType() const;
	bool isEqualTypeTrigger(const Trigger& enemy);
	virtual bool operator ==( const Trigger& trigger ) = 0;
protected:
	TriggerType m_Type;
};

