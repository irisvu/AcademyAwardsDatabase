#include "actBinaryTree.h"
#include "picBinaryTree.h"
#include <utility>

/***************************************** FUNCTIONS FOR THE TREE *****************************************************/
//actBinaryTree Constructor
actBinaryTree::actBinaryTree(){actorInfo = nullptr;}

//Main function to import everything from the file into the tree
void actBinaryTree::createList()
{
    ifstream actorInFile;
    string actorHeader, actYear, actAward, actWin, actName, actFilm;

    ///IMPORTANT This pathing much be changed depending on where the file is coming from
    actorInFile.open("actor-actress.csv");

    if (!actorInFile){
        cout << "Unable to open file." << endl;
        exit(1);
    }

    actorInfo = new BSTree<actor>;

    //Reading in the header line
    getline(actorInFile, actorHeader);

    //While there is info, continue reading in lines
    //All data needs to be read into the tree in order:
    //Year -> Award -> Winner -> Name -> Film
    while (actorInFile.good()){
        auto* current = new actor;

        getline(actorInFile, actYear, ',');
        current->year = actYear;
        getline(actorInFile, actAward, ',');
        current->award = actAward;
        getline(actorInFile, actWin, ',');
        current->winner = actWin;
        getline(actorInFile, actName, ',');
        current->name = actName;
        getline(actorInFile, actFilm);
        current->film = actFilm;

        if (!current->name.empty()){
            actorInfo->insert(current);
        }
        else{delete current;}
    }
    //Make sure not to leave the file open
    actorInFile.close();
}

//Main Menu for the actor tree
//Menu will also need to be in order:
//Add -> Delete -> Modify -> Search -> Sort -> Print -> Change to other database
//Doing all of this in a switch statement for the user's choice
void actBinaryTree::mainMenu()
{
    int userChoice;
    //potentially using boolean to stop menu looping if they have switched. might not be needed
    bool haveSwitched = false;
    actMenu::main_Menu();
    picBinaryTree switchToPicture;
    cin >> userChoice;

    userChoice = stoi(errorCheck(to_string(userChoice), "EIGHT", 9, 1, 0));

    while (userChoice != 8)
    {
        switch (userChoice)
        {
            case 1:
                cout << "\n  Here is where you can add a record \n" << "_________________________________________\n";
                actorAdd();
                break;
            case 2:
                cout << "\n  Here is where you can delete a record \n" << "_________________________________________\n";
                actorDelete();
                break;
            case 3:
                cout << "\n  Here is where you can modify a record \n" << "_________________________________________\n";
                break;
            case 4:
                cout << "\n  Here is where you can search the records \n" << "_________________________________________\n";
                actorSearch();
                break;
            case 5:
                cout << "\n  Here you can sort the database by a specific field \n" << "_________________________________________\n";
                actorSort();
                break;
            case 6:
                cout << "\n  Here you can print the database to a file \n" << "_________________________________________\n";
                printDatabase();
                break;
            case 7: {
                int choice;
                cout << "\n  Would you like to switch to the pictures database or stay here? \n"
                     << "_________________________________________\n";
                cout << "1. Switch to the picture database\n"
                     << "2. Stay in the Actor / Actress database\n";
                cin >> choice;

                if(choice == 1) {
                    switchToPicture.createList();
                    switchToPicture.mainMenu();
                    haveSwitched = true;
                }
                break;
            }
            default:
                break;
        }

        cout << endl;
        actMenu::main_Menu();
        cin >> userChoice;

    }

}

//Overloading for printing out the database
ostream& operator << (ostream& out, actBinaryTree& list){
    out << *list.actorInfo;
    return out;
}
/************************************** FUNCTIONS FOR THE TREE END ****************************************************/
/***************************************** FUNCTIONS FOR GETTERS ******************************************************/

//Following string functions are all getters
string actBinaryTree::getYear(){
    string getYear;
    cout << "\nPlease enter in a four digit year:\n ";
    cin >> getYear;
    getYear = errorCheck(getYear, "year", 6, 6, 1);
    return getYear;
}
string actBinaryTree::getAward(int userChoice){
    string award_Type, getAward;
    if (userChoice == 1){
        actMenu::field_Menu(5);
        cin >> award_Type;
        //error check
        award_Type = errorCheck(award_Type, "FOUR", 4, 2, 5);
        getAward = actMenu::award_Selection(stoi(award_Type), 1);
    }
    if (userChoice == 2){
        actMenu::field_Menu(6);
        cin >> award_Type;
        //error check
        award_Type = errorCheck(award_Type, "FOUR", 4, 2, 6);
        getAward = actMenu::award_Selection(stoi(award_Type), 2);
    }
    return getAward;
}
string actBinaryTree::getWinner(){
    string getWinner;
    actMenu::field_Menu(7);
    cin >> getWinner;
    //error check
    getWinner = errorCheck(getWinner, "winner", 1, 2, 7);
    return getWinner;
}
string actBinaryTree::getName(int userChoice){
    string first, middle, last, getName;
    if (userChoice == 1){
        cout << "\nPlease enter the FULL NAME:\n";
        cout << "First Name: ";
        cin >> first;

        //error check
        first = errorCheck(first, "nodigits", 7, 6, 2);

        cout << "Please enter the middle initial. If you don't know, you can make one up! Or just enter \"-\"\n";
        cin >> middle;

        //error check
        middle = errorCheck(middle, "checkIntMidName", 8, 6, 3);

        cout << "Last Name: ";
        cin >> last;

        last = errorCheck(last, "nodigits", 7, 6, 4);

        //If no middle name insert a blank space for getname
        //Make sure to add a . to the middle name ex: A.
        if (actor::checkTrue(middle, "checkMidName")){ getName = first + " " + last;}
        else{
            if (middle.size() == 1){
                if (string::npos != middle.find_first_not_of('.')){middle = middle + ".";}
            }
            getName = first + " " + middle + " " + last;
        }

        //Simple toupper function to change the names into proper format
        for (int i = 0; i < getName.length(); i++){
            if (i == 0 || getName[i - 1] == ' ')
            {
                getName[i] = toupper(getName[i]);
            }
        }
    }
    //Option for complete search
    if (userChoice == 2)
    {
        cout << "\nPlease enter the FULL NAME:\n";
        getline(cin, getName);
    }

    //Option for partial search
    if (userChoice == 3)
    {
        cout << "\nPlease enter what you wanting to search for: ";
        getline(cin, getName);
    }
    return getName;
}
string actBinaryTree::getFilm(int UserChoice){
    string getFilm;

    if (UserChoice == 1){
        cout << "\nPlease enter the name of the FILM:\n";
        getline(cin, getFilm);

        //toupper function to convert the film to proper format
        for (int i = 0; i < getFilm.length(); i++){
            if (i == 0 || getFilm[i - 1] == ' '){getFilm[i] = toupper(getFilm[i]);}
        }
    }
    if (UserChoice == 2){
        cout << "\nPlease enter what you wanting to search for: ";
        getline(cin, getFilm);
    }
    return getFilm;
}

/*************************************** FUNCTIONS FOR GETTERS END ****************************************************/
/***************************************** FUNCTIONS FOR ERRORS *******************************************************/

//Function to control the errors and send the user back to what they were trying to do if an error occurred.
string actBinaryTree::errorCheck(string choice, const string& error_Num, int error, int menu_Field, int userChoice){
    while (!actor::checkTrue(choice, error_Num)){
        actMenu::error_Check(error);

        if (menu_Field == 1){actMenu::main_Menu();}                         //1 = main menu
        else if (menu_Field == 2){actMenu::field_Menu(userChoice);}         //2 = Field menu
        else if (menu_Field == 3){actMenu::confirmation_Menu(userChoice);}  //3 = Confirmation
        else if (menu_Field == 4){actMenu::type_Menu(userChoice);}          //4 = Sub menu
        else if (menu_Field == 5){actMenu::another_Menu(userChoice);}       //5 = another_Menu
        else if (menu_Field == 6){actMenu::set_Info(userChoice);}           //6 = set_Info

    }
    return choice;
}

//More error checks, making sure the user enters the correct option for record picker
//PRIMARILY USED FOR DELETING RECORDS
//Makes sure that the user doesn't break the system when picking a record
string actBinaryTree::record_PickerError(int size, string userChoice){
    switch(size){
        case 2:{
            while (!actor::checkTrue(userChoice, "TWO"))
            {
                cout << "Whoops! Looks like that didn't work... Your choices are between 1 and " << size << " :\n";
                cin >> userChoice;
            }break;
        }
        case 3:{
            while (!actor::checkTrue(userChoice, "THREE"))
            {
                cout << "Whoops! Looks like that didn't work... Your choices are between 1 and " << size << " :\n";
                cin >> userChoice;
            }break;
        }
        case 4:{
            while (!actor::checkTrue(userChoice, "FOUR"))
            {
                cout << "Whoops! Looks like that didn't work... Your choices are between 1 and " << size << " :\n";
                cin >> userChoice;
            }break;
        }
        case 5:{
            while (!actor::checkTrue(userChoice, "FIVE"))
            {
                cout << "Whoops! Looks like that didn't work... Your choices are between 1 and " << size << " :\n";
                cin >> userChoice;
            }break;
        }
        default:
            break;
    }

    return userChoice;
}
/**************************************** FUNCTIONS FOR ERRORS END ****************************************************/
/******************************************* FUNCTIONS FOR ADD ********************************************************/

//This calls the add record function
void actBinaryTree::actorAdd()
{
    cout << endl;
    actorAddRecord();
}

//Main function for adding a record
//All of the fields for the record will be received by functions called in order:
//Year -> Award -> Winner -> Name -> Film
//Will then print out the input provided by the user
void actBinaryTree::actorAddRecord()
{
    string temp, confirm;
    //creating the new record with auto
    auto* newRecord = new actor;

    newRecord->year = getYear();
    cout << endl;

    newRecord->award = getAward(1);
    cout << endl;

    newRecord->winner = getWinner();

    //Making sure a skip doesn't happen
    getline(cin, temp);

    newRecord->name = getName(1);

    //Making sure a skip doesn't happen
    getline(cin, temp);

    newRecord->film = getFilm(1);

    cout << "\nThe new record looks great to me! But just in case.....\n";
    cout << setw(6) << left              << "\nYEAR" << "- "
         << setw(newRecord->award.length()) << "AWARD" << " - "
         << setw(7)                      << "WINNER" << "- "
         << setw(newRecord->name.length())  << "NAME" << " - "
         << "FILM\n";
    cout << setw(5) << newRecord->year << "- " << setw(newRecord->award.length())
         << newRecord->award << " - " << setw(7) << newRecord->winner << "- "
         << setw(newRecord->name.length()) << newRecord->name << " - " << newRecord->film << endl;

    //Will call for the confirmation to continue
    actMenu::confirmation_Menu(1);
    cin >> confirm;
    //If there is an invalid choice, they will get to choose again
    confirm = errorCheck(confirm, "THREE", 3, 3, 1);

    //Add the record
    confirmRecordAdd(confirm, actorInfo, newRecord);
}

//Main function for editing what the user wants to add if they change their mind
//Works very similarly to the add function.
//Done in the same order for the statements:
//Year -> Award -> Winner -> Name -> Film
//Will then print out the new edited add input provided by the user
void actBinaryTree::changeMindAddRecord(string confirm, actor* record)
{
    string changeMind, changeField, temp;

    actMenu::type_Menu(1);
    cin >> changeMind;
    //If there is an invalid choice, they will get to choose again
    changeMind = errorCheck(changeMind, "TWO", 2, 4, 1);

    //Choosing the field to change
    //Year -> Award -> Winner -> Name -> Film
    if (changeMind == "1")
    {
        actMenu::field_Menu(1);
        cin >> changeField;
        //If there is an invalid choice, they will get to choose again
        changeField = errorCheck(changeField, "FIVE", 5, 2, 1);

        if (changeField == "1"){ record->year = getYear();}
        else if (changeField == "2"){ record->award = getAward(1);}
        else if (changeField == "3"){ record->winner = getWinner();}
        else if (changeField == "4"){ record->name = getName(1);}
        else if (changeField == "5"){
            getline(cin, temp);
            record->film = getFilm(1);
        }

        cout << "\nOkay.. So here is your updated information you want to add... " << endl;
        cout << setw(6) << left           << "\nYEAR" << "- "
             << setw(record->award.length()) << "AWARD" << " - "
             << setw(7)                   << "WINNER" << "- "
             << setw(record->name.length())  << "NAME" << " - "
                                             << "FILM\n";
        cout << setw(5) << record->year << "- " << setw(record->award.length())
             << record->award << " - " << setw(7) << record->winner << "- "
             << setw(record->name.length()) << record->name << " - " << record->film << endl;

        actMenu::confirmation_Menu(1);
        cin >> confirm;
        //If there is an invalid choice, they will get to choose again
        confirm = errorCheck(confirm, "THREE", 3, 3, 1);

        //check to add the record
        confirmRecordAdd(confirm, actorInfo, record);

        //Add the record
    }else if (changeMind == "2"){actorAdd();}
}

//Function to confirm the record.
//Will add the record to the tree
void actBinaryTree::confirmRecordAdd(const string& choice, BSTree<actor>* tree, actor* record)
{
    string adder;

    switch (stoi(choice))
    {
        case 1:
            tree->insert(record);
            cout << "\nI have added the record for you!" << endl;
            actMenu::another_Menu(1);
            cin >> adder;
            adder = errorCheck(adder, "TWO", 2, 5, 1);
            if (adder == "1"){actorAdd();}
            else if (adder == "2"){return;}
            break;
        case 2:
            changeMindAddRecord("2", record);
            break;
        case 3:
            return;
    }
}

/***************************************** FUNCTIONS FOR ADD END ******************************************************/
/***************************************** FUNCTIONS FOR DELETE  ******************************************************/

//Function to make sure that deleting is what the user wants to do
//Will call the actorDeleteRecord function to finish everything
void actBinaryTree::actorDelete() {
    int choice;
    cout << "Woah there! You are about to delete a record, are you sure you want to continue?\n"
         << "1. Continue to delete a record\n"
         << "2. Back to Actor / Actress menu\n";
    cin >> choice;

    switch(choice){
        case 1:
            actorDeleteRecord();
            break;
        case 2:
            cout << endl;
            mainMenu();
            break;
        default:
            cout << "Well that's not an option but I'll take you back to the menu anyway\n";
            mainMenu();
    }
}

//Main function to delete a record
//Will need to find the file first with the finders and find_TheRecord
//Once the record is found, CONFIRM that the user wants to delete it and then delete it
//Check to see if the user wants to delete anything else
//Run delete function again if yes, return to main menu if no
void actBinaryTree::actorDeleteRecord(){

    string confirm, confirm_More;
    vector<actor> finder, finder_Two, finder_Three;

    finder = find_TheRecord(1, actorInfo->getter_Vec());

    switch(finder.size()){
        case 0:{
            cout << "\nOkay I am taking you back to the main menu now, one second....\n";
            return;
        }
        case 1:
            finder = finder;
            break;
        case 2 ... 5:
            finder = record_Picker(finder);
            break;
        default:
            cout << setw(2) << left << "\nYEAR" << " - "
                 << setw(28) << "AWARD" << " - "
                 << setw(6) << "WINNER" << " - "
                 << setw(28) << "NAME" << " - " << "FILM\n";

            for (auto & result : finder){
                cout << result;
                finder_Two.push_back(result);
            }

            cout << "\nSorry, but I need you to make your search a little more specific\n";
            finder_Three = find_TheRecord(1, finder_Two);

            if (finder_Three.size() <= 5){finder = record_Picker(finder_Three);}
    }


    cout << "\nAre you sure you want to delete this record? I quite like that record personally...\n ";
    //Display the record that the user wants to delete
    for (auto & result : finder){cout << result;}

    //Send user to the confirmation menu to confirm and move forward
    actMenu::confirmation_Menu(2);
    cin >> confirm;

    //Error checking inside of the function for valid input
    while (!actor::checkTrue(confirm, "THREE")){
        cout << "\nSorry, but you need to choose between 1 and 3, please make sure you actually want to delete this record:\n";

        for (auto & result : finder){cout << result;}

        //Send them back to the confirmation menu
        actMenu::confirmation_Menu(2);
        cin >> confirm;
    }

    ///MAIN DELETE PROCESS
    //Push all off the attributes into the the new tree node
    //MUST BE IN ORDER:
    // name -> year -> award -> winner -> film
    if (confirm == "1"){
        for (auto & result : finder){
            auto* temp = new actor;
            temp->name = result.name;
            temp->year = result.year;
            temp->award = result.award;
            temp->winner = result.winner;
            temp->film = result.film;

            //REMOVE THE RECORD
            actorInfo->removeRecord(temp);
        }

        cout << "\n We deleted the record, but I'm going to miss it!\n";

        actMenu::another_Menu(2);
        cin >> confirm_More;

        //Error checking the choices
        confirm_More = errorCheck(confirm_More, "TWO", 2, 5, 2);

        //If the user confirms then delete then run the delete function again
        //If not then return to the main menu
        if (confirm_More == "1"){actorDelete();}
        else if (confirm_More == "2"){
            cout << "\nAlright, back to the main menu we go! One second...\n";
            return;
        }
        //Check confirm status and repeat delete function is confirm == 2
        //Otherwise go back to the main menu
    }else if (confirm == "2"){actorDelete();}
    else if (confirm == "3"){
        cout << "\nAlright, back to the main menu we go! One second...\n";
        return;
    }
}

/*************************************** FUNCTIONS FOR DELETE END *****************************************************/
/***************************************** FUNCTIONS FOR MODIFY ******************************************************/




/***************************************** FUNCTIONS FOR MODIFY END ***************************************************/
/***************************************** FUNCTIONS FOR SEARCH *******************************************************/

//Function to let the user pick either a partial or complete search
//Option 1 is complete search
//Option 2 is partial search
//Option 3 is back to the main menu
void actBinaryTree::actorSearch()
{
    string choice, confirm;
    actMenu::type_Menu(3);
    cin >> choice;

    choice = errorCheck(choice, "TWO", 2, 4, 3); // DISPLAY ERROR IF WRONG CHOICE AND CHOOSE AGAIN

    if (choice == "1"){
        actMenu::confirmation_Menu(6);
        cin >> confirm;
        confirm = errorCheck(confirm, "THREE", 3, 3, 6);

        if (confirm == "1"){
            cout << "\nCOMPLETE search for the Actor / Actress Database.\n";
            actor_SearchType(1);
            new_Search(1);
        }
        else if (confirm == "2"){
            cout << "\nPARTIAL search for the Actor / Actress Database.\n";
            actor_SearchType(2);
            new_Search(2);
        }
        else if (confirm == "3"){
            return;
        }
    }
    else if (choice == "2"){
        cout << "\tPARTIAL SEARCH\n";
        actor_SearchType(2);
        new_Search(2);
    }
}

//Function for Complete and Partial Search
//searchType = 1 is for complete search
//searchType = 2 is for partial search
//Will go in order:
//year -> award -> winner -> name -> film
//checkIfThere will check to locate the item being searched
void actBinaryTree::actor_SearchType(int searchType)
{
    string field, mode_Choice, year_Search, award_Search, winner_Search, name_Search, film_Search, temp;

    //complete search
    if (searchType == 1){
        actMenu::field_Menu(2);
        cin >> field,
                field = errorCheck(field, "FIVE", 5, 2, 2);

        switch (stoi(field)){
            case 1:
                year_Search = getYear();
                complete_SearchReturn(year_Search, "year");
                checkIfThere(year_Search);
                break;
            case 2:
                award_Search = getAward(1);
                complete_SearchReturn(award_Search, "award");
                break;
            case 3:
                winner_Search = getWinner();
                complete_SearchReturn(winner_Search, "winner");
                break;
            case 4:
                getline(cin, temp);
                name_Search = getName(2);
                complete_SearchReturn(name_Search, "name");
                checkIfThere(name_Search);
                break;
            case 5:
                getline(cin, temp);
                film_Search = getFilm(2);
                complete_SearchReturn(film_Search, "film");
                checkIfThere(film_Search);
                break;
        }
    }
        //Partial search
    else if (searchType == 2){
        actMenu::type_Menu(2);
        cin >> mode_Choice;
        mode_Choice = errorCheck(mode_Choice, "TWO", 2, 4, 2);
        actMenu::choose_Mode(mode_Choice);
        actMenu::field_Menu(4);
        cin >> field;
        field = errorCheck(field, "THREE", 3, 2, 4);

        switch (stoi(field)){
            case 1:
                getline(cin, temp);
                award_Search = getAward(2);
                partial_SearchReturn(award_Search, "award", mode_Choice);
                checkIfThere(award_Search);
                break;
            case 2:
                getline(cin, temp);
                name_Search = getName(3);
                partial_SearchReturn(name_Search, "name", mode_Choice);
                checkIfThere(name_Search);
                break;
            case 3:
                getline(cin, temp);
                film_Search = getFilm(2);
                partial_SearchReturn(film_Search, "film", mode_Choice);
                checkIfThere(film_Search);
                break;
        }
    }
}

//This function is designed to print the complete search results
//Gets the list from the vector
//Then prints out the results in order:
//year -> award -> winner -> name -> film
void actBinaryTree::complete_SearchReturn(const string& search, const string& field){
    vector<actor> allRecords = actorInfo->getter_Vec();
    cout << "\nI am printing out the results from the complete search, one moment!...\n";
    cout << "\nYEAR,AWARD,WINNER,NAME,FILM" << endl;
    for (auto & full_Records : allRecords){
        if (field == "year"){
            if (full_Records.year == search){
                record_Count++;
                cout << full_Records;
            }
        }
        if (field == "award"){
            if (full_Records.award == search){
                record_Count++;
                cout << full_Records;
            }
        }
        if (field == "winner"){
            if (full_Records.winner == search){
                record_Count++;
                cout << full_Records;
            }
        }
        if (field == "name"){
            if (full_Records.name == search){
                record_Count++;
                cout << full_Records;
            }
        }
        if (field == "film"){
            if (full_Records.film == search){
                record_Count++;
                cout << full_Records;
            }
        }
    }
}

//This function is designed to print the partial search results
//Gets the list from the vector
//Then prints out the results in order:
//year -> award -> winner -> name -> film
void actBinaryTree::partial_SearchReturn(const string& search, const string& field, const string& choice){
    vector<actor> allRecords = actorInfo->getter_Vec();
    string againstSearch;
    cout << "\nI am printing out the results from the partial search, one moment!...\n";
    cout << "\nYEAR,AWARD,WINNER,NAME,FILM" << endl;
    for (auto & allRecord : allRecords){
        if (choice == "1"){
            if (field == "award"){
                if (allRecord.award.find(search) != string::npos){
                    record_Count++;
                    cout << allRecord;
                }
            }
            if (field == "name"){
                againstSearch = allRecord.name;
                transform(againstSearch.begin(), againstSearch.end(), againstSearch.begin(), ::tolower);
                if (againstSearch.find(search) != string::npos){
                    record_Count++;
                    cout << allRecord;
                }
            }
            if (field == "film"){
                againstSearch = allRecord.film;
                transform(againstSearch.begin(), againstSearch.end(), againstSearch.begin(), ::tolower);
                if (againstSearch.find(search) != string::npos)
                {
                    record_Count++;
                    cout << allRecord;
                }
            }
        }
        if (choice == "2"){
            if (field == "award"){
                if (allRecord.award.find(search) != string::npos){
                    record_Count++;
                    cout << allRecord;
                }
            }
            if (field == "name"){
                if (allRecord.name.find(search) != string::npos){
                    record_Count++;
                    cout << allRecord;
                }
            }
            if (field == "film"){
                if (allRecord.film.find(search) != string::npos){
                    record_Count++;
                    cout << allRecord;
                }
            }
        }
    }
}

//Function for doing a new search
//1 for complete search, 2 for partial search and back to main menu
void actBinaryTree::new_Search(int userChoice)
{
    string search;
    actMenu::confirmation_Menu(5);
    cin >> search;
    search = errorCheck(search, "TWO", 2, 3, 5);

    if (search == "1"){
        if (userChoice == 1){
            cout << "\nCOMPLETE SEARCH SELECTION\n";
            actor_SearchType(1);
        }
        if (userChoice == 2){
            cout << "\nPARTIAL SEARCH SELECTION\n";
            actor_SearchType(2);
        }
    }
    else if (search == "2"){return;}
}

//Function to send out menu calls and search function calls.
//Will do either a complete or partial search
//Also does error checks throughout the function
vector<actor> actBinaryTree::find_TheRecord(int userChoice, const vector<actor>& act_Vec){
    string string_Searcher, confirm;
    vector<actor> finder;

    //userChoice 1 is for type_Menu option 6 for deletion menu
    //retrieve the string_Searcher and error check it
    //userChoice 2 is for modifying the record
    if (userChoice == 1){
        actMenu::type_Menu(6);
        cin >> string_Searcher;
        string_Searcher = errorCheck(string_Searcher, "TWO", 2, 4, 4);
    }else if (userChoice == 2){
        actMenu::type_Menu(5);
        cin >> string_Searcher;
        string_Searcher = errorCheck(string_Searcher, "TWO", 2, 4, 5);
    }

    //Complete search if string_Searcher returns 1 from the menu
    if (string_Searcher == "1"){
        //Complete search confirming menu
        actMenu::confirmation_Menu(6);
        cin >> confirm;
        //error checking
        confirm = errorCheck(confirm, "TWO", 2, 3, 6);

        if (confirm == "1" || confirm == "2"){finder = return_SearchResult(stoi(confirm), act_Vec);}
    }
        //Partial search if string_Searcher returns 2 from menu
    else if (string_Searcher == "2"){finder = return_SearchResult(stoi(string_Searcher), act_Vec);}
    return finder;
}

//Will allow the user to select the record that they want to delete
//Returns the record tied to the choice
int actBinaryTree::pickRecord(int choice){
    int record = 0;
    switch(choice){
        case 1:
            record = 0;
            break;
        case 2:
            record = 1;
            break;
        case 3:
            record = 2;
            break;
        case 4:
            record = 3;
            break;
        case 5:
            record = 4;
            break;
        default:
            break;
    }
    return record;
}

//Shows the user which record they are choosing to delete
//Lets user select the record
//Error checking through record_PickerError
//return finder
vector<actor> actBinaryTree::record_Picker(vector<actor> act_Vec){
    string record;
    int selection;
    vector<actor> finder, finder_Two;

    cout << "\nIs this what you were looking for?\n "
         << setw(6) << left << "\n   YEAR" << " - "
         << setw(28) << "AWARD" << " - "
         << setw(6) << "WINNER" << " - "
         << setw(28) << "NAME" << " - " << "FILM" << endl;

    for (unsigned i = 0; i < act_Vec.size(); i++){cout << i + 1 << ": " << act_Vec[i];}

    cout << "\nThis part is pretty important!... Please select the number relating to the record you want: ";
    cin >> record;
    //Error checking
    record = record_PickerError(act_Vec.size(), record);
    //Record picking
    selection = pickRecord(stoi(record));
    //push_back into the vector with selected record
    finder.push_back(act_Vec[selection]);
    return finder;
}

//This will do either the complete or partial search for the record being deleted.
//Lets the user pick, then does the search chosen
//Calls the menu options to make sure the right thing is searched
//Then calls the main search function
vector<actor> actBinaryTree::return_SearchResult(int searcher, vector<actor> act_Vec) {
    string field_Choice, userChoice, search, field, temp;
    vector<actor> finder;

    //First option 1 is for doing a complete search
    if (searcher == 1){
        userChoice = "3";
        //field_Menu option 2 for complete search
        actMenu::field_Menu(2);
        cin >> field_Choice;
        //Error checking
        field_Choice = errorCheck(field_Choice, "FIVE", 5, 2, 2);

        //This needs to be done in order:
        //year -> award -> winner -> name -> film
        switch (stoi(field_Choice)){
            case 1:
                search = getYear();
                field = "year";
                break;
            case 2:
                search = getAward(1);
                field = "award";
                break;
            case 3:
                search = getWinner();
                field = "winner";
                break;
            case 4:
                getline(cin, temp);
                search = getName(2);
                field = "name";
                break;
            case 5:
                getline(cin, temp);
                search = getFilm(2);
                field = "film";
                break;
            default:
                break;
        }
        //Second option 2 is for doing a partial search
    }else if (searcher == 2){
        //checking is the user wants to do the contain or exact option
        actMenu::type_Menu(2);
        cin >> userChoice;
        userChoice = errorCheck(userChoice, "TWO", 2, 4, 2);
        actMenu::choose_Mode(userChoice);
        actMenu::field_Menu(4);
        cin >> field_Choice;
        field_Choice = errorCheck(field_Choice, "THREE", 3, 2, 4);

        //This needs to be done in order:
        //award -> name -> film
        //Partial
        switch (stoi(field_Choice))
        {
            case 1:
                getline(cin, temp);
                search = getAward(2);
                field = "award";
                break;
            case 2:
                getline(cin, temp);
                search = getName(3);
                field = "name";
                break;
            case 3:
                getline(cin, temp);
                search = getFilm(2);
                field = "film";
                break;
        }
    }

    //Making sure it is there then returning finder
    finder = search_ForRecord(search, field, searcher, userChoice, std::move(act_Vec));
    checkIfThere(search);
    return finder;
}

//main search function to get through the vector and return the found vector
//Used for deletion
//Will go through complete or partial checks, and also contains/exact partial checks
vector<actor>
actBinaryTree::search_ForRecord(const string& search, const string& field, int searcher, const string& userChoice, vector<actor> act_Vec) {
    //retrieving the vector
    vector<actor> records = std::move(act_Vec);
    vector<actor> found;
    string checker;

    for (auto & allRecord : records){
        //option 1 for complete check
        //These checks must be done in order:
        //year -> award -> winner -> name -> film
        if (searcher == 1){
            if (userChoice == "3"){
                if (field == "year"){
                    if (allRecord.year == search){
                        record_Count++;
                        found.push_back(allRecord);
                    }
                }if (field == "award"){
                    if (allRecord.award == search){
                        record_Count++;
                        found.push_back(allRecord);
                    }
                }
                if (field == "winner"){
                    if (allRecord.winner == search){
                        record_Count++;
                        found.push_back(allRecord);
                    }
                }
                if (field == "name"){
                    if (allRecord.name == search){
                        record_Count++;
                        found.push_back(allRecord);
                    }
                }
                if (field == "film"){
                    if (allRecord.film == search){
                        record_Count++;
                        found.push_back(allRecord);
                    }
                }
            }

        }
            //option 2 for partial check
            //These checks must be done in order:
            //For contains option userChoice = 1:
            //award -> name -> film
            //For exact option userChoice = 2:
            //award -> name -> film

        else if (searcher == 2){
            if (userChoice == "1"){
                if (field == "award"){
                    if (allRecord.award.find(search) != string::npos){
                        record_Count++;
                        found.push_back(allRecord);
                    }
                }
                if (field == "name"){
                    checker = allRecord.name;
                    transform(checker.begin(), checker.end(), checker.begin(), ::tolower);
                    if (checker.find(search) != string::npos){
                        record_Count++;
                        found.push_back(allRecord);
                    }
                }
                if (field == "film"){
                    checker = allRecord.film;
                    transform(checker.begin(), checker.end(), checker.begin(), ::tolower);
                    if (checker.find(search) != string::npos){
                        record_Count++;
                        found.push_back(allRecord);
                    }
                }
            }
            if (userChoice == "2"){
                if (field == "award"){
                    if (allRecord.award.find(search) != string::npos){
                        record_Count++;
                        found.push_back(allRecord);
                    }
                }
                if (field == "name"){
                    if (allRecord.name.find(search) != string::npos){
                        record_Count++;
                        found.push_back(allRecord);
                    }
                }
                if (field == "film"){
                    if (allRecord.film.find(search) != string::npos){
                        record_Count++;
                        found.push_back(allRecord);
                    }
                }
            }
        }
    }

    return found;
}
/***************************************** FUNCTIONS FOR SEARCH END ***************************************************/
/******************************************* FUNCTIONS FOR SORT  ******************************************************/

//Main function for sorting
void actBinaryTree::actorSort(){
    string sort_Type, confirm, sort_Again;
    actMenu::field_Menu(3);
    cin >> sort_Type;
    //error checking
    sort_Type = errorCheck(sort_Type, "FIVE", 5, 2, 3);

    //Actor / Actress field
    if (sort_Type == "4"){
        cout << "\nGood News! The database is currently sorted by " << actor::fields(stoi(sort_Type)) << "!\n";
        //check for additional sorting
        actMenu::another_Menu(6);
        cin >> sort_Again;
        //error checking
        sort_Again = errorCheck(sort_Again, "TWO", 2, 5, 6);

        if (sort_Again == "1"){actorSort();}
        else if (sort_Again == "2"){
            cout << "\nOkay, I am taking you back to the main menu now...\n";
            return;
        }
    }

    cout << "\nYou are about to sort by " << actor::fields(stoi(sort_Type)) << ", are you sure you want to do that?\n";
    actMenu::confirmation_Menu(4);
    cin >> confirm;

    //More error checking
    while (!actor::checkTrue(confirm, "THREE"))
    {
        cout << "Whoops! Can't do that, please try again...\n "
             << "Make sure your choice is between 1-3 or it won't work!\n"
             << "\nYou are about to sort by " << actor::fields(stoi(sort_Type)) << ", are you sure you want to do that?\n";
        actMenu::confirmation_Menu(4);
        cin >> confirm;
    }

    if (confirm == "1"){
        switch (stoi(sort_Type)){
            case 1:
                //Year
                database_Sorter(2);
                break;
            case 2:
                //Award
                database_Sorter(4);
                break;
            case 3:
                //Winner
                database_Sorter(3);
                break;
            case 5:
                //Film
                database_Sorter(1);
                break;
        }

        cout << "\nGood News! The database is currently sorted by " << actor::fields(stoi(sort_Type)) << "!\n";
        cout << "\nOkay, I am taking you back to the main menu now...\n";
    }
    //sort menu
    if (confirm == "2"){actorSort();}
    //main menu
    if (confirm == "3"){
        cout << "\nOkay, I am taking you back to the main menu now...\n";
        return;
    }
}

//Sort database function, tree sort
//Will retrieve the list, delete the tree, then sort by the selected field
void actBinaryTree::database_Sorter(int chosen_Field){
    vector<actor> list = actorInfo->getter_Vec();
    actorInfo->deleteTree();

    for (auto & i : list){
        auto* newRecord = new actor;
        *newRecord = i;
        newRecord->fieldType = chosen_Field;
        actorInfo->insert(newRecord);
    }
}

//Function to check the number of records and print if it was not found
void actBinaryTree::checkIfThere(const string& search){
    if (get_record_Count() == 0){
        cout << "Oh No! Your search for \"" << search << "\" could not be found!\n";
    }
}


/***************************************** FUNCTIONS FOR SORT END *****************************************************/
/****************************************** FUNCTIONS FOR OUTPUT ******************************************************/

//Function to print the database
void actBinaryTree::printDatabase(){
    string confirm;
    actMenu::confirmation_Menu(7);
    cin >> confirm;
    confirm = errorCheck(confirm, "TWO", 2, 3, 7);

    if (confirm == "1"){output_ToFile();}
    else if (confirm == "2"){return;}
}

//Function to output the database to a csv file
void actBinaryTree::output_ToFile(){
    ofstream outFile;
    vector<actor> allRecords = actorInfo->getter_Vec();
    outFile.open("finished_Database.csv");

    for (auto & allRecord : allRecords){print_file(outFile, allRecord);}
    outFile.close();

}

//Will output the fields
void actBinaryTree::print_file(ostream &out, actor &record) {
    out << record.year << ",";
    out << record.award << ",";
    out << record.winner << ",";
    out << record.name << ",";
    out << record.film << endl;
}

/**************************************** FUNCTIONS FOR OUTPUT END ****************************************************/