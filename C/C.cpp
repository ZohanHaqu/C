#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <cstdio>
#include <windows.h>

void runCFile(const std::string& filename) {
    // Compile the C code using cl.exe
    std::string compileCommand = "cl /nologo /Fe:temp_output.exe " + filename;
    int compileResult = system(compileCommand.c_str());
    if (compileResult != 0) {
        std::cerr << "Compilation failed for file: " << filename << "\n";
        return;
    }

    // Run the compiled executable
    int runResult = system("temp_output.exe");
    if (runResult != 0) {
        std::cerr << "Execution failed for file: " << filename << "\n";
    }

    // Clean up the compiled executable
    remove("temp_output.exe");
}

void saveTemporaryCFile(const std::string& code, const std::string& tempFilename) {
    std::ofstream tempFile(tempFilename);
    if (!tempFile) {
        std::cerr << "Failed to create temporary file: " << tempFilename << "\n";
        return;
    }
    tempFile << code;
    tempFile.close();
}

void runScriptFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "File not found: " << filename << "\n";
        return;
    }

    // Directly compile and execute the C file
    runCFile(filename);
}

int main(int argc, char* argv[]) {
    if (argc == 1) {
        std::cout << "C Version C23\nType your C code (type 'run' to execute, 'exit' to quit)\nC For Windows 1.0\n";
        std::ostringstream code;
        std::string line;

        while (true) {
            std::cout << ">>> ";
            std::getline(std::cin, line);

            if (line == "exit") break;

            if (line.rfind("run", 0) == 0) { // If line starts with "run"
                std::string filename = line.substr(4); // Extract filename after "run "
                if (!filename.empty()) {
                    runScriptFromFile(filename);
                }
                else {
                    // Save current C code to a temporary file and compile it
                    std::string tempFilename = "temp_input.c";
                    saveTemporaryCFile(code.str(), tempFilename);
                    runCFile(tempFilename);
                    code.str("");
                    code.clear();
                }
                continue;
            }

            code << line << '\n';
        }
    }
    else if (argc == 2) {
        runScriptFromFile(argv[1]);
    }
    else {
        std::cerr << "Usage:\n";
        std::cerr << "  c            - Interactive mode\n";
        std::cerr << "  c file.c     - Run C code from file\n";
    }

    return 0;
}