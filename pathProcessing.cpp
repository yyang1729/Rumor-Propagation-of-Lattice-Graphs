#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <filesystem>

using namespace std;

int main(int argc, char *argv[])
{
    string filename = argv[1];
    string line;
    ifstream infile(filename);
    double total = 0;
    int N = 0;
    if (infile.is_open())
    {
        while (getline(infile, line))
        {
            N++;
            total += stod(line);
        }
        
        double output = total / N;
        cout << filename << " : " << output << endl;
    }
    return 0;
}