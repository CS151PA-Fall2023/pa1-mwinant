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
    do{
        
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

        cin >> menu;
        if(menu<1 || menu>12)
        {
        cout<< "Invalid menu, please try again\n\n\n";
        }
    }while(menu<1 || menu>12);
    return menu;



}