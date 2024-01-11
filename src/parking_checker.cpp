/*
parking_checker.hpp
Author: 16048438
Created: 19/22/2023
Updated: 22/12/2023
*/

#include "parking_checker.hpp"

ParkingChecker::ParkingChecker() {}


ParkingChecker::~ParkingChecker() {}


int ParkingChecker::search_lines_in_file(std::ifstream& infile) {

    std::string line;

    // error handling if file fails to open
    if (!infile.is_open()) {
        std::cerr << "Error when opening the file" << std::endl;
        return 1;
    }

    // opening the file
    while (std::getline(infile, line)) {

        std::istringstream phrase(line); // shows if line is string

        // variables that we can take out of the input file to create
        // vehicle objects and get information from them
        std::string vehicle_type;
        std::string reg_number;
        std::string in_or_out;
        std::string time;
        char first_char;

        // check if the first character of each line is the startings of
        // a date, i.e 01/xx/xx, 11/xx/xx
        if ((phrase >> std::ws >> first_char) &&
            (first_char <= '3')) {

            // set the date found as current date field
            this->set_current_date(line);

            // keep this for the output file later on
            this->dates.push_back(this->get_current_date());

            // reset the search so we can get data describing cars and vans
            phrase.clear();
            phrase.seekg(0);
        }

        // this is the lines that show cars/vans coming in or leaving
        else {
            phrase >> std::ws >> vehicle_type;
            phrase >> std::ws >> reg_number;

            // detect if the next word is for when the vehicle is coming
            // into the car park, keyword is "IN" or "OUT
            std::string next_word;
            phrase >> std::ws >> next_word;
            if (next_word == "IN") {
                in_or_out = "IN";
            }
            else {
                in_or_out = "OUT";
            }
            phrase >> std::ws >> time;
        }

        // now we need to use the data to create Car and Van objects
        // we can use a Vehicle* pointer as this will work for both
        Vehicle* vehicle_ptr = nullptr;

        // create the car object if the start of the line is "car", then
        // put it into the "cars" vector
        if (vehicle_type == "ar") {
            vehicle_ptr = new Car(reg_number, in_or_out, time, this->date);
            this->cars.push_back(dynamic_cast<Car*>(vehicle_ptr));
        }

        // same as above but for vans
        else if (vehicle_type == "an"){
            vehicle_ptr = new Van(reg_number, in_or_out, time, this->date);
            this->vans.push_back(dynamic_cast<Van*>(vehicle_ptr));
        }
    }

    infile.close();

    return 0;
}


void ParkingChecker::set_current_date(std::string date) {

    this->date = date;
}


std::string ParkingChecker::get_current_date() {

    return this->date;
}


std::vector<double> ParkingChecker::calculate_daily_takings(
                                            std::string current_date)  {

    double daily_car_takings = 0.0;
    double daily_van_takings = 0.0;

    // get total takings for cars coming in on a day
    for (Car* car : this->cars) {
        if (car->get_date() == current_date && car->get_in_or_out() == "IN") {
            daily_car_takings += CAR_PRICE;
        }
    }

    // same as above for vans
    for (Van* van : this->vans) {
        if (van->get_date() == current_date && van->get_in_or_out() == "IN") {
            daily_van_takings += VAN_PRICE;
        }
    }

    double total_daily_takings = daily_car_takings + daily_van_takings;

    std::vector<double> results = {total_daily_takings, 
                                    daily_car_takings, 
                                    daily_van_takings};
    return results;
}


std::vector<int> ParkingChecker::daily_number_of_vehicles(
                                                std::string current_date ) {

    // init variables to hold data we find for each date
    std::vector<int> results;
    int car_count = 0;
    int van_count = 0;
    int cars_turned_away = 0;
    int vans_turned_away = 0;

    // get amount of cars coming in per day
    for (auto car : this->cars) {
        if (car->get_date() == current_date && car->get_in_or_out() == "IN"
            && car_count < this->TOTAL_CAR_SPACES) {
            car_count++;
        }
    }

    // get amount of cars turned away due to no space
    for (auto car : this->cars) {
        if (car->get_date() == current_date && car->get_in_or_out() == "IN"
            && car_count >= this->TOTAL_CAR_SPACES) {
            cars_turned_away++;
        }
    }

    // get amount of vans coming in per day
    for (auto van : this->vans) {
        if (van->get_date() == current_date && van->get_in_or_out() == "IN"
            && van_count < this->TOTAL_VAN_SPACES) {
            van_count++;
        }
    }

    // get amount of vans turned away due to no space
    for (auto van : this->vans) {
        if (van->get_date() == current_date && van->get_in_or_out() == "IN"
            && van_count >= this->TOTAL_VAN_SPACES) {
            vans_turned_away++;
        }
    }

    results = {car_count, van_count, cars_turned_away, vans_turned_away};
    return results;
}


std::vector<std::string>  ParkingChecker::get_dates() {

    return this->dates;
}


std::string ParkingChecker::set_output_filename(std::string input) {

    std::string result;

    // remove all non digits from the date, i.e. 01/10/2023 -> 01102023
    for (auto i : input) {
        if (std::isdigit(i)) {
            result.push_back(i);
        }
    }

    // append .dat so the file type is data file
    result = result + ".dat";
    return result;
}