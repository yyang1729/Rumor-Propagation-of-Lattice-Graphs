#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <filesystem>

using namespace std;

int main(int argc, char* argv[]) {
    string path = "Apexdata/";
    // for (const auto & entry : filesystem::directory_iterator(path)) {
        // string filename = entry.path();
        string filename = argv[1];
        // if (filename == "ndata/path_N_1000_D_5.csv") break;
        string line;
        ifstream infile(filename);
        if (infile.is_open()) {
            int total = 0;
            while(getline(infile, line)) {
                for (int i = 0; i < line.size(); i++) {
                    if (line[i] == ',') total++;
                }
            }
            double average = total / 100;
            int N = stoi(argv[2]);
            double output = average / N;
            cout << filename << " : " << output << endl;
        }
    // }
    return 0;
}