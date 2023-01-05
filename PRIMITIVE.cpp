#include "ADT.h"

void createQueueUser(QueueUser &Q) {
    Q.head = NULL;
    Q.tail = NULL;
}

void createQueueInt(QueueInt &Q) {
    Q.head = NULL;
    Q.tail = NULL;
}

void createStackSC(StackChar &S) {
    S.top = -1;
}
void createStackSI(StackInt &S) {
    S.top = -1;
}

adrQueueUser createElmQueueUser(infotypeQueueUser x)
{
    adrQueueUser p = new elmQueueUser;

    p->info = x;
    p->next = NULL;

    return p;
}
adrQueueInt createElmQueueInt(infotypeQueueInt x)
{
    adrQueueInt p = new elmQueueInt;

    p->info = x;
    p->next = NULL;

    return p;
}

bool isPalindrom(StackChar &S, string kode)
{
    string diBalik = "";
    char v;
    int i = 0;
    int panjangKode = kode.size();

    while (i < panjangKode) {
        pushSC(S, kode[i]);
        i++;
    }

    while (S.top != -1){
        v = popSC(S);
        diBalik = diBalik + v;
    }

    if(kode == diBalik){
        return true;
    } else {
        return false;
    }
}

bool isEmptySC(StackChar &S)
{
    if(S.top == -1){
        return true;
    }
    return false;
}

bool isEmptySI(StackInt &S)
{
    if(S.top == -1){
        return true;
    }
    return false;
}

bool isFullSC(StackChar &S) {
    if(S.top == 30){
        return true;
    } else if (S.top == 11){
        return true;
    } else {
        return false;
    }
}

bool isFullSI(StackInt &S) {
    if(S.top == 30){
        return true;
    } else if (S.top == 11){
        return true;
    } else {
        return false;
    }
}

void pushSC(StackChar &S, char x) {
    if (S.top < 10) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "stack penuh" << endl;
    }
}

void pushSI(StackInt &S, int x) {
    if (S.top < 10) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "stack penuh" << endl;
    }
}

char popSC(StackChar &S) {
    char x;

    if (S.top == -1){
        cout << "Kosong" << endl;
    } else {
        x = S.info[S.top];
        S.top--;
    }

    return x;
}

int popSI(StackInt &S) {
    int x;

    if (S.top == -1){
        cout << "Kosong" << endl;
    } else {
        x = S.info[S.top];
        S.top--;
    }

    return x;
}

void enQueueU(QueueUser &Q, adrQueueUser x)
{
    adrQueueUser i = Q.head;
    if (Q.head == NULL) {
        Q.head = x;
    } else {
        while(i->next != NULL){
            i = i->next;
        }
        i->next = x;
    }
}

void enQueueI(QueueInt &Q, adrQueueInt x) {
    adrQueueInt i = Q.head;
    if (Q.head == NULL) {
        Q.head = x;
    } else {
        while(i->next != NULL){
            i = i->next;
        }
        i->next = x;
    }
}

void deQueueU(QueueUser &Q, adrQueueUser &x) {
    if(Q.head == NULL) {
        Q.head = x;
        Q.tail = x;
    } else {
        cout << "kosong" <<endl;
    }
}

void deQueueI(QueueInt &Q, adrQueueInt &x) {
    if(Q.head == NULL) {
        Q.head = x;
        Q.tail = x;
    } else {
        cout << "kosong" <<endl;
    }
}

void decimalToBiner(adrQueueUser p, StackInt &stackTgl, StackInt &stackBln) {
    int tgl, bln;

    tgl = p->info.tanggal;
    while(tgl > 0) {
        pushSI(stackTgl, tgl%2);
        tgl = tgl/2;
    }

    bln = p->info.bulan;
    while(bln > 0) {
        pushSI(stackBln, bln%2);
        bln = bln/2;
    }
}

int binerToDecimal(QueueInt Q)
{
    int panjangQueue, decimal;
    adrQueueInt p;

    p = Q.head;
    panjangQueue = -1;
    while(p != NULL) {
        panjangQueue++;
        p = p->next;
    }

    p = Q.head;
    decimal = 0;
    while(p != NULL) {
        decimal += p->info * pow(2, panjangQueue);
        panjangQueue--;
        p = p->next;
    }

    return decimal;
}
