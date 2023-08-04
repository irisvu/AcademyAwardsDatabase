#include "pictures.h"
#include <iostream>
#include "Menu.h"
using namespace std;


void actMenu::main_Menu() {

    cout << "\n\nWelcome to the Actor and Actress main menu!\n"
         << "You get a few options here, what would like to do?\n"
         << "Please enter the number that goes with the option you would like to do.\n\n"
         << "1) Add a record\n"
         << "2) Delete a record\n"
         << "3) Modify a record (NOT IMPLEMENTED YET)\n"
         << "4) Search the database\n"
         << "5) Sort the database by a chosen field\n"
         << "6) Print the latest database\n"
         << "7) Navigate to a different database\n"
         << "8) Exit this program\n";

}
void actMenu::field_Menu(int userChoice) {
    switch(userChoice){
        //Menu for add record
        case 1:{
            cout << "\nPlease choose a field to enter.\n"
                 << "1) Year\n"
                 << "2) Award\n"
                 << "3) Winner\n"
                 << "4) Actor/Actress Name\n"
                 << "5) Film\n";
            break;
        }
            //Menu for complete search
        case 2:{
            cout << "\nPlease choose a field to search from.\n"
                 << "1) Year\n"
                 << "2) Award\n"
                 << "3) Winner\n"
                 << "4) Actor/Actress Name\n"
                 << "5) Film\n";
            break;
        }
            //Menu for sorting database
        case 3:{
            cout << "\nPlease choose a field to search by.\n"
                 << "1) Year\n"
                 << "2) Award\n"
                 << "3) Winner\n"
                 << "4) Actor/Actress Name\n"
                 << "5) Film\n";
            break;
        }
            //Menu for Partial search
        case 4:{
            cout << "\nPlease choose a field to search.\n"
                 << "1) Award\n"
                 << "2) Actor/Actress Name\n"
                 << "3) Film\n";
            break;
        }
            //Menu for finding award, role and gender options
        case 5:{
            cout << "\nPlease choose the award category by role and gender.\n"
                 << "1) Actress in a Leading Role\n"
                 << "2) Actress in a Supporting Role\n"
                 << "3) Actor in a Leading Role\n"
                 << "4) Actor in a Supporting Role\n";

            break;
        }
            //Menu for finding award, partial choice
        case 6:{
            cout << "\nHere are the partial choice options, please choose one.\n"
                 << "1) Actress\n"
                 << "2) Actor\n"
                 << "3) Leading Role\n"
                 << "4) Supporting Role\n";
            break;
        }
            //Menu for win or not
        case 7:{
            cout << "\nPlease choose if they won or not.\n"
                 << "1) He/She won the award\n"
                 << "0) He/She did not win the award\n";
            break;
        }
        default:
            break;
    }
}
void actMenu::type_Menu(int userChoice) {

    switch(userChoice){

        case 1:{
            cout << "\nPlease choose how to edit the record.\n"
                 << "1) By field\n"
                 << "2) Enter in new information for the record\n";
            break;
        }
        case 2:
        case 4:
        case 5:{
            cout << "\n\"Contains\" or \"exact\" style of search?\n"
                 << "1) Contains\n"
                 << "2) Exact\n";
            break;
        }
        case 3:{
            cout << "\nComplete or Partial search?\n"
                 << "1) Complete\n"
                 << "2) Partial\n";
            break;
        }
        case 6:{
            cout << "\n\"Exact\" or \"Contains\" style of search for what we are deleting?\n"
                 << "1) Exact\n"
                 << "2) Contains\n";
            break;
        }
        default:
            break;

    }
}

///Need to edit: Modify
void actMenu::confirmation_Menu(int userChoice) {

    switch(userChoice) {

        //option 1 for adding a record
        case 1: {
            cout << "\nPlease confirm your choice to add that to the record.\n"
                 << "1) Confirm\n"
                 << "2) Change information to add\n"
                 << "3) Main menu\n";
            break;
        }
            //option 2 for deleting a record
        case 2: {
            cout << "\nPlease confirm your choice to delete that from the record.\n"
                 << "1) Confirm\n"
                 << "2) Change information for deletion\n"
                 << "3) Main menu\n";
            break;
        }
            /// MODIFY A RECORD : NEED TO EDIT
        case 3: {
            cout << "\nAre you done modifying this record?\n"
                 << "1) Yes, I am\n"
                 << "2) No, I want to modify a different field\n"
                 << "3) No, I want to re-modify the same field\n"
                 << "3) No, I want to modify a different record\n"
                 << "3) Return to Actor / Actress database\n";
            break;
        }
            //option 4 for confirm sort
        case 4: {
            cout << "1) Confirm sort\n"
                    "2) Change field selection for sort\n"
                    "3) Return to Actor / Actress database menu\n";
            break;
        }
            //option 5 for new search
        case 5: {
            cout << "\nPlease select if you would like to search something else.\n"
                    "1) New search\n"
                    "2) Return to Actor / Actress database menu\n";
            break;
        }
            //option 6 for complete search
        case 6: {
            cout
                    << "\nOkay! but to do the complete search, you need to know the exact information for what you are looking for.\n"
                    << "\nContinue with search?\n"
                    << "1) Continue\n"
                    << "2) Return to Partial Search\n"
                    << "2) Return to Actor / Actress database menu\n";
            break;
        }
            //option 7 for printing the database
        case 7: {
            cout << "\nPlease confirm to print the database\n"
                 << "1) Confirm\n"
                 << "2) Return to Actor / Actress database menu\n";
            break;
        }
        default:
            break;
    }

}
///Need to edit: Modify
void actMenu::another_Menu(int userChoice) {
    switch(userChoice) {
        //option 1 for adding record
        case 1: {
            cout << "\nPlease confirm if you would like to add another record.\n"
                 << "1) Confirm\n"
                 << "2) Return to Actor / Actress database menu\n";
            break;
        }
            //option for deletion
        case 2: {
            cout << "\nPlease confirm if you would like to delete another record.\n"
                 << "1) Confirm\n"
                 << "2) Return to Actor / Actress database menu\n";
            break;
        }
            /// MODIFY A RECORD : NEED TO EDIT
        case 3: {
            cout << "\nPlease confirm if you would like to modify another record.\n"
                 << "1) Same record\n"
                 << "2) Different record\n"
                 << "3) Return to Actor / Actress database menu\n";
            break;
        }
            //option 4 for new search
        case 4: {
            cout << "\nPlease confirm to do a new search\n"
                 << "1) Confirm\n"
                 << "2) Return to Actor / Actress database menu\n";
            break;
        }
            //option 5 for another search
        case 5: {
            cout << "\nPlease confirm to do another search\n"
                 << "1) Confirm\n"
                 << "2) Return to Actor / Actress database menu\n";
            break;
        }
            //option 6 for different field
        case 6: {
            cout << "\nPlease confirm to sort with a different field.\n"
                 << "1: Confirm\n"
                 << "2: Return to Actor / Actress database menu\n";
            break;
        }
        default:
            break;
    }

}
//error check statements
//add more as needed
void actMenu::error_Check(int error) {

    switch(error){
        case 1:{   cout << "\nERROR: Please make sure to choose 1 or 0!\n"; break;}
        case 2:{   cout << "\nERROR: Please make sure to choose 1 or 2!\n"; break;}
        case 3:{   cout << "\nERROR: Please make sure to choose between 1 and 3!\n"; break;}
        case 4:{   cout << "\nERROR: Please make sure to choose between 1 and 4!\n"; break;}
        case 5:{   cout << "\nERROR: Please make sure to choose between 1 and 5!\n"; break;}
        case 6:{   cout << "\nERROR: This needs to be 4 digits that are between the years 1928 and 2020!\n"; break;}
        case 7:{   cout << "\nERROR: Please make sure that this doesn't contain numbers!\n"; break;}
        case 8:{   cout << "\nERROR: Please make sure to to only enter the first initial!\n"; break;}
        case 9:{   cout << "\nERROR: Please make sure to choose between 1 and 8!\n"; break; }
        default:   break;
    }
}
//set info to the variables
//add more as needed
void actMenu::set_Info(int userChoice) {

    switch(userChoice) {
        case 1: { cout << "\nPlease give me a four digit year of the award: " << endl; break;}
        case 2: { cout << "\nFirst Name: "; break;}
        case 3: { cout << "\nMiddle Name: "; break;}
        case 4: { cout << "\nLast Name: "; break;}
        default: break;
    }

}
//Menu for award selection
string actMenu::award_Selection(int choice, int awardChoice) {
    string role;
    if (awardChoice == 1){
        switch (choice){
            case 1: role = "Actress in a Leading Role"; break;
            case 2: role = "Actress in a Supporting Role"; break;
            case 3: role = "Actor in a Leading Role"; break;
            case 4: role = "Actor in a Supporting Role"; break;
            default: break;
        }
    }

    if (awardChoice == 2){
        switch (choice){
            case 1: role = "Actress"; break;
            case 2: role = "Actor"; break;
            case 3: role = "Leading Role"; break;
            case 4: role = "Supporting Role"; break;
            default: break;
        }
    }
    return role;
}
//lets the user choose between the contains method or exact search mthod
void actMenu::choose_Mode(const string& userChoice) {

    if (userChoice == "1"){ cout << "\nCONTAINS SEARCH MODE" << endl; }
    else if (userChoice == "2"){ cout << "\nEXACT SEARCH MODE" << endl; }

}

//////// Below are all the same menus, just for the picture functions /////////////

void picMenu::main_Menu() {
    cout << "\n\nWelcome to the Pictures main menu!\n"
         << "You get a few options here, what would like to do?\n"
         << "Please enter the number that goes with the option you would like to do.\n\n"
         << "1) Add a record\n"
         << "2) Delete a record (NOT IMPLEMENTED YET)\n"
         << "3) Modify a record (NOT IMPLEMENTED YET)\n"
         << "4) Search the database\n"
         << "5) Sort the database by a chosen field\n"
         << "6) Print the latest database\n"
         << "7) Navigate to a different database\n"
         << "8) Exit this program\n";
}
void picMenu::field_Menu(int userChoice) {
    switch(userChoice){
        //Menu for add record
        case 1:{
            cout << "\nPlease choose a field to enter.\n"
                 << "1) Title\n"
                 << "2) Year\n"
                 << "3) Number of Nominations\n"
                 << "4) IMDB rating\n"
                 << "5) Duration\n"
                 << "6) Primary Genre\n"
                 << "7) Secondary Genre\n"
                 << "8) Month of release\n"
                 << "9) Metacritic rating\n"
                 << "10) Synopsis\n";
            break;
        }
            //Menu for complete search
        case 2:{
            cout << "\nPlease choose a field to search from.\n"
                 << "1) Title\n"
                 << "2) Year\n"
                 << "3) Number of Nominations\n"
                 << "4) IMDB rating\n"
                 << "5) Duration\n"
                 << "6) Primary Genre\n"
                 << "7) Secondary Genre\n"
                 << "8) Month of release\n"
                 << "9) Metacritic rating\n"
                 << "10) Synopsis\n";
            break;
        }
            //Menu for sorting database
        case 3:{
            cout << "\nPlease choose a field to sort by.\n"
                 << "1) Title\n"
                 << "2) Year\n"
                 << "3) Number of Nominations\n"
                 << "4) IMDB rating\n"
                 << "5) Duration\n"
                 << "6) Primary Genre\n"
                 << "7) Secondary Genre\n"
                 << "8) Month of release\n"
                 << "9) Metacritic rating\n"
                 << "10) Synopsis\n";
            break;
        }
            //Menu for Partial search
        case 4:{
            cout << "\nPlease choose a field to search.\n"
                 << "1) Title\n"
                 << "2) Year\n"
                 << "3) Number of Nominations\n"
                 << "4) IMDB rating\n"
                 << "5) Duration\n"
                 << "6) Primary Genre\n"
                 << "7) Secondary Genre\n"
                 << "8) Month of release\n"
                 << "9) Metacritic rating\n";
            break;
        }
        default:
            break;
    }
}
void picMenu::type_Menu(int userChoice) {
    switch(userChoice){
        case 1:{
            cout << "\nPlease choose how to edit the record.\n"
                 << "1) By field\n"
                 << "2) Enter in new information for the record\n";
            break;
        }
        case 2:
        case 4:
        case 5:{
            cout << "\n\"Contains\" or \"exact\" style of search?\n"
                 << "1) Contains\n"
                 << "2) Exact\n";
            break;
        }
        case 3:{
            cout << "\nComplete or Partial search?\n"
                 << "1) Complete\n"
                 << "2) Partial\n";
            break;
        }
        case 6:{
            cout << "\n\"Exact\" or \"Contains\" style of search for what we are deleting?\n"
                 << "1) Exact\n"
                 << "2) Contains\n";
            break;
        }
        default:
            break;
    }
}

//Need to edit to accomodate for modify
void picMenu::confirmation_Menu(int userChoice) {
    switch(userChoice) {
        //option 1 for adding a record
        case 1: {
            cout << "\nPlease confirm your choice to add that to the record.\n"
                 << "1) Confirm\n"
                 << "2) Change information to add\n"
                 << "3) Main menu\n";
            break;
        }
            //option 2 for deleting a record
        case 2: {
            cout << "\nPlease confirm your choice to delete that from the record.\n"
                 << "1) Confirm\n"
                 << "2) Change information for deletion\n"
                 << "3) Main menu\n";
            break;
        }
            /// MODIFY A RECORD : NEED TO EDIT
        case 3: {
            cout << "\nAre you done modifying this record?\n"
                 << "1) Yes, I am\n"
                 << "2) No, I want to modify a different field\n"
                 << "3) No, I want to re-modify the same field\n"
                 << "3) No, I want to modify a different record\n"
                 << "3) Return to Pictures database\n";
            break;
        }
            //option 4 for confirm sort
        case 4: {
            cout << "1) Confirm sort\n"
                    "2) Change field selection for sort\n"
                    "3) Return to Pictures database menu\n";
            break;
        }
            //option 5 for new search
        case 5: {
            cout << "\nPlease select if you would like to search something else.\n"
                    "1) New search\n"
                    "2) Return to Pictures database menu\n";
            break;
        }
            //option 6 for complete search
        case 6: {
            cout
                    << "\nOkay! but to do the complete search, you need to know the exact information for what you are looking for.\n"
                    << "\nContinue with search?\n"
                    << "1) Continue\n"
                    << "2) Return to Partial Search\n"
                    << "2) Return to Pictures database menu\n";
            break;
        }
            //option 7 for printing the database
        case 7: {
            cout << "\nPlease confirm to print the database\n"
                 << "1) Confirm\n"
                 << "2) Return to Pictures database menu\n";
            break;
        }
        default:
            break;
    }
}
//Need to edit to accomodate for Modify
void picMenu::another_Menu(int userChoice) {
    switch(userChoice) {
        //option 1 for adding record
        case 1: {
            cout << "\nPlease confirm if you would like to add another record.\n"
                 << "1) Confirm\n"
                 << "2) Return to Pictures database menu\n";
            break;
        }
            //option for deletion
        case 2: {
            cout << "\nPlease confirm if you would like to delete another record.\n"
                 << "1) Confirm\n"
                 << "2) Return to Pictures database menu\n";
            break;
        }
            /// MODIFY A RECORD : NEED TO EDIT
        case 3: {
            cout << "\nPlease confirm if you would like to modify another record.\n"
                 << "1) Same record\n"
                 << "2) Different record\n"
                 << "3) Return to Pictures database menu\n";
            break;
        }
            //option 4 for new search
        case 4: {
            cout << "\nPlease confirm to do a new search\n"
                 << "1) Confirm\n"
                 << "2) Return to Pictures database menu\n";
            break;
        }
            //option 5 for another search
        case 5: {
            cout << "\nPlease confirm to do another search\n"
                 << "1) Confirm\n"
                 << "2) Return to Pictures database menu\n";
            break;
        }
            //option 6 for different field
        case 6: {
            cout << "\nPlease confirm to sort with a different field.\n"
                 << "1: Confirm\n"
                 << "2: Return to Pictures database menu\n";
            break;
        }
        default:
            break;
    }
}
void picMenu::error_Check(int error) {
    switch(error){
        case 1:{   cout << "\nERROR: Please make sure to choose 1 or 0!\n"; break;}
        case 2:{   cout << "\nERROR: Please make sure to choose 1 or 2!\n"; break;}
        case 3:{   cout << "\nERROR: Please make sure to choose between 1 and 3!\n"; break;}
        case 4:{   cout << "\nERROR: Please make sure to choose between 1 and 4!\n"; break;}
        case 5:{   cout << "\nERROR: Please make sure to choose between 1 and 5!\n"; break;}
        case 6:{   cout << "\nERROR: This needs to be 4 digits that are between the years 1928 and 2020!\n"; break;}
        case 7:{   cout << "\nERROR: Please make sure that this doesn't contain numbers!\n"; break;}
        case 8:{   cout << "\nERROR: Please make sure to to only enter the first initial!\n"; break;}
        case 9:{   cout << "\nERROR: Please make sure to choose between 1 and 8!\n"; break; }
        default:   break;
    }
}
void picMenu::set_Info(int infoType) {
    switch(infoType) {
        case 1: { cout << "\nPlease give me a four digit year of the award: " << endl; break;}
        case 2: { cout << "\nFirst Name: "; break;}
        case 3: { cout << "\nMiddle Name: "; break;}
        case 4: { cout << "\nLast Name: "; break;}
        default: break;
    }
}
string picMenu::award_Selection(int choice, int awardChoice) {
    return std::string();
}
void picMenu::choose_Mode(const string &modeChoice) {
    if (modeChoice == "1"){ cout << "\nCONTAINS SEARCH MODE" << endl; }
    else if (modeChoice == "2"){ cout << "\nEXACT SEARCH MODE" << endl; }
}

