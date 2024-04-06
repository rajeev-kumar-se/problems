#include <iostream>
#include <fstream>
#include <random>

using namespace std;

int main() {
    const int num_testcases = 20;
    ofstream outfile("in.txt");
    outfile << num_testcases << endl;
    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 999);

    for (int i = 0; i < num_testcases; ++i) {
        int a = dist(gen);
        int b = dist(gen);
        outfile << a << " " << b << endl;
    }

    outfile.close();
    
    return 0;
}
