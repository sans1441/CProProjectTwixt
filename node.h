#ifndef NODE_H
#define NODE_H

#include<stdio.h>
#include<stdlib.h>

typedef struct _Node
{
    int x, y; 
    int player;
    int neighbours[8];
} Node;

Node* createNode(int x, int y);
void setLink(Node *a, int direction); // Not important for midsubmission, do later.
void clearLink(Node *a, int direction); //Clears link for the node
void freeNode(Node *a);

#endif