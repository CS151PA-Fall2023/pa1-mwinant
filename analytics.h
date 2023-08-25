/**
 * @file analytics.h
 * @author Mikayla Winant
 * @brief 
 * @version 0.1
 * @date 2023-08-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;


#ifndef ANALYTICS_H
#define ANALYTICS_H
//Struct Definition
struct GradEmploymentData
{
    int demographicsTotal;     // The estimated total of people awarded degrees in this major during 2005
    string educationMajor;     // The name of the major for these graduated students
    float meanSalary;          // The average (mean) recorded salary reported for employed people with this degree
    float medianSalary;        // The median recorded salary reported for employed people with this degree
    int demographicsAsian;     // The estimated number of people identifying as Asian that were awarded degrees in this major
    int demographicsMinority;  // The estimated number of people identifying as minority 
                               // (e.g., Black, African American, Native American) that were awarded degrees in this major
    int demographicsWhite;     // The estimated number of people identifying as White that were awarded degrees in this major
    int demographicsFemales;   // The estimate number of women awarded degrees in this major
    int demographicsMales;     // The estimate number of men awarded degrees in this major
    int educationBachelor;     // The estimated number of bachelor degrees awarded in this for major
    int educationDoctorate;    // The estimated number of doctoral degrees awarded in this for major
    int educationMasters;      // The estimated number of Masters awarded in this for major
};

//Function Headers
int displayMenu();
void displayVector(vector<GradEmploymentData> &grad);
void readFile(vector<GradEmploymentData> &grad, ifstream &gradFile);
void sortMenu1(vector<GradEmploymentData> &grad, int size);
void sortMenu2(vector<GradEmploymentData> &grad, int size);



// END GUARD CODE
#endif