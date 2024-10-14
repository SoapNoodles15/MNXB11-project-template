
#include <iostream>
#include <string>
#include <CLI.hpp>

int main(int argc, char *argv[]) {
    std::cout << "Hello"
                 "There"
              << std::endl;

    // Create a CLI app
    CLI::App app{"CSV Reader"};

    // Variable to hold the input file name
    std::string input_file;

    // Define command line argument for input file
    app.add_option("-i,--input-file", input_file, "Path to the CSV file to read")->required();

    // Parse the command line arguments
    CLI11_PARSE(app, argc, argv);

    // Print the number of command line arguments and the first argument
    std::cout << "We were passed " << argc
              << " command line arguments, the first of which was " << argv[0]
              << std::endl;

    // Print the input file name
    std::cout << "Input CSV file: " << input_file << std::endl;

    std::cout << "With a good CLI library, we could use the command line "
                 "arguments to make a useful program."
              << std::endl;

    // Here you would add your logic to read and process the CSV file
    // Example: read_csv(input_file);

    return 0;
}

