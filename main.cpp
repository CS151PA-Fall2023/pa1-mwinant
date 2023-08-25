/**
 * @file main.cpp
 * @author Mikayla Winant
 * @brief 
 * @version 0.1
 * @date 2023-08-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include "analytics.h"
using namespace std;

int main()
{
    //opening file
    ifstream gradFile;
    gradFile.open("graduates2015.csv");

    //if file does not open
    if(!gradFile)
    {
        cout<< "Error opening file\n";
        exit(1);
    }
    //create vector to store data
    vector<GradEmploymentData> grad;

    //reading file
    readFile(grad, gradFile);
    //display vector test
    //displayVector(grad);
    //display main menu
    displayMenu();
    choice(grad);


    return 0;
}