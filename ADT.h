#ifndef ADT_H_INCLUDED
#define ADT_H_INCLUDED

#include <iostream>
#include <math.h>

using namespace std;

struct user
{
    string nama, kode;
    int tanggal,bulan,tahun, kodeRahasi;
};

typedef char infotypeStackChar;
typedef int infotypeStackInt;
typedef user infotypeQueueUser;
typedef int infotypeQueueInt;
typedef struct elmQueueUser *adrQueueUser;
typedef struct elmQueueInt *adrQueueInt;

struct StackChar
{
    infotypeStackChar info[10];
    int top;
};

struct StackInt
{
    infotypeStackInt info[15];
    int top;
};

struct elmQueueUser
{
   infotypeQueueUser info;
   adrQueueUser next;
};

struct elmQueueInt
{
    infotypeQueueInt info;
    adrQueueInt next;
};

struct QueueUser
{
    adrQueueUser head, tail;
};

struct QueueInt
{
    adrQueueInt head, tail;
};

void createQueueUser(QueueUser &Q);
void createQueueInt(QueueInt &Q);
void createStackSC(StackChar &S);
void createStackSI(StackInt &S);
adrQueueUser createElmQueueUser(infotypeQueueUser x);
adrQueueInt createElmQueueInt(infotypeQueueInt x);
bool isPalindrom(StackChar &S, string kode);
bool isEmptySC(StackChar &S);
bool isEmptySI(StackInt &S);
bool isFullSC(StackChar &S);
bool isFullSI(StackInt &S);
void pushSC(StackChar &S, char x);
void pushSI(StackInt &S, int x);
char popSC(StackChar &S);
int popSI(StackInt &S);
void enQueueU(QueueUser &Q, adrQueueUser x);
void enQueueI(QueueInt &Q, adrQueueInt x);
void deQueueU(QueueUser &Q, adrQueueUser &x);
void deQueueI(QueueInt &Q, adrQueueInt &x);
void decimalToBiner(adrQueueUser p, StackInt &stackTgl, StackInt &stackBln);
int binerToDecimal(QueueInt Q);

#endif // ADT_H_INCLUDED
