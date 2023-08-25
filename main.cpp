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
#include "analytics.h"
using namespace std;

int main()
{
    //displayMenu();

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
    while(gradFile.peek()!=EOF)
    {  
        GradEmploymentData line;
            //reading demographics total and comma
            char delim;
            gradFile >>line.demographicsTotal>>delim;

            //reading education major and comma
            getline(gradFile, line.educationMajor, ',');
            //reading mean salary and comma
            gradFile>> line.meanSalary>>delim;
            //reading median salary and comma
            gradFile>>line.medianSalary>>delim;
            //reading Asian Demographic total and comma
            gradFile>>line.demographicsAsian>>delim;
            //reading minority demographic total and comma
            gradFile>>line.demographicsMinority>>delim;
            //reading white demographic total and comma
            gradFile>>line.demographicsWhite>>delim;
            //reading female total and comma
            gradFile>>line.demographicsFemales>>delim;
            //reading male total and comma
            gradFile>>line.demographicsMales>>delim;
            //reading bachelor degree total and comma
            gradFile>>line.educationBachelor>>delim;
            //reading doctorate degree total and comma
            gradFile>>line.educationDoctorate>>delim;
            //reading masters degree total and comma
            gradFile>>line.educationMasters;

            grad.push_back(line);

    }

    //display vector
    displayVector(grad);


    return 0;
}