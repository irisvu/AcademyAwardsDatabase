//
// Created by Josh Mansito on 11/25/20.
//

#ifndef BARTHOLOMEW_ACTBINARYTREE_H
#define BARTHOLOMEW_ACTBINARYTREE_H

#include "Menu.h"
#include <fstream>
#include <algorithm>

using namespace std;

class actBinaryTree
{
    BSTree<actor>* actorInfo;
    int record_Count = 0;

    //Error checking function
    static string errorCheck(string choice, const string& error_Num, int error, int menu_Field, int userChoice);

    //Add record Functions
    void actorAddRecord();
    void changeMindAddRecord(string confirm, actor* record);
    void confirmRecordAdd(const string& choice, BSTree<actor>* tree, actor* record);

    //Delete record functions
    void actorDeleteRecord();

    //Search Functions
    void actor_SearchType(int searchType);
    void complete_SearchReturn(const string& search, const string& field);
    void partial_SearchReturn(const string& search, const string& field, const string& choice);
    void new_Search(int userChoice);
    static int pickRecord(int choice);
    static string record_PickerError(int size, string userChoice);

    //Search functions primarily used for deletion
    static vector<actor> record_Picker(vector<actor> act_Vec);
    vector<actor> find_TheRecord(int userChoice, const vector<actor>& act_Vec);
    vector<actor> return_SearchResult(int searcher, vector<actor> act_Vec);
    vector<actor> search_ForRecord(const string& search, const string& field, int searcher, const string& userChoice, vector<actor> act_Vec);

    //Sort Functions
    void database_Sorter(int chosen_Field);
    void checkIfThere(const string& search);


    //Output to file
    void output_ToFile();

    //Getters for variables
    static string getYear();
    static string getAward(int userChoice);
    static string getWinner();
    static string getName(int userChoice);
    static string getFilm(int UserChoice);
    int get_record_Count() const { return record_Count;}

public:
    //Create the tree
    actBinaryTree();
    void createList();
    //Menu function
    void mainMenu();
    //Add function
    void actorAdd();
    //Delete Function
    void actorDelete();
    //Search function
    void actorSearch();
    //Sort function
    void actorSort();
    //Print functions
    void printDatabase();
    static void print_file(ostream& out, actor& record);

    //Fiend overload for printing
    friend ostream& operator << (ostream& out, actBinaryTree& list);

    ///Unfinished functions
    //void modifyARecord();

};

#endif //BARTHOLOMEW_ACTBINARYTREE_H
