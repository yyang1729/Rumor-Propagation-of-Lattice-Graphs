#include "Graph.hpp"

Graph::Graph(int num_verticies, int d, int random_type, double random_index_1, double random_index_2) {
    edge_matrix.resize(num_verticies);
    for (int i = 0; i < edge_matrix.size(); i++) {
        edge_matrix[i].resize(num_verticies);
    }

    // This method is O(d*n), which is much faster than the current method. However, it does not default 
    // the non-existing edges. If our future algorithm can ignore this problem, we can switch to this
    // for (int i = 0; i < num_verticies; i++) {
    //     for (int j = 1; j <= d; j++) {
    //         if (i - j >= 0) {
    //             edge_matrix[i][i - j] = random_num_gen(random_type, double random_index_1, double random_index_2);
    //         }
    //         if (i + j < num_verticies) {
    //             edge_matrix[i][i - j] = random_num_gen(random_type, double random_index_1, double random_index_2);
    //         }
    //     }
    // }

    // This method is O(n^2). The non-existing edge is set to -1
    // If the value is -2, something wrong happened with random variable
    for (int i = 0; i < num_verticies; i++) {
        for (int j = 0; j < num_verticies; j++) {
            if (std::abs(i - j) <= d && i != j) {
                edge_matrix[i][j] = random_num_gen(random_type, random_index_1, random_index_2);
            } else {
                edge_matrix[i][j] = -1;
            }
        }
    }
}

void Graph::reassign_edge(int random_type, double random_index_1, double random_index_2) {
    // I'm writing the O(n^2) method here
    for (int i = 0; i < edge_matrix.size(); i++) {
        for (int j = 0; j < edge_matrix.size(); j++) {
            if (edge_matrix[i][j] != -1) edge_matrix[i][j] = random_num_gen(random_type, random_index_1, random_index_2);
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
        std::normal_distribution<double> distribution(random_index_1, random_index_2);
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