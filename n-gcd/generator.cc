#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0)); // Seed for random number generation

    // Generate number of test cases
    int num_testcases = rand() % 11 + 10; // Random number between 10 and 20
    cout << num_testcases << endl;

    // Write test cases to in.txt file
    ofstream infile("in.txt");
    for (int i = 0; i < num_testcases; ++i) {
        int n = rand() % 1000000000 + 1; // Random number between 1 and 10^9
        infile << n << endl;
    }
    infile.close();

    return 0;
}
