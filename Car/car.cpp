#include "car.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

Car::Car(std::string VIN,
         std::string year,
         std::string make,
         std::string model,
         std::string mileage,
         std::string citympg,
         std::string highwaympg,
         std::string price,
         std::string currVal)
  : year{ year }
  , make{ make }
  , model{ model }
  , mileage{ mileage }
  , cityMPG{ citympg }
  , highwayMPG{ highwaympg }
{
  setVIN(VIN);
  setPurchasePrice(price);
  setCurrentValue(currVal);
};

void
Car::setVIN(std::string vin)
{
  if (vin.length() == 17) {
    _VIN = vin;
  } else {
    _VIN = "Invalid";
  }
};

void
Car::setPurchasePrice(std::string purchasePrice)
{
  int priceConv = stoi(purchasePrice);

  if (priceConv > 0) {
    _purchasePrice = purchasePrice;
  } else {
    _purchasePrice = "0";
  }
};

void
Car::setCurrentValue(std::string currentValue)
{
  int valConv = stoi(currentValue);
  if (valConv > 0) {
    _currentValue = currentValue;
  } else {
    _currentValue = "0";
  }
};

void
Car::EditCarDetails()
{
  std::cout << "\n If you would like to edit a certain value, enter a new "
               "value when prompted. If you would like to keep the current "
               "value, simply press Enter \n \n";
  std::vector<std::string> detailPrompts = { "Year",
                                             "Make",
                                             "Model",
                                             "Mileage",
                                             "City Miles Per Gallon",
                                             "Highway Miles Per Gallon",
                                             "Original Purchase Price",
                                             "Current Market Value" };
  int currIdx = 1;

  for (std::string& currDetail : detailPrompts) {
    std::cout << "Enter a value for " << currDetail
              << "(Current: " << this->operator[](currIdx) << "): ";
    std::string newVal;
    std::getline(std::cin, newVal);

    if (newVal.empty()) {
      std::cout << "Previous Value Saved"
                << "\n";
    } else {
      transform(newVal.begin(), newVal.end(), newVal.begin(), ::toupper);

      switch (currIdx) {
        case 1:
          year = newVal;
          break;
        case 2:
          make = newVal;
          break;
        case 3:
          model = newVal;
          break;
        case 4:
          mileage = newVal;
          break;
        case 5:
          cityMPG = newVal;
          break;
        case 6:
          highwayMPG = newVal;
          break;
        case 7:
          setPurchasePrice(newVal);
          break;
        case 8:
          setCurrentValue(newVal);
          break;
      }
    }
    currIdx++;
  }
};

std::string
Car::getVIN()
{
  return _VIN;
};

std::string
Car::getPurchasePrice()
{
  return _purchasePrice;
};

std::string
Car::getCurrentValue()
{
  return _currentValue;
};
