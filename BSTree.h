//
// Created by Josh Mansito on 12/6/20.
//

#ifndef BARTHOLOMEW_BSTREE_H
#define BARTHOLOMEW_BSTREE_H
#include <iostream>
#include <vector>
#include <string>
#include "actor.h"

using namespace std;

template <class tree_Root>
class BSTree{

    //Making the tree root
    tree_Root* root;

    vector<tree_Root> get_Vec(tree_Root* current, vector<tree_Root>& tree_Vec);
    tree_Root* node_Remover(tree_Root* deleteRecord, tree_Root* current);
    tree_Root* min_Tree(tree_Root* current);

    bool isRemoved(tree_Root* record);

public:

    BSTree();
    ~BSTree();

    void deleteNode(tree_Root* current);
    void deleteTree();
    bool insert(tree_Root* newRecord);

    vector<tree_Root> getter_Vec();
    void removeRecord(tree_Root* record);

    friend ostream& operator << (ostream& out, BSTree& tree){
        vector<tree_Root> newRecords = tree.getter_Vec();
        int size = (int)newRecords.size();
        for (int i = 0; i < size; i++){out << newRecords.at(i);}
        return out;
    }
};
template <class tree_Root>
BSTree<tree_Root>::BSTree(){root = nullptr;}

template <class tree_Root>
BSTree<tree_Root>::~BSTree(){
    if (root == nullptr){return;}
    delete root;
}

//made for deleting nodes
template <class tree_Root>
void BSTree<tree_Root>::deleteNode(tree_Root* current){
    //if left or right are not empty, delete them, then delete current node
    if (current->left != nullptr){deleteNode(current->left);}
    if (current->right != nullptr){deleteNode(current->right);}
    delete current;
}

//made for deleting the tree
template <class tree_Root>
void BSTree<tree_Root>::deleteTree(){
    if (root == nullptr){return;}
    deleteNode(root);
    root = nullptr;
}

//function for insertion
//started with root, then goes through the tree and sets the left and right
//credit for insert: https://www.tutorialspoint.com/insert-into-a-binary-search-tree-in-cplusplus
template <class tree_Root>
bool BSTree<tree_Root>::insert(tree_Root* newRecord){
    if (root == nullptr){
        root = newRecord;
        return true;
    }

    tree_Root* current = root;
    bool setLeft = false;
    bool setRight = false;

    while (!setRight && !setLeft){
        if (newRecord->getField() > current->getField()){
            if (current->right != nullptr){
                current = current->right;
            }else{setRight = true;}
        }else{
            if (current->left != nullptr){
                current = current->left;
            }else{setLeft = true;}
        }
    }

    if (setLeft){current->left = newRecord;}
    if (setRight){current->right = newRecord;}
    return true;
}

//function to return the tree
template <class tree_Root>
vector<tree_Root> BSTree<tree_Root>::get_Vec(tree_Root* current, vector<tree_Root>& tree_Vec){
    if (current->left != nullptr){
        get_Vec(current->left, tree_Vec);
    }
    tree_Root newRecord = *current;
    newRecord.left = nullptr;
    newRecord.right = nullptr;
    tree_Vec.push_back(newRecord);

    if (current->right != nullptr){
        get_Vec(current->right, tree_Vec);
    }
    return tree_Vec;
}
//function to get the new vector
template <class tree_Root>
vector<tree_Root> BSTree<tree_Root>::getter_Vec(){
    vector<tree_Root> new_Vec;
    return get_Vec(root, new_Vec);
}

template<class tree_Root>
void BSTree<tree_Root>::removeRecord(tree_Root *record) {
    bool removed = isRemoved(record);

    if (!removed){cout << "Oh no! Database not found!\n";}
}
//Function needed to traverse the tree and find and delete data from it
//Will go though each layer checking the node -> left child -> right child
//Once it finds it then it will check for one or two children and do the removal process
template <class tree_Root>
tree_Root* BSTree<tree_Root>::node_Remover(tree_Root* deleteRecord, tree_Root* current){
    //If the tree is already empty then just return
    if (current == nullptr){return current;}

    //Check to see if the target for deletion is smaller than the root, then go to left child
    if (deleteRecord->getField() < current->getField()){
        current->left = node_Remover(deleteRecord, current->left);
    //Check to see if the target for deletion is larger than the root, then go to right child
    }else if (deleteRecord->getField() > current->getField()){
        current->right = node_Remover(deleteRecord, current->right);
    }
    //If the node is the target for deletion
    if (deleteRecord->getField() == current->getField()){
        //check for left child
        if (deleteRecord->film < current->film){
            current->left = node_Remover(deleteRecord, current->left);
            //check right child
        }else if (deleteRecord->film > current->film){
            current->right = node_Remover(deleteRecord, current->right);
            //check film node
        }if (deleteRecord->film == current->film){
            //check left child
            if (deleteRecord->year < current->year){
                current->left = node_Remover(deleteRecord, current->left);
                //check right child
            }else if (deleteRecord->year > current->year){
                current->right = node_Remover(deleteRecord, current->right);
                //check year node
            }if (deleteRecord->year == current->year){
                //check left child
                if (deleteRecord->winner < current->winner){
                    current->left = node_Remover(deleteRecord, current->left);
                    //check right child
                }else if (deleteRecord->winner > current->winner){
                    current->right = node_Remover(deleteRecord, current->right);
                    //check winner node
                }if (deleteRecord->winner == current->winner){
                    //check left child
                    if (deleteRecord->award < current->award){
                        current->left = node_Remover(deleteRecord, current->left);
                        //check right child
                    }else if (deleteRecord->award > current->award){
                        current->right = node_Remover(deleteRecord, current->right);
                        //check award node
                    }if (deleteRecord->award == current->award){
                        //award can be null, check for it, delete it, then set to nullptr
                        if (current->left == nullptr && current->right == nullptr){
                            delete current;
                            current = nullptr;
                        }
                            //if it has a child, check for children.
                            //first check if it only has right child
                            //store all of the contents from temp into root in ORDER:
                            //year -> award -> winner -> name -> film
                            //store the left and right nodes into root
                            //delete temp
                        else if (current->left == nullptr){
                            tree_Root* temp = current->right;

                            current->year = temp->year;
                            current->award = temp->award;
                            current->winner = temp->winner;
                            current->name = temp->name;
                            current->film = temp->film;

                            current->left = temp->left;
                            current->right = temp->right;
                            delete temp;

                            //Second, check for only having a left child
                            //store all of the contents from temp into root in ORDER:
                            //year -> award -> winner -> name -> film
                            //store the left and right nodes into root
                            //delete temp
                        }else if (current->right == nullptr){
                            tree_Root* temp = current->left;

                            current->year = temp->year;
                            current->award = temp->award;
                            current->winner = temp->winner;
                            current->name = temp->name;
                            current->film = temp->film;

                            current->left = temp->left;
                            current->right = temp->right;
                            delete temp;
                            //Third, do the process for it having both left and right children
                            //Recursively run to continue checking for children
                        }else{
                            tree_Root* temp = min_Tree(current->right);
                            current->year = temp->year;
                            current->award = temp->award;
                            current->winner = temp->winner;
                            current->name = temp->name;
                            current->film = temp->film;
                            current->right = node_Remover(temp, current->right);
                        }
                    }
                }
            }
        }
    }
    //Return the tree after modifications
    return current;
}
//Function to find the min
template<class tree_Root>
tree_Root *BSTree<tree_Root>::min_Tree(tree_Root *current) {

    while (current->left != nullptr){current = current->left;}
    return current;
}

template<class tree_Root>
bool BSTree<tree_Root>::isRemoved(tree_Root *record) {
    if (record == nullptr)
    {
        cout << "This is empty" << endl;
        return false;
    }


    root = node_Remover(record, root);
    return true;
}



#endif //BARTHOLOMEW_BSTREE_H
