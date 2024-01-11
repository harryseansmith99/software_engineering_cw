#ifndef _PARKINGCHECKER_HPP_
#define _PARKINGCHECKER_HPP_
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "vehicle.hpp"
#include "car.hpp"
#include "van.hpp"

/*
parking_checker.hpp
Author: 16048438
*/

class ParkingChecker {
    private:
        std::vector<Car*> cars; ///< Vector holding pointers to Car objects
        std::vector<Van*> vans; ///< Vector holding pointers to Can objects
        std::string input_filename; ///< input filename to get parking data
        std::string output_filename; ///< output file to print daily report
        const double CAR_PRICE = 1.00; ///< Constant value for car parking price, £1.00
        const double VAN_PRICE = 1.50; ///< Constant value for van parking price, £1.50
        const int TOTAL_CAR_SPACES = 1000; ///< Constant value for total car spaces, 1000
        const int TOTAL_VAN_SPACES = 20; ///< Constant value for total van spaces, 20
        std::string date; /// date value for each day
        std::vector<std::string> dates; ///< Vector holding all detected dates in input_file

    public:

        /**
         * @brief Default constructor for the ParkingChecker class.
         */
        ParkingChecker();


        /**
         * @brief Destructor for the ParkingChecker class.
         */
        virtual ~ParkingChecker();


        /**
         * @brief Search through input file, retrieve all dates, Cars and Vans
         *
         * This function will search through the input file, retrieve all dates, 
         * cars, vans, and put them into their appropriate Vectors 
         * (private members)
         *
         * @param infile
         */
        int search_lines_in_file(std::ifstream& infile);


        /**
         * @brief Set the current date.
         * @param date The new current date.
         */
        void set_current_date(std::string date);


        /**
         * @brief Get the current date.
         * @return The current date.
         */
        std::string get_current_date();


        /**
         * @brief Calculate daily takings for a given date.
         * @param current_date The date for which to calculate daily takings.
         * @return A vector of doubles containing daily takings
         */
        std::vector<double> calculate_daily_takings(std::string current_date);


        /**
         * @brief Get the daily number of vehicles for a given date.
         * @param current_date The date for which to get the daily number 
         *                      of vehicles.
         * @return A vector of integers containing the counts of cars and vans 
         *          for the day.
         */
        std::vector<int> daily_number_of_vehicles(std::string current_date);


        /**
         * @brief Get all available dates in the parking data.
         * @return this->dates
         */
        std::vector<std::string> get_dates();


        /**
         * @brief Set the output filename based on the input filename.
         * @param input The input filename.
         * @return The output filename.
         */
        std::string set_output_filename(std::string input);
};

#endif