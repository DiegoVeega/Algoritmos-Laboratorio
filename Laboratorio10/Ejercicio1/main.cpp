/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 00148816
 *
 * Created on November 13, 2019, 9:15 AM
 */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

struct node
{
    int key;
    struct node *left, *right;
    int height;
};

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

struct node *newNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    temp->height = 1;
    return temp;
}

void preOrder(struct node *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->key);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

int Balance(node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

node *rightRotate(node *y)
{
    node *x = y->left;
    node *t = x->right;

    x->right = y;
    y->left = t;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

node *leftRotate(node *x)
{
    node *y = x->right;
    node *t = y->left;

    y->left = x;
    x->right = t;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

struct node *insert(struct node *node, int key)
{
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    node->height = 1 + max(height(node->left),
                           height(node->right));

    int balance = Balance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void obtenerL(struct node* root,vector<node*> &v1){
    if(root!=NULL){
        obtenerL(root->left,v1);
        v1.push_back(root);
        obtenerL(root->right,v1);
    }
}

struct node* balancear(vector<node*> &v1,int inicio, int f){
    if(inicio>f) return NULL;
    int mid=(inicio+f)/2;
    struct node* root=v1.at(mid);
    root->left=balancear(v1,inicio,mid-1);
    root->right=balancear(v1,mid+1,f);
    return root;
}

int main()
{
    struct node *root = NULL;

    vector<node*> lista;
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 8);
    root = insert(root, 7);
    root = insert(root, 6);
    root = insert(root, 5);
    root = insert(root, 4);
    
    obtenerL(root,lista);
    int size=lista.size();
    root=balancear(lista,0,size-1);
    
    preOrder(root);

    return 0;
}