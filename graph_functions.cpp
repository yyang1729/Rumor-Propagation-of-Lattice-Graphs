#include "Graph.hpp"

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


double Graph::findDis(int[] pivots){
        double toreturn = 0.0;
        for(int i = 1; i <  pivots.size(); i++){
                toreturn += edge_matrix[pivots[i-1]][pivots[i]];
        }
        return toreturn;
}