#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>

struct TemperatureNode {
    std::string date;
    double maxTemperature;
    double minTemperature;
    TemperatureNode* left;
    TemperatureNode* right;

    TemperatureNode(const std::string& d, double maxTemp, double minTemp);
};

class TemperatureBST {
private:
    TemperatureNode* root;

    void insertNode(TemperatureNode*& node, const std::string& date, double maxTemp, double minTemp);
    TemperatureNode* findMax(TemperatureNode* node);
    TemperatureNode* findMin(TemperatureNode* node);

public:
    TemperatureBST();
    void insert(const std::string& date, double maxTemp, double minTemp);
    double findGreatestTemperature();
    double findMinimumTemperature();
};

#endif 
