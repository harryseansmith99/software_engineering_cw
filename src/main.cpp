/*
main.cpp
Author: 16048438
Created: 20/12/2023
Updated: 22/12/2023
*/

#include <iostream>
#include <fstream>
#include "parking_checker.hpp"


int main(int argc, char *argv[]) {

    // ensure filename is given in terminal when running program
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <PROVIDE_INPUT_FILE\n>" 
        << std::endl;
        return 1;
    }

    // assign the arg given as the input file name
    const char *input_file_name = argv[1];
    std::ifstream infile(input_file_name);

    if (!infile) {
        std::cerr << "Error: Unable to open file " << input_file_name 
        << std::endl;
        return 1;
    }

    ParkingChecker p;
    p.search_lines_in_file(infile);

    // creating our output files, init vectors to store vehicle info
    std::vector<double> daily_takings;
    std::vector<int> daily_vehicles;

    // for every day found, create a file with that date and input vehicle data
    for (const auto &date: p.get_dates()) {

        daily_takings = p.calculate_daily_takings(date);
        daily_vehicles = p.daily_number_of_vehicles(date);
        std::ofstream outfile(p.set_output_filename(date));

        if (outfile.is_open()) {
            outfile << "Date: " << date
                << "\nTotal takings: " << daily_takings[0]
                << "\nTotal takings for Cars: £" << daily_takings[1]
                << "\nTotal takings for Vans: £" << daily_takings[2]
                << "\nTotal of cars: " << daily_vehicles[0]
                << "\nTotal of vans: " << daily_vehicles[1]
                << "\nTotal of cars turned away: " << daily_vehicles[2]
                << "\nTotal of vans turned away: " << daily_vehicles[3]
                << std::endl;
        }
        outfile.close();
    }

    return 0;
}