#pragma once
#include <iostream>

class Car
{

public:
  Car(){

  };
  Car(std::string VIN,
      std::string year,
      std::string make,
      std::string model,
      std::string mileage,
      std::string citympg,
      std::string highwaympg,
      std::string price,
      std::string currVal);
  void EditCarDetails();

  // Setters
  void setVIN(std::string vin);
  void setPurchasePrice(std::string purchasePrice);
  void setCurrentValue(std::string currentValue);

  // Getters
  std::string getVIN();
  std::string getPurchasePrice();
  std::string getCurrentValue();

  std::string& operator[](size_t idx)
  {
    switch (idx) {
      case 0:
        return _VIN;
      case 1:
        return year;
      case 2:
        return make;
      case 3:
        return model;
      case 4:
        return mileage;
      case 5:
        return cityMPG;
      case 6:
        return highwayMPG;
      case 7:
        return _purchasePrice;
      case 8:
        return _currentValue;
      default:
        throw std::runtime_error("bad index");
    };
  };

private:
public:
  std::string year;
  std::string make;
  std::string model;
  std::string mileage;
  std::string cityMPG;
  std::string highwayMPG;

private:
  std::string _VIN;
  std::string _purchasePrice;
  std::string _currentValue;
};