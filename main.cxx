#include <iostream>
#include <fstream>
#include <string>
#include "CLI.hpp"


int main(int argc, char **argv) {
    CLI::App app{"CSV File Reader"};

    std::string filename;
    app.add_option("-i,--input-file", filename, "CSV file to read")
       ->required()
       ->type_name("FILE");

    CLI11_PARSE(app, argc, argv);

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file " << filename << std::endl;
        return 1;
    }

    std::cout << "Reading CSV file: " << filename << std::endl;
    
    file.close();

    return 0;
}
