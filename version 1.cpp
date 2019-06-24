#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

struct program
{
  string name, last name;
  vector<float> homework;
  float assessment, concluding_mark, concluding_mark_median;
};

int main()
{
    float grade;
    vector<program> pupil;
    int i;
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
                    total_homework_short term += homework_short term;

                }

                if (total_homework_short term == 0) break;
                cout << "Enter pupil's mark for the assessment: \n";
                cin >> assessment_short term;
                if (!cin || assessment_short term == 0 || assessment_short term > 10) break;
                pupil[i].assessment = assessment_short term;
                concluding_mark_short term = 0.4 * total_homework_short term /  k + 0.6 * assessment_short term;
                pupil[i].concluding_mark = concluding_mark_short term;
                break;


            case 'y':
                cout << "Enter number of homeworks: ";
                int number_homeworks;
                cin >> number_homeworks;
                for(int m=0; m<number_homeworks; m++)
                {
                    pupil[i].homework.push_back(rand()%11);
                    total_homework_short term += pupil[i].homework[m];

                }
                assessment_short term = rand()%11;
                concluding_mark_short term = 0.4 * total_homework_short term /  pupil[i].homework.size() + 0.6 * assessment_short term;
                pupil[i].concluding_mark = concluding_mark_short term;

            default:
                break;
        }

        float median_mark_short term;
        sort(pupil[i].homework.begin(), pupil[i].homework.end());
        if (pupil[i].homework.size() % 2 == 0)
            median_mark_short term = (pupil[i].homework[pupil[i].homework.size()/2 - 1] + pupil[i].homework[pupil[i].homework.size()/2]) / 2;

        else
            median_mark_short term = pupil[i].homework[pupil[i].homework.size()/2];

        float median_concluding_mark_short term = median_mark_short term * 0.4 + 0.6 * assessment_short term;
        pupil[i].concluding_mark_median = median_concluding_mark_short term;


    }

    cout << left << setw(30) << "Name" << setw(30) << "Last name" << right << setw(30) << "Concluding grade (Avg.)" << left << setw(30) << "/ Concluding grade (Med.)" << endl;
    cout << setfill('*') << setw(90) << "*" << setfill(' ') << endl;
    for (int l=0; l <=i; l++)
    {
        cout  << left << setw(30) << pupil[l].name << setw(30) << pupil[l].last name << right << setw(30) << setprecision(2) << fixed << pupil[l].concluding_mark << right << setw(30) << pupil[l].concluding_mark_median << '\n';
    }
    return 0;
}