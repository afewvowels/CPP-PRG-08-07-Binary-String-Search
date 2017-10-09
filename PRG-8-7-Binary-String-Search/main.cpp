//
//  main.cpp
//  PRG-8-7-Binary-String-Search
//
//  Created by Keith Smith on 10/8/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Modify the binarySearch function presented in this chapter so it searches an array
//  of strings instead of an array of ints. Test the function with a driver program. Use
//  Program 8-8 as a skeleton to complete. (The array must be sorted before the binary
//  search will work.)

#include <iostream>
#include <string>

using namespace std;

const int INT_NUM_NAMES = 20;

void sortNameArray(string[]);
void displayNames(const string[]);
void binaryStringSearch(const string[]);
void exitHold();

int main()
{
    string strNames[INT_NUM_NAMES] = { "Collins, Bill", "Smith, Bart", "Allen, Jim",
                                        "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
                                        "Taylor, Terri", "Johnson, Jill",
                                        "Allison, Jeff", "Looney, Joe", "Wolfe, Bille",
                                        "James, Jean", "Weaver, Jim", "Pore, Bob",
                                        "Rutherford, Greg", "Javens, Renee",
                                        "Harrison, Rose", "Setzer, Cathy",
                                        "Pike, Gordon", "Holland, Beth" };
    
    sortNameArray(strNames);
    
    displayNames(strNames);
    
    binaryStringSearch(strNames);
    
    return 0;
}

void sortNameArray(string names[])
{
    int minIndex;
    
    string minValue;
    string temp;
    
    for (int start = 0; start < (INT_NUM_NAMES - 1); start++)
    {
        minIndex = start;
        minValue = names[start];
        for (int index = start + 1; index < INT_NUM_NAMES; index++)
        {
            if (names[index] < minValue)
            {
                minValue = names[index];
                minIndex = index;
            }
        }
        temp = names[minIndex];
        names[minIndex] = names[start];
        names[start] = temp;
    }
}

void displayNames(const string names[])
{
    for (int i = 0; i < INT_NUM_NAMES; i++)
    {
        cout << names[i] << endl;
    }
}

void binaryStringSearch(const string names[])
{
    string value;
    
    int first = 0;
    int last = INT_NUM_NAMES - 1;
    int middle;
    int position = -1;
    
    bool found = false;
    
    cout << "Please enter a name to search for:\n";
    getline(cin, value);
    
    while (!found && first <= last)
    {
        middle = (first + last) / 2;
        if (names[middle] == value)
        {
            found = true;
            position = middle;
        }
        else if (names[middle] > value)
        {
            last = middle - 1;
        }
        else
        {
            first = middle + 1;
        }
    }
    
    if (position != -1)
    {
        cout << "That name was found!\n";
        cout << names[position];
    }
    else
    {
        cout << "That name was not found.\n";
    }
}
