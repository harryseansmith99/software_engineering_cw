/*
car.cpp
Author: 16048438
Created: 04/12/2023
Updated: 19/12/2023
*/

#include "car.hpp"

Car::Car (
    std::string reg_number,
    std::string in_or_out,
    std::string time,
    std::string day
    ) : 
    Vehicle ( 
        reg_number, 
        in_or_out,
        time,
        day )
{
    Vehicle::set_reg_number(reg_number);
    Vehicle::set_in_or_out(in_or_out);
    Vehicle::set_time(time);
    Vehicle::set_date(day);
}

Car::~Car() {}

std::string Car::to_string() {
    return "car " + get_reg_number() 
    + " " + get_in_or_out() 
    + " " + get_time() + 
    " " + get_date();
}
