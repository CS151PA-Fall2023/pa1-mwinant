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
        cin >> menu;
        if(menu<0 || menu>12)
        {
            cout<< "Invalid Menu, Please Try Again\n";
            cin >> menu;
        }
        //Exit Menu if user selects 12
        if(menu==12)
        {
            cout<< "Exiting menu now...\n";
            exit(1);
        }
        else
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
void readFile(vector<GradEmploymentData> &grad, ifstream &gradFile)
{
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
}
void sortMenu1(vector<GradEmploymentData> &grad, int size)
{
    bool madeSwap=true;
    int lastIndex=size-1;

    while(madeSwap)
    {
        madeSwap=false;
        for(int count=0; count< lastIndex; ++count)
        {
            if(grad[count].meanSalary < grad[count+1].meanSalary) //change sign here for descending order?
            {
                GradEmploymentData temp= grad[count];
                grad[count]=grad[count+1];
                grad[count+1]=temp;
                madeSwap=true;
            }
        }
        --lastIndex;
    }
    cout << "Education Major                           "<<"Mean Salary\n";
    cout << "_________________________________________________________\n";
    for(int i=0; i<10; i++)
    {
        cout<<grad[i].educationMajor<<right<<setw(45-grad[i].educationMajor.length());
        cout<<"$  "<<fixed<<setprecision(2)<<grad[i].meanSalary<<endl;
    }
}
void sortMenu2(vector<GradEmploymentData> &grad, int size)
{
    bool madeSwap=true;
    int lastIndex=size-1;

    while(madeSwap)
    {
        madeSwap=false;
        for(int count=0; count< lastIndex; ++count)
        {
            if(grad[count].meanSalary > grad[count+1].meanSalary) //change sign here for descending order
            {
                GradEmploymentData temp= grad[count];
                grad[count]=grad[count+1];
                grad[count+1]=temp;
                madeSwap=true;
            }
        }
        --lastIndex;
    }
    cout << "Education Major                           "<<"Mean Salary\n";
    cout << "_________________________________________________________\n";
    for(int i=1; i<11; i++)
    {
        cout<<grad[i].educationMajor<<right<<setw(45-grad[i].educationMajor.length());
        cout<<"$  "<<fixed<<setprecision(2)<<grad[i].meanSalary<<endl;
    }

}
