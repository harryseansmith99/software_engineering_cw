/*
vehicle.cpp
Author: 16048438
Created: 04/12/2023
Updated: 19/12/2023
*/

#include "vehicle.hpp"

Vehicle::Vehicle (
    std::string reg_number,
    std::string in_or_out,
    std::string time,
    std::string day ) {

        this->reg_number = reg_number;
        this->in_or_out = in_or_out;
        this->time = time;
        this->day = day;
}


std::string Vehicle::get_reg_number() {
    return this->reg_number;
}


void Vehicle::set_reg_number(std::string reg) {
    this->reg_number = reg;
}


std::string Vehicle::get_in_or_out() {
    return this->in_or_out;
}


void Vehicle::set_in_or_out(std::string status) {
    this->in_or_out = status;
}


std::string Vehicle::get_time() {
    return this->time;
}


void Vehicle::set_time(std::string time) {
    this->time = time;
}


std::string Vehicle::get_date() {
    return this->day;
}


void Vehicle::set_date(std::string day) {
    this->day = day;
}

Vehicle::~Vehicle() {}

