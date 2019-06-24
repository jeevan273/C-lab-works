#include <iostream>
#include "Functions.h"
#include <fstream>

using namespace std;

int main()
{
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
            cout << left << setw(30) << "Name" << setw(30) << "Last name" << right << setw(30) << "Concluding grade (Avg.)" << left << setw(30) << "/ Concluding grade (Med.)" << endl;
            cout << setfill('*') << setw(90) << "*" << setfill(' ') << endl;
            int a,b,c,d,e,f_exam;
            string name_text,last name_text;
            myfile.ignore(150, '\n');

            while (myfile >> name_text >> last name_text >> a >> b >> c >> d >> e >> f_exam)
            {

                pupil.push_back(program());

                pupil[f].name = name_text;
                pupil[f].last name = last name_text;
                pupil[f].homework.push_back(a);
                pupil[f].homework.push_back(b);
                pupil[f].homework.push_back(c);
                pupil[f].homework.push_back(d);
                pupil[f].homework.push_back(e);
                pupil[f].assessment= f_exam;
                pupil[f].concluding_mark = concluding_mark_average_function(pupil[f].homework, pupil[f].exam);
                pupil[f].concluding_mark_median = concluding_mark_median_function(pupil[f].homework, pupil[f].exam);
                cout  << left << setw(30) << pupil[f].name << setw(30) << pupil[f].last name
        << right << setw(30) << setprecision(2) << fixed << pupil[f].concluding_mark << right << setw(30) << pupil[f].concluding_mark_median << '\n';
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
            if (name_short term == "0") break;
            pupil.push_back(program());
            pupil[i].name = name_short term;

            cout << "Enter pupil's last name: \n";
            try{cin >> last name_short term;
            if (last name_short term == "0")
                throw "Incorrect input!";
            pupil[i].last name = last name_short term;}
            catch (const char* msg)
            {
                pupil[i].last name = "ERROR";
                cout << msg << endl;
            }


            float total_homework_short term = 0;
            int k;
            float exam_short term, concluding_mark_short term;

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

                cout << "Enter pupil's mark for the exam: \n";
                cin >> exam_short term;
                if (!cin || exam_short term == 0 || exam_short term > 10) break;
                pupil[i].assessment= exam_short term;
                break;


            case 'y':
                cout << "Enter number of homeworks: ";
                int number_homeworks;
                cin >> number_homeworks;
                for(int m=0; m<number_homeworks; m++)
                {
                    pupil[i].homework.push_back(rand()%11);

                }
                pupil[i].assessment= rand()%11;
                break;

            default:
                cout << "Incorrect input!";
                break;
            }
        try
        {
            if (pupil[i].homework[0]==0 || pupil[i].exam==0) throw "The pupil can not be evaluated because:";
            pupil[i].concluding_mark_median = concluding_mark_median_function(pupil[i].homework, pupil[i].exam);
            pupil[i].concluding_mark = concluding_mark_average_function(pupil[i].homework, pupil[i].exam);
        }
        catch(const char* msg)
        {
            cout << msg << endl;
            cout << "  1) They does not have any evaluated homework;\n  2) They did not take the concluding exam."<< endl;
        }

    }

    cout << left << setw(30) << "Name" << setw(30) << "Last name" << right << setw(30) << "Concluding grade (Avg.)" << left << setw(30) << "/ Concluding grade (Med.)" << endl;
    cout << setfill('*') << setw(90) << "*" << setfill(' ') << endl;
    for (int l=0; l <=i; l++)
    {
        cout  << left << setw(30) << pupil[l].name << setw(30) << pupil[l].last name
        << right << setw(30) << setprecision(2) << fixed << pupil[l].concluding_mark << right << setw(30) << pupil[l].concluding_mark_median << '\n';
    }
    break;}

    default:
        cout << "Incorrect input!";
        break;
    }
    return 0;
}