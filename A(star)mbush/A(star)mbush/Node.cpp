#include "Node.h"

Node::Node(SDL_Point position, std::string tag)
{
	m_position = position;
	m_tag = tag;
}

void Node::AddArc(Node *n)
{
	Arc arc;
	arc.setNode(n);
	if (n->GetTag() == "wall")
	{
		arc.setWeight(100);
	}
	else if (n->GetTag() == "ground")
	{
		arc.setWeight(1);
	}
	m_arcs.push_back(arc);
}

void Node::SetMarked(bool marked)
{
	m_marked = marked;
}

void Node::SetPrevious(Node * previousN)
{
	m_previousN = previousN;
}

void Node::SetCost(float cost)
{
	m_cost = cost;
}

void Node::draw(SDL_Renderer * renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderDrawPoint(renderer, m_position.x, m_position.y);
	SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
	for (std::list<Arc>::iterator i = m_arcs.begin(); i != m_arcs.end(); i++)
	{
		SDL_RenderDrawLine(renderer, m_position.x, m_position.y, (*i).getNode()->GetPosition().x, (*i).getNode()->GetPosition().y);
	}
}

