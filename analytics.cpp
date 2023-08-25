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

/**
 * @brief Display Menu and return choice from user
 * 
 * @return int 
 */
void displayMenu()
{
    cout<< "2015 National Survey of Recent College Graduate\n";
    cout<< "1. Top 10 Majors with the Highest Mean Salary\n";
    cout<< "2. Top 10 Majors with the Lowest Mean Salary\n";
    cout<< "3. Top 10 Majors with the Highest Median Salary\n";
    cout<< "4. Top 10 Majors with the Lowest Median Salary\n";
    cout<< "5. Top 5 Majors with the Highest Number of Asians\n";
    cout<< "6. Top 5 Majors with the Lowest Number of Asians\n";
    cout<< "7. Top 5 Majors with the Highest Number of Minorities\n";
    cout<< "8. Top 5 Majors with the Lowest Number of Minorities\n";
    cout<< "9. Top 3 Masters programs\n";
    cout<< "10. Top 3 Bachelors programs\n";
    cout<< "11. Number of Female Students in Anthropology and Archeology Major\n";
    cout<< "12. Exit\n\n";
    cout<< "Select a Menu: _\n";

}
/**
 * @brief display vector for testing purposes
 * 
 * @param grad 
 */
void displayVector(vector<GradEmploymentData> &grad)
{
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
/**
 * @brief read graduates2015.csv file
 * 
 * @param grad 
 * @param gradFile 
 */
void readFile(vector<GradEmploymentData> &grad, ifstream &gradFile)
{
    string firstLine;
    getline(gradFile,firstLine, ':');

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
/**
 * @brief displays information based on choice from user
 * 
 * @param c 
 */
void choice(vector<GradEmploymentData> &grad)
{
        int choice=0;
    do
    {
        cin >> choice;
        //Exit Menu if user selects 12
        if(choice==12)
        {
            cout<< "Exiting menu now...\n";
            exit(1);
        }

        if(choice==1)
            sortMenu1(grad, 46);

        if(choice==2)
            sortMenu2(grad, 46);

        if(choice==3)
            sortMenu3(grad, 46);

        if(choice==4)
            sortMenu4(grad, 46);

        if(choice==5)
            sortMenu5(grad, 46);

        if(choice==6)
            sortMenu6(grad, 46);

        if(choice==7)
            sortMenu7(grad, 46);

        if(choice==8)
            sortMenu8(grad, 46);

        if(choice==9)
            sortMenu9(grad, 46);

        if(choice==10)
            sortMenu10(grad, 46);

        if(choice==11)
            sortMenu11(grad, 46);

        displayMenu();
    }while(choice>=0&&choice<=12);

}
/**
 * @brief Sort and display Top 10 Majors with the Highest Mean Salary
 * 
 * @param grad 
 * @param size 
 */
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
    cout << "Top 10 Majors with the Highest Mean Salary\n\n";
    cout << "Education Major                           "<<"Mean Salary\n";
    cout << "_________________________________________________________\n";
    for(int i=0; i<10; i++)
    {
        cout<<grad[i].educationMajor<<right<<setw(45-grad[i].educationMajor.length());
        cout<<"$  "<<fixed<<setprecision(2)<<grad[i].meanSalary<<endl;
    }
    cout<<endl<<endl;
}
/**
 * @brief sort and display Top 10 Majors with the Lowest Mean Salary
 * 
 * @param grad 
 * @param size 
 */
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
    cout << "Top 10 Majors with the Lowest Mean Salary\n\n";
    cout << "Education Major                           "<<"Mean Salary\n";
    cout << "_________________________________________________________\n";
    for(int i=1; i<11; i++)
    {
        cout<<grad[i].educationMajor<<right<<setw(45-grad[i].educationMajor.length());
        cout<<"$  "<<fixed<<setprecision(2)<<grad[i].meanSalary<<endl;
    }
    cout<<endl<<endl;

}
/**
 * @brief sort and display Top 10 Majors with the Highest Median Salary
 * 
 * @param grad 
 * @param size 
 */
void sortMenu3(vector<GradEmploymentData> &grad, int size)
{
    bool madeSwap=true;
    int lastIndex=size-1;

    while(madeSwap)
    {
        madeSwap=false;
        for(int count=0; count< lastIndex; ++count)
        {
            if(grad[count].medianSalary < grad[count+1].medianSalary) //change sign here for descending order?
            {
                GradEmploymentData temp= grad[count];
                grad[count]=grad[count+1];
                grad[count+1]=temp;
                madeSwap=true;
            }
        }
        --lastIndex;
    }
    cout << "Top 10 Majors with the Highest Median Salary\n\n";
    cout << "Education Major                           "<<"Median Salary\n";
    cout << "_________________________________________________________\n";
    for(int i=0; i<10; i++)
    {
        cout<<grad[i].educationMajor<<right<<setw(45-grad[i].educationMajor.length());
        cout<<"$  "<<fixed<<setprecision(2)<<grad[i].medianSalary<<endl;
    }
    cout<<endl<<endl;
}
/**
 * @brief sort and display Top 10 Majors with the Lowest Median Salary
 * 
 * @param grad 
 * @param size 
 */
void sortMenu4(vector<GradEmploymentData> &grad, int size)
{
    bool madeSwap=true;
    int lastIndex=size-1;

    while(madeSwap)
    {
        madeSwap=false;
        for(int count=0; count< lastIndex; ++count)
        {
            if(grad[count].medianSalary > grad[count+1].medianSalary) //change sign here for descending order?
            {
                GradEmploymentData temp= grad[count];
                grad[count]=grad[count+1];
                grad[count+1]=temp;
                madeSwap=true;
            }
        }
        --lastIndex;
    }
    cout << "Top 10 Majors with the Lowest Median Salary\n\n";
    cout << "Education Major                           "<<"Median Salary\n";
    cout << "_________________________________________________________\n";
    for(int i=1; i<11; i++)
    {
        cout<<grad[i].educationMajor<<right<<setw(45-grad[i].educationMajor.length());
        cout<<"$  "<<fixed<<setprecision(2)<<grad[i].medianSalary<<endl;
    }
    cout<<endl<<endl;
}
/**
 * @brief sort and display Top 5 Majors with the Highest Number of Asians
 * 
 * @param grad 
 * @param size 
 */
void sortMenu5(vector<GradEmploymentData> &grad, int size)
{
    bool madeSwap=true;
    int lastIndex=size-1;

    while(madeSwap)
    {
        madeSwap=false;
        for(int count=0; count< lastIndex; ++count)
        {
            if(grad[count].demographicsAsian < grad[count+1].demographicsAsian) //change sign here for descending order?
            {
                GradEmploymentData temp= grad[count];
                grad[count]=grad[count+1];
                grad[count+1]=temp;
                madeSwap=true;
            }
        }
        --lastIndex;
    }
    cout << "Top 5 Majors with the Highest Number of Asians\n\n";
    cout << "Education Major                    "<<"Asian Demographic Total\n";
    cout << "__________________________________________________________\n";
    for(int i=0; i<5; i++)
    {
        cout<<grad[i].educationMajor<<right<<setw(45-grad[i].educationMajor.length());
        cout<<grad[i].demographicsAsian<<endl;
    }
    cout<<endl<<endl;
}
/**
 * @brief sort and display Top 5 Majors with the Lowest Number of Asians
 * 
 * @param grad 
 * @param size 
 */
void sortMenu6(vector<GradEmploymentData> &grad, int size)
{
    bool madeSwap=true;
    int lastIndex=size-1;

    while(madeSwap)
    {
        madeSwap=false;
        for(int count=0; count< lastIndex; ++count)
        {
            if(grad[count].demographicsAsian > grad[count+1].demographicsAsian) //change sign here for descending order?
            {
                GradEmploymentData temp= grad[count];
                grad[count]=grad[count+1];
                grad[count+1]=temp;
                madeSwap=true;
            }
        }
        --lastIndex;
    }
    cout << "Top 5 Majors with the Lowest Number of Asians\n\n";
    cout << "Education Major                    "<<"Asian Demographic Total\n";
    cout << "__________________________________________________________\n";
    for(int i=1; i<6; i++)
    {
        cout<<grad[i].educationMajor<<right<<setw(45-grad[i].educationMajor.length());
        cout<<grad[i].demographicsAsian<<endl;
    }
    cout<<endl<<endl;
}
/**
 * @brief sort and display Top 5 Majors with the Highest Number of Minorities
 * 
 * @param grad 
 * @param size 
 */
void sortMenu7(vector<GradEmploymentData> &grad, int size)
{
    bool madeSwap=true;
    int lastIndex=size-1;

    while(madeSwap)
    {
        madeSwap=false;
        for(int count=0; count< lastIndex; ++count)
        {
            if(grad[count].demographicsMinority < grad[count+1].demographicsMinority)//change sign here for descending order?
            {
                GradEmploymentData temp= grad[count];
                grad[count]=grad[count+1];
                grad[count+1]=temp;
                madeSwap=true;
            }
        }
        --lastIndex;
    }

    cout << "Top 5 Majors with the Highest Number of Minorities\n\n";
    cout << "Education Major                    "<<"Minority Demographic Total\n";
    cout << "__________________________________________________________\n";
    for(int i=0; i<5; i++)
    {
        cout<<grad[i].educationMajor<<right<<setw(45-grad[i].educationMajor.length());
        cout<<grad[i].demographicsMinority<<endl;
    }
    cout<<endl<<endl;
}
/**
 * @brief Sort and display the Top 5 Majors 
 * with the Lowest Number of Minorities
 * 
 * @param grad 
 * @param size 
 */
void sortMenu8(vector<GradEmploymentData> &grad, int size)
{
    bool madeSwap=true;
    int lastIndex=size-1;

    while(madeSwap)
    {
        madeSwap=false;
        for(int count=0; count< lastIndex; ++count)
        {
            if(grad[count].demographicsMinority > grad[count+1].demographicsMinority) //change sign here for descending order?
            {
                GradEmploymentData temp= grad[count];
                grad[count]=grad[count+1];
                grad[count+1]=temp;
                madeSwap=true;
            }
        }
        --lastIndex;
    }
    cout<< "Top 5 Majors with the Lowest Number of Minorities\n\n";
    cout << "Education Major                    "<<"Minority Demographic Total\n";
    cout << "__________________________________________________________\n";
    for(int i=1; i<6; i++)
    {
        cout<<grad[i].educationMajor<<right<<setw(55-grad[i].educationMajor.length());
        cout<<grad[i].demographicsMinority<<endl;
    }
    cout<<endl<<endl;
}
/**
 * @brief Sort and dislay Top 3 Masters programs
 * 
 * @param grad 
 * @param size 
 */
void sortMenu9(vector<GradEmploymentData> &grad, int size)
{
    bool madeSwap=true;
    int lastIndex=size-1;

    while(madeSwap)
    {
        madeSwap=false;
        for(int count=0; count< lastIndex; ++count)
        {
            if(grad[count].educationMasters> grad[count+1].educationMasters) //change sign here for descending order
            {
                GradEmploymentData temp= grad[count];
                grad[count]=grad[count+1];
                grad[count+1]=temp;
                madeSwap=true;
            }
        }
        --lastIndex;
    }
    cout<< "Top 3 Masters programs\n\n";
    cout << "Education Major                    "<<"Total Number of Students\n";
    cout << "__________________________________________________________\n";
    for(int i=0; i<3; i++)
    {
        cout<<grad[i].educationMajor<<right<<setw(55-grad[i].educationMajor.length());
        cout<<grad[i].educationMasters<<endl;
    }
    cout<<endl<<endl;

}
/**
 * @brief Sort and Display Top 3 Bachelors programs
 * 
 * @param grad 
 * @param size 
 */
void sortMenu10(vector<GradEmploymentData> &grad, int size)
{
    bool madeSwap=true;
    int lastIndex=size-1;

    while(madeSwap)
    {
        madeSwap=false;
        for(int count=0; count< lastIndex; ++count)
        {
            if(grad[count].educationBachelor> grad[count+1].educationBachelor) //change sign here for descending order
            {
                GradEmploymentData temp= grad[count];
                grad[count]=grad[count+1];
                grad[count+1]=temp;
                madeSwap=true;
            }
        }
        --lastIndex;
    }
    cout<< "Top 3 Bachelors programs\n\n";
    cout << "Education Major                    "<<"Total Number of Students\n";
    cout << "__________________________________________________________\n";
    for(int i=0; i<3; i++)
    {
        cout<<grad[i].educationMajor<<right<<setw(55-grad[i].educationMajor.length());
        cout<<grad[i].educationBachelor<<endl;
    }
    cout<<endl<<endl;

}
/**
 * @brief Sort and Display Number of Female Students in Anthropology and Archeology Major
 * 
 * @param grad 
 * @param size 
 */
void sortMenu11(vector<GradEmploymentData> &grad, int size)
{
    cout << "Number of Female Students in Anthropology and Archeology Major\n\n";
    cout << "Anthropology/Archaelogy Major                    "<<"Female Student Total\n";
    cout << "__________________________________________________________\n";

    cout<<grad[2].educationMajor<<right<<setw(55-grad[2].educationMajor.length());
    cout<<grad[2].demographicsFemales<<endl;

    cout<<endl<<endl;

}
