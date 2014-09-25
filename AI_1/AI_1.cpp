#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <list>
#include <queue>
#include <set>
#include "DeliveryManClient.h"
#pragma comment (lib, "DeliveryManClient")


class Problem {
public:
	Problem(Location start, Location goal) {
		s = start;
		g = goal;
	}

	Location getStart() {
		return s;
	}

	Location getGoal() {
		return g;
	}

private:
	Location s;
	Location g;
}


class Node {
public:
	Node() {
		s = 0;
		pc = 0;
	}
	
	Node(Location state, int pathCost) {
		s = state;
		pc = pathCost;
	}
	
	bool operator() (const Node& n1, const Node& n2) {
		return n1.pc < n2.pc;
	}
	
	Location getState() {
		return s;
	}
	
	int getPathCost() {
		return pc;
	}

private:
	Location s;
	int pc;
};


std::vector<std::pair<int,int>> aStar(Problem problem) {
	Node startNode(problem.getStart(), 0);

	std::priority_queue<Node, std::vector<Node>, Node> frontier;
	frontier.push(startNode);

	std::set<Location> explored;

	while(true) {
		if (frontier.empty()) {
			return NULL;
		}
		
		Node node = frontier.top();
		frontier.pop();

		if (node.getState() == problem.getGoal()) {
			return solution(node); // TBI
		}

		explored.insert(node.getState);
		
		// Find children of node
		// Iterate over them
			// If the child is not in explored or frontier, insert the child into the frontier
			// Else if the child is in frontier with higher path cost, replace that node with the child
	}
}


std::map<int,std::vector<std::pair<int,int>>> vanInstructions;

int dist(Location start, Location end) {
	return ((start.first-end.first)+(start.second-end.second));
}

void sendPathway(int vanNumber, Location start, Location end) {
	std::map<int,std::vector<std::pair<int,int>>> retValue;
	std::vector<std::pair<int,int>> path;
	//int yDist = end.second - start.second;
	//if(yDist>0) {
	//}
	std::pair<int,int> trip;
	trip.first = start.first *2;
	trip.second = start.second;
	path.push_back(trip);
	path.reserve(1);
	vanInstructions[vanNumber]=path;
}

int _tmain(int argc, _TCHAR* argv[])
{
	std::wcout << L"Hello and welcome!\n";

	// Create client
	std::wstring name = L"Group1";
	bool OK;
	DM_Client client(name, OK);

	// Start game and print information
	std::vector<std::vector<std::wstring>> nodes;
	std::wstring startOutput;
	client.startGame(nodes, startOutput);
	std::wcout << L"Node type at (10,10): " << nodes[40][40] << L"\n";
	std::wcout << L"Output: " << startOutput << L"\n\n";

	// Get information about the environment state
	int time;
	std::vector<std::vector<int>> edges;
	std::vector<VanInfo> vans;
	std::vector<DeliveryInfo> waitingDeliveries;
	std::vector<DeliveryInfo> activeDeliveries;
	std::vector<std::pair<int,int>> completedDeliveries;
	std::wstring informationOutput;
	std::wstring uselessString;

	client.getInformation(time, edges, vans, waitingDeliveries, activeDeliveries, completedDeliveries, informationOutput);

	// spread out cars


	//main loop
	while(completedDeliveries.size() < 20){
		edges.clear();
		vans.clear();
		waitingDeliveries.clear();
		activeDeliveries.clear();
		completedDeliveries.clear();
		client.getInformation(time, edges, vans, waitingDeliveries, activeDeliveries, completedDeliveries, informationOutput);

		std::list<VanInfo> availableVans;
		for(int i = 0; i < vans.size(); i++){
			VanInfo currentVan = vans[i];
			if (currentVan.cargo != -1){									//vans that have a delivery
				DeliveryInfo  delivery = activeDeliveries[currentVan.cargo];
				if (currentVan.instructions.size() == 0){					//stranded vans and vans that just picked up a delivery
					//calculate route from van to dropoff point
					//sendInstructions to van
				}
				else if (delivery.dropOff != currentVan.instructions[currentVan.instructions.size()]){	//vans that have accidently picked up delivery
					//calculate route from van to dropoff point
					//sendInstructions to van
				}
			}
			else{
				availableVans.push_back(currentVan);	//add van to list of available vans
			}
		}

		int i = 0;
		while(!availableVans.empty() &&  i < waitingDeliveries.size()){
			//find closest van in available list
			//calculate route from closest van to pickup point
			//send Instructions to closest van
			i++;
		}
	}


	return 0;
}





