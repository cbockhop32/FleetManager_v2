#include <iostream>
#include <iomanip>
#include <locale>

#include "fleet.hpp"


void Fleet::AddCarToFleet(Car& newCar){
    if(CarExists(newCar.getVIN())) {
        std::cout << "Car Already exists with that VIN number" << '\n';
    } else {
        _fleet.insert({newCar.getVIN(), newCar});
    }
};

void Fleet::RemoveCarFromFleet(std::string vin){
    if(!CarExists(vin)) {
        std::cout << "Vehicle does not exist with that VIN number" << "\n";

    } else {

        Car& car = _fleet.at(vin);
        

        std::cout << "\nYou want to remove the following car: " << car.year << " " << car.make << " " << car.model <<'\n';

        std::string removeCmd;

        while(true) {
            std::cout << "Do you want to remove this vehicle to your fleet? (yes/no)" << '\n';
            std::getline(std::cin, removeCmd);


            if(removeCmd == "yes") {
                std::cout << "\nCar has been removed from your fleet" << '\n';
                _fleet.erase(vin);

                break;
            }else if (removeCmd == "no") {
                std::cout << "Going back to main menu" << '\n';
                break;

            } else {
                std::cin.clear();
                continue;
            }

        }

    }
};

void Fleet::ListCarsInFleet(){
    int count {1};
    if(_fleet.size() == 0) {
        std::cout << "Fleet Is Empty" << "\n";
    } else {
        std::cout << "\n____Cars in Your Fleet____\n";
        for (auto& [vin, car] : _fleet) {
        std::cout << count << " : " << car.getVIN() << " " << car.year << " " << car.make << " " << car.model << " " << car.mileage << " " << car.cityMPG << " " << car.highwayMPG << " " << car.getPurchasePrice() << " " << car.getCurrentValue() << '\n';
        count++;}
    }
};

void Fleet::GetCarDetails(std::string vin){
    if(!CarExists(vin)) {
        std::cout << "Car Does Exists With That VIN Number" << '\n';

    } else {
        Car& car = _fleet.at(vin);

        std::cout << car.year << " " << car.make << " " << car.model << '\n';
        std::cout << "Current Mileage: " << car.mileage << '\n';
        std::cout << "City/Highway MPG: " << car.cityMPG << " / " << car.highwayMPG << '\n';
    }
};


Car& Fleet::GetCarByVIN(std::string vin){
    return _fleet.at(vin);
};

void Fleet::GetFleetStats(){
    if(_fleet.size() == 0) {
        std::cout << "There are currently no cars within your fleet" << '\n';
    } else {
        
        uint32_t totalPurchase {0};
        uint32_t totalCurrentVal {0};
        uint32_t totalMileage {0};
        uint32_t totalCityMPG {0};
        uint32_t totalHighwayMPG {0};

        for(auto& [vin, car] : _fleet) {
            totalPurchase += stoi(car.getPurchasePrice());
            totalCurrentVal += stoi(car.getCurrentValue());
            totalMileage += stoi(car.mileage);
            totalCityMPG += stoi(car.cityMPG);
            totalHighwayMPG += stoi(car.highwayMPG);
        }

        

        float totalReturn {(1-(float)totalCurrentVal/(float)totalPurchase)*100};


        std::cout.imbue(std::locale(""));

        std::cout <<"Average Original Cost (Per Vehicle): $" << totalPurchase / _fleet.size() << "\n";
        std::cout <<"Average Current Value (Per Vehicle): $" << totalCurrentVal / _fleet.size() << "\n";
        std::cout <<"Average Mileage (Per Vehicle): " << totalMileage / _fleet.size() << "\n";
        std::cout <<  std::fixed << std::setprecision(2)  <<"Average Loss (Per Vehicle): "<< totalReturn << "%" << '\n';


        std::cout << "Average Fuel Economy (City/Highway MPG): " << totalCityMPG / _fleet.size() << " / " << totalHighwayMPG / _fleet.size() <<'\n'; 
    }


};



bool Fleet::CarExists(std::string vin){
    if(_fleet.find(vin) == _fleet.end()) {
        return false;
    }

    return true;
};








