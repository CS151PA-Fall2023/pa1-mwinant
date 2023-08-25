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

    //display main menu
    displayMenu();

    //display vector (testing)
    //displayVector(grad);

    int choice=displayMenu();
    if(choice==1)
    {
        sortMenu1(grad, 46);
    }

    if(choice==2)
    {
        sortMenu2(grad, 46);
    }

    if(choice==3)
    cout<< "test2\n";

    /**switch(choice){
        case 1:
            menu1(grad);
            break;
        case 2:
            cout<< "test\n";
            break;
        case 3:
            cout<< "test2\n";
            break;
        //add case 2-12
    }
    **/

    return 0;
}