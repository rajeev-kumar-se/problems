#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    ofstream inputFile("in.txt");
    int t = 10 ;
    inputFile << t << endl;
    while (t--) {
        int n = rand() % 100 + 1; // Generate random value of n between 1 and 100
        inputFile << n << endl;
    }
    inputFile.close();
    return 0;
}
