#include "Graph.h"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <cmath>

int main(){
    int num_of_simu = 900;
    int x=0;
    int y=0;
    //std::cout<<"start"<<std::endl;
    for(int s = 0; s < 1; s++){
        if(s == 0){ 
            x = 5000;
        } else if (s == 1){
            x = 2000;
        } else if (s == 2){
            x = 2000;
        } else {
            x = 5000;
        }
        //std::cout<<x<<std::endl;
        for(int t=0; t<1; t++){
            if(t == 0){
                y = 5;
            } else if (t == 1){
                y = x/10;
            } else if (t == 2){
                y = std::pow(x, 0.46);
            } else if (t == 3){
                y = std::pow(x, 0.48);
            } else {
                y = x/5;
            }
            //y = t;
            //if (y > x) {
            //    std::cout<<"Overflow y greater than x"<<std::endl;
            //}
            //std::cout<<y<<std::endl;
            Graph g = Graph(x,y,0,0,1);  
            //std::cout<<"g"<<std::endl;          
            std::string name = "_N_" + std::to_string(x) + "_D_"+std::to_string(y);
            std::ofstream pathseqfile;
            std::string pathseqname = "./Apexdata/path_seq"+name+".csv";
            pathseqfile.open(pathseqname);
            std::ofstream pathfile;
            std::string pathname = "./Apexdata/path"+name+".csv";
            pathfile.open(pathname);
            std::ofstream nrpfile;
            std::string nrpname = "./Apexdata/nrp"+name+".csv";
            nrpfile.open(nrpname);
            for(int u = 0; u < num_of_simu; u++){
                g.reassign_edge(0,0,1);
                std::cout<<name+" "+std::to_string(u)+" time"<<std::endl;
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
            // pathseqfile.close();
            // pathfile.close();
            nrpfile.close();
        }
    }
    return 0;
}