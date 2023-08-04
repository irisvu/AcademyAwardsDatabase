//
// Created by Josh Mansito on 11/25/20.
//

#ifndef BARTHOLOMEW_PICTURES_H
#define BARTHOLOMEW_PICTURES_H

#include <iostream>
using namespace std;

class picture {
public:
    //For nodes in the tree
    picture* left;
    picture* right;
    //Variables for the pictures
    string picName, picYear, nominations, imdbRating, duration, genre1, genre2, releaseMonth, metaRating, synopsis;
    int fieldType;

    //Picture (movie) default constructor
    picture()
    {
        left = nullptr;
        right = nullptr;
        picName = "";
        picYear = "";
        nominations = "";
        imdbRating = "";
        duration = "";
        genre1 = "";
        genre2 = "";
        releaseMonth = "";
        metaRating = "";
        synopsis = "";
        fieldType = 0;
    }

    //Display the picture information
    string getField() const;

    //Edit the picture information
    static string fields(int choice);

    //Used to verify user entry regarding picture fields in search functions
    static bool isCorrect(string num, const string& choice);

    //Overloads output operator
    friend ostream &operator <<(ostream &out, picture &record);

};

#endif //BARTHOLOMEW_PICTURES_H