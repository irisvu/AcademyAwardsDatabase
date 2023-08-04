//
// Created by Josh Mansito on 12/8/20.
//

#ifndef BARTHOLOMEW_PICBINARYTREE_H
#define BARTHOLOMEW_PICBINARYTREE_H


#include <iostream>
#include <fstream>
#include "pictures.h"
#include "Menu.h"

using namespace std;

class picBinaryTree
{
private:
    BSTree<picture>* pictureInfo;
    int record_Count = 0;

    //Error checking function
    static string errorCheck(string choice, const string& error_Num, int error, int menu_Field, int userChoice);

    //Add record Functions
    void pictureAddRecord();
    void changeMindAddRecord(string confirm, picture* record);
    void confirmRecordAdd(const string& choice, BSTree<picture>* tree, picture* record);

    //Search Functions
    void picture_SearchType(int searchType);
    void complete_SearchReturn(const string& search, const string& field);
    void partial_SearchReturn(const string& search, const string& field, const string& choice);
    void new_Search(int userChoice);

    //Sort Functions
    void database_Sorter(int chosen_Field);
    void checkIfThere(const string& search);

    //Output to file
    void output_ToFile();

    //Getters for variables
    static string getPicName();
    static string getPicYear();
    static string getNominations();
    static string getIMDBRating();
    static string getDuration();
    static string getPrimaryGenre();
    static string getSecondaryGenre();
    static string getReleaseMonth();
    static string getMetaRating();
    static string getSynopsis();
    //figure out what to do w this
    static string getPicName(int userChoice);

    int get_record_Count() const {return record_Count;}

public: // FUNCTIONS CAN CALL IN MAIN
    //These functions will be called in the Menu system
    //Constructor to make picture objects
    picBinaryTree();
    //Creates the tree
    void createList();
    //Calls the main menu
    void mainMenu();
    //Adds a record to the tree
    void picAdd();
    //Deletes a record from the tree
    //void deleteARecord();
    //Modifies a record from the tree
    //void modifyARecord();
    //Access the type of search
    void picSearch();
    //Sorts the tree
    void picSort();

    //Prints the database to the screen/file
    void printDatabase();
    static void print_file(ostream& out, picture& record);

    //Overloads << operator to print picture records/list
    friend ostream& operator <<(ostream& out, picBinaryTree& list);
};



#endif //BARTHOLOMEW_PICBINARYTREE_H
