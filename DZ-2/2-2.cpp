﻿// 2-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    string str;
    vector <string> ans;

    setlocale(LC_ALL, "Russian");

    cout << "Введите строку:\n";

    getline(cin, str);

    cout << "\nВведите символ-разделитель:\n";

    // символ-разделитель
    char xyu;
    cin >> xyu;

    str += xyu;

    while (str.length() > 0)
    {
        string tmp = str.substr(0, str.find(xyu));
        str.erase(0, str.find(xyu) + 1);
        ans.push_back(tmp);
    }

    cout << "\nРезультат:\n";

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << '\n';
    
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
