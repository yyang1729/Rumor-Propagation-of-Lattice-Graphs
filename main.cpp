#include "Graph.h"
#include <iostream>

int main(){
    std::cout<<"START"<<std::endl;
    Graph g = Graph(10,1,0,0,1);
    
    std::vector<int> path = g.findShortestPath(0,9);
    std::vector<int> nrp =  g.findNRP(path);
    for(int i :nrp){
        std::cout<<i<<std::endl;
    }
    return 0;
}