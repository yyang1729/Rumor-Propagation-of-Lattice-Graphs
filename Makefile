graph: Graph.cpp main.cpp
	g++ main.cpp Graph.cpp -o graph
data: Graph.cpp generate_main.cpp
	g++ generate_main.cpp Graph.cpp -o graph