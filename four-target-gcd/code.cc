#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate GCD of two numbers
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to find unique quadruplets whose GCD is target
void findQuadruplets(vector<int>& nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<int> prevQuadruplet(4, -1); // Initialize with values that won't occur in nums
    for (int i = 0; i < n - 3; ++i) {
        for (int j = i + 1; j < n - 2; ++j) {
            for (int k = j + 1; k < n - 1; ++k) {
                for (int l = k + 1; l < n; ++l) {
                    if (gcd(gcd(nums[i], nums[j]), gcd(nums[k], nums[l])) == target) {
                        // Check if the current quadruplet is different from the previous one
                        vector<int> currQuadruplet = {nums[i], nums[j], nums[k], nums[l]};
                        if (currQuadruplet != prevQuadruplet) {
                            cout << i << " " << j << " " << k << " " << l << endl;
                            // cout << "Elements: " << nums[i] << " " << nums[j] << " " << nums[k] << " " << nums[l] << "\n";
                            prevQuadruplet = currQuadruplet;
                        }
                    }
                }
            }
        }
    }
}



int solve() {
    int N;
    int target;
    cin >> N;
    cin >> target;
    vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    } 
    findQuadruplets(nums, target);
    return 0;
}
int main(int argc, char const *argv[]){
// #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
// #endif
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}


