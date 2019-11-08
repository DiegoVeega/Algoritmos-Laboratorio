/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 00148816
 *
 * Created on November 8, 2019, 3:48 PM
 */

#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct node{
    int key;
    struct node *left, *right;
};

struct node *newNode(int item){
    struct node *temp = new node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct node *root){
    if (root != NULL){
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

struct node* insert(struct node* node, int key){
    if (node == NULL) return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    return node;
}


struct node * minValueNode(struct node* node){
    struct node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct node * maxValueNode(struct node* node){
    struct node* current = node;
    while (current && current->right != NULL)
        current = current->right;
    return current;
}

int Padre(struct node * root, int number1, int number2){
    struct node* current = root;
    
    if(current->key > number1 && current->key > number2){
        current = current ->left;
        Padre(current, number1, number2);
    }
    if(current->key < number1 && current->key < number2){
        current = current->right;
        Padre(current, number1, number2);
    }
    else{
        return current->key;
    }
}


int main(){

/* Let us create following BST
            8
        /       \
    3              10
 /      \             \
1       6             14 
    /       \        /
   4         7      13
*/

    struct node *root = NULL;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 14);
    root = insert(root, 13);
    
    printf("Inorder traversal of the given tree \n");
    inorder(root);
    
    //Es necesaria la raiz del arbol y los indices a comparar.
    printf("\n");
    printf("Ejercicio1: \n");
    printf("%d",Padre(root, 1, 7));
    return 0;
}

