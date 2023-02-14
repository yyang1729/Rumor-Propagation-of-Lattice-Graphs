#pragma once

#include <iostream>
#include <random>

class Graph {
    public:
        Graph() = default;
        Graph(int num_verticies, int d, int random_type);

        // Graph algorithm to find shortest path from vertex a to vertex b
        int[] findSP(int start, int end);

        int[] findPivot(int[] shortest_path);
        double findDis(int[] pivots);
        ~Graph();

    private:
        int[][] edge_matrix;
        int d;
};


