g++ -std=c++20 -o out code.cpp && ./out < in.txt > out.txt;

https://www.geeksforgeeks.org/inputoutput-external-file-cc-java-python-competitive-programming/

I will give you a competitive programming problem, you need to generate several files.
First solution.cc and Second test_case_generator.cc file.
By default generate both files to handle multiple testcase both in solution.cc and test_case_generator.cc.

Means for the first file you should read the no of test case first and solve for each test case using solve() method to individully solve each test case.
 
For the second file test_case_generator.cc you should write no of testcase = 20 first and then individual cases to in.txt file in present in current directory.
And random integers should be less than 1000 and use uniform int dist to generate random numbers.

You can use something like this in solution.cc code.
// #ifndef ONLINE_JUDGE 
// For getting input from in.txt file 
freopen("in.txt", "r", stdin); 
// Printing the Output to out.txt file 
freopen("out.txt", "w", stdout); 
// #endif 

And Now I will give you the input and output description.

<!-- Tracker -->

"n-gcd" : Done,
"gcd-sum" : Done,
"range-gcd" : Done, 
"range-gcd-point-update" : Done,
"four-target-gcd",
"max-gcd-subarray" : Done,
"subarray-with-k-gcd" : Done,
"max-gcd-k-size-subarray",
"max-gcd-subsequence",
"max-gcd-k-size-subsequence" : Done,
"subsequence-with-k-gcd" : Done