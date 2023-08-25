/**
 * @file analytics.cpp
 * @author Mikayla Winant
 * @brief 
 * @version 0.1
 * @date 2023-08-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "analytics.h"

//Function Definition
int displayMenu()
{
    int menu;
        
        cout<< "2015 National Survey of Recent College Graduate\n";
        cout<< "1. Top 10 Majors with the Highest Mean Salary\n";
        cout<< "2. Top 10 Majors with the Lowest Mean Salary\n";
        cout<< "3. Top 10 Majors with the Highest Median Salary\n";
        cout<< "4. Top 10 Majors with the Lowest Median Salary\n";
        cout<< "5. What are the Top 5 Majors with the Highest Number of Asians\n";
        cout<< "6. What are the Top 5 Majors with the Lowest Number of Asians\n";
        cout<< "7. What are the Top 5 Majors with the Highest Number of Minorities\n";
        cout<< "8. What are the Top 5 Majors with the Lowest Number of Minorities\n";
        cout<< "9. <Design and implement a menu item that provides information through the data\n";
        cout<< "10. <Design and implement a menu item that provides information through the data\n";
        cout<< "11. Display Information for a Specific Major\n";
        cout<< "12. Exit\n\n";
        cout<< "Select a Menu: _\n";
        do{
            cin >> menu;
             
        }while(menu<1 || menu>12);
        //Exit Menu if user selects 12
        if(menu==12)
        {
            cout<< "Exiting menu now...\n";
            exit(1);
        }
    return menu;

}
void displayVector(vector<GradEmploymentData> &grad)
{
    cout<< "Demographics Total  Education Major  Mean Salary  Median Salary  Asain Dem.  ";
    cout<< "Minority Dem.  White Dem. Female  Male  Bachelors  Doctorate  Masters\n";
    for(int i=0; i<grad.size(); i++)
    {
        cout<< grad[i].demographicsTotal<<" "<<grad[i].educationMajor<<" "<<grad[i].meanSalary<<" ";
        cout<< grad[i].medianSalary<<" "<<grad[i].demographicsAsian<<" "<<grad[i].demographicsMinority<<" ";
        cout<< grad[i].demographicsWhite<<" "<<grad[i].demographicsFemales<<" ";
        cout<< grad[i].demographicsMales<<" ";
        cout<< grad[i].educationBachelor<<" "<<grad[i].educationDoctorate<<" "<<grad[i].educationMasters;
        cout<< endl;
    }
}
void menu1(int menu)
{
    
}