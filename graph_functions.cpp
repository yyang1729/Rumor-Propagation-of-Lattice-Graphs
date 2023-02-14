#include "Graph.hpp"
#include <set>
#include <queue>

int[] Graph::findPivot(int[] shortest_path){
        int cur_small = shortest_path[shortest_path.size()-1];
        int[] toreturn = [];
        for(int i = shortest_path.size() - 2; i > 0, i--){
                if(shortest_path[i] < cur_small){
                        cur_small = shortest_path[i];
                        if(shortest_path[i-1] > cur_small) {
                                toreturn.push_back(i);
                        }
                }
        }
        return toreturn;
}

//currently implementing shortest path using the standard Dijkstra's Algorithm
int[] Graph::findShortestPath(int start, int end){
        int[] result = {};
        std::set MST;
        int n = edge_matrix.size();

        //array to make traceback easier
        int prev[n] = {0};

        //initialize a *tentative* distance array with default value infinity except for our starting vertex
        double distance[n] = {0}; //c initialization to 0
        //set to inf if not the start
        for(int i = 0; i < n; i++){
                prev[i] = -1;
                if(i == start) continue;
                distance[i] = INFINITY;
        }

        while(MST.size() < n){
                double min = INFINITY;
                int i = 0
                for(; i < n; i++){
                        if(distance[i] < min){
                                break;
                        }
                }

                MST.insert(i);

                for(int j = i - d; j <= i + d; j++){
                        if(!MST.count(j) && distance[i] + edge_matrix[i][j] < distance[j]){
                                distance[j] = distance[i] + edge_matrix[i][j];
                                prev[j] = i;
                        }
                }
        }

        int cur = end;
        if(distance[cur] == INFINITY){
                //something went wrong and graph was not connected
                return NULL;
        }
        
        int i = 0;
        while(cur != start){
                result[i] = prev[cur];
                cur = prev[cur];
                i++;
        }

        reverse(result, result + (sizeof(result)));


        return result;
}

double Graph::findDis(int[] pivots){
        double toreturn = 0.0;
        for(int i = 1; i <  pivots.size(); i++){
                toreturn += edge_matrix[pivots[i-1]][pivots[i]];
        }
        return toreturn;
}