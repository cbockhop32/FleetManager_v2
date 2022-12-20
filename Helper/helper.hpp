#pragma once

#include "../Fleet/fleet.hpp"
#include <iostream>

void
mainFunctionCaller(int userChoice, Fleet& fleet);
Car
addCarHelper(std::string vin);
std::string
vinRetriever(std::string action);
void
uppercaseInput(std::string& carInput);
