#pragma once
#include "stdafx.h"

class Node;
class Arc
{
public:
	Arc() {}
	void setNode(Node *n);
	Node* getNode() { return m_node; };
	void setWeight(float weight);
	float getWeight() { return m_weight; };

private:
	Node* m_node;
	int m_weight;
};