#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
const std::string PROBLEM = "$file_name";
const std::string file_name = "./" + PROBLEM;
const std::string cpp_file_name = file_name+".cpp";      // Specify the C++ file name here
const std::string input_file_name = file_name+".in";      // Specify the input file name here
const std::string output_file_name = file_name+".out";    // Specify the output file name here
const std::string binary_file_name = file_name;       // Specify the binary file name here
int main() {
    // Compile and run the C++ file
    std::string compile_command = "g++ -std=c++20 -o " + binary_file_name + " " + cpp_file_name + " 2>&1";
        // Create a pipe to capture the compiler output
    FILE* pipe = popen(compile_command.c_str(), "r");
    if (!pipe) {
        std::cerr << "Failed to open pipe." << std::endl;
        return -1;
    }

    // Read the compiler output and print it on the console
    char buffer[128];
    std::string compilerOutput;
    while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
        compilerOutput += buffer;
    }

    // Close the pipe
    pclose(pipe);

    if (compilerOutput.empty()) {
        std::cout << "Compilation successful." << std::endl;
    } else {
        std::cout << "Compilation failed. Compiler errors:" << std::endl;
        std::cout << compilerOutput << std::endl;
    }

    std::string run_command = "./" + binary_file_name + " < " + input_file_name + " > " + output_file_name + " 2>&1";
    FILE* executePipe = popen(run_command.c_str(), "r");
    if (!executePipe) {
        std::cerr << "Failed to open pipe for program execution." << std::endl;
        return -1;
    }

    // Read the program output and print it on the console
    char executeBuffer[128];
    std::string programOutput;
    while (fgets(executeBuffer, sizeof(executeBuffer), executePipe) != NULL) {
        programOutput += executeBuffer;
    }

    // Close the program execution pipe
    pclose(executePipe);

    if (!programOutput.empty()) {
        std::cout << "Program output:" << std::endl;
        std::cout << programOutput << std::endl;
    }
    // Check if the output file was created
    std::ifstream output_file(output_file_name);
    if (!output_file.is_open()) {
        std::cerr << "Error opening output file." << std::endl;
        return 1;
    }
    // Read and display the output
    std::string output_line;
    while (std::getline(output_file, output_line)) {
        std::cout << output_line << std::endl;
    }
    std::cout << "Testcase results has been generated to "+PROBLEM+".out"<< std::endl;
    output_file.close();
    // Delete the binary file
    std::remove(binary_file_name.c_str());
    return 0;
}
