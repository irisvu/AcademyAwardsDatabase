//
// Created by Josh Mansito on 12/6/20.
//
#include "actor.h"

string actor::getField() const {

    if (fieldType == 0){return name;}
    else if (fieldType == 1){return film;}
    else if (fieldType == 2){return year;}
    else if (fieldType == 3){return winner;}
    else if (fieldType == 4){return award;}
    return name;
}

string actor::fields(int choice) {

    string setter;

    if (choice == 1){setter = "Year";}
    else if (choice == 2){setter = "Award";}
    else if (choice == 3){setter = "Winner";}
    else if (choice == 4){setter = "Actor/Actress Name";}
    else if (choice == 5){setter = "Film";}
    return setter;
}

bool actor::checkTrue(string num, const string& choice){

    //These are the number of choices for all of the menus.
    //When there is a check, this will send back the number needed to run the menu.
    if (choice == "TWO"){
        if (string::npos == num.find_first_not_of("12") && num.size() == 1){return true;}
        else{return false;}
    }
    if (choice == "THREE"){
        if (string::npos == num.find_first_not_of("123") && num.size() == 1){return true;}
        else{return false;}
    }
    if (choice == "FOUR"){
        if (string::npos == num.find_first_not_of("1234") && num.size() == 1){return true;}
        else{return false;}
    }
    if (choice == "FIVE"){
        if (string::npos == num.find_first_not_of("12345") && num.size() == 1){return true;}
        else{return false;}
    }
    if (choice == "EIGHT"){
        if (string::npos == num.find_first_not_of("12345678") && num.size() == 1){return true;}
        else{return false;}
    }
    if (choice == "winner"){
        if (string::npos == num.find_first_not_of("01") && num.size() == 1){return true;}
        else{return false;}
    }
    if (choice == "year"){
        if (string::npos == num.find_first_not_of("1234567890") && num.size() == 4){
            if (num >= "1928" && num <= "2020"){return true;}
            else{return false;}
        }else{return false;}
    }
    if (choice == "decade"){
        if (string::npos == num.find_first_not_of("1234567890") && num.size() == 4 && num[3] == '0'){
            if (num >= "1920" && num <= "2020"){return true;}
            else{return false;}
        }else{return false;}
    }
    if (choice == "checkIntMidName"){
        if (!num.empty() && num.size() < 3){
            if (string::npos == num.find_first_of("1234567890")){return true;}
            else{return false;}
        }else{return false;}
    }
    if (choice == "checkMidName"){
        if (string::npos == num.find_first_not_of('-')){return true;}
        else{return false;}
    }


    if (choice == "checkMidNameDot"){
        if (string::npos == num.find_first_not_of('.')){return true;}
        else{return false;}
    }
    if (choice == "nodigits"){
        if (string::npos == num.find_first_of("1234567890")){return true;}
        else{return false;}
    }


    return false;
}

ostream &operator<<(ostream &out, actor &record) {
    out << record.year << " - ";
    out << record.award << " - ";
    out << record.winner << " - ";
    out << record.name << " - ";
    out << record.film << endl;
    return out;
}