/************************************************************************/
/*
CLASS			: ToolSpriteEditLayer
Author			: �輺��
����				: ���ο� Sprite ���� Edit Box ���� �߰�
���� ��������		: 2014-11-08
���� ������		:
���� ��������		:
Comment			:
*/
/************************************************************************/
#pragma once
#include "cocos2d.h"
#include "cocos-ext.h"
#include "Util.h"
#include <vector>

BEGIN_NS_AT

class ToolSpriteEditLayer : public cocos2d::Layer, public cocos2d::extension::EditBoxDelegate
{
public:
	enum InfoOder
	{
		TYPE = 0,
		DELAY,
		FRAMENUM,
		FILENAME,
		SAVE,
	};

	OVERRIDE bool init();
	void		  createEditBox(const char* boxTitle, int fontSize, int maxLength, InfoOder tag);
	void		  setEditBox();
	void		  createAniNames(AnimationInfo* aniInfo);
	ResourceType  changeStringTypeToResourceType(const char* currentType);
	

	CREATE_FUNC(ToolSpriteEditLayer);
private:
	std::vector<cocos2d::extension::EditBox*> m_EditBoxs;
	const char*								  m_CurrentType;
	ResourceType							  m_CurrentTypeEnum;
	int										  m_CurrentDelay;
	int										  m_CurrentFrameNum;
	const char*								  m_CurrentFileName;

	

	//����Ʈ �ڽ� Ŭ���ϸ� ȣ���ϴ� �޼ҵ�
	OVERRIDE void editBoxEditingDidBegin(cocos2d::extension::EditBox* editBox);

	//����Ʈ �ڽ� �Է��� ����Ű�� �Է��ؼ� ������ �� ��µǴ� �޼ҵ�
	OVERRIDE void editBoxEditingDidEnd(cocos2d::extension::EditBox* editBox);

	//����Ʈ �ڽ��� Ŭ���� �� ���ڸ� �Է��� ������ ȣ��Ǵ� �޼ҵ�
	OVERRIDE void editBoxTextChanged(cocos2d::extension::EditBox* editBox, const std::string& text);

	//����Ű�� �Է��� �� ��µǴ� �޼ҵ�, �Ϲ������� ����Ű�� �Է��ϸ� editBoxEditingDidEnd()�� ȣ��ǰ�
	//editBoxReturn() �޼ҵ尡 �� �������� ȣ��˴ϴ�.
	OVERRIDE void editBoxReturn(cocos2d::extension::EditBox* editBox);
	

};

END_NS_AT