#include<stdio.h>
#include<stdlib.h>
#include"node.h"

Node* createNode(int xcoord, int ycoord)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->x = xcoord;
    newNode->y = ycoord;
    newNode->player = 0;
    for(int i=0; i<8; i++) newNode->neighbours[i] = 0;
    return newNode;
}

void setLink(Node *a, int direction)
{
    if(direction>=0&&direction<8) a->neighbours[direction] = 1;
    return;
}

void clearLink(Node *a, int direction)
{
    a->neighbours[direction] = 0;
    return;
}

void freeNode(Node *a)
{
    free(a);
}