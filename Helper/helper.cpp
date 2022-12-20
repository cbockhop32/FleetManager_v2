#include <iostream>

#include "../Display/display.hpp"
#include "helper.hpp"

void
mainFunctionCaller(int userChoice, Fleet& fleet)
{

  switch (userChoice) {
    case 1: {
      std::string vin = vinRetriever("Add");
      if (fleet.CarExists(vin)) {
        std::cout
          << "\n**A Car with that VIN number already exists in your fleet**"
          << "\n";
        break;
      }

      Car newCar = addCarHelper(vin);
      fleet.AddCarToFleet(newCar);
      break;
    }
    case 2: {
      std::string vin = vinRetriever("Remove");
      fleet.RemoveCarFromFleet(vin);
      break;
    }

    case 3: {
      std::string vin = vinRetriever("Edit");
      Car& CarToEdit = fleet.GetCarByVIN(vin);
      CarToEdit.EditCarDetails();
      break;
    }
    case 4:
      fleet.ListCarsInFleet();
      break;
    case 5: {
      std::string vin = vinRetriever("Look Up");
      fleet.GetCarDetails(vin);
      break;
    }
    case 6:
      fleet.GetFleetStats();
      break;
    case 7:
      helpPage();
      break;
    default:
      std::cout << "Invalid command" << std::endl;
  };
};

Car
addCarHelper(std::string vin)
{
  std::vector<std::string> attributePrompts = { "Year",
                                                "Make",
                                                "Model",
                                                "Mileage",
                                                "City Miles Per Gallon",
                                                "Highway Miles Per Gallon",
                                                "Original Purchase Price",
                                                "Current Market Value" };

  Car newCar;
  newCar.setVIN(vin);

  int currIdx = 1;

  for (std::string& prompt : attributePrompts) {
    std::cout << "Enter value for " << prompt << ": ";
    std::string input;
    std::getline(std::cin, input);

    if (input.empty()) {
      newCar[currIdx] = "None";
      std::cin.clear();
    } else {
      if (currIdx == 7) {
        newCar.setPurchasePrice(input);
      } else if (currIdx == 8) {
        newCar.setCurrentValue(input);
      } else {
        uppercaseInput(input);
        newCar[currIdx] = input;
      }
    }
    currIdx++;
  }
  return newCar;
};

std::string
vinRetriever(std::string action)
{
  std::cout << "Enter the VIN number of the car you would like to " << action
            << ": ";
  ;
  std::string input;
  std::getline(std::cin, input);

  return input;
};

void
uppercaseInput(std::string& carInput)
{
  transform(carInput.begin(), carInput.end(), carInput.begin(), ::toupper);
};
