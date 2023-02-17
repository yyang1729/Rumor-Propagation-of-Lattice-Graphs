#include "Graph.h"
#include <iostream>
#include <fstream>
#include <string>
int main(){
    Graph g = Graph(10,1,0,0,1);
    for(int u = 0; u < 100; u++){
        g.reassign_edge(10,1,0,0,1);
        
        std::vector<int> path = g.findShortestPath(1,9);
        std::string path_str = "";
        for(int i : path){
            path_str += std::to_string(i) + ",";
        }
        std::vector<int> nrp =  g.findNRP(path);
        std::string nrp_str = "";
        for(int i : nrp){
            nrp_str += std::to_string(i) + ",";
        }        
        std::ofstream pathfile;
        pathfile.open("path.csv");
        pathfile << path_str;
        pathfile.close;

        std::ofstream nrpfile;
        nrpfile.open("path.csv");
        nrpfile << nrp_str;
        nrpfile.close;
    }


}