g++ -std=c++20 -o out code.cpp && ./out < in.txt > out.txt;

https://www.geeksforgeeks.org/inputoutput-external-file-cc-java-python-competitive-programming/

I will give you a competitive programming problem, you need to generate several files.
First solution.cc and Second test_case_generator.cc file.
By default generate both files to handle multiple testcase(min=10, max=20) both in solution.cc and test_case_generator.cc.

Means for the first file you should read the no of test case first and solve for each test case using solve() method to individully solve each test case.
 
For the second file test_case_generator.cc you should write no of testcase first and then individual cases to in.txt file in present in current directory.

You can use something like this in solution.cc code.
// #ifndef ONLINE_JUDGE 
// For getting input from in.txt file 
freopen("in.txt", "r", stdin); 
// Printing the Output to out.txt file 
freopen("out.txt", "w", stdout); 
// #endif 

And Now I will give you the input and output description.