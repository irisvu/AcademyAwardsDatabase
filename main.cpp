#include <iostream>
#include "actBinaryTree.h"
#include "picBinaryTree.h"

using namespace std;

int main()
{
    int firstMenu = 0;

    cout << "----Welcome to Bartholomew, the Database Data Structure assistant!----\n\n";
    //or something
    cout << "There are a lot of things I can do for you, but first, tell me which data base you would like to start with.\n"
         << "1) Actor / Actress Database\n"
         << "2) Pictures \"Movies\" Database\n";
    cin >> firstMenu;

    switch(firstMenu){

        case 1: {

            actBinaryTree actorInfo;
            actorInfo.createList();
            actorInfo.mainMenu();

            break;
        }
        case 2: {

            picBinaryTree pictureInfo;
            pictureInfo.createList();
            pictureInfo.mainMenu();

            break;
        }
        default:
            break;

    }
    return 0;
}