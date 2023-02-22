#include "Graph.h"
#include <iostream>
#include <fstream>
#include <string>
int main(){
    int num_of_simu = 100;
    for(int x = 1000; x < 2500; x+=500){
        for(int y=x/10; y<=x; y+=(x/10)){
            Graph g = Graph(x,y,0,0,1);
            std::string name = "_N_" + std::to_string(x) + "_D_"+std::to_string(y);
            std::ofstream pathseqfile;
            std::string pathseqname = "./data/path_seq"+name+".csv";
            pathseqfile.open(pathseqname);
            std::ofstream pathfile;
            std::string pathname = "./data/path"+name+".csv";
            pathfile.open(pathname);
            std::ofstream nrpfile;
            std::string nrpname = "./data/nrp"+name+".csv";
            nrpfile.open(nrpname);
            for(int u = 0; u < num_of_simu; u++){
                g.reassign_edge(0,0,1);
                //std::cout<<name+" "+std::to_string(u)+" time"<<std::endl;
                pair<vector<int>, double> path_result = g.findShortestPath(1,x-1);
                vector<int> path = path_result.first;
                std::string path_str = "";
                for(int i : path){
                    path_str += std::to_string(i) + ",";
                }
                path_str += "\n";
                std::vector<int> nrp =  g.findNRP(path);
                std::string nrp_str = "";
                for(int i : nrp){
                    nrp_str += std::to_string(i) + ",";
                }      
                nrp_str += "\n";  

                pathseqfile << path_str;
                pathfile << std::to_string(path_result.second)+"\n";
                nrpfile << nrp_str;
            }
            pathseqfile.close();
            pathfile.close();
            nrpfile.close();
        }
    }
    return 0;
}