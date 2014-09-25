//Martins kod

// Delivery.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"

#include <queue>
#include <set>
#include <iostream>

// #include "DeliveryManClient.h"
// #pragma comment (lib, "DeliveryManClient")


class Node {
public:
  Node(int state, int pathCost) {
    s = state;
    pc = pathCost;
  }
  
  bool operator() (const Node& n1, const Node& n2) {
    return n1.pc < n2.pc;
  }
  
  int getState() {
    return s;
  }
  
  int getPathCost() {
    return pc;
  }
  
//  int s;
//  int pc;

private:
  int s;
  int pc;
};


int main(int argc, char *argv[]) {
	/*std::wcout << L"Hello and welcome!\n";

	std::priority_queue<Node, std::set<Node>, Node> nodeQueue;
	int j = 4;
	for (int i = 0; i < 10; i++) {
	  Node node(i, j);
	  nodeQueue.push(node);
	  j = j * -2;
	}
	
	while (!nodeQueue.empty()) {
	  Node outNode;
	  outNode = nodeQueue.pop();
	  std::wcout << L"Path cost: " << outNode.getPathCost() << L"\n" << L"State: " << outNode.getState() << L"\n\n";
	}
	*/return 0;
}