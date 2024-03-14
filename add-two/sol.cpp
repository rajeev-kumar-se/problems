#include <iostream>

using namespace std;

int main() {
    // Read the number of test cases
    int numTestCases;
    cin >> numTestCases;

    // Iterate through each test case
    for (int i = 0; i < numTestCases; ++i) {
        // Read the two numbers
        int a, b;
        cin >> a >> b;

        // Calculate the sum
        int sum = a + b;

        // Output the sum
        cout << sum << endl;
    }

    return 0;
}
