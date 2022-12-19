#pragma once

#include <iostream>
#include "../Fleet/fleet.hpp"




void mainFunctionCaller(int userChoice, Fleet& fleet);
Car addCarHelper(std::string vin);
std::string vinRetriever(std::string action);
void uppercaseInput(std::string& carInput);

