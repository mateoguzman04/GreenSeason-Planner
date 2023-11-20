#include "bst.h"

TemperatureNode::TemperatureNode(const std::string& d, double maxTemp, double minTemp)
    : date(d), maxTemperature(maxTemp), minTemperature(minTemp), left(nullptr), right(nullptr) {}

TemperatureBST::TemperatureBST() : root(nullptr) {}

void TemperatureBST::insert(const std::string& date, double maxTemp, double minTemp) {
    insertNode(root, date, maxTemp, minTemp);
}

void TemperatureBST::insertNode(TemperatureNode*& node, const std::string& date, double maxTemp, double minTemp) {
        if (!node) {
            node = new TemperatureNode(date, maxTemp, minTemp);
        } else {
            if (maxTemp > node->maxTemperature) {
                insertNode(node->right, date, maxTemp, minTemp);
            } else if (maxTemp < node->maxTemperature) {
                insertNode(node->left, date, maxTemp, minTemp);
            } else {
                 // If max temperatures are equal, compare based on min temperature
                if (minTemp > node->minTemperature) {
                    insertNode(node->right, date, maxTemp, minTemp);
                } else {
                    insertNode(node->left, date, maxTemp, minTemp);
                }
            }
        }
}

double TemperatureBST::findGreatestTemperature() {
     TemperatureNode* maxNode = findMax(root);
        if (maxNode) {
            return maxNode->maxTemperature;
        } else {
            return -1; // Return a default value indicating no temperature found
        }
}

double TemperatureBST::findMinimumTemperature() {
           TemperatureNode* minNode = findMin(root);
        if(minNode) {
            return minNode->minTemperature;
        } else {
            return -1; // Return a default value indicating no temperature foun
        }
}

TemperatureNode* TemperatureBST::findMax(TemperatureNode* node) {
    while (node->right) {
        node = node->right;
    }
    return node;
}

TemperatureNode* TemperatureBST::findMin(TemperatureNode* node) {
    while(node->left) {
        node = node->left;
        }
    return node;
}

