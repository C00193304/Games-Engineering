#pragma once

#include "NodeHolder.h"
#include "Player.h"
#include <queue>

class AStar {
public:
	AStar();
	void update();
	void calculatePath(Node* pDest, std::vector<Node*>& path);
	NodeHolder* getLayout();
	void addPlayer(Player* player);
	bool getChangedNode();

private:
	NodeHolder * m_nodeHolder;
	Player* m_player;
	Node* m_start;
	int m_nodeNearPlayer;
	bool m_changedNode;

	void ucs(Node* pStart, Node* pDest, std::vector<Node*>& path);

	float magnitude(SDL_Point p1, SDL_Point p2);
};