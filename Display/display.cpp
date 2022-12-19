
#include <iostream>
#include <string>
#include <chrono>
#include <thread>

#include "display.hpp"
#include "../Helper/helper.hpp"




void Init(Fleet& fleet) {

    bool isRunning {true};
    std::string functionCmd;

    std::string introPrompt = 
    "\n ~~ Welcome to Fleet Manager ~~ \n\n"
    "Fleet Manager will allow you to easily manage your fleet of automobiles.\n\n"
    
    "Please choose from the following options: \n";


    std::string commandPrompt = 
        "\n\nEnter the following numbers to execute the following commands: \n\n"
        "1 :  Add A Car\n"
        "2 :  Remove A Car\n"
        "3 :  Edit An Existing Cars Details \n"
        "4 :  List All Current Cars \n"
        "5 :  Look Up Car In Fleet By VIN \n"
        "6 :  List Fleet Statistics \n"
        "7 :  Help Page \n\n"
        "Enter Command:  ";

    std::cout << introPrompt << "\n";

    do{
        std::cout << commandPrompt;
        std::getline(std::cin, functionCmd);

        mainFunctionCaller(stoi(functionCmd), fleet);

    }
    while(isRunning != false);



};


void helpPage() {
     bool helpRunning = true;
        
        std::string helpCommands = 
        "\n\n Enter the following numbers to get more info: \n\n"
        "1 :  How To Add A Car\n"
        "2 :  How To Remove A Car\n"
        "3 :  How to Edit Existing Car Details \n"
        "4 :  List All Current Cars \n"
        "5 :  Look Up Car In Fleet By VIN \n"
        "6 :  Fleet Statistics and Calculation Methodology \n"

        "0 :  Go Back To Main Menu\n\n"
        "Enter a menu option: ";

        do{
            std::cout << helpCommands;
            std::string helpInput;
            std::getline(std::cin, helpInput);
          
            switch (stoi(helpInput))
            {
                case 1:
                    addHelp();
                    break;
                case 2:
                    removeHelp();
                    break;
                case 3:
                    editHelp();
                    break;
                case 4:
                    listAllHelp();
                    break;
                case 5:
                    lookUpHelp();
                    break;
                case 6:
                    fleetStatsHelp();
                    break;
                case 0:
                    std::cout << "Going back to main menu" <<std::endl;
                    helpRunning = false;
                    break;
                default:
                    std::cout << "Invalid command" << std::endl;
            }

            // Slight delay before help menu pops up again unless you're going back to the main menu
            if(stoi(helpInput) != 0) {
                std::this_thread::sleep_for(std::chrono::milliseconds(1500));

            }
        } while(helpRunning != false);    

};

void addHelp(){
    std::string helpInfo = 
        "\n*** ADD A CAR TO THE FLEET HELP ***\n"

        "\n\n To add a car, you will need the following information: \n"
        "   1. VIN Number (Required)\n"      
        "       - A VIN number is required to add a car\n"
        "       - You can add a car with only just the VIN number and then choose to edit the other details \n"
        "           later using the Edit functionality\n\n"
        "   2. Model Year (Optional)\n"      
        "       - A Model Year of the car is optional at first and can be added later using the Edit functionality\n"
        "       - Please enter a four digit year (example: 2018)\n\n"
        "   3. Make (Optional)\n"      
        "       - A Make of the car is optional at first and can be added later using the Edit functionality\n\n"
        "   4. Model (Optional)\n"      
        "       - A Model of the car is optional at first and can be added later using the Edit functionality\n\n"
        ;

        std::cout << helpInfo << '\n';

};

void removeHelp(){
    std::string helpInfo = 
       "\n*** REMOVE A CAR FROM THE FLEET HELP ***\n"
        "\n"
        "   To remove a car, you will need the VIN number of the car that you want to be removed. \n"
        "   The car needs to exist in order to use the remove functionality. If a VIN number is entered that does not exist in the fleet.\n"      
        "   The program will return back to the main menu.\n\n"
        "   Once a valid VIN number is entered, the program will prompt the user to confirm the removal of the car, providing the \n"
        "   details of the car to removed. \n\n"
        "   Once the user has confirmed the removal of the car, the user can check that the car has been removed from the fleet by going to the\n"
        "   main menu and using the 'List All Current Cars' functionality to check if the car has been removed."
        ;

    std::cout << helpInfo << '\n';

};

void editHelp(){
    std::string helpInfo = 
        "\n*** EDIT A CAR'S DETAILS HELP ***\n"
        "\n\n To edit the details of a car, you first need to add the car in order to use this functionality. \n"
        "\n\n You will first be prompted to enter a VIN number of the car you would like to edit\n"
        " Again, the car has to exist within the fleet in order for the edit functionality to work\n\n"
        " You can either choose to enter a new value for a given attribute or you can keep the current value by pressing enter. \n"
        " You cannot change the VIN number of the car, if you want to change the VIN number, you first have to delete that specific car\n"
        " and then add another car with the desired VIN number"
        ;
    std::cout << helpInfo << '\n';

};

void listAllHelp(){
    std::string helpInfo = 
        "\n*** LISTING ALL THE CURRENT CARS IN THE FLEET HELP ***\n"
        "\n\n This will list all the current cars that have been added to your fleet. \n"
        "\n\n This can be used to get information quickly on cars (i.e. look up VIN numbers, model years, etc.)\n"
        " If a specific vehicle attribute has been left blank by the user, it will display 'None' within the list of vehicles."
        ;
    std::cout << helpInfo << '\n';


};

void lookUpHelp(){
    std::string helpInfo = 
        "\n*** LOOK UP CAR BY VIN NUMBER HELP ***\n"
        "\n\n You can look up a car within your fleet by VIN number \n"
        " The VIN number must be valid as-in a car exists in your fleet with that exact VIN number\n"
        " If your fleet does not contain a car with your VIN number then it will return to the main menu\n"
        "\n\n Once the car is found then it will display all the details/attributes associated with that car\n";
    std::cout << helpInfo << '\n';
};


void fleetStatsHelp(){
    std::string helpInfo = 
        "\n*** SEE CURRENT FLEET STATISTICS HELP ***\n"
        "\n\n You can generate the current statistics accross your entire fleet. \n"
        " You will be able to see the average MSRP (price) across all your vehichles in your fleet.\n"
        "   This is calculated by taking each of the car's respective MSRPs and then dividing it by the number of cars in your fleet\n"
        "\n\n You will be able to see the averge fuel economy (in miles per gallon) across all your vehichles in your fleet\n"
        "   This will be listed by the average city MPG and then the average highway MPG\n"
        "   This is calculated by adding up the city and highway MPG across all the cars in your fleets and then dividing it by the number of vehichles in your fleet\n";


    std::cout << helpInfo << '\n';

};


