#include <iostream>
#include <fstream>
#include <string>
#include <sys/types.h>
#include <dirent.h>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
    DIR* datadir = opendir("ndata");
    dirent* entry = readdir(datadir);

    while(entry){
        char part[6];
        
        memcpy(part, entry->d_name, 6);
        part[6] = 0;
        
        if(strcmp(part, "path_N") == 0){
            char * temp = entry->d_name + 7;
            int N = atoi(temp);
            
            while(temp && temp[0] != 'D'){
                temp++;
            }

            if(!temp) {
                printf("filename did not include D");
                exit(1);
            } 
            int d = atoi(temp + 2);

            int samples = 0;
            double tottime = 0;

            string line;
            string filename = entry->d_name;

            ifstream infile("ndata/" + filename);
            if (infile.is_open()) {
                while(getline(infile, line)) {
                    tottime = stod(line);
                    samples++;
                }
            } else {printf("failed to open %s\n", entry->d_name);}

            printf("%d %d %f\n", N, d, tottime / samples);
        }
        entry = readdir(datadir);
    }
}