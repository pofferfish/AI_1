//main

// Delivery.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include "DeliveryManClient.h"
#pragma comment (lib, "DeliveryManClient")

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
	std::wstring name = L"This will be our group name";
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

	for(int deliveryID=0;deliveryID<min(waitingDeliveries.size(),5);deliveryID++) {
		int lowestDistance = 100;
		int bestVanID = 0;
		for(int vanID=0;vanID<5;vanID++) {
			int thisDistance = dist(waitingDeliveries[deliveryID].pickUp,vans[vanID].location);
			if (thisDistance<lowestDistance) {
				lowestDistance = thisDistance;
				bestVanID = vanID;
			}
		}
	}

	while(true) {
		for(int j=0;j<40;j++) {
			waitingDeliveries.clear();
			activeDeliveries.clear();
			completedDeliveries.clear();
			client.getInformation(time, edges, vans, waitingDeliveries, activeDeliveries, completedDeliveries, informationOutput);
			std::wcout << L"Time: " << time << "\n";
			std::wcout << L"Cargo in van 0: " << vans[0].cargo << L"\n";
			std::wcout << L"Cargo in van 1: " << vans[1].cargo << L"\n";
			std::wcout << L"Cargo in van 2: " << vans[2].cargo << L"\n";
			std::wcout << L"Cargo in van 3: " << vans[3].cargo << L"\n";
			std::wcout << L"Cargo in van 4: " << vans[4].cargo << L"\n";

			std::wcout << L"Van 0 location: " << vans[0].location.first << ", " << vans[0].location.second << L"\n";
			std::wcout << L"Van 1 location: " << vans[1].location.first << ", " << vans[1].location.second << L"\n";
			std::wcout << L"Van 2 location: " << vans[2].location.first << ", " << vans[2].location.second << L"\n";
			std::wcout << L"Van 3 location: " << vans[3].location.first << ", " << vans[3].location.second << L"\n";
			std::wcout << L"Van 4 location: " << vans[4].location.first << ", " << vans[4].location.second << L"\n";

			std::wcout << L"Number of packages: " << waitingDeliveries.size() << L"\n";

			for(int i=0;i<waitingDeliveries.size();i++) {
				std::wcout << L"Package " << i << " location: " << waitingDeliveries[i].pickUp.first << ", " << waitingDeliveries[i].pickUp.second << L"\n";
			}

			sendPathway(0,vans[0].location,vans[1].location);
			client.sendInstructions(vanInstructions,uselessString);

		}
	}

	return 0;
}



	// --- Pseudocode ---
	// General comment: checks for stranded vans and vans that are
        // heading for the wrong destination might be done with shorter
        // or longer time intervals than indicated below.
	//
        // spread out cars (evenly?)
        //
	// getInformation->completedDeliveries
	// while(completedDeliveries.length < 20):
	//     (((Main loop)))
	//     activeDeliveries = getInformation->activeDeliveries
        //     for (van in getInformation->Vans):
        //
	//         if van.cargo != -1:
        //
        //             if (van.instructions.length() == 0):
        //                 (((This catches vans that are stranded and vans that
        //                    have just picked up a delivery)))
	//                 calculate route from van to dropoff point
        //                 sendInstructions to van
	//
	//             delivery = activeDeliveries(van.cargo)
	//             else if (delivery.dropOff != van.instructions.last()):
        //                 (((This catches vans that have accidently picked up
        //                    a delivery)))
        //                 calculate route from van to dropoff point
        //                 sendInstructions to van
	//
	//     for (delivery in getInformation->waitingDeliveries):
	//         for (van in getInformation->Vans):
	//             if (van.cargo == -1):
        //                 vanList.add(van, distance fr van to pickup point)
	//                 (((Or use something else than a list)))
        //         if (vanList.length == 0):
	//             break for-loop (or continue to next delivery, hoping that
        //                             some van becomes free?)
        //         else:
        //             calculate route from closest van to pickup point
        //             sendInstructions to closest van
        //


