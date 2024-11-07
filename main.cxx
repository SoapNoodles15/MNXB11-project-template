#include <iostream>
#include <fstream>
#include <string>
#include "CLI.hpp"
#include "csv.hpp"  // Vince's CSV parser


int main(int argc, char **argv) {
    CLI::App app{"CSV File Reader"};

    std::string filename;
    app.add_option("-i,--input-file", filename, "CSV file to read")
       ->required()
       ->type_name("FILE");

   
    CLI11_PARSE(app, argc, argv);

    try {
        
        csv::CSVReader reader(filename);

        
        for (csv::CSVRow& row : reader) {
            
            int day = row["day"].get<int>();
            int year = row["year"].get<int>();
            int month = row["month"].get<int>();
            double measurement = row["measurement"].get<double>();

        std::cout   <<"Day" << day
                    <<",Year" << year
                    <<",Month" << month
                    <<",Measurment" << measurement << std::endl;
            
        }
    } catch (const std::exception& e) {
        std::cerr << "Error reading CSV file: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}