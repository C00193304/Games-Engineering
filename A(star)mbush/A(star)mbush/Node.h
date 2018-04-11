#pragma once
#include "stdafx.h"
#include "Arcs.h"
#include <list>
#include <queue>

class Node
{

private:
	SDL_Point m_position;
	Node* m_previousN;
	std::list<Arc> m_arcs;

	bool m_marked;

	float m_cost;
	float m_heuristic;

	std::string m_tag;

public:
	Node() {};
	Node(SDL_Point position, std::string tag);
	void AddArc(Node *n);

	SDL_Point GetPosition() { return m_position; };

	std::string GetTag() { return m_tag; };

	void SetMarked(bool marked);
	bool GetMarked() { return m_marked; };

	void SetPrevious(Node *previousN);
	Node* getPrevious() { return m_previousN; };

	float GetHeuristic() { return m_heuristic; };
	void setHeuristic(float heuristic);

	void SetCost(float cost);
	float GeCost() { return m_cost; };

	std::list<Arc>& GetArcs() { return m_arcs; };
	void draw(SDL_Renderer *renderer);
};