#pragma once

#include <random>
#include <vector>
#include <cstdlib>

using std::vector;

class Graph {
    public:
        Graph() = default;
        //      random_type               random_index_1              random_index_2
        //  0     uniform                  lower bound                 upper bound
        //  1      normal                      mean                        std
        //  2     expnential                   mean                         \
        //  3      binomial                   times                    probability
        Graph(int num_verticies, int d, int random_type, double random_index_1, double random_index_2);
        void reassign_edge(int random_type, double random_index_1, double random_index_2);
        vector<int> findShortestPath(int start, int end);
        vector<int> findNRP(vector<int> shortest_path);
        void print_graph();
        //double findDis(int pivots[]);
       // ~Graph();

    private:
        vector< vector<double> > edge_matrix;
        int d_;
        double random_num_gen(int random_type, double random_index_1, double random_index_2);
};

