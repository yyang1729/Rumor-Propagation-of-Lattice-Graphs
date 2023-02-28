#include "Graph.h"
#include <set>
#include <queue>
#include <algorithm>
#include <iostream>

Graph::Graph(int num_verticies, int d, int random_type, double random_index_1, double random_index_2)
{
        d_ = d;
        edge_matrix.resize(num_verticies);
        for (int i = 0; i < edge_matrix.size(); i++)
        {
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
        // for (int i = 0; i < num_verticies; i++)
        // {
        //         for (int j = 0; j < num_verticies; j++)
        //         {
        //                 if (std::abs(i - j) <= d && i != j)
        //                 {
        //                         edge_matrix[i][j] = random_num_gen(random_type, random_index_1, random_index_2);
        //                 }
        //                 else
        //                 {
        //                         edge_matrix[i][j] = -1;
        //                 }
        //         }
        // }
}

void Graph::reassign_edge(int random_type, double random_index_1, double random_index_2)
{
        // I'm writing the O(n*d) method here
        for (int i = 0; i < edge_matrix.size(); i++) {
                for (int j = 1; j <= d_; j++) {
                        if (i - j >= 0) {
                                edge_matrix[i][i - j] = random_num_gen(random_type, random_index_1, random_index_2);
                                edge_matrix[i - j][i] = edge_matrix[i][i - j];
                        }
                }
        }
}

double Graph::random_num_gen(int random_type, double random_index_1, double random_index_2)
{
        std::random_device rd;
        std::mt19937 gen(rd());
        if (random_type == 0)
        {
                // uniform distribution
                std::uniform_real_distribution<> distribution(random_index_1, random_index_2);
                return distribution(gen);
        }
        else if (random_type == 1)
        {
                // normal distribution
                std::normal_distribution<double> distribution(random_index_1, random_index_2);
                return distribution(gen);
        }
        else if (random_type == 2)
        {
                // exponential distribution
                std::exponential_distribution<> distribution(random_index_1);
                return distribution(gen);
        }
        else if (random_type == 3)
        {
                // binomial distribution
                std::binomial_distribution<> distribution(random_index_1, random_index_2);
                return distribution(gen);
        }
        return -2;
}

std::vector<int> Graph::findNRP(std::vector<int> shortest_path)
{
        int cur_small = shortest_path[shortest_path.size() - 1];
        std::vector<int> toreturn;
        for (int i = shortest_path.size() - 2; i > 0; i--)
        {
                if (shortest_path[i] < cur_small)
                {
                        cur_small = shortest_path[i];
                        if (shortest_path[i - 1] > cur_small)
                        {
                                toreturn.push_back(shortest_path[i]);
                        }
                }
        }
        return toreturn;
}

// currently implementing shortest path using the standard Dijkstra's Algorithm
pair<vector<int>, double> Graph::findShortestPath(int start, int end)
{
        std::vector<int> result;
        std::set<int> MST;
        int n = edge_matrix.size();

        // array to make traceback easier
        int prev[n];

        // initialize a *tentative* distance array with default value infinity except for our starting vertex
        double distance[n]; // c initialization to 0
        // set to inf if not the start
        for (int i = 0; i < n; i++)
        {
                prev[i] = -1;
                if (i == start){distance[i] = 0;
                    continue;}
                        
                distance[i] = INFINITY;
        }

        while (distance[end] == INFINITY)
        {
                double min = INFINITY;
                int u = -1;
                for (int i = 0; i < n; i++)
                {
                        if (!MST.count(i) && distance[i] < min)
                        {
                                min = distance[i];
                                u = i;
                        }
                }

                MST.insert(u);

                for (int j = u - d_; j <= u + d_; j++)
                {
                        if (!MST.count(j) && j < n && j >= 0 && distance[u] + edge_matrix[j][u] < distance[j])
                        {
                                distance[j] = distance[u] + edge_matrix[j][u];
                                //distance[j] = 0;
                                prev[j] = u;
                        }
                }
        }

        int cur = end;
        
        result.push_back(cur);

        int i = 0;
        while (cur != start)
        {
                result.push_back(prev[cur]);
                cur = prev[cur];
                i++;
        }

        std::reverse(result.begin(), result.end());

        return pair<vector<int>, double> (result, distance[end]);
}
/*
double Graph::findDis(int[] pivots){
        double toreturn = 0.0;
        for(int i = 1; i <  pivots.size(); i++){
                toreturn += edge_matrix[pivots[i-1]][pivots[i]];
        }
        return toreturn;
}*/

void Graph::print_graph() {
        std::cout << "Graph:" << std::endl;
        for (int i = 0; i < edge_matrix.size(); i++) {
                for (int j = 0; j < edge_matrix.size(); j++) {
                        if(edge_matrix[i][j]) std::cout << edge_matrix[i][j] << " ";
                }
                std::cout << std::endl;
        }
}
