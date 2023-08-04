//
// Created by Josh Mansito on 12/6/20.
//

#ifndef BARTHOLOMEW_ACTOR_H
#define BARTHOLOMEW_ACTOR_H
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

class actor
{
public:
    actor* left;
    actor* right;

    string year, award, winner, name, film;
    int fieldType;

    // ONLY WORKS IF FUNCTIONS ARE WITHIN CLASS
    actor()
    {
        left = nullptr;
        right = nullptr;
        year = "";
        award = "";
        winner = "";
        name = "";
        film = "";
        fieldType = 0;
    }

    string getField() const;
    static string fields(int choice);
    static bool checkTrue(string num, const string& choice);
    friend ostream& operator << (ostream& out, actor& record);

};

#endif //BARTHOLOMEW_ACTOR_H
