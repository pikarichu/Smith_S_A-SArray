// A-SArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//This program takes the data of miles run per day by runners from a text file, calculates the total miles run and average miles run per day
//and outputs that to a table in a terminal window.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int NROWS = 5;
const int NCOLS = 7;
const string fileName = "runners.txt";

//Reads the data in from the file to the arrays
//Preconditions: File "runners.txt", runners array and two-dimensional miles array
//Postconditions: Stores the file data into an array of names and an array of miles run per day
int readData(string runners[], int miles[][NCOLS]);

//Calculates the total amount of miles run and the average miles run per day
//Preconditons: A runners array, a two-dimensional miles array with data stored, and an array to hold average and total
//Postconditions: The average miles per day and the total miles run are stored into the averageTotal array
void calcAverageTotal(int miles[][NCOLS], float averageTotal[][2]);

//Inputs the data into a table for viewing
//Preconditions: The runners array, the miles array, and the averageTotal array, all populated with data
//Postconditions: Outputs a table into the terminal with all of the data from the arrays
void displayResults(string runners[], int miles[][NCOLS], float averageTotal[][2]);

int main()
{
    string runners[NROWS];

    int miles[NROWS][NCOLS];

    float averageTotal[NROWS][2];


    readData(runners, miles);

    calcAverageTotal(miles, averageTotal);

    displayResults(runners, miles, averageTotal);

}

int readData(string runners[], int miles[][NCOLS])
{
    ifstream inFile;
    int rows = 0;
    inFile.open(fileName);
    if (!inFile.is_open())
    {

        cout << "Could not open file\n";
        return -1;
    }
    for (int i = 0; i < NROWS; i++)
    {
        inFile >> runners[i];
        for (int j = 0; j < NCOLS; j++)
        {
            inFile >> miles[i][j];
        }
    }

    return 0;
}

void calcAverageTotal(int miles[][NCOLS], float averageTotal[][2])
{
    int total = 0;
    for (int i = 0; i < NROWS; i++)
    {
        for (int j = 0; j < NCOLS; j++)
        {
            total += miles[i][j];
        }
        averageTotal[i][0] = total;
        averageTotal[i][1] = float(total) / float(NCOLS);
    }
}

void displayResults(string runners[], int miles[][NCOLS], float averageTotal[][2])
{
    for (int i = 0; i < NROWS; i++)
    {
        cout << setw(8) << runners[i] << " ";
        for (int j = 0; j < NCOLS; j++)
        {
            cout << setw(2) << miles[i][j] << " ";
        }
        cout << "Total: " << averageTotal[i][0] << " " << "Average: " << averageTotal[i][1] << endl;
    }
}