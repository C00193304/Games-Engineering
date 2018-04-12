#include "A-Star.h"

AStar::AStar() {
	m_nodeHolder = new NodeHolder;
	m_changedNode = false;
}

void AStar::update()
{
	if (m_changedNode == true) 
	{
		m_changedNode = false;
	}
	int indexClosestToPlayer = 0;
	float closestDistPlayer = 99999;

	for (int i = 0; i < m_nodeHolder->GetMaxNodes(); i++) 
	{
		float distPlayer = magnitude(m_nodeHolder->getNodes().at(i)->GetPosition(), m_player->GetPosition());

		if (distPlayer < closestDistPlayer) 
		{
			closestDistPlayer = distPlayer;
			indexClosestToPlayer = i;
		}
	}

	if (m_nodeHolder->getNodes().at(m_nodeNearPlayer) != m_start) {
		m_start = m_nodeHolder->getNodes().at(m_nodeNearPlayer);
		m_changedNode = true;
	}
}

void AStar::calculatePath(Node *dest, std::vector<Node*>& path) 
{
	if (m_start == NULL) 
	{
		m_start = m_nodeHolder->getNodes().at(0);
	}

	if (m_start != NULL) 
	{
		ucs(dest, m_start, path);

		for (int i = 0; i < m_nodeHolder->GetMaxNodes() - 1; i++) 
		{
			m_nodeHolder->getNodes()[i]->setHeuristic(m_nodeHolder->getNodes()[i]->GeCost() * 0.9);
			m_nodeHolder->getNodes()[i]->SetCost(99999);
		}

		std::priority_queue<Node*, std::vector<Node*>, NodeSearchCostComparerAStar> priorityQueue;

		m_start->SetCost(0);
		m_start->SetMarked(true);

		priorityQueue.push(m_start);

		while (priorityQueue.size() != 0 && priorityQueue.top() != dest)
		{
			auto iter = priorityQueue.top()->GetArcs().begin();
			auto endIter = priorityQueue.top()->GetArcs().end();

			for (; iter != endIter; iter++)
			{
				float distC = priorityQueue.top()->GeCost() + (*iter).getWeight();

				if (distC < (*iter).getNode()->GeCost()) 
				{
					(*iter).getNode()->SetCost(distC);
					(*iter).getNode()->SetPrevious(priorityQueue.top());
				}

				if ((*iter).getNode()->GetMarked() == false) 
				{
					priorityQueue.push((*iter).getNode());
					(*iter).getNode()->SetMarked(true);
				}

				if ((*iter).getNode() == dest) 
				{
					Node* temp = dest;

					if (distC <= (*iter).getNode()->GeCost()) 
					{
						if (path.empty() != true)
						{
							path.clear();
						}

						while (temp != m_start) 
						{
							path.push_back(temp);
							temp = temp->getPrevious();
						}
						path.push_back(m_start);
					}
				}
			}

			priorityQueue.pop(); // occasionally throws exception in debug
		}
	}

	for (int i = 0; i < m_nodeHolder->GetMaxNodes() - 1; i++)
	{
		m_nodeHolder->getNodes()[i]->SetMarked(false);
	}
}

void AStar::ucs(Node *start, Node *dest, std::vector<Node*>& path)
{
	if (start != NULL) 
	{
		for (int i = 0; i < m_nodeHolder->GetMaxNodes() - 1; i++) 
		{
			m_nodeHolder->getNodes()[i]->SetCost(99999);
		}

		std::priority_queue<Node*, std::vector<Node*>, NodeSearchCostComparerUCS> priorityQueue;

		start->SetCost(0);
		start->SetMarked(true);

		priorityQueue.push(start);

		while (priorityQueue.size() != 0 && priorityQueue.top() != dest) 
		{
			auto iter = priorityQueue.top()->GetArcs().begin();
			auto endIter = priorityQueue.top()->GetArcs().end();

			for (; iter != endIter; iter++) {
				float distC = priorityQueue.top()->GeCost() + (*iter).getWeight();

				if (distC < (*iter).getNode()->GeCost()) {
					(*iter).getNode()->SetCost(distC);
					(*iter).getNode()->SetPrevious(priorityQueue.top());
				}

				if ((*iter).getNode()->GetMarked() == false) 
				{
					priorityQueue.push((*iter).getNode());
					(*iter).getNode()->SetMarked(true);
				}

				if ((*iter).getNode() == dest) 
				{
					Node* temp = dest;

					if (distC <= (*iter).getNode()->GeCost()) 
					{
						if (path.empty() != true) 
						{
							path.clear();
						}

						while (temp != start) 
						{
							path.push_back(temp);
							temp = temp->getPrevious();
						}
						path.push_back(start);
					}
				}
			}
			priorityQueue.pop();
		}
	}

	for (int i = 0; i < m_nodeHolder->GetMaxNodes() - 1; i++) 
	{
		m_nodeHolder->getNodes()[i]->SetMarked(false);
	}
}

float AStar::magnitude(SDL_Point p1, SDL_Point p2)
{
	return 0.0f;
}

NodeHolder* AStar::getLayout() 
{
	return m_nodeHolder;
}

void AStar::addPlayer(Player *player) 
{
	m_player = player;
}

bool AStar::getChangedNode()
{
	return m_changedNode;
}

class NodeSearchCostComparerAStar 
{
public:
	bool operator()(Node* n1, Node* n2) 
	{
		return n1->GeCost() + n1->GetHeuristic() > n2->GeCost() + n2->GetHeuristic();
	}
};

class NodeSearchCostComparerUCS 
{
public:
	bool operator()(Node* n1, Node* n2) 
	{
		return n1->GeCost() > n2->GeCost();
	}
};