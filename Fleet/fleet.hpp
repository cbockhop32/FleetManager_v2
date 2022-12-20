#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>

#include "../Car/car.hpp"

class Fleet
{
public:
  void AddCarToFleet(Car& newCar);
  void RemoveCarFromFleet(std::string vin);
  void ListCarsInFleet();
  void GetCarDetails(std::string vin);
  Car& GetCarByVIN(std::string vin);
  void GetFleetStats();
  bool CarExists(std::string vin);

private:
public:
private:
  std::unordered_map<std::string, Car> _fleet;
};