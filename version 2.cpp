#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <fstream>

using namespace std;

struct program
{
  string name, last name;
  vector<float> homework;
  float assessment, concluding_mark, concluding_mark_median;
};

float concluding_mark_average_function ( vector<float> homework_data, float assessment_function )
{
    float sum;
    for(int k=0; k<=homework_data.size(); k++)
    {
        sum += homework_data[k];
    }
    float r;
    r = sum / homework_data.size() * 0.4 + assessment_function * 0.6;
    return r;
}

float concluding_mark_median_function (vector<float> homework_data_2, float assessment_function_2)
{
    float median_mark_short term;
        sort(homework_data_2.begin(), homework_data_2.end());
        if (homework_data_2.size() % 2 == 0)
            median_mark_short term = (homework_data_2[homework_data_2.size()/2 - 1] + homework_data_2[homework_data_2.size()/2]) / 2;

        else
            median_mark_short term = homework_data_2[homework_data_2.size()/2];
    float r_2;
    r_2 = median_mark_short term *0.4 + 0.6 * assessment_function_2;
    return r_2;
}

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
        {string line;
        int f=0;
        ifstream myfile("book.txt");
        if (myfile.is_open())
        {
            cout << left << setw(25) << "Name" << setw(25) << "Last name" << right << setw(30) << "Concluding grade (Avg.)" << left << setw(30) << "/ Concluding grade (Med.)" << endl;
            cout << setfill('*') << setw(90) << "*" << setfill(' ') << endl;
            int a,b,c,d,e,f_assessment;
            string name_text,last name_text;
            while (getline(myfile,line))
                {
            if (myfile >> name_text >> last name_text >> a >> b >> c >> d >> e >> f_assessment)
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
                cout  << left << setw(25) << pupil[f].name << setw(25) << pupil[f].last name
        << right << setw(30) << setprecision(2) << fixed << pupil[f].concluding_mark << right << setw(25) << pupil[f].concluding_mark_median << '\n';
                f++;

            }
            else
                {cout << left << setw(25) << "Name" << setw(25) << "Last name" << right << setw(30) << "Concluding grade (Avg.)" << left << setw(30) << "/ Concluding grade (Med.)" << endl;
    cout << setfill('*') << setw(90) << "*" << setfill(' ') << endl;}
                }}
        else {cout << "Unable to open the file";}



        break;}
        case 'n':
    {
        for(i=0; i<999; i++)
    {
        string name_short term, last name_short term;
        cout << "Please enter pupil's name: \n";
        cin >> name_short term;
        if (name_short term == "0") break;

        cout << "Enter pupil's last name: \n";
        cin >> last name_short term;
        if (last name_short term == "0") break;
        pupil.push_back(program());

        pupil[i].name = name_short term;
        pupil[i].last name = last name_short term;

        float total_homework_short term = 0;
        int k;
        float assessment_short term, concluding_mark_short term;

        cout << "Do you want to generate random numbers as grades for homework? (y/n): ";
        char decision;
        cin >> decision;
        switch (decision)
        {
            case 'n':
                for ( k=0; k<999; k++)
                {

                    float homework_short term;
                    cout << "Enter value of homework " << k+1 << ":\n";
                    cin >> homework_short term;
                    if (!cin || homework_short term == 0 || homework_short term > 10) break;
                    pupil[i].homework.push_back(homework_short term);

                }
                cout << "Enter pupil's mark for the assessment: \n";
                cin >> assessment_short term;
                if (!cin || assessment_short term == 0 || assessment_short term > 10) break;
                pupil[i].assessment = assessment_short term;
                pupil[i].concluding_mark = concluding_mark_average_function(pupil[i].homework, pupil[i].assessment);
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

            default:
                break;
        }
        pupil[i].concluding_mark_median = concluding_mark_median_function(pupil[i].homework, pupil[i].assessment);
        pupil[i].concluding_mark = concluding_mark_average_function(pupil[i].homework, pupil[i].assessment);

    }

    cout << left << setw(25) << "Name" << setw(25) << "Last name" << right << setw(30) << "Concluding grade (Avg.)" << left << setw(30) << "/ Concluding grade (Med.)" << endl;
    cout << setfill('*') << setw(90) << "*" << setfill(' ') << endl;
    for (int l=0; l <=i; l++)
    {
        cout  << left << setw(25) << pupil[l].name << setw(25) << pupil[l].last name
        << right << setw(30) << setprecision(2) << fixed << pupil[l].concluding_mark << right << setw(25) << pupil[l].concluding_mark_median << '\n';
    }
    break;}

    default:
        break;
    }
    return 0;
}