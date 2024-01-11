#ifndef _CAR_HPP_
#define _CAR_HPP_
#include <string>
#include "vehicle.hpp"

/*
car.hpp
Author: 16048438
Created: 04/12/2023
Updated: 19/12/2023
*/

/**
 * @brief The Car class represents a car vehicle, inheriting from the Vehicle class.
 */
class Car : public Vehicle {
    public:

        /**
         * @brief Constructor for the Car class.
         * @param reg_number The registration number of the car.
         * @param int_or_out The status of the car (IN or OUT).
         * @param time The time associated with the car entry or exit.
         * @param day The day of the car entry or exit.
         */
        Car(
            std::string reg_number,
            std::string int_or_out,
            std::string time,
            std::string day
        );


        /**
         * @brief Destructor for the Car class.
         */
        virtual ~Car();


        /**
         * @brief Convert Car information to a string.
         * @return A string representation of the Car.
         */
        std::string to_string() override;
};

#endif