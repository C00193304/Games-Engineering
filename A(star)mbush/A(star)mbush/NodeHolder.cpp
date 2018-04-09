#include "NodeHolder.h"

void NodeHolder::AddNode(SDL_Point position, std::string tag)
{
	m_nodes.push_back(new Node(position, tag));
}

void NodeHolder::SetNodes(int num)
{
	m_nodesPerLine = num;
}

void NodeHolder::draw(SDL_Renderer * renderer)
{
	for (int i = 0; i < m_nodes.size(); i++)
	{
		m_nodes.at(i)->draw(renderer);
	}
}

void NodeHolder::AddArcs()
{
	int column = 1;
	for (int i = 0; i < m_nodes.size(); i++)
	{
		if (i == m_nodesPerLine * column)
		{
			column++;
		}
		//if nodes is less than the max node
		if (i + m_nodesPerLine < m_nodes.size())
		{
			m_nodes.at(i)->AddArc(m_nodes.at(i + m_nodesPerLine));
			m_nodes.at(i + m_nodesPerLine)->AddArc(m_nodes.at(i));
		}

		if (i + 1 < m_nodes.size())
		{
			if (i < (m_nodesPerLine * column) - 1)
			{
				m_nodes.at(i)->AddArc(m_nodes.at(i + 1));
				m_nodes.at(i + 1)->AddArc(m_nodes.at(i));
			}
		}

	}
}
