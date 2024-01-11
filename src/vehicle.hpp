#ifndef _VEHICLE_HPP_
#define _VEHICLE_HPP_
#include <string>

/*
vehicle.hpp
Author: 16048438
Created: 04/12/2023
Updated: 19/12/2023
*/


/**
 * @class Vehicle
 * @brief Base class representing a generic vehicle.
 */
class Vehicle {
private:
    std::string reg_number; ///< Registration number of the vehicle.
    std::string in_or_out;  ///< Direction of the vehicle, either "IN" or "OUT".
    std::string time;       ///< Time of the vehicle's entry or exit.
    std::string day;        ///< Day of the vehicle's entry or exit.

public:
    /**
     * @brief Constructor for the Vehicle class.
     * @param reg_number Registration number of the vehicle.
     * @param in_or_out Direction of the vehicle, either "IN" or "OUT".
     * @param time Time of the vehicle's entry or exit.
     * @param day Day of the vehicle's entry or exit.
     */
    Vehicle(
            std::string reg_number,
            std::string in_or_out,
            std::string time,
            std::string day
    );

    /**
     * @brief Virtual destructor for the Vehicle class.
     */
    virtual ~Vehicle();

    /**
     * @brief Getter for the registration number.
     * @return The registration number of the vehicle.
     */
    std::string get_reg_number();

    /**
     * @brief Setter for the registration number.
     * @param reg The new registration number to set.
     */
    void set_reg_number(std::string reg);

    /**
     * @brief Getter for the direction of the vehicle.
     * @return The direction of the vehicle, either "IN" or "OUT".
     */
    std::string get_in_or_out();

    /**
     * @brief Setter for the direction of the vehicle.
     * @param status The new direction to set, either "IN" or "OUT".
     */
    void set_in_or_out(std::string status);

    /**
     * @brief Getter for the time of the vehicle's entry or exit.
     * @return The time of the vehicle's entry or exit.
     */
    std::string get_time();

    /**
     * @brief Setter for the time of the vehicle's entry or exit.
     * @param time The new time to set.
     */
    void set_time(std::string time);

    /**
     * @brief Getter for the day of the vehicle's entry or exit.
     * @return The day of the vehicle's entry or exit.
     */
    std::string get_date();

    /**
     * @brief Setter for the day of the vehicle's entry or exit.
     * @param day The new day to set.
     */
    void set_date(std::string day);

    /**
     * @brief Pure virtual function to convert the vehicle information to a string.
     * @return A string representation of the vehicle.
     */
    virtual std::string to_string() = 0;
};

#endif
