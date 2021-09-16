﻿// 2-3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
    vector <int> v;
    string str;
    
    setlocale(LC_ALL, "Russian");

    cout << "Введите массив через пробелы:\n";

    getline(cin, str);

    str += ' ';

    while (str.length() > 0)
    {
        string tmp = str.substr(0, str.find(' '));
        str.erase(0, str.find(' ') + 1);
        int tmp_int = stoi(tmp);
        v.push_back(tmp_int);
    }

    int n = v.size();

    int i = 0;
    while (i < n)
    {
        int j = i;
        while (j > 0 && v[j - 1] > v[j])
        {
            swap(v[j], v[j - 1]);
            j -= 1;
        }

        i += 1;
    }

    cout << "\nОтсортированный массив:\n";

    for (int i = 0; i < n; i++)
        cout << v[i] << ' ';

    cout << '\n';

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
