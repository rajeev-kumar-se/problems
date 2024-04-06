// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to find GCD
int gcd(int a, int b)
{
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

void findMaxGCD(int arr[], int n){

	// To store the maximum GCD
	int maxGCD = 0;

	// Traverse the array
	for (int i = 0; i < n - 1; i++) {

		// Find GCD of the consecutive
		// element
		int val = gcd(arr[i], arr[i + 1]);

		// If calculated GCD > maxGCD
		// then update it
		if (val > maxGCD) {
			maxGCD = val;
		}
	}

	// Print the maximum GCD
	cout << maxGCD << endl;
}


void solve() {
    int n;
    std::cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    findMaxGCD(arr, n);
}

int main() {
    // #ifndef ONLINE_JUDGE
    // For getting input from in.txt file
    freopen("in.txt", "r", stdin);
    // Printing the Output to out.txt file
    freopen("out.txt", "w", stdout);
    // #endif
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
