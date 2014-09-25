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

	return path;
}





