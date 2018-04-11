#pragma once
#include "Node.h"
#include "NodeHolder.h"
#include <queue>

class AStar
{
public:
	AStar();
	AStar(NodeHolder &nodes);

	void calculatePath(Node* pStart, Node*pDest, std::vector<Node*>& path);
	NodeHolder getLayout() { return m_nodeHolder; };
private:
	NodeHolder m_nodeHolder;
	void ucs(Node* pStart, Node* pDest, std::vector<Node*>& path);


};

