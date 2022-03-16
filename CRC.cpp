#include <iostream>
#include <string>
using namespace std;

#define MAX_LENGTH 1000

int Dataword[MAX_LENGTH]; //also works as a codeword 
int Divisor[MAX_LENGTH];
int Quotient[MAX_LENGTH];
int Remainder[MAX_LENGTH];

int orda_len, da_len, di_len;
int cnt, qnt;

string dataword, divisor;
bool state;

void CRC(int choose) {
    if (choose == 0) return;

    if (choose == 1)
        cout << "Dataword : ";

    if (choose == 2)
        cout << "Codeword : ";

    cin >> dataword;
    cout << "Divisor : ";
    cin >> divisor;

    orda_len = dataword.length();
    da_len = dataword.length();
    di_len = divisor.length();

    if (choose == 1) {
        for (int i = 0; i < di_len - 1; i++) {
            dataword.push_back('0');
        }
        da_len = dataword.length();
    }

    for (int i = 0; i < da_len; i++) {
        Dataword[i] = dataword[i] - '0';
    }

    for (int i = 0; i < di_len; i++) {
        Divisor[i] = divisor[i] - '0';
    }

    //calculate
    while (1) {

        int len = da_len - di_len;

        if (cnt == len + 1) { //무한루프 탈출조건
            break;
        }

        if (Dataword[qnt] == 1) { //몫값이 1
            Quotient[qnt++] = 1;
            for (int j = 0; j < divisor.length(); j++) { //xor연산
                if (Divisor[j] != Dataword[j + cnt]) {
                    Dataword[j + cnt] = 1;
                }
                else {
                    Dataword[j + cnt] = 0;
                }
            }
        }

        else { //목값이 0
            Quotient[qnt++] = 0;
            for (int j = 0; j < divisor.length(); j++) { //xor연산
                if (0 != Dataword[j + cnt]) {
                    Dataword[j + cnt] = 1;
                }
                else {
                    Dataword[j + cnt] = 0;
                }
            }
        }
        cnt++;
    } //loop

    int r_cnt = 0;

    for (int i = cnt; i < da_len; i++) {
        Remainder[r_cnt++] = Dataword[i];
    }

    //print
    cout << "Remainder : ";
    for (int i = 0; i < da_len - cnt; i++) {
        if (Remainder[i] != 0) {
            cout << Remainder[i];
            state = true;
        }

        if (state && Remainder[i] == 0) {
            cout << Remainder[i];
        }

    }cout << '\n';

    cout << "FCS : ";
    for (int i = 0; i < da_len - cnt; i++) {
        cout << Remainder[i];
    } cout << "\n\n";


    if (choose == 1) {
        cout << "Codeword : ";
        for (int i = 0; i < orda_len; i++) {
            cout << dataword[i];
        }
        for (int i = 0; i < da_len - cnt; i++) {
            cout << Remainder[i];
        }cout << '\n';
    }

    else if (choose == 2) {
        bool possible = true;

        for (int i = 0; i < da_len - cnt; i++) {
            if (Remainder[i] == 1) possible = false;
        }

        if (possible) {
            cout << "유효함!\n";

            cout << "Dataword : ";
            for (int i = 0; i < da_len - (di_len - 1); i++) {
                cout << dataword[i];
            }
        }
        else cout << "무효함!\n";

    }
}

int main() {

    cout << "1: Dataword to codeword\n";
    cout << "2: Codeword to dataword\n";
    cout << "0 : Exit\n";
    cout << "> ";

    int choose;
    cin >> choose;

    CRC(choose);

    return 0;
}