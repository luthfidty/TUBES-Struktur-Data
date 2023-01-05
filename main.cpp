#include "ADT.h"

int main()
{
    QueueUser QU;
    StackChar SC;
    adrQueueUser pu;
    infotypeQueueUser dataUser;
    char lanjut;
    bool lanjutInput;

    createQueueUser(QU);
    createStackSC(SC);

    cout << "Selamat Datang di Program Generate Kode Rahasia" << endl << endl;

    lanjutInput = true;
    while (lanjutInput) {
        cout << "Input Nama: ";
        cin >> dataUser.nama;
        cout << "Input Tanggal Lahir (1-31): ";
        cin >> dataUser.tanggal;
        cout << "Input Bulan Lahir (1-12): ";
        cin >> dataUser.bulan;
        cout << "Input Tahun (4 digit): ";
        cin >> dataUser.tahun;
        cout << "Input Kode: ";
        cin >> dataUser.kode;
        while (!isPalindrom(SC,dataUser.kode)) {
            cout << "Input Kode: ";
            cin >> dataUser.kode;
        }

        pu = createElmQueueUser(dataUser);
        enQueueU(QU, pu);

        cout << endl;

        cout << "lanjut? (y/n): ";
        cin >> lanjut;

        if (lanjut == 'y'){
            lanjutInput = true;
        } else {
            lanjutInput = false;
        }

        cout << endl;
    }

    StackInt stackTgl, stackBln;
    QueueInt QI;
    adrQueueInt pi;

    adrQueueUser pu1 = QU.head;
    int i, hasilPop, kodeRahasia;
    int j = 1;
    while (pu1 != NULL) {
        createQueueInt(QI);
        createStackSI(stackTgl);
        createStackSI(stackBln);

        cout << "User-" << j << endl;
        decimalToBiner(pu1, stackTgl, stackBln);
        cout << "Angka Biner dari tanggal: ";
        i = stackTgl.top;
        while (i > -1) {
            cout << stackTgl.info[i];
            i--;
        }
        cout << endl;
        cout << "Angka Biner dari bulan: ";
        i = stackBln.top;
        while (i > -1) {
            cout << stackBln.info[i];
            i--;
        }
        cout << endl;

        while (stackTgl.top > -1 || stackBln.top > -1) {
            if (stackTgl.top > -1) {
                hasilPop = popSI(stackTgl);
                pi = createElmQueueInt(hasilPop);
                enQueueI(QI, pi);
            }
            if (stackBln.top > -1) {
                hasilPop = popSI(stackBln);
                pi = createElmQueueInt(hasilPop);
                enQueueI(QI, pi);
            }
        }

        cout << "Hasil selang seling angka binary tanggal dan bulan: ";
        pi = QI.head;
        while (pi != NULL) {
            cout << pi->info;
            pi = pi->next;
        }
        cout << endl;

        kodeRahasia = binerToDecimal(QI);
        cout << "Kode rahasia: " << kodeRahasia;
        pu1->info.kodeRahasi = kodeRahasia;

        cout << endl << endl;

        pu1 = pu1->next;
        j++;
    }
    return 0;
}
