#include "Graph.h"
#include <set>
#include <queue>

Graph::Graph(int num_verticies, int d, int random_type, double random_index_1, double random_index_2) {
        d_ = d;
    edge_matrix.resize(num_verticies);
    for (int i = 0; i < edge_matrix.size(); i++) {
        edge_matrix[i].resize(num_verticies);
    }

    // This method is O(d*n), which is much faster than the current method. However, it does not default 
    // the non-existing edges. If our future algorithm can ignore this problem, we can switch to this
    for (int i = 0; i < num_verticies; i++) {
        for (int j = 1; j <= d; j++) {
            if (i - j >= 0) {
                edge_matrix[i][i - j] = random_num_gen(random_type, random_index_1, random_index_2);
                edge_matrix[i - j][i] = edge_matrix[i][i - j];
            }
        }
    }

    // This method is O(n^2). The non-existing edge is set to -1
    // If the value is -2, something wrong happened with random variable
//     for (int i = 0; i < num_verticies; i++) {
//         for (int j = 0; j < num_verticies; j++) {
//             if (std::abs(i - j) <= d && i != j) {
//                 edge_matrix[i][j] = random_num_gen(random_type, random_index_1, random_index_2);
//             } else {
//                 edge_matrix[i][j] = -1;
//             }
//         }
//     }
}

void Graph::reassign_edge(int random_type, double random_index_1, double random_index_2) {
    // I'm writing the O(n^2) method here
//     for (int i = 0; i < edge_matrix.size(); i++) {
//         for (int j = 0; j < edge_matrix.size(); j++) {
//             if (edge_matrix[i][j] != -1) edge_matrix[i][j] = random_num_gen(random_type, random_index_1, random_index_2);
//         }
//     }
        for (int i = 0; i < edge_matrix.size(); i++) {
                for (int j = 1; j <= d_; j++) {
                        if (i - j >= 0) {
                                edge_matrix[i][i - j] = random_num_gen(random_type, random_index_1, random_index_2);
                                edge_matrix[i - j][i] = edge_matrix[i][i - j];
                        }
                }
        }
}

double Graph::random_num_gen(int random_type, double random_index_1, double random_index_2) {
    std::random_device rd;
    std::mt19937 gen(rd());
    if (random_type == 0) {
        // uniform distribution
        std::uniform_real_distribution<> distribution(random_index_1, random_index_2);
        return distribution(gen);
    } else if (random_type == 1) {
        // normal distribution
        std::normal_distribution<> distribution(random_index_1, random_index_2);
        return distribution(gen);
    } else if (random_type == 2) {
        // exponential distribution
        std::exponential_distribution<> distribution(random_index_1);
        return distribution(gen);
    } else if (random_type == 3) {
        // binomial distribution
        std::binomial_distribution<> distribution(random_index_1, random_index_2);
        return distribution(gen);
    }
    return -2;
}


int * Graph::findPivot(int shortest_path[]){
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