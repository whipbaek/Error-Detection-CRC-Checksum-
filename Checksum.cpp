#include <iostream>
#include <string>
#include <vector>
using namespace std;

int EmptyStr[16] = { 0,0,0,0,
                     0,0,0,0,
                     0,0,0,0,
                     0,0,0,0 };

#define MAXV 1000


string HtoB(char ch) {
    string str;
    switch (ch) {

    case '0': str = "0000"; break;
    case '1': str = "0001"; break;
    case '2': str = "0010"; break;
    case '3': str = "0011"; break;
    case '4': str = "0100"; break;
    case '5': str = "0101"; break;
    case '6': str = "0110"; break;
    case '7': str = "0111"; break;
    case '8': str = "1000"; break;
    case '9': str = "1001"; break;
    case 'a': str = "1010"; break;
    case 'b': str = "1011"; break;
    case 'c': str = "1100"; break;
    case 'd': str = "1101"; break;
    case 'e': str = "1110"; break;
    case 'f': str = "1111"; break;

    default:
        break;
    }

    return str;
}

char BtoH(string str) {
    char ch;

    if (str == "0000") ch = '0';
    if (str == "0001") ch = '1';
    if (str == "0010") ch = '2';
    if (str == "0011") ch = '3';
    if (str == "0100") ch = '4';
    if (str == "0101") ch = '5';
    if (str == "0110") ch = '6';
    if (str == "0111") ch = '7';
    if (str == "1000") ch = '8';
    if (str == "1001") ch = '9';
    if (str == "1010") ch = 'A';
    if (str == "1011") ch = 'B';
    if (str == "1100") ch = 'C';
    if (str == "1101") ch = 'D';
    if (str == "1110") ch = 'E';
    if (str == "1111") ch = 'F';

    return ch;
}

int main() {

    for (int choose = 1; choose <= 2; choose++) {
        if (choose == 1) cout << "수신 메세지(16진수) : ";
        else cout << "\n송신 메세지(16진수) : ";


        string msg;
        vector<string> tempbin;
        vector<string> Sbin;
        vector<vector<int>> a;
        cin >> msg;

        for (int i = 0; i < msg.length(); i++) {
            string temp = HtoB(msg[i]);
            tempbin.push_back(temp);
        }

        int cnt = 0;
        for (int i = 0; i < tempbin.size() / 4; i++) {
            string temp;
            for (int j = 0; j < 4; j++) {
                temp += tempbin[cnt++];
            }
            Sbin.push_back(temp);
        }

        cout << "<2진수 변환>\n";

        for (int i = 0; i < Sbin.size(); i++) {
            cout << Sbin[i] << '\n';  //Sbin에 16비트의 값이 담겨있음
        }

        for (int i = 0; i < Sbin.size(); i++) {
            string temp = Sbin[i];
            vector<int> itemp;
            for (int j = 0; j < temp.size(); j++) {
                itemp.push_back(temp[j] - '0');
            }
            a.push_back(itemp);
        }

        //Calculate

        int Carry = 0;

        for (int i = 0; i < a.size() - 1; i++) {

            for (int j = 15; j >= 0; j--) {

                int A = a[i][j];
                int B = a[i + 1][j];
                a[i + 1][j] = (A ^ B) ^ Carry; // S = (A^B) ^ Cin
                Carry = (A & B) | (Carry & (A ^ B)); // Cout = AB + Cin(A^B); 
            }

            //loop문을 다 돌고 나왔는데 Carry가 있다면
            if (Carry == 1) {
                for (int j = 15; j >= 0; j--) {
                    int A = EmptyStr[j];
                    int B = a[i + 1][j];

                    a[i + 1][j] = (A ^ B) ^ Carry;
                    Carry = (A & B) | (Carry & (A ^ B));
                }
            }

        }

        cout << "Sum : ";
        int idx = a.size() - 1;
        for (int i = 0; i < 16; i++) {
            cout << a[idx][i];
            if (a[idx][i] == 1) a[idx][i] = 0;
            else a[idx][i] = 1;
        }cout << '\n';

        vector<string> btoh;
        int cntt = 0;
        string temp = "";
        for (int i = 1; i <= 16; i++) {
            temp += a[idx][i - 1] + '0';
            if (i % 4 == 0) {
                btoh.push_back(temp);
                temp = "";
            }
        }

        bool error = false;

        if (choose == 1) {
            cout << "CheckSum : ";
            for (int i = 0; i < btoh.size(); i++) {
                cout << BtoH(btoh[i]) << ' ';
            }cout << '\n';

            cout << "송신 측 : ";
            for (int i = 0; i < msg.size(); i++) {
                if (i % 2 == 0 && i != 0) cout << ' ';
                cout << msg[i];
            }
            cout << " [";
            for (int i = 0; i < btoh.size(); i++) {
                if (i % 2 == 0 && i != 0) cout << ' ';
                cout << BtoH(btoh[i]);
            }
            cout << "]";
        }

        else if (choose == 2) {
            cout << "Caluclated : ";
            for (int i = 0; i < btoh.size(); i++) {
                cout << BtoH(btoh[i]) << ' ';
                if (BtoH(btoh[i]) != '0') error = true;
            }cout << '\n';

            if (error) cout << "오류 있음\n";
            else cout << "오류 없음\n";
        }
        cout << '\n';
    }

    return 0;
}