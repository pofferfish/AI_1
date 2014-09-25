/*#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <list>
#include "DeliveryManClient.h"
#pragma comment (lib, "DeliveryManClient")

std::vector<std::vector<std::wstring>> nodes;
std::vector<std::vector<int>> edges;
/////////////////////////////////////////////

struct A_node{
int h;
int f;
}

std::vector<std::vector<A_node>> nodes_a(41,41);
std::list<Location> open;
std::list<Location> closed;


std::vector<Location> findPath(Location start, Location end){
std::vector<Location> instructions;
for(int x=0; x < 41;x++){
for(int y; y < 41; y++){
nodes_a[x][y].h = abs(start.second - x) + abs(start.first - y);
}
}

open.push_back(start);

while(!open.empty()){
Location current = open.pop_front();
//up
//right
//down
//right
}


return instructions;
}

*/
