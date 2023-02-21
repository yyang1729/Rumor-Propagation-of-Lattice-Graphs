#include "Graph.h"
#include <iostream>

int main(){
    int N = 10;
    int d = 2;
    int rtype = 0;
    double ri1 = 0.0;
    double ri2 = 1.0;

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
    std::cout<<"Find NPR"<<std::endl;
    for(int i :nrp){
        std::cout<<i<<std::endl;
    }
    std::cout<<"END"<<std::endl;
    return 0;
}