#ifndef BARTHOLOMEW_MENU_H
#define BARTHOLOMEW_MENU_H
#include "BSTree.h"

class actMenu{

public:
    //Functions for the menus
    //They are all split up for all of the menus and are called through the tree functions

    //Current finished menus:
    static void main_Menu();
    static void field_Menu(int userChoice);
    static void type_Menu(int userChoice);

    ///All below functions are needing some work fleshing out
    static void confirmation_Menu(int userChoice);
    static void another_Menu(int userChoice);
    static void error_Check(int error);
    static void set_Info(int userChoice);
    static string award_Selection(int choice, int awardChoice);
    static void choose_Mode(const string& userChoice);

};

class picMenu{
public:
    //Functions for the menus
    //They are all split up for all of the menus and are called through the tree functions

    //Current finished menus:
    static void main_Menu();
    static void field_Menu(int userChoice);
    static void type_Menu(int userChoice);

    ///All below functions are needing some work fleshing out
    static void confirmation_Menu(int userChoice);
    static void another_Menu(int userChoice);
    static void error_Check(int error);
    static void set_Info(int infoType);
    static string award_Selection(int choice, int awardChoice);
    static void choose_Mode(const string& modeChoice);
};

#endif //BARTHOLOMEW_MENU_H
