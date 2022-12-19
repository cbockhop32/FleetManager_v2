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
    if(CarExists(vin)) {
        _fleet.erase(vin);
    } else {
        std::cout << "Vehicle does not exist with that VIN number" << "\n";
    }
};

void Fleet::ListCarsInFleet(){
    int count {1};
    if(_fleet.size() == 0) {
        std::cout << "Fleet Is Empty" << "\n";
    } else {
        for (auto& car : _fleet) {
        std::cout << count << " : " << car.second.getVIN() << " " << car.second.year << " " << car.second.make << " " << car.second.model << " " << car.second.cityMPG << " " << car.second.highwayMPG << " " << car.second.getPurchasePrice() << " " << car.second.getCurrentValue() << '\n';
        count++;}
    }

    

    
};

void Fleet::GetCarDetails(std::string vin){
    if(!CarExists(vin)) {
        std::cout << "Car Does Exists With That VIN Number" << '\n';

    } else {
        Car car = _fleet.at(vin);

        std::cout << car.year << " " << car.make << " " << car.model << '\n';
        std::cout << "City/Highway MPG: " << car.cityMPG << " / " << car.highwayMPG << '\n';
    }
};


Car& Fleet::GetCarByVIN(std::string vin){
    return _fleet.at(vin);
};

void Fleet::GetFleetStats(){
    if(_fleet.size() == 0) {
        std::cout << "There are currently no cars wihtin your fleet" << '\n';
    } else {
        int totalPurchase {0};
        int totalCurrentVal {0};
        int totalCityMPG {0};
        int totalHighwayMPG {0};

        for(auto& car : _fleet) {
            totalPurchase += stoi(car.second.getPurchasePrice());
            totalCurrentVal += stoi(car.second.getCurrentValue());
            totalCityMPG += stoi(car.second.cityMPG);
            totalHighwayMPG += stoi(car.second.highwayMPG);
        }

        

        float totalReturn {(1-(float)totalCurrentVal/(float)totalPurchase)*100};


        std::cout.imbue(std::locale(""));

        std::cout <<"Average Original Cost (Per Vehicle): $" << totalPurchase / _fleet.size() << "\n";
        std::cout <<"Average Current Value (Per Vehicle): $" << totalCurrentVal / _fleet.size() << "\n";
        std::cout <<  std::fixed << std::setprecision(2)  <<"Average Loss (Per Vehicle): "<< totalReturn << "%" << '\n';


        std::cout << "Average Fuel Economy (MPG): " << totalCityMPG / _fleet.size() << " / " << totalHighwayMPG / _fleet.size() <<'\n'; 
    }


};



bool Fleet::CarExists(std::string vin){
    if(_fleet.find(vin) == _fleet.end()) {
        return false;
    }

    return true;
};








