#pragma once
#include "Node.h"
#include "NodeHolder.h"
#include <queue>

class AStar
{
public:
	AStar();
	void update();

	void calculatePath(Node*pDest, std::vector<Node*>& path);
	NodeHolder getLayout() { return m_nodeHolder; };


private:
	Node* m_start;
	Player* m_player;
	int m_playerNode;
	void ucs(Node* pStart, Node* pDest, std::vector<Node*>& path);
	NodeHolder m_nodeHolder;
};

