//
// Created by Josh Mansito on 12/8/20.
//

#include "picBinaryTree.h"
#include "actBinaryTree.h"

//CONSTRUCTOR: Creates a Picture object
picBinaryTree :: picBinaryTree() {pictureInfo = nullptr;}

//Reads in records from a file and adds them as a node into the tree
//This must be done IN ORDER. Order is listed in the the function
void picBinaryTree ::createList(){
    ifstream picFile;
    string picHead, name, year, picNominations, picImdbRating, picDuration, picGenre1, picGenre2, picReleaseMonth, picMetaRating, picSynopsis;

    //Opens the file to read in the information
    picFile.open("pictures.csv");

    //Error message if file fails to open
    if (picFile.fail()) {
        cout << "Unable to open file." << endl;
        exit(1);
    }

    pictureInfo = new BSTree<picture>;

    //Reads the header file line (All of the category names)
    getline(picFile, picHead);

    while (picFile.good()) {
        auto* current = new picture;
        getline(picFile, name, ',');current->picName = name;                            //Gets the title
        getline(picFile, year, ',');current->picYear = year;                            //Gets the year of release
        getline(picFile, picNominations, ',');current->nominations = picNominations;    //Gets the number of nominations
        getline(picFile, picImdbRating, ',');current->imdbRating = picImdbRating;       //Gets the IMDB rating of the picture
        getline(picFile, picDuration, ',');current->duration = picDuration;             //Gets the film duration
        getline(picFile, picGenre1, ',');current->genre1 = picGenre1;                   //Gets the primary genre
        getline(picFile, picGenre2, ',');current->genre2 = picGenre2;                   //Gets the secondary genre
        getline(picFile, picReleaseMonth, ',');current->releaseMonth = picReleaseMonth; //Gets the month of release
        getline(picFile, picMetaRating, ',');current->metaRating = picMetaRating;       //Gets the Meta-critic rating
        getline(picFile, picSynopsis, ',');current->synopsis = picSynopsis;             //Gets the synopsis
        if(!current->picName.empty()){pictureInfo->insert(current);}
        else{delete current;}
    }
    picFile.close();
}

//Function to control the errors and send the user back to what they were trying to do if an error occurred.
string picBinaryTree::errorCheck(string choice, const string& error_Num, int error, int menu_Field, int userChoice){
    while (!actor::checkTrue(choice, error_Num)){
        picMenu::error_Check(error);

        if (menu_Field == 1){picMenu::main_Menu();}                         //1 = main menu
        else if (menu_Field == 2){picMenu::field_Menu(userChoice);}         //2 = Field menu
        else if (menu_Field == 3){picMenu::confirmation_Menu(userChoice);}  //3 = Confirmation
        else if (menu_Field == 4){picMenu::type_Menu(userChoice);}          //4 = Sub menu
        else if (menu_Field == 5){picMenu::another_Menu(userChoice);}       //5 = another_Menu
        else if (menu_Field == 6){picMenu::set_Info(userChoice);}           //6 = set_Info

    }
    return choice;
}

//Main Menu for the picture tree
//Menu will also need to be in order:
//Add -> Delete -> Modify -> Search -> Sort -> Print -> Change to other database
//Doing all of this in a switch statement for the user's choice
void picBinaryTree::mainMenu()
{
    int userChoice;
    picMenu::main_Menu();
    actBinaryTree switchToAct;
    bool haveSwitched = false;
    cin >> userChoice;

    userChoice = stoi(errorCheck(to_string(userChoice), "EIGHT", 9, 1, 0));

    while (userChoice != 8){
        switch (userChoice){
            case 1:
                cout << "\n  Here is where you can add a record \n" << "_________________________________________\n";
                picAdd();
                break;
            case 2:
                cout << "\n  Here is where you can delete a record \n" << "_________________________________________\n";
                break;
            case 3:
                cout << "\n  Here is where you can modify a record \n" << "_________________________________________\n";
                break;
            case 4:
                cout << "\n  Here is where you can search the records \n" << "_________________________________________\n";
                picSearch();
                break;
            case 5:
                cout << "\n  Here you can sort the database by a specific field \n" << "_________________________________________\n";
                picSort();
                break;
            case 6:
                cout << "\n  Here you can print the database to a file \n" << "_________________________________________\n";
                printDatabase();
                break;
            case 7:
                int choice;
                cout << "\n  Would you like to switch to the Actor / Actress database or stay here? \n"
                     << "_________________________________________\n";
                cout << "1. Switch to the Actor / Actress database\n"
                     << "2. Stay in the Pictures database\n";
                cin >> choice;

                if(choice == 1) {
                    switchToAct.createList();
                    switchToAct.mainMenu();
                    haveSwitched = true;
                }
                break;
            default:
                break;
        }

        cout << endl;
        picMenu::main_Menu();
        cin >> userChoice;
    }
}

//This calls the add record function
void picBinaryTree::picAdd() {cout << endl;pictureAddRecord();}

//Main function for adding a record
//All of the fields for the record will be received by functions called in order:
//Order is listed in the function
//Will then print out the input provided by the user
void picBinaryTree::pictureAddRecord(){
    string temp, confirm;
    //creating the new record with auto
    auto* newRecord = new picture;

    newRecord->picName = getPicName(1); cout << endl;   // GETS TITLE
    newRecord->picYear = getPicYear(); cout << endl;              // GETS YEAR
    newRecord->nominations = getNominations(); cout << endl;      // GETS NOMINATIONS
    newRecord->imdbRating = getIMDBRating(); cout << endl;        // GETS RATING
    newRecord->duration = getDuration(); cout << endl;            // GETS DURATION
    newRecord->genre1 = getPrimaryGenre(); cout << endl;          // GETS PRIMARY GENRE
    newRecord->genre2 = getSecondaryGenre(); cout << endl;        // GETS SECONDARY GENRE
    newRecord->releaseMonth = getReleaseMonth(); cout << endl;    // GETS MONTH OF RELEASE
    newRecord->metaRating = getMetaRating(); cout << endl;        // GETS META-CRITIC RATING
    newRecord->synopsis = getSynopsis(); cout << endl;            // GETS SYNOPSIS
    //Making sure a skip doesn't happen, might have to use this more than once throughout the code
    getline(cin, temp);

    cout << "\nThe new record looks great to me! But just in case.....\n";
    cout << setw(6) << left                     << "\nTITLE" << " - "
         << setw(newRecord->picYear.length())      << "YEAR" << " - "
         << setw(7)                             << "NUMBER OF NOMINATIONS" << " - "
         << setw(newRecord->imdbRating.length())   << "IMDB RATING" << " - "
         << setw(newRecord->duration.length())     << "DURATION" << " - "
         << setw(newRecord->genre1.length())       << "PRIMARY GENRE" << " - "
         << setw(newRecord->genre2.length())       << "SECONDARY GENRE" << " - "
         << setw(newRecord->releaseMonth.length()) << "MONTH OF RELEASE" << " - "
         << setw(newRecord->metaRating.length())   << "META-CRITIC RATING" << " - "
         << "SYNOPSIS\n";
    cout << setw(5) << newRecord->picName << "- " << setw(newRecord->picYear.length())
         << newRecord->picYear << " - " << setw(7) << newRecord->nominations << "- "
         << setw(newRecord->imdbRating.length()) << newRecord->imdbRating << " - "
         << setw(newRecord->duration.length()) << newRecord->duration << " - "
         << setw(newRecord->genre1.length()) << newRecord->genre1 << " - "
         << setw(newRecord->genre2.length()) << newRecord->genre2 << " - "
         << setw(newRecord->releaseMonth.length()) << newRecord->releaseMonth << " - "
         << setw(newRecord->metaRating.length()) << newRecord->metaRating << " - "
         << newRecord->synopsis << endl;

    //Will call for the confirmation to continue
    picMenu::confirmation_Menu(1);
    cin >> confirm;
    //If there is an invalid choice, they will get to choose again
    confirm = errorCheck(confirm, "THREE", 3, 3, 1);
    //Add the record
    confirmRecordAdd(confirm, pictureInfo, newRecord);
}

//Function to confirm the record.
//Will add the record to the tree
void picBinaryTree::confirmRecordAdd(const string& choice, BSTree<picture>* tree, picture* record){
    string adder;
    switch (stoi(choice)){
        case 1:
            tree->insert(record);
            cout << "\nI have added the record for you!" << endl;
            picMenu::another_Menu(1);
            cin >> adder;
            adder = errorCheck(adder, "TWO", 2, 5, 1);
            if (adder == "1"){picAdd();}
            else if (adder == "2"){return;}
            break;
        case 2:
            changeMindAddRecord("2", record);
            break;
        case 3:
            return;
    }
}

//Function to let the user pick either a partial or complete search
//Option 1 is complete search
//Option 2 is partial search
//Option 3 is back to the main menu
void picBinaryTree:: picSearch(){
    string choice, confirm;
    picMenu::type_Menu(3);
    cin >> choice;

    choice = errorCheck(choice, "TWO", 2, 4, 3); // DISPLAY ERROR IF WRONG CHOICE AND CHOOSE AGAIN

    if (choice == "1"){
        picMenu::confirmation_Menu(6);
        cin >> confirm;
        confirm = errorCheck(confirm, "THREE", 3, 3, 6);

        if (confirm == "1"){
            cout << "\nCOMPLETE search for the Pictures Database.\n";
            picture_SearchType(1);
            new_Search(1);
        }
        else if (confirm == "2"){
            cout << "\nPARTIAL search for the Pictures Database.\n";
            picture_SearchType(2);
            new_Search(2);
        }
        else if (confirm == "3"){
            return;
        }
    }
    else if (choice == "2"){
        cout << "\tPARTIAL SEARCH\n";
        picture_SearchType(2);
        new_Search(2);
    }
}

//Function for Complete and Partial Search
//searchType = 1 is for complete search
//searchType = 2 is for partial search
//checkIfThere will check to locate the item being searched
void picBinaryTree::picture_SearchType(int searchType)
{
    string field, mode_Choice, name_Search, year_Search, nominations_Search, imdb_Search, duration_Search, genre1_Search, genre2_Search, releaseMonth_Search, meta_Search, temp;

    //complete search
    if (searchType == 1){
        picMenu::field_Menu(2);
        cin >> field,
                field = errorCheck(field, "FIVE", 5, 2, 2);

        switch (stoi(field)){
            case 1:
                getline(cin, temp);
                name_Search = getPicName(2);
                complete_SearchReturn(name_Search, "name");
                checkIfThere(name_Search);
                break;
            case 2:
                year_Search = getPicYear();
                complete_SearchReturn(year_Search, "year");
                checkIfThere(year_Search);
                break;
            case 3:
                nominations_Search = getNominations();
                complete_SearchReturn(nominations_Search, "nomination");
                checkIfThere(nominations_Search);
                break;
            case 4:
                imdb_Search = getIMDBRating();
                complete_SearchReturn(imdb_Search, "IMDB");
                checkIfThere(imdb_Search);
                break;
            case 5:
                duration_Search = getDuration();
                complete_SearchReturn(duration_Search, "Duration");
                checkIfThere(duration_Search);
                break;
            case 6:
                genre1_Search = getPrimaryGenre();
                complete_SearchReturn(genre1_Search, "Prim");
                checkIfThere(genre1_Search);
                break;
            case 7:
                genre2_Search = getSecondaryGenre();
                complete_SearchReturn(genre2_Search, "Second");
                checkIfThere(genre2_Search);
                break;
            case 8:
                releaseMonth_Search = getReleaseMonth();
                complete_SearchReturn(releaseMonth_Search, "release");
                checkIfThere(releaseMonth_Search);
                break;
            case 9:
                meta_Search = getMetaRating();
                complete_SearchReturn(meta_Search, "meta");
                checkIfThere(meta_Search);
                break;
        }
    }
        //Partial search
    else if (searchType == 2){
        picMenu::type_Menu(2);
        cin >> mode_Choice;
        mode_Choice = errorCheck(mode_Choice, "TWO", 2, 4, 2);
        picMenu::choose_Mode(mode_Choice);
        picMenu::field_Menu(4);
        cin >> field;
       // field = errorCheck(field, "THREE", 3, 2, 4);

        switch (stoi(field)){
            case 1:
                getline(cin, temp);
                name_Search = getPicName(2);
                partial_SearchReturn(name_Search, "name", mode_Choice);
                checkIfThere(name_Search);
                break;
            case 2:
                year_Search = getPicYear();
                partial_SearchReturn(year_Search, "year", mode_Choice);
                checkIfThere(year_Search);
                break;
            case 3:
                nominations_Search = getNominations();
                partial_SearchReturn(nominations_Search, "nominations", mode_Choice);
                checkIfThere(nominations_Search);
                break;
            case 4:
                imdb_Search = getIMDBRating();
                partial_SearchReturn(imdb_Search, "IMDB", mode_Choice);
                checkIfThere(imdb_Search);
                break;
            case 5:
                duration_Search = getDuration();
                partial_SearchReturn(duration_Search, "Duration", mode_Choice);
                checkIfThere(duration_Search);
                break;
            case 6:
                genre1_Search = getPrimaryGenre();
                partial_SearchReturn(genre1_Search, "Prim", mode_Choice);
                checkIfThere(genre1_Search);
                break;
            case 7:
                genre2_Search = getSecondaryGenre();
                partial_SearchReturn(genre2_Search, "Second", mode_Choice);
                checkIfThere(genre2_Search);
                break;
            case 8:
                releaseMonth_Search = getReleaseMonth();
                partial_SearchReturn(releaseMonth_Search, "release", mode_Choice);
                checkIfThere(releaseMonth_Search);
                break;
            case 9:
                meta_Search = getMetaRating();
                partial_SearchReturn(meta_Search, "meta", mode_Choice);
                checkIfThere(meta_Search);
                break;
        }
    }
}

//This function is designed to print the complete search results
//Gets the list from the vector
//Then prints out the results in order:
//film name -> year -> number of nominations -> imdb rating -> duration -> primary genre -> secondary genre -> month of release -> metacritic rating -> synopsis
void picBinaryTree::complete_SearchReturn(const string& search, const string& field){
    vector<picture> allRecords = pictureInfo->getter_Vec();
    cout << "\nI am printing out the results from the complete search, one moment!...\n";
    cout << "\nNAME,YEAR,NUMBER OF NOMINATIONS,IMDB RATING,DURATION,PRIMARY GENRE,SECONDARY GENRE,MONTH OF RELEASE,METACRITIC RATING,SYNOPSIS" << endl;
    for (auto & full_Records : allRecords){
        if (field == "name"){
            if (full_Records.picName == search){
                record_Count++;
                cout << full_Records;
            }
        }
        if (field == "year"){
            if (full_Records.picYear == search){
                record_Count++;
                cout << full_Records;
            }
        }
        if (field == "nominations"){
            if (full_Records.nominations == search){
                record_Count++;
                cout << full_Records;
            }
        }
        if (field == "IMDB"){
            if (full_Records.imdbRating == search){
                record_Count++;
                cout << full_Records;
            }
        }
        if (field == "Duration"){
            if (full_Records.duration == search){
                record_Count++;
                cout << full_Records;
            }
        }
        if (field == "Prim"){
            if (full_Records.genre1 == search){
                record_Count++;
                cout << full_Records;
            }
        }
        if (field == "Second"){
            if (full_Records.genre2 == search){
                record_Count++;
                cout << full_Records;
            }
        }
        if (field == "release"){
            if (full_Records.releaseMonth == search){
                record_Count++;
                cout << full_Records;
            }
        }
        if (field == "meta"){
            if (full_Records.metaRating == search){
                record_Count++;
                cout << full_Records;
            }
        }
    }
}

// figure out the choices Here
//This function is designed to print the partial search results
//Gets the list from the vector
//Then prints out the results in order:
//year -> award -> winner -> name -> film
void picBinaryTree::partial_SearchReturn(const string& search, const string& field, const string& choice){
    vector<picture> allRecords = pictureInfo->getter_Vec();
    string againstSearch;
    cout << "\nI am printing out the results from the partial search, one moment!...\n";
    cout << "\nNAME-YEAR-NUMBER OF NOMINATIONS-IMDB-RATING-DURATION-PRIMARY GENRE-SECONDARY GENRE-MONTH OF RELEASE-METACRITIC RATING-SYNOPSIS" << endl;
    for (auto & allRecord : allRecords){
        if (choice == "1"){
            if (field == "name"){
                if (allRecord.picName.find(search) != string::npos){
                    record_Count++;
                    cout << allRecord;
                }
            }
            if (field == "year"){
                if (allRecord.picYear.find(search) != string::npos){
                    record_Count++;
                    cout << allRecord;
                }
            }
            if (field == "nominations"){
                if (allRecord.nominations.find(search) != string::npos){
                    record_Count++;
                    cout << allRecord;
                }
            }
            if (field == "IMDB"){
                if (allRecord.imdbRating.find(search) != string::npos){
                    record_Count++;
                    cout << allRecord;
                }
            }
            if (field == "Duration"){
                if (allRecord.duration.find(search) != string::npos){
                    record_Count++;
                    cout << allRecord;
                }
            }
            if (field == "Prim"){
                if (allRecord.genre1.find(search) != string::npos){
                    record_Count++;
                    cout << allRecord;
                }
            }
            if (field == "Second"){
                if (allRecord.genre2.find(search) != string::npos){
                    record_Count++;
                    cout << allRecord;
                }
            }
            if (field == "release"){
                if (allRecord.releaseMonth.find(search) != string::npos){
                    record_Count++;
                    cout << allRecord;
                }
            }
            if (field == "meta"){
                if (allRecord.metaRating.find(search) != string::npos){
                    record_Count++;
                    cout << allRecord;
                }
            }

        }
        if (choice == "2"){
            if (field == "name"){
                againstSearch = allRecord.picName;
                transform(againstSearch.begin(), againstSearch.end(), againstSearch.begin(), ::tolower);
                if (againstSearch.find(search) != string::npos){
                    record_Count++;
                    cout << allRecord;
                }
            }
            if (field == "year"){
                againstSearch = allRecord.picYear;
                transform(againstSearch.begin(), againstSearch.end(), againstSearch.begin(), ::tolower);
                if (againstSearch.find(search) != string::npos){
                    record_Count++;
                    cout << allRecord;
                }
            }
            if (field == "nominations"){
                againstSearch = allRecord.nominations;
                transform(againstSearch.begin(), againstSearch.end(), againstSearch.begin(), ::tolower);
                if (againstSearch.find(search) != string::npos){
                    record_Count++;
                    cout << allRecord;
                }
            }
            if (field == "IMDB"){
                againstSearch = allRecord.imdbRating;
                transform(againstSearch.begin(), againstSearch.end(), againstSearch.begin(), ::tolower);
                if (againstSearch.find(search) != string::npos){
                    record_Count++;
                    cout << allRecord;
                }
            }
            if (field == "Duration"){
                againstSearch = allRecord.duration;
                transform(againstSearch.begin(), againstSearch.end(), againstSearch.begin(), ::tolower);
                if (againstSearch.find(search) != string::npos){
                    record_Count++;
                    cout << allRecord;
                }
            }
            if (field == "Prim"){
                againstSearch = allRecord.genre1;
                transform(againstSearch.begin(), againstSearch.end(), againstSearch.begin(), ::tolower);
                if (againstSearch.find(search) != string::npos){
                    record_Count++;
                    cout << allRecord;
                }
            }
            if (field == "Second"){
                againstSearch = allRecord.genre2;
                transform(againstSearch.begin(), againstSearch.end(), againstSearch.begin(), ::tolower);
                if (againstSearch.find(search) != string::npos){
                    record_Count++;
                    cout << allRecord;
                }
            }
            if (field == "release"){
                againstSearch = allRecord.releaseMonth;
                transform(againstSearch.begin(), againstSearch.end(), againstSearch.begin(), ::tolower);
                if (againstSearch.find(search) != string::npos){
                    record_Count++;
                    cout << allRecord;
                }
            }
            if (field == "meta"){
                againstSearch = allRecord.metaRating;
                transform(againstSearch.begin(), againstSearch.end(), againstSearch.begin(), ::tolower);
                if (againstSearch.find(search) != string::npos){
                    record_Count++;
                    cout << allRecord;
                }
            }
        }
    }
}


//Function for doing a new search
//1 for complete search, 2 for partial search and back to main menu
void picBinaryTree::new_Search(int userChoice)
{
    string search;
    picMenu::confirmation_Menu(5);
    cin >> search;
    search = errorCheck(search, "TWO", 2, 3, 5);

    if (search == "1"){
        if (userChoice == 1){
            cout << "\nCOMPLETE SEARCH SELECTION\n";
            picture_SearchType(1);
        }
        if (userChoice == 2){
            cout << "\nPARTIAL SEARCH SELECTION\n";
            picture_SearchType(2);
        }
    }
    else if (search == "2"){return;}
}

//Main function for sorting
void picBinaryTree::picSort(){
    string sort_Type, confirm, sort_Again;
    picMenu::field_Menu(3);
    cin >> sort_Type;
    //error checking
    sort_Type = errorCheck(sort_Type, "FIVE", 5, 2, 3);

    //Actor / Actress field
    if (sort_Type == "4"){
        cout << "\nGood News! The database is currently sorted by " << picture::fields(stoi(sort_Type)) << "!\n";
        //check for additional sorting
        picMenu::another_Menu(6);
        cin >> sort_Again;
        //error checking
        sort_Again = errorCheck(sort_Again, "TWO", 2, 5, 6);

        if (sort_Again == "1"){picSort();}
        else if (sort_Again == "2"){
            cout << "\nOkay, I am taking you back to the main menu now...\n";
            return;
        }
    }

    cout << "\nYou are about to sort by " << picture::fields(stoi(sort_Type)) << ", are you sure you want to do that?\n";
    picMenu::confirmation_Menu(4);
    cin >> confirm;

    //More error checking
    while (!picture::isCorrect(confirm, "THREE"))
    {
        cout << "Whoops! Can't do that, please try again...\n "
             << "Make sure your choice is between 1-3 or it won't work!\n"
             << "\nYou are about to sort by " << picture::fields(stoi(sort_Type)) << ", are you sure you want to do that?\n";
        picMenu::confirmation_Menu(4);
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

        cout << "\nGood News! The database is currently sorted by " << picture::fields(stoi(sort_Type)) << "!\n";
        cout << "\nOkay, I am taking you back to the main menu now...\n";
    }
    //sort menu
    if (confirm == "2"){picSort();}
    //main menu
    if (confirm == "3"){
        cout << "\nOkay, I am taking you back to the main menu now...\n";
        return;
    }
}

//Sort database function, tree sort
//Will retrieve the list, delete the tree, then sort by the selected field
void picBinaryTree::database_Sorter(int chosen_Field){
    vector<picture> list = pictureInfo->getter_Vec();
    pictureInfo->deleteTree();

    for (auto & i : list){
        auto* newRecord = new picture;
        *newRecord = i;
        newRecord->fieldType = chosen_Field;
        pictureInfo->insert(newRecord);
    }
}

//Function to check the number of records and print if it was not found
void picBinaryTree::checkIfThere(const string& search){
    if (get_record_Count() == 0){
        cout << "Oh No! Your search for \"" << search << "\" could not be found!\n";
    }
}

//Function to print the database
void picBinaryTree::printDatabase(){
    string confirm;
    picMenu::confirmation_Menu(7);
    cin >> confirm;
    confirm = errorCheck(confirm, "TWO", 2, 3, 7);

    if (confirm == "1"){output_ToFile();}
    else if (confirm == "2"){return;}
}

//Function to output the database to a csv file
void picBinaryTree::output_ToFile(){
    ofstream outFile;
    vector<picture> allRecords = pictureInfo->getter_Vec();
    outFile.open("finished_Database.csv");

    for (auto & allRecord : allRecords){print_file(outFile, allRecord);}
    outFile.close();
}

//Will output the fields
void picBinaryTree::print_file(ostream &out, picture &record) {
    out << record.picName << ",";
    out << record.picYear << ",";
    out << record.nominations << ",";
    out << record.imdbRating << ",";
    out << record.duration << ",";
    out << record.genre1 << ",";
    out << record.genre2 << ",";
    out << record.releaseMonth << ",";
    out << record.metaRating << ",";
    out << record.synopsis << endl;
}

/* Finish getters */

//Overloading for printing out the database
ostream& operator << (ostream& out, picBinaryTree& list){out << *list.pictureInfo; return out;}

///Unfinished functions
void picBinaryTree::changeMindAddRecord(string confirm, picture *record) {
    cout << "Need to finish this";
}


///Need to add/verify that the error checks work
string picBinaryTree::getPicName(int userChoice) {
    string getName;
    if (userChoice == 1){
        cout << "\nPlease enter the FULL title:\n";
        cout << "Title: ";
        cin >> getName;

        //error check
        getName = errorCheck(getName, "nodigits", 7, 6, 2);
    }
    return getName;
}

string picBinaryTree::getPicYear() {
    string getYear;
    cout << "\nPlease enter in a four digit year:\n ";
    cin >> getYear;
    getYear = errorCheck(getYear, "year", 6, 6, 1);
    return getYear;
}

string picBinaryTree::getNominations() {
    string getNoms;
    cout <<"\nPlease enter in the number of nominations for this title:\n";
    cin >> getNoms;
    return getNoms;
}

string picBinaryTree::getIMDBRating() {
    string getIMDB;
    cout <<"\nPlease enter in the IMDB rating for this title:\n";
    cin >> getIMDB;
    return getIMDB;
}

string picBinaryTree::getDuration() {
    string getDura;
    cout <<"\nPlease enter in the duration for this title (in cumulative minutes):\n";
    cin >> getDura;
    return getDura;
}

string picBinaryTree::getPrimaryGenre() {
    string getGen1;
    cout <<"\nPlease enter in the primary genre for this title:\n";
    cin >> getGen1;
    return getGen1;
}

string picBinaryTree::getSecondaryGenre() {
    string getGen2;
    cout <<"\nPlease enter in the secondary genre for this title:\n";
    cin >> getGen2;
    return getGen2;
}

string picBinaryTree::getReleaseMonth() {
    string getMo;
    cout <<"\nPlease enter in the month this title was released:\n";
    cin >> getMo;
    return getMo;
}

string picBinaryTree::getMetaRating() {
    string getMeta;
    cout <<"\nPlease enter in the Metacritic rating for this title:\n";
    cin >> getMeta;
    return getMeta;
}

string picBinaryTree::getSynopsis() {
    string getSyn;
    cout <<"\nPlease enter in a synopsis for this title:\n";
    cin >> getSyn;
    return getSyn;
}