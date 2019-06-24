#include <iostream>
#include "Functions.h"
#include <fstream>
#include <chrono>

using namespace std;

int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    float grade;
    vector<program> pupil;
    int i;
    char decision_2;
    cout << "Want to read the text file? y/n\n";
    cin >> decision_2;
    switch (decision_2)
    {
    case 'y':
    {
        int f=0;
        ifstream myfile("book.txt");
        if (myfile.is_open())
        {
            int a,b,c,d,e,f_assessment;
            string name_text,last name_text;
            myfile.ignore(150, '\n');

            while (myfile >> name_text >> last name_text >> a >> b >> c >> d >> e >> f_assessment)
            {

                pupil.push_back(program());

                pupil[f].name = name_text;
                pupil[f].last name = last name_text;
                pupil[f].homework.push_back(a);
                pupil[f].homework.push_back(b);
                pupil[f].homework.push_back(c);
                pupil[f].homework.push_back(d);
                pupil[f].homework.push_back(e);
                pupil[f].assessment = f_assessment;
                pupil[f].concluding_mark = concluding_mark_average_function(pupil[f].homework, pupil[f].assessment);
                pupil[f].concluding_mark_median = concluding_mark_median_function(pupil[f].homework, pupil[f].assessment);
                f++;
            }
        }
        else {cout << "Unable to open the file";}
        break;
    }


    case 'n':
    {
        for(i=0; i<999; i++)
        {
            string name_short term, last name_short term;
            cout << "Please enter pupil's name: \n";
            cin >> name_short term;
            pupil.push_back(program());
            pupil[i].name = name_short term;
            if (name_short term == "0") break;

            cout << "Enter pupil's last name: \n";
            try
            {
                cin >> last name_short term;
                if (last name_short term == "0")
                    throw "Incorrect input!";
                pupil[i].last name = last name_short term;
            }
            catch (const char* msg)
            {
                pupil[i].last name = "ERROR";
                cout << msg << endl;
            }


            float total_homework_short term = 0;
            int k;
            float assessment_short term, concluding_mark_short term;

            cout << "Do you want to generate random numbers as grades for homework? (y/n): \n";
            char decision;
            cin >> decision;
            switch (decision)
            {
            case 'n':
                for ( k=0; k>-1; k++)
                {
                    int input;
                    cout << "Enter value of homework " << k+1 << ":\n";
                    cin >> input;
                    pupil[i].homework.push_back(input);
                    if (!cin || input == 0 || input > 10) break;
                }

                cout << "Enter pupil's mark for the assessment: \n";
                cin >> assessment_short term;
                if (!cin || assessment_short term == 0 || assessment_short term > 10) break;
                pupil[i].assessment = assessment_short term;
                break;


            case 'y':
                cout << "Enter number of homeworks: ";
                int number_homeworks;
                cin >> number_homeworks;
                for(int m=0; m<number_homeworks; m++)
                {
                    pupil[i].homework.push_back(rand()%11);
                }
                pupil[i].assessment = rand()%11;
                break;

            default:
                cout << "Incorrect input!";
                break;
            }
            try
            {
                if (pupil[i].homework[0]==0 || pupil[i].assessment==0)
                    throw "The pupil can not be evaluated because:";
                pupil[i].concluding_mark_median = concluding_mark_median_function(pupil[i].homework, pupil[i].assessment);
                pupil[i].concluding_mark = concluding_mark_average_function(pupil[i].homework, pupil[i].assessment);
            }
            catch(const char* msg)
            {
                cout << msg << endl;
                cout << "  1) They does not have any evaluated homework;\n  2) They did not take the concluding assessment."<< endl;
            }

        }
        break;}

    default:
        cout << "Incorrect input!";
        break;
    }
    try
    {
        if ((decision_2 != 'y' && decision_2 != 'n') || pupil[0].name == "0")
            throw "No data to output!";
        vector<program> failed_vector;
        vector<program> passed_vector;
        ofstream failed, passed;
        for (int i=0; i<pupil.size(); i++)
        {
            if(pupil[i].concluding_mark<5)
            {
                failed_vector.push_back(pupil[i]);
            }
        else
            passed_vector.push_back(pupil[i]);
        }
        pupil.clear();
        pupil.shrink_to_fit();

        failed.open("failed.txt");
        failed << left << setw(90) << " List of pupils who failed the subject";
        failed << setfill('*') << setw(90) << "*" << setfill(' ') << endl;
        failed << left << setw(30) << "Name" << setw(30) << "Last name" << right << setw(30) << "Concluding grade (Avg.)" << left << setw(30) << "/ Concluding grade (Med.)" << endl;
        failed << setfill('*') << setw(90) << "*" << setfill(' ') << endl;
        for (int i=0; i<failed_vector.size(); i++)
        {
            failed << left << setw(30) << failed_vector[i].name << setw(30) << failed_vector[i].last name
                << right << setw(30) << setprecision(2) << fixed << failed_vector[i].concluding_mark << right << setw(30) << failed_vector[i].concluding_mark_median << '\n';
        }
        failed.close();

        passed.open("passed.txt");
        passed << left << setw(90) << " List of pupils who passed the subject";
        passed << setfill('*') << setw(90) << "*" << setfill(' ') << endl;
        passed << left << setw(30) << "Name" << setw(30) << "Last name" << right << setw(30) << "Concluding grade (Avg.)" << left << setw(30) << "/ Concluding grade (Med.)" << endl;
        passed << setfill('*') << setw(90) << "*" << setfill(' ') << endl;
        for (int i=0; i<passed_vector.size(); i++)
        {
            passed << left << setw(30) << passed_vector[i].name << setw(30) << passed_vector[i].last name
                << right << setw(30) << setprecision(2) << fixed << passed_vector[i].concluding_mark << right << setw(30) << passed_vector[i].concluding_mark_median << '\n';
        }
        passed.close();

        cout << '\n' << left << setw(30) << "Name" << setw(30) << "Last name" << right << setw(30) << "Concluding grade (Avg.)" << left << setw(30) << "/ Concluding grade (Med.)" << endl;
        cout << setfill('*') << setw(90) << "*" << setfill(' ') << endl;
        cout << setfill('*') << left << setw(90) << "List of pupils who passed the subject" << endl;
        cout << setw(90) << "*" << setfill(' ') << endl;
        for (int i=0; i<passed_vector.size(); i++)
        {
            cout << left << setw(30) << passed_vector[i].name << setw(30) << passed_vector[i].last name
                << right << setw(30) << setprecision(2) << fixed << passed_vector[i].concluding_mark << right << setw(30) << passed_vector[i].concluding_mark_median << '\n';
        }
        cout << setfill('*') << setw(90) << "*" << setfill(' ') << endl;
        cout << setfill('*') << left << setw(90) << "List of pupils who failed the subject" << endl;
        cout << setw(90) << "*" << setfill(' ') << endl;
        for (int i=0; i<failed_vector.size(); i++)
        {
            cout << left << setw(30) << failed_vector[i].name << setw(30) << failed_vector[i].last name
                << right << setw(30) << setprecision(2) << fixed << failed_vector[i].concluding_mark << right << setw(30) << failed_vector[i].concluding_mark_median << '\n';
        }

    }
    catch(const char* no_data)
    {
        cout << no_data << endl;
    }
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    cout << "Elapsed time: " << elapsed.count() << " s\n";
    return 0;
}