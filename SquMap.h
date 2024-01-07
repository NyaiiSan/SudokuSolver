#ifndef __SQUMAP_H__
#define __SQUMAP_H__

#include "main.h"

typedef int SqMDataType;

typedef struct squMapNode{
    SqMDataType val;
    struct squMapNode * right;
    struct squMapNode * bottom;
} SquMapNode;

typedef struct squMap{
    struct squMapNode * origin;
    int width;
}SquMap;

SquMap * createSquMap(int);

SquMapNode * createSquMapNode(SqMDataType val);

int initSquMap(SquMap *);

int setNodeValue(SquMap *, int x, int y, SqMDataType);

int getNodeValue(SquMap *, int x, int y, SqMDataType *);

void printSquMap(SquMap *);

void deleteSquMap(SquMap *);

void destroySquMap(SquMap *);

SquMap * copySquMap(SquMap *);

int inputLine(SquMap * head, int y);

int inputLines(SquMap * head);

#endif