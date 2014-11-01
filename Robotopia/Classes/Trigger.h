/************************************************************************/
/*
CLASS			: Trigger
Author			: �迬��
����				: Ʈ���ŵ��� �ֻ��� Ŭ����.
���� ��������	: 2014-10-29
���� ������		: ������
���� ��������	: Component ��� �޴� ���� ������ �����ϱ� ���� �� �մϴ�.
Comment			: ���� ���� - == �տ� ���� ���� ���ǿ� �ش��ϴ� trigger�� �ڿ� ���� ���� ���� �߻��� trigger�Դϴ�. 
					A == B�� B == A �� �ٸ� �� �ֱ� ������ �� ���� �����ؼ� �ڵ� �ۼ� ���.
*/
/************************************************************************/
#pragma once
#include "Util.h"

BEGIN_NS_AT

class Trigger
{
public:
	Trigger();
	~Trigger();

	int getType() const;
	bool isEqualTypeTrigger(const Trigger& enemy);
	void autoRelease();
	virtual bool operator ==( Trigger& trigger ) = 0;
protected:
	TriggerType m_Type;
	bool		m_IsAutoRelease;
};

END_NS_AT