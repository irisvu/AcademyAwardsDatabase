//
// Created by Josh Mansito on 11/25/20.
//

#include "pictures.h"

string picture::getField() const {
    if (fieldType == 0) {return picName;}
    if (fieldType == 1) {return picYear;}
    if (fieldType == 2) {return nominations;}
    if (fieldType == 3) {return imdbRating;}
    if (fieldType == 4) {return duration;}
    if (fieldType == 5) {return genre1;}
    if (fieldType == 6) {return genre2;}
    if (fieldType == 7) {return releaseMonth;}
    if (fieldType == 8) {return metaRating;}
    if (fieldType == 9) {return synopsis;}
    return picName;
}

string picture::fields(int choice) {
    string setter;

    if (choice == 1) {setter  = "Picture Name";}
    if (choice == 2) {setter = "Year of Release";}
    if (choice == 3) {setter = "Number of Nominations";}
    if (choice == 4) {setter = "IMDB Rating";}
    if (choice == 5) {setter = "Duration of Picture";}
    if (choice == 6) {setter = "Primary Genre";}
    if (choice == 7) {setter = "Secondary Genre";}
    if (choice == 8) {setter = "Month of Release";}
    if (choice == 9) {setter = "Meta Rating";}
    if (choice == 10){setter = "Synopsis";}
    return setter;
}

bool picture::isCorrect(string num, const string &choice) {
    /* NUMBER OF CHOICES */
    if (choice == "TWO") {
        if (string::npos == num.find_first_not_of("12") && num.size() == 1) {return true;}
        else {return false;}
    }
    if (choice == "THREE") {
        if (string::npos == num.find_first_not_of("123") && num.size() == 1) {return true;}
        else {return false;}
    }
    if (choice == "FOUR") {
        if (string::npos == num.find_first_not_of("1234") && num.size() == 1) {return true;}
        else {return false;}
    }
    if (choice == "FIVE") {
        if (string::npos == num.find_first_not_of("12345") && num.size() == 1) {return true;}
        else {return false;}
    }
    if (choice == "year") {
        if (string::npos == num.find_first_not_of("0123456789") && num.size() == 1) {return true;}
        else {return false;}
    }
    //will add other choices as i figure them out
    return false; //not sure if this will mess w logic
}

ostream &operator << (ostream &out, picture &record) {
    out << record.picName << " - ";
    out << record.picYear << " - ";
    out << record.nominations << " - ";
    out << record.imdbRating << " - ";
    out << record.duration << " - ";
    out << record.genre1 << " - ";
    out << record.genre2 << " - ";
    out << record.releaseMonth << " - ";
    out << record.metaRating << " - ";
    out << record.synopsis << " - ";
    return out;
}

