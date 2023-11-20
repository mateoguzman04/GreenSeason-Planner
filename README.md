# GreenSeason-Planner-
The GreenSeason Planner uses historical weather data for data-driven guidance, aiding farmers in optimal crop planting and livestock care decisions by analyzing temperature trends, heatwaves, and rainfall patterns.


## Files and Directories
- **main.cpp**: Contains the main program code for the GreenSeason Planner.
- **bst.h**: Header file containing the declaration of the Binary Search Tree (BST) class.
- **bst.cpp**: Source file containing the implementation of the Binary Search Tree (BST) methods.
- **converted.in**: Input file with historical weather data.

## Overview of the Project
The GreenSeason Planner is a program that analyzes historical weather data to provide data-driven recommendations for optimal agricultural timing. The project aims to assist farmers and agricultural enthusiasts in making informed decisions about planting crops and raising livestock based on temperature trends, heatwave occurrences, and rainfall patterns.

### Research Questions
- What are the optimal temperature conditions for planting crops in specific geographic locations?
- How can temperature data influence decisions related to livestock activities?

### Stakeholders
Farmers, agricultural enthusiasts, and residents of Butte County or similar geographic locations could benefit from the information and insights provided by this program.

## Problem-Solving Approach
The approach involves utilizing a Binary Search Tree (BST) to store and organize temperature data efficiently. The program analyzes historical weather data, extracts temperature information, and computes average, maximum, and minimum temperatures. The BST aids in finding the greatest and lowest temperatures for recommendations.

Key variables/inputs include temperature readings (maximum and minimum) and corresponding dates.

The chosen ADT (Abstract Data Type) is a Binary Search Tree due to its efficient search and insertion capabilities, essential for organizing temperature data and finding extreme values.

## Development Experience Overview
During the project development, challenges included handling input data, ensuring proper parsing and conversion of temperatures, and implementing BST insertion and traversal methods. Debugging and troubleshooting were essential in resolving issues related to data parsing and BST operations.

Several iterations of the algorithm were necessary to refine temperature data extraction and BST functionality.

## How to Use the Program
1. Clone the repository containing the code.
2. Compile `main.cpp`, `bst.h`, and `bst.cpp` together.
3. Ensure the `converted.in` file with historical weather data is in the directory.
4. Execute the compiled program.
5. Follow the prompts to enter your geographic location and year to receive recommendations.

For example:
```bash
$ g++ main.cpp bst.cpp -o GreenSeasonPlanner
$ ./GreenSeasonPlanner
