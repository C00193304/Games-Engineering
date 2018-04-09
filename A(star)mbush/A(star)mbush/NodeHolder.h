#pragma once
#include <queue>
#include "stdafx.h"
#include "Arcs.h"
#include "Node.h"

class NodeHolder
{
public:
	NodeHolder() {};

	void AddNode(SDL_Point position, std::string tag);
	void SetNodes(int num);
	int GetMaxNodes() { return m_nodes.size(); };

	void draw(SDL_Renderer *renderer);
	void AddArcs();

	std::vector<Node*> getNodes() { return m_nodes; };

private:
	std::vector<Node*> m_nodes;
	int m_nodesPerLine;
};