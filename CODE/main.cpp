#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "bst.h"




// Function determineCity declaration
void determineCity(std::string cityName, int year);

int main(){
    std::string userConfirmation; // user choice to start the program
    std::string cityUser; // user input for city
    int yearUser; // user input for year

    std::cout << "🌱 Welcome to GreenSeason Planner - Your Agricultural Timing Advisor!" << std::endl;
    std::cout << "Are you a farmer or agricultural enthusiast looking for the perfect time to start your planting and livestock activities? (yes/no)  ";
  

    while (true) {
        std::cin >> userConfirmation; 
        std::cout << std::endl;
        if (userConfirmation == "yes") {
            std::cout << "Look no further! GreenSeason Planner is here to provide you with data-driven recommendations for optimal agricultural timing.\n\n📊 Our program analyzes historical weather data from 2018 to 2022, including temperature trends, heatwave occurrences, and rainfall patterns in your specific location.\n\n💡 We've crunched the numbers to help you make informed decisions about when to plant crops and raise livestock." << std::endl;
            std::cout << "To get started, simply enter your geographic location." << std::endl;
            std::cout << "Please note that this app is designed for residents of Butte County in the following cities:" << std::endl;
            
            std::cout << "   - CHICO" << std::endl;
            std::cout << "   - MAGALIA" << std::endl;
            std::cout << "   - PARADISE" << std::endl;
            std::cout << "   - DE SABLA" << std::endl;
            std::cout << "   - COHASSET" << std::endl;
            std::cout << "If your city is not listed, please select the closest one to your location." << std::endl;   
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer        
            while (true) {
                getline(std::cin, cityUser);
                if (cityUser == "CHICO" || cityUser == "MAGALIA" || cityUser == "PARADISE" ||
                cityUser == "DE SABLA" || cityUser == "COHASSET") {
                    std::cout << "Enter a year (2018 - 2022)" <<std::endl;
                    std::cin>> yearUser;
                    determineCity(cityUser, yearUser); // Analyze weather data for the user's selected city
                    break;
                } else {
                    std::cout << "\nInvalid input. Please try again." << std::endl;
                }
            }
            std::cout << "\nDo you want to go again?(yes/no)" <<std::endl;
        }else if (userConfirmation == "no") {
            std::cout << "Goodbye!" << std::endl;
            break; // exit the while loop
        }else{  
            std::cout << "Invalid Input. Please enter either 'yes' or 'no'." << std::endl;
        }
    }
    return 0;
}



void determineCity(std::string cityName, int year) {
    std::ifstream inFile("converted.in");

    if (!inFile) {
        std::cerr << "Failed to open the input file." << std::endl;
        return;
    }

    double totalAverageTemperature = 0.0;
    int dataCount = 0;

    TemperatureBST temperatureBST; //

    std::string station, name, name2, date, dapr, mdpr, prcp, snow, snwd, tavg, tmax, tmin, tobs;

    while (std::getline(inFile, name) && std::getline(inFile, name2) >> date >> dapr >> mdpr >>
           prcp >> snow >> snwd >> tavg >> tmax >> tmin >> tobs) {
        name = name + name2; // creates name without a comma
        if (name.find(cityName) != std::string::npos && date.substr(0, 4) == std::to_string(year)) {

            try {
                double maxTemp = std::stod(tmax);
                double minTemp = std::stod(tmin);
                std::cout << "Maximum Temperature: " << maxTemp << "     " << date << std::endl;
                std::cout << "Minimum Temperature: " << minTemp << "     " << std::endl << std::endl;

                // Add temperature data to the BST
                temperatureBST.insert(date, maxTemp, minTemp);

                // Calculate the total average temperature
                totalAverageTemperature += maxTemp;
                dataCount++;
            } catch (const std::invalid_argument& e) {
                // std::cerr << "Error converting tavg to a double: " << e.what() << std::endl;
            }
        }
    }
    inFile.close();

    if (dataCount > 0) {
        double average = totalAverageTemperature / dataCount;
        std::cout << "Overall Average Temperature: " << average << std::endl;

        // Find and display the greatest temperature using the BST
        double greatestTemperature = temperatureBST.findGreatestTemperature();
        double lowestTemperature = temperatureBST.findMinimumTemperature();
        if (greatestTemperature != -1) {
            std::cout << "Highest Temperature: " << greatestTemperature << std::endl; // Print the highest temperature
        } else {
            std::cerr << "No temperature data found in the input file." << std::endl;
        }
        if (lowestTemperature != -1) {
            std::cout << "Lowest Temperature: " << lowestTemperature << std::endl; // Print the lowest temperature
        } else {
            std::cerr << "No temperature data found in the input file." << std::endl;
        }


         if (greatestTemperature != -1 && lowestTemperature != -1) {

        std::cout << "\nRecommendations for planting and livestock activities:" << std::endl;
        std::cout << "--------------------------------------------------" << std::endl;

// Planting Conditions -------------------------------->>>>>>>>>>>>>>>>
        if (average > 50 && average < 85) {
            std::cout << "Optimal temperature conditions suggest a good time for planting." << std::endl;
        } else if (average >= 85) {
            std::cout << "High temperatures indicate a suitable time for heat-resistant crops or late planting." << std::endl;
        } else {
            std::cout << "Low temperatures may limit certain crops. Consider cold-resistant varieties." << std::endl;
        }
//-------------------------------->>>>>>>>>>>>>>>>

// Livestock Conditions -------------------------------->>>>>>>>>>>>>>>>
        if (average > 35 && average < 75) {
            std::cout << "Moderate temperatures favor livestock activities." << std::endl;
        } else if (average >= 75) {
            std::cout << "High temperatures may require extra care and cooling measures for livestock." << std::endl;
        } else {
            std::cout << "Low temperatures may need additional shelter or warmth for livestock." << std::endl;
        }
//-------------------------------->>>>>>>>>>>>>>>>
        } else {
            std::cerr << "Insufficient temperature data to provide recommendations." << std::endl;
        }
    } else {
        std::cerr << "No valid data found in the input file." << std::endl;
    }
}

