#include "Graph.h"
#include <iostream>

int main(){
    std::cout<<"START"<<std::endl;
    Graph g = Graph(10,1,0,0,1);
    std::cout<<"GRAPH INITIALIZED"<<std::endl;
    std::vector<int> path = g.findShortestPath(1,9);
    std::cout<<"Find Path"<<std::endl;
    std::vector<int> nrp =  g.findNRP(path);
    std::cout<<"Find NPR"<<std::endl;
    for(int i :nrp){
        std::cout<<i<<std::endl;
    }
    std::cout<<"END"<<std::endl;
    return 0;
}