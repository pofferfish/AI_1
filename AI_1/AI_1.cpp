#include "stdafx.h"
#include <iostream>
#include "DeliveryManClient.h"
#pragma comment (lib, "DeliveryManClient")

int _tmain(int argc, _TCHAR* argv[]){
	std::wcout << L"Hello and welcome!\n";

	// Create client
	std::wstring name = L"One";
	bool OK;
	DM_Client client(name, OK);

	// Start game and print information
	std::vector<std::vector<std::wstring>> nodes;
	std::wstring startOutput;
	client.startGame(nodes, startOutput);
	std::wcout << L"Node type at (0, 0): " << nodes[0][0] << L"\n";
	std::wcout << L"Output: " << startOutput << L"\n\n";

	// Get information about the environment state
	int time;
	std::vector<std::vector<int>> edges;
	std::vector<VanInfo> vans;
	std::vector<DeliveryInfo> waitingDeliveries;
	std::vector<DeliveryInfo> activeDeliveries;
	std::vector<std::pair<int,int>> completedDeliveries;
	std::wstring informationOutput;
	client.getInformation(time, edges, vans, waitingDeliveries, activeDeliveries, completedDeliveries, informationOutput);

	while(completedDeliveries.size() < 20){
		//deliver stuff
	}


	return 0;
}


//returns shortest path of edges from node1 to node 2
std::vector<Location> edgePath(Location node1, Location node2, std::vector<std::vector<int>> edges){
	std::vector<Location> path;

	//create grid
	


	//use manhattan formula for calculating heuristics for all points
	//Loop through using open/close list (open list ordered after size) and put in parent, heuristic+movement cost



	return path;
}

//returns the edge between node1 and node2
Location nodesToEdge(Location node1, Location node2){
	int y1 = node1.first;
	int x1 = node1.second;
	int y2 = node2.first;
	int x2 = node2.second;

	Location edge;

	if(y1==y2){
		edge.first = 2*y1; 
		edge.second = std::min(x1,x2);
	}
	else if(x1==x2){
		edge.first = y1+y2;
		edge.second = x1;
	}
	else{
		//nodes not adjecent
	}
	return edge;
}

//makes a path of nodes into a path of edges
std::vector<Location> nodeToEdgePath(std::vector<Location> nodes){
	int length = nodes.size() - 1;
	std::vector<Location> edges;
	for(int i = 0; i < length; i++){
		edges[i] = nodesToEdge(nodes[i],nodes[i+1]); 
	}
	return edges;
}



