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
    cout << "=== 歡迎使用eCash ===" << endl;
    string acc;
    cout << "eCash: 請輸入您的帳號:";
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
        cout << "eCash: 帳號開啟完成!";
    } else {
        money = 0;
        cout << "eCash: 帳號不存在, 第一次使用!";
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
        cout << "eCash: 帳號登出，已存檔!\n謝謝，ByeBye!\n";
    } else {
        cout << "eCash: 出現錯誤，存檔失敗\n";
    }

}
// Third, yhe system will exhibit the next pocess you need to preserve and count your money after the count of the system.
void eCash::userInterface() {
    cout << account << "您好，請選擇項目:\ns: 儲值\np: 消費\nd: 查詢餘額\nq: 離開\n";
}

void eCash::store() {
    cout << "請輸入儲存金額:\n";
    long long num;
    cin >> num;
    if (num < 0) {
        cout << "eCash: 請輸入大於0的金額" << endl;
    } else {
        money += num;
        cout << "eCash: 您存了" << num << "元" << endl;
    }
}
// Forth, the code will show us how much money and what can we do next.
void eCash::pay() {
    cout << "請輸入消費金額:\n";
    long long num;
    cin >> num;
    if (num < 0) {
        cout << "eCash: 請輸入大於0的金額" << endl;
    } else if (num > money) {
        cout << "eCash: 您的錢不夠" << endl;
    } else {
        money -= num;
        cout << "eCash: 您花了" << num << "元" << endl;
    }
}
// Last but not least, ecash account shows how money you left and this is the end of this program.
void eCash::display() {
    cout << "eCash: 您尚有" << money << "元\n";
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
