/************************************************************************/
/*
CLASS			: PathFinder
Author			: �迬��
����				: �������� - ��ǥ���� ��ֹ� �Ѿ �� ã���ִ� ��ƿŬ����
���� ��������	: 2014-12-12
���� ������		:
���� ��������	:
Comment			: ��ã�Ⱑ �ʿ��ϸ� Finder�� �����ϰ� 
				  initFinder�� �Ѵ�. �� ã���� true �� ã���� false �����ϹǷ� false�϶��� ��ã�� �����Ѵ�.
				  �׸��� getPath�� ã�� ��θ� ���´�. vector�����͸� �ѱ��.
				  �ٽ� ��ã�Ⱑ �ʿ��ϸ� ���� �ν��Ͻ��� initFinder�ؼ� ��ã�⸦ �ٽ� �� �� �ִ�.
				  ����)
				  if(initFinder(startX, startY, goalX, goalY)
				  {
					getPath(std::vector<cocos2d::Point>* pathes);
				  }
				
/************************************************************************/

#pragma once
#include "util.h"
#define MAX_WIDTH 10
#define MAX_HEIGHT 10

struct Tag
{
	int		m_X = -1;
	int		m_Y = -1;
	int		m_PastCost = 0;
	int		m_FutureCost = 0;

	int	totalCost()
	{
		return m_PastCost + m_FutureCost;
	}
};

class PathFinder
{
public:
	enum Dir
	{
		DIR_UP,
		DIR_DOWN,
		DIR_LEFT,
		DIR_RIGHT,
		DIR_MAX,
	};
	enum CheckResult
	{
		FAIL = 0x00,
		CHECKING = 0x01,
		FIND = 0x02,
	};
	class Compare
	{
	public:
		bool operator() (Tag a, Tag b)
		{
			return a.totalCost() > b.totalCost();
		}
	};

public:
	PathFinder();
	~PathFinder();

	bool			initFinder(int startX, int startY, int goalX, int goalY);
	void			getPath(std::vector<cocos2d::Point>* pathes);

private:
	int				checkPos(cocos2d::Point checkingPos, std::priority_queue<Tag, std::vector<Tag>, Compare>* openTags);
	cocos2d::Point	findNeighbor(int direction);
	bool			findWay(Tag nextCheckTag);

	cocos2d::Size				m_MapSize;
	cocos2d::Point				m_StartPos;
	cocos2d::Point				m_GoalPos;
	Tag							m_CurTag;
	std::vector<int>			m_Map;
	std::hash_map<int, int>		m_CostMap;
	std::stack<cocos2d::Point>	m_Path;

};

