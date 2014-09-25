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