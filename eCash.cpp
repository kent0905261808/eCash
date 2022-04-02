#include <iostream>
#include <fstream>
#include <string.h>
#include <windows.h>

using namespace std;

string long_long_to_string(long long n) {
    string re;
    while (n > 0) {
        re = (char) (n % 10 + 48) + re;
        n /= 10;
    }
    return re;
}

// This code not only illistrate the login and logout system, but also execute the main part of the program.
class eCash {
private:
    long long money;
    string account;
public:
    void login();
    void logout();
    void userInterface();
    void store();
    void pay();
    void display();
};
// First step is that we need to login our account in order to certain the real user, and show whether your account is aveiable or not.
void eCash::login(){
    cout << "=== �w��ϥ�eCash ===" << endl;
    string acc;
    cout << "eCash: �п�J�z���b��:";
    cin >> acc;
    account = acc;

    acc = acc + ".acc";
    fstream accf;
    accf.open(acc.c_str(), ios::in);
    if(accf) {
        long long temp = 0;
        string s, cac;

        while(accf>>cac) {
            s += cac;
        }
        for (int i = 0; i < s.length(); i++) {
            temp = temp * 10 + s[i] - 48;
        }
        money = temp;
        accf.close();
        cout << "eCash: �b���}�ҧ���!";
    } else {
        money = 0;
        cout << "eCash: �b�����s�b, �Ĥ@���ϥ�!";
    }
    cout << endl << endl;
}
// Second, accumulate how much money we own and after that it will make sure your account is complete or not.
void eCash::logout() {
    string accf =  account + ".acc";
    fstream f;
    f.open(accf.c_str(), ios::trunc | ios::out);
    if (f) {
        f << long_long_to_string(money);
        f.close();
        cout << "eCash: �b���n�X�A�w�s��!\n���¡AByeBye!\n";
    } else {
        cout << "eCash: �X�{���~�A�s�ɥ���\n";
    }

}
// Third, yhe system will exhibit the next pocess you need to preserve and count your money after the count of the system.
void eCash::userInterface() {
    cout << account << "�z�n�A�п�ܶ���:\ns: �x��\np: ���O\nd: �d�߾l�B\nq: ���}\n";
}

void eCash::store() {
    cout << "�п�J�x�s���B:\n";
    long long num;
    cin >> num;
    if (num < 0) {
        cout << "eCash: �п�J�j��0�����B" << endl;
    } else {
        money += num;
        cout << "eCash: �z�s�F" << num << "��" << endl;
    }
}
// Forth, the code will show us how much money and what can we do next.
void eCash::pay() {
    cout << "�п�J���O���B:\n";
    long long num;
    cin >> num;
    if (num < 0) {
        cout << "eCash: �п�J�j��0�����B" << endl;
    } else if (num > money) {
        cout << "eCash: �z��������" << endl;
    } else {
        money -= num;
        cout << "eCash: �z��F" << num << "��" << endl;
    }
}
// Last but not least, ecash account shows how money you left and this is the end of this program.
void eCash::display() {
    cout << "eCash: �z�|��" << money << "��\n";
}

int main() {
    eCash usr;
    usr.login();

    bool Work = true;
    while(Work) {
        usr.userInterface();
        string s;
        cin >> s;

        switch (s[0]) {
        case 's':
            usr.store();
            break;
        case 'p':
            usr.pay();
            break;
        case 'd':
            usr.display();
            break;
        case 'q':
            usr.logout();
            Work = false;
        }
        system("pause");
        system("cls");
    }

    return 0;
}
