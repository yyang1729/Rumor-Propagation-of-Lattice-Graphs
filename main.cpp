#include "Graph.h"
#include <iostream>

int main(){
    int N = 10;
    int d = 2;
    int rtype = 0;
    double ri1 = 0.0;
    double ri2 = 1.0;
    int ITERATIONS = 100;

    Graph g = Graph(N, d, rtype, ri1, ri2);
    for(int i = 0; i < ITERATIONS; i++){
        g.reassign_edge(rtype, ri1, ri2);
        pair<vector<int>, double> path = g.findShortestPath(0, 9);
        for(int j = 0; j < path.first.size(); j++){
            printf("%d ", path.first[j]);
        }
        printf("\n%f\n", path.second);
        
        std::vector<int> nrp = g.findNRP(path.first);
        for(int j = 0; j < nrp.size(); j++){
            printf("%d ", nrp[j]);
        }
        std::cout << std::endl;
    }

/*
    std::cout<<"START"<<std::endl;
    Graph g = Graph(N, d, rtype, ri1, ri2);
    std::cout<<"GRAPH INITIALIZED"<<std::endl;

    g.print_graph();

    pair<std::vector<int>, double> path = g.findShortestPath(0,9);
    std::cout<<"Find Path"<<std::endl;

    for(int i = 0; i < N; i++){
        printf("%d ", path.first[i]);
    }
    std::cout << std::endl;
    printf("%f\n", path.second);
    

    std::vector<int> nrp =  g.findNRP(path.first);
    std::cout<<"Find NRP"<<std::endl;
    for(int i :nrp){
        std::cout<<i<<std::endl;
    }
    std::cout<<"END"<<std::endl;

*/
    return 0;
}