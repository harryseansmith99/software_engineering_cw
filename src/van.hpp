#ifndef _VAN_HPP_
#define _VAN_HPP_
#include <string>
#include "vehicle.hpp"

/*
van.hpp
Author: 16048438
Created: 04/12/2023
Updated: 19/12/2023
*/

/**
 * @class Van
 * @brief Represents a van, inheriting from the Vehicle class.
 */
class Van : public Vehicle {
public:
    /**
     * @brief Constructor for the Van class.
     * @param reg_number Registration number of the van.
     * @param in_or_out Direction of the van, either "IN" or "OUT".
     * @param time Time of the van's entry or exit.
     * @param day Day of the van's entry or exit.
     */
    Van(
            std::string reg_number,
            std::string in_or_out,
            std::string time,
            std::string day
    );

    /**
     * @brief Destructor for the Van class.
     */
    virtual ~Van();

    /**
     * @brief Convert the van information to a string.
     * @return A string representation of the van.
     */
    std::string to_string() override;
};

#endif