#include <iostream>
#include <fstream>
#include <string>
#include "CLI.hpp"
#include "csv.hpp"         // Vince's CSV parser
#include "date.h"          // Howard Hinnant's Date library

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

            std::string day_str = std::string(row["day"].get<std::string>());
            std::string year_str = std::string(row["year"].get<std::string>());
            std::string month_str = std::string(row["month"].get<std::string>());
            std::string measurement_str = std::string(row["measurement"].get<std::string>());
            if (month < 1 || month > 12) {
                std::cerr << "Invalid month value: " << month << std::endl;
                continue;
            }

            if (day < 1 || day > 31) {
                std::cerr << "Invalid day value: " << day << std::endl;
                continue;
            }

            date::year_month_day ymd{date::year{year}, date::month{static_cast<unsigned int>(month)}, date::day{static_cast<unsigned int>(day)}};

            date::sys_days sys_date = ymd;

            date::weekday weekday{sys_date};

            std::cout << "Date: " << ymd << " (" << weekday << "), "
                      << "Measurement: " << measurement << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error reading CSV file: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}