#include <iostream>
#include "Display/display.hpp"
#include "Car/car.hpp"
#include "Fleet/fleet.hpp"



int main()
{
    // Car newCar1 {"1FVACWDU1BHBB3474","2022","FORD","F150",20,25,52000,50000};
    // Car newCar2 {"1GNDX03E03D188446","2022","SUBARU","WRX",23,28,32000,31500};
    // Car newCar3 {"JTHFF2C26B2515141","2018","LEXUS","IS350",24,30,42000,40000};

    Fleet newFleet;

    Init(newFleet);


    // newFleet.AddCarToFleet(newCar1);
    // newFleet.AddCarToFleet(newCar2);
    // newFleet.AddCarToFleet(newCar3);

    // // newFleet.ListCarsInFleet();
    // newFleet.GetCarDetails("1GNDX03E03D188446");

    // newFleet.RemoveCarFromFleet("1GNDX03E03D1886");

    // newFleet.ListCarsInFleet();

    return 0;
}