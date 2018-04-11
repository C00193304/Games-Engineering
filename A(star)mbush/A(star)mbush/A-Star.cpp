#include "A-Star.h"

void AStar::ucs(Node * pStart, Node * pDest, std::vector<Node*>& path)
{
	if (pStart != NULL)
	{
		for (int i = 0; i < m_nodeHolder.GetMaxNodes() - 1; i++)
		{
			m_nodeHolder.getNodes()[i]->SetCost(999999999999);
		}

		//priority queue checks heuristic cost to the total cost
		std::priority_queue<Node*, std::vector<Node*>, NodeSearchCostComparerUCS> priorityQ;
		pStart->SetCost(0.0f);
		//set the starting node to marked and push it to the Q
		priorityQ.push(pStart);
		pStart->SetMarked(true);
		while (priorityQ.size() != 0 && priorityQ.top() != pDest)
		{
			auto iter = priorityQ.top()->GetArcs().begin();
			auto endIter = priorityQ.top()->GetArcs().end();

			for (; iter != endIter; iter++)
			{
				float distC = priorityQ.top()->GeCost() + (*iter).getWeight();
				//add the weight of the top of the Q to the weight of the arc it is connecting to
				//and if its less than the nodes weight that it is connecting to
				if (distC < (*iter).getNode()->GeCost())
				{
					//set the node to the previous node
					(*iter).getNode()->SetCost(distC);
					(*iter).getNode()->SetPrevious(priorityQ.top());
				}
				if ((*iter).getNode()->GetMarked() == false)
				{
					//marks the node and add it to the queue 
					priorityQ.push((*iter).getNode());
					((*iter).getNode()->SetMarked(true));
				}
				if ((*iter).getNode() == pDest)
				{
					Node* tempDest = pDest;
					if (distC <= (*iter).getNode()->GeCost())
					{
						if (path.empty() != true)
						{
							path.clear();
						}
						while (tempDest != pStart)
						{
							path.push_back(tempDest);
							tempDest = tempDest->getPrevious();
							//moves back to the previous node until it reaches the initial node.

						}
						path.push_back(pStart);
					}
				}
			}
			priorityQ.pop();
		}
	}
	//reset
	for (int i = 0; i < m_nodeHolder.GetMaxNodes() - 1; i++)
	{
		m_nodeHolder.getNodes()[i]->SetMarked(false);
	}
}

AStar::AStar()
{
}

AStar::AStar(NodeHolder & nodes)
{
}

void AStar::calculatePath(Node * pStart, Node * pDest, std::vector<Node*>& path)
{
	if (pStart != NULL)
	{
		ucs(pStart, pDest, path);

		for (int i = 0; i < m_nodeHolder.GetMaxNodes() - 1; i++)
		{
			//using the cost it calculates the heuristic
			m_nodeHolder.getNodes()[i]->setHeuristic(m_nodeHolder.getNodes()[i]->GeCost() * 0.9);

			m_nodeHolder.getNodes()[i]->SetCost(999999999);
		}

		std::priority_queue<Node*, std::vector<Node*>, NodeSearchCostComparerAStar> priorityQ;

		pStart->SetCost(0);

		//push the starting node to the queue and set it as marked
		priorityQ.push(pStart);
		pStart->SetMarked(true);
		//if there are nodes in the queue and the destination is not the top 

		while (priorityQ.size() != 0 && priorityQ.top() != pDest)
		{
			//add all child nodes to the top of the queue
			//iterate through the list of arcs
			auto iter = priorityQ.top()->GetArcs().begin();
			auto endIter = priorityQ.top()->GetArcs().end();

			for (; iter != endIter; iter++) {
				//adds weight to the arc 
				float distC = priorityQ.top()->GeCost() + (*iter).getWeight();

				if (distC < (*iter).getNode()->GeCost()) {
					(*iter).getNode()->SetCost(distC);
					//sets current node to the previous node.
					(*iter).getNode()->SetPrevious(priorityQ.top());
				}

				if ((*iter).getNode()->GetMarked() == false) {
					//add node to the queue and mark it
					priorityQ.push((*iter).getNode());
					(*iter).getNode()->SetMarked(true);
				}

				if ((*iter).getNode() == pDest) {
					Node* temp = pDest;

					if (distC <= (*iter).getNode()->GeCost()) {
						if (path.empty() != true) {
							path.clear();
						}
						//returns to the previous node
						while (temp != pStart) {
							path.push_back(temp);
							temp = temp->getPrevious(); 
						}
						path.push_back(pStart);
					}
				}
			}

			priorityQ.pop();
		}
	}

//resets nodes
	for (int i = 0; i < m_nodeHolder.GetMaxNodes() - 1; i++)
	{
		m_nodeHolder.getNodes()[i]->SetMarked(false);
	}
}


class NodeSearchCostComparerAStar {
public:
	bool operator()(Node* n1, Node* n2) {
		return n1->GeCost() + n1->GetHeuristic() > n2->GeCost() + n2->GetHeuristic();
	}
};

class NodeSearchCostComparerUCS {
public:
	bool operator()(Node* n1, Node* n2) {
		return n1->GeCost() > n2->GeCost();
	}
};