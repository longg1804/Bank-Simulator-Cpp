#include <bits/stdc++.h>
#include "bank.h"
#include <windows.h>
#include <conio.h>
using namespace std;

//=====================KHAI BAO========================

int ec, x, point, lang = 1;
char choose;
string theme = "dark";
vector<Account> accounts;

//=====================TIEN ICH========================

void delay(int ms) {Sleep(ms);}
void cls() {system("cls");}
void pause_anykey() {
    if (lang == 1)
        cout << "Nhan phim bat ki de quay tro lai...";
    else cout << "Press any key to return...";
    _getch();
}
void luachonsai() {
    cls();
    if (lang == 1)
        cout << "Lua chon khong hop le, vui long chon lai!";
    else cout << "Invalid choice, please select again!";
    delay(1000);
}
string chuanhoa(string s) {
    while (s[0] == ' ') s.erase(0, 1);
    while (s[s.size() - 1] == ' ') s.erase(s.size() - 1, 1);
    while (s.find("  ") != string::npos) s.erase(s.find("  "), 1);
    s[0] = toupper(s[0]);
    for (int i = 1; i < s.size(); ++i) s[i] = tolower(s[i]);
    for (int i = 1; i < s.size(); ++i)
        if (s[i - 1] == ' ') s[i] = toupper(s[i]);
    return s;
}
string realtime() {
    auto now = chrono::system_clock::now();
    time_t t = chrono::system_clock::to_time_t(now);
    tm localtime;
    localtime_s(&localtime, &t);
    char c[100];
    strftime(c, sizeof(c), "%H:%M:%S %d/%m/%Y", &localtime);
    return string(c);
}
void changefile() {
    ofstream out("accounts_data.txt");
    for (int i = 0; i < accounts.size(); ++i)
        out << accounts[i].TenDangNhap << '|' << accounts[i].MatKhau << '|' << accounts[i].Ten << '|' << accounts[i].SoTaiKhoan << '|' << accounts[i].SoDu << '|' << "\n";
    out.close();
}
string magiaodich() {
    string res;
    res.reserve(15);
    for (int i = 0; i < 15; i++) {
        res.push_back('0' + rand() % 10);
    }
    return res;
}
void setcolor(int text, int background = 0) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, (background << 4) | text);
}
void header() {
    cls();
    cout << "====================================\n";
    cout << "          NHLongg Bank  \n";
    cout << "====================================\n";
}
//======================TINH NANG=======================

void doigiaodien() {
    int a, b;
    if (theme == "dark") {
        a = 0;
        b = 15;
    }
    else {
        a = 15;
        b = 0;
    }
    header();
    int k;
    t:
    if (lang == 1) {
        cout << "Doi giao dien (Nhan 0 de quay lai): \n";
        cout << "   1. Giao dien sang\n";
        cout << "   2. Giao dien toi\n";
        cout << "   3. Giao dien tuy chinh\n";
        cout << "Nhap lua chon: ";
    }
    else {
        cout << "Change theme (Press 0 to return): \n";
        cout << "   1. Light Theme\n";
        cout << "   2. Dark Theme\n";
        cout << "   3. Custom Theme\n";
        cout << "Please select: ";
    }
    cin >> k;
    if ((k < 0) && (k > 3)) {
        luachonsai();
        delay(1000);
        doigiaodien();
    }
    else
    if (k == 0) {
        return;
    }
    else
    if (k == 1) {
        a = 0;
        b = 15;
        setcolor(a, b);
        header();
        if (lang == 1)
            cout << "Doi giao dien thanh cong!\n";
        else cout << "Theme changed successfully!\n";
        return;
    }
    else
    if (k == 2) {
        a = 15;
        b = 0;
        setcolor(a, b);
        header();
        if (lang == 1)
            cout << "Doi giao dien thanh cong!\n";
        else cout << "Theme changed successfully!\n";
        return;
    }
    else
    if (k == 3) {
        p:
        header();
        if (lang == 1) {
            cout << "Tuy chinh giao dien (Nhap 0 de quay tro lai):\n";
            cout << "   1. Den\n";
            cout << "   2. Xanh duong\n";
            cout << "   3. Xanh la\n";
            cout << "   4. Xanh ngoc\n";
            cout << "   5. Do\n";
            cout << "   6. Tim\n";
            cout << "   7. Vang\n";
            cout << "   8. Xam nhat\n";
            cout << "   9. Xam\n";
            cout << "   10. Xanh duong sang\n";
            cout << "   11. Xanh la sang\n";
            cout << "   12. Xanh ngoc sang\n";
            cout << "   13. Do sang\n";
            cout << "   14. Tim sang\n";
            cout << "   15. Vang sang\n";
            cout << "   16. Trang\n";
            cout << "Chon mau chu (1 - 16): ";
        }
        else {
            cout << "Theme customization (Press 0 to return):\n";
            cout << "   1. Black\n";
            cout << "   2. Blue\n";
            cout << "   3. Green\n";
            cout << "   4. Cyan\n";
            cout << "   5. Red\n";
            cout << "   6. Purple\n";
            cout << "   7. Yellow\n";
            cout << "   8. Light Gray\n";
            cout << "   9. Gray\n";
            cout << "   10. Light Blue\n";
            cout << "   11. Light Green\n";
            cout << "   12. Light Cyan\n";
            cout << "   13. Light Red\n";
            cout << "   14. Light Purple\n";
            cout << "   15. Light Yellow\n";
            cout << "   16. White\n";
            cout << "Choose text color: (1 - 16): ";
        }
        cin >> a;
        if (a == 0) {
            header();
            goto t;
        }
        if (a > 16) {
            luachonsai();
            goto p;
        }
        if (lang == 1)
            cout << "Chon mau nen (1 - 16): ";
        else cout << "Choose background color (1 - 16): ";
        cin >> b;
        if (b > 16) {
            luachonsai();
            goto p;
        }
        if (a == b) {
            if (lang == 1)
                cout << "Mau chu khong duoc trung voi mau nen!\n";
            else cout << "Text color cannot be the same as the background color!\n";
            pause_anykey();
            goto p;
        }
        setcolor(a - 1, b - 1);
        header();
        if (lang == 1)
            cout << "Doi giao dien thanh cong!\n";
        else cout << "Theme changed successfully!\n";
        return;
    }
}
void dangnhap() {
    string tendangnhap, matkhau;
    header();
    int dangnhapcheck = 0;
    if (lang == 1) {
        cout << "Dien ten dang nhap va mat khau: \n";
        cout << "   Ten dang nhap: ";
        cin >> tendangnhap;
        cout << "   Mat khau: ";
        cin >> matkhau;
    }
    else {
        cout << "Enter username and password: \n";
        cout << "   Username: ";
        cin >> tendangnhap;
        cout << "   Password: ";
        cin >> matkhau;
    }
    for (int i = 0; i < accounts.size(); ++i)
        if ((accounts[i].TenDangNhap == tendangnhap) && (accounts[i].MatKhau == matkhau)) {
            dangnhapcheck = 1;
            x = i;
            break;
        }
    if (dangnhapcheck) {
        if (lang == 1)
            cout << "Dang nhap thanh cong, dang tro ve menu!\n";
        else cout << "Login successful, returning to menu!\n";
        delay(1000);
        ec = 1;
    }
    else {
        if (lang == 1)
            cout << "Thong tin khong hop le, vui long kiem tra lai!\n";
        else cout << "Invalid information, please check again!\n";
        delay(1000);
        dangnhap();
    }
}
void dangky() {
    header();
    string tendangnhap, matkhau, sotaikhoan, hoten;
    ofstream out("accounts_data.txt", ios::app);
    if (lang == 1) {
        cout << "Ban dang thuc hien dang ky tai khoan, vui long nhap tai khoan va mat khau: " << endl;
        cout << "   Ten dang nhap: ";
    }
    else {
        cout << "You are registering an account, please enter username and password:\n";
        cout << "   Username: ";
    }
    cin >> tendangnhap;
    bool kt = true;
    for (int i = 0; i < accounts.size(); ++i)
        if (tendangnhap == accounts[i].TenDangNhap) {
            kt = false;
            break;
        }
    if (!kt) {
        if (lang == 1)
            cout << "Ten dang nhap da ton tai, vui long thu lai!" << endl;
        else cout << "Username already exists, please try again!" << endl;
        delay(1000);
        dangky();
    }
    if (lang == 1) {
        cout << "   Mat khau: ";
        cin >> matkhau;
        cout << "   Ho va ten: ";
        cin.ignore();
        getline(cin, hoten);
        hoten = chuanhoa(hoten);
        cout << "   So tai khoan: ";
        cin >> sotaikhoan;
    }
    else {
        cout << "   Password: ";
        cin >> matkhau;
        cout << "   Fullname: ";
        cin.ignore();
        getline(cin, hoten);
        hoten = chuanhoa(hoten);
        cout << "   Account number: ";
        cin >> sotaikhoan;
    }
    for (int i = 0; i < accounts.size(); ++i)
        if (sotaikhoan == accounts[i].SoTaiKhoan) {
            kt = false;
            break;
        }
    if (!kt) {
        if (lang == 1)
            cout << "So tai khoan da ton tai, vui long thu lai!" << endl;
        else cout << "Account number already exists, please try again!" << endl;
        delay(1000);
        dangky();
    }
    if (kt) {
        string s = "";
        Account newacc;
        newacc.TenDangNhap = tendangnhap;
        newacc.MatKhau = matkhau;
        newacc.Ten = hoten;
        newacc.SoTaiKhoan = sotaikhoan;
        newacc.SoDu = 0;
        s = s + tendangnhap + '|' + matkhau + '|' + hoten + '|' + sotaikhoan + "|0|";
        accounts.push_back(newacc);
        out << s << "\n";
        out.close();
        x = accounts.size() - 1;
        if (lang == 1)
            cout << "Dang ky tai khoan thanh cong, dang dang nhap!";
        else cout << "Account registration successful, logging in!";
        delay(1000);
        ec = 1;
    }
}
void dangnhapdangky() {
    header();
    if (lang == 1) {
        cout << "Vui long chon:\n";
        cout << "   1. Dang nhap\n";
        cout << "   2. Dang ky\n";
        cout << "   3. Change language (Vietnamese - English)\n";
        cout << "   4. Doi giao dien\n";
        cout << "   0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> choose;
    }
    else {
        cout << "Please select:\n";
        cout << "   1. Login\n";
        cout << "   2. Register\n";
        cout << "   3. Doi ngon ngu (Tieng Viet - Tieng Anh)\n";
        cout << "   4. Custom Theme\n";
        cout << "   0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choose;
    }
    if (choose == '0') {
        if (lang == 1)
            cout << "Xin chao va hen gap lai quy khach!\n\n";
        else cout << "Thank you and see you again!\n\n";
        ec = -1;
        exit(0);
    }
    else
    if (choose == '1') {
        dangnhap();
    }
    else
    if (choose == '2') {
        cls();
        dangky();
    }
    else
    if (choose == '3') {
        if (lang == 1) lang = 2;
        else lang = 1;
        dangnhapdangky();
    }
    else
    if (choose == '4') {
        doigiaodien();
        pause_anykey();
        dangnhapdangky();
    }
    else {
        luachonsai();
        dangnhapdangky();
    }
}
void tracuu() {
    header();
    if (lang == 1) {
        cout << "Ho ten      : " << accounts[x].Ten << endl;
        cout << "So tai khoan: " << accounts[x].SoTaiKhoan << endl;
        cout << "So du       : " << accounts[x].SoDu << "VND" << endl;
    }
    else {
        cout << "Fullname      : " << accounts[x].Ten << endl;
        cout << "Account number: " << accounts[x].SoTaiKhoan << endl;
        cout << "Balance       : " << accounts[x].SoDu << "VND" << endl;
    }
    pause_anykey();
    return;
}
void inhoadon(string s, int point, long long tien, string mgd) {
    ofstream out("transaction_details.txt");
    out << "===================NHLongg Bank===================\n";
    if (lang == 1)
        out << "Cam on ban da su dung dich vu, chi tiet giao dich:\n";
    else out << "Thank you for using our service, transaction details:\n";
    out << endl;
    if (s == "naptien") {
        if (lang == 1) {
            out << "Thoi gian giao dich:   " << realtime() << endl;
            out << "Ma giao dich       :   " << mgd << endl;
            out << "Loai giao dich     :   Nap tien truc tuyen" << endl;
            out << "Tai khoan thuc hien:   " << accounts[x].Ten << " - " << accounts[x].SoTaiKhoan << endl;
            out << "So tien giao dich  :   " << tien << endl;
            out << "Tinh trang         :   Giao dich thanh cong \n";
        }
        else {
            out << "Transaction time  :   " << realtime() << endl;
            out << "Transaction ID    :   " << mgd << endl;
            out << "Transaction type  :   Online deposit" << endl;
            out << "From account      :   " << accounts[x].Ten << " - " << accounts[x].SoTaiKhoan << endl;
            out << "Transaction amount:   " << tien << endl;
            out << "Status            :   Transaction successful \n";
        }
    }
    else
    if (s == "ruttien") {
        if (lang == 1) {
            out << "Thoi gian giao dich:   " << realtime() << endl;
            out << "Ma giao dich       :   " << mgd << endl;
            out << "Loai giao dich     :   Rut tien truc tuyen" << endl;
            out << "Tai khoan thuc hien:   " << accounts[x].Ten << " - " << accounts[x].SoTaiKhoan << endl;
            out << "So tien giao dich  :   " << tien << endl;
            out << "Tinh trang         :   Giao dich thanh cong \n";
        }
        else {
            out << "Transaction time  :   " << realtime() << endl;
            out << "Transaction ID    :   " << mgd << endl;
            out << "Transaction type  :   Online withdrawal" << endl;
            out << "From account      :   " << accounts[x].Ten << " - " << accounts[x].SoTaiKhoan << endl;
            out << "Transaction amount:   " << tien << endl;
            out << "Status            :   Transaction successful \n";
        }
    }
    if (s == "chuyentien") {
        if (lang == 1) {
            out << "Thoi gian giao dich:   " << realtime() << endl;
            out << "Ma giao dich       :   " << mgd << endl;
            out << "Loai giao dich     :   Chuyen tien truc tuyen" << endl;
            out << "Tai khoan thuc hien:   " << accounts[x].Ten << " - " << accounts[x].SoTaiKhoan << endl;
            out << "Tai khoan thu huong:   " << accounts[point].Ten << " - " << accounts[point].SoTaiKhoan << endl;
            out << "So tien giao dich  :   " << tien << endl;
            out << "Tinh trang         :   Giao dich thanh cong \n";
        }
        else {
            out << "Transaction time  :   " << realtime() << endl;
            out << "Transaction ID    :   " << mgd << endl;
            out << "Transaction type  :   Online transfer" << endl;
            out << "From account      :   " << accounts[x].Ten << " - " << accounts[x].SoTaiKhoan << endl;
            out << "Receiving account :   " << accounts[point].Ten << " - " << accounts[point].SoTaiKhoan << endl;
            out << "Transaction amount:   " << tien << endl;
            out << "Status            :   Transaction successful \n";
        }
    }
    out << "==================================================\n";
    if (lang == 1)
        out << "Xin chan thanh cam on!";
    else out << "Sincerely thank you!";
    out.close();
}
void biendong(int point, string mgd, string type, long long tien) {
    ofstream out(accounts[x].Ten + "_Balance_Fluctuations.txt", ios::app);
    out << realtime() << "|" << mgd << "|";
    if (type == "naptien") {
        if (lang == 1)
            out << "Nap tien      |+" << tien << " VND";
        else out << "Deposit       |+" << tien << " VND";
        string c = to_string(tien);
        for (int i = 17; i >= c.size() + 5; --i) out << " ";
        out << "|     NHLongg Bank     |SUCCESS       |" << accounts[x].SoDu << " VND";
        c = to_string(accounts[x].SoDu);
        for (int i = 17; i >= c.size() + 4; --i) out << " ";
        out << "|";
    }
    else
    if (type == "ruttien") {
        if (lang == 1)
            out << "Rut tien      |-" << tien << " VND";
        else out << "Withdrawal    |-" << tien << " VND";
        string c = to_string(tien);
        for (int i = 17; i >= c.size() + 5; --i) out << " ";
        out << "|     NHLongg Bank     |SUCCESS       |" << accounts[x].SoDu << " VND";
        c = to_string(accounts[x].SoDu);
        for (int i = 17; i >= c.size() + 4; --i) out << " ";
        out << "|";
    }
    else
    if (type == "chuyentien") {
        if (lang == 1)
            out << "Chuyen tien   |-" << tien << " VND";
        else out << "Transfer      |-" << tien << " VND";
        string c = to_string(tien);
        for (int i = 17; i >= c.size() + 5; --i) out << " ";
        out << "|" << accounts[point].Ten;
        for (int i = 21; i >= accounts[point].Ten.size(); --i) out << " ";
        out << "|SUCCESS       |" << accounts[x].SoDu << " VND";
        c = to_string(accounts[x].SoDu);
        for (int i = 17; i >= c.size() + 4; --i) out << " ";
        out << "|";
    }
    out << "\n";
    out.close();
}
void biendongnhantien(int point, string mgd, long long tien, int x) {
    ofstream out(accounts[point].Ten + "_Balance_Fluctuations.txt", ios::app);
    out << realtime() << "|" << mgd << "|";
    if (lang == 1)
        out << "Nhan tien     |+" << tien << " VND";
    else out << "Incoming      |+" << tien << " VND";
    string c = to_string(tien);
    for (int i = 17; i >= c.size() + 5; --i) out << " ";
    out << "|" << accounts[x].Ten;
    for (int i = 21; i >= accounts[x].Ten.size(); --i) out << " ";
    out << "|SUCCESS       |" << accounts[point].SoDu << " VND";
    c = to_string(accounts[point].SoDu);
    for (int i = 17; i >= c.size() + 4; --i) out << " ";
    out << "|";
    out << "\n";
    out.close();
}
void naptien() {
    header();
    long long tien;
    string mgd = magiaodich();
    if (lang == 1)
        cout << "Nhap so tien muon nap (Nhap 0 de quay tro lai): ";
    else cout << "Enter the amount you want to deposit (Enter 0 to return): ";
    cin >> tien;
    if (tien == 0) return;
    else
    if (tien < 1000) {
        if (lang == 1)
            cout << "So tien phai lon hon 1000!\n";
        else cout << "The amount must be greater than 1000!\n";
        delay(1000);
        naptien();
    }
    else {
        accounts[x].SoDu += tien;
        changefile();
        cls();
        if (lang == 1) {
            cout << "Nap tien thanh cong!" << endl;
            cout << "Ma giao dich: " << mgd << endl;
            cout << "So tien da nap: " << tien << "VND" << endl;
            cout << "So du hien tai: " << accounts[x].SoDu << "VND" << endl;
            cout << "Chi tiet giao dich da duoc tao thanh cong!" << endl;
        }
        else {
            cout << "Deposit successful!" << endl;
            cout << "Transaction ID: " << mgd << endl;
            cout << "Deposited amount: " << tien << "VND" << endl;
            cout << "Current balance: " << accounts[x].SoDu << "VND" << endl;
            cout << "Transaction details have been successfully created!" << endl;
        }
        inhoadon("naptien", 0, tien, mgd);
        biendong(0, mgd, "naptien", tien);
        pause_anykey();
        return;
    }
}
void ruttien() {
    header();
    long long tien;
    string mgd = magiaodich();
    if (lang == 1)
        cout << "Nhap so tien muon rut (Nhap 0 de quay tro lai): ";
    else cout << "Enter the amount you want to withdraw (Enter 0 to return): ";
    cin >> tien;
    if (tien == 0) return;
    else
    if (tien < 1000) {
        if (lang == 1)
            cout << "So tien phai lon hon 1000!\n";
        else cout << "The amount must be greater than 1000!\n";
        delay(1000);
        ruttien();
    }
    else
    if (tien > accounts[x].SoDu) {
        if (lang == 1)
            cout << "So du khong du, vui long nhap lai!" << endl;
        else cout << "Insufficient balance, please re-enter!" << endl;
        delay(1000);
        ruttien();
    }
    else {
        accounts[x].SoDu -= tien;
        changefile();
        cls();
        if (lang == 1) {
            cout << "Rut tien thanh cong!" << endl;
            cout << "Ma giao dich: " << mgd << endl;
            cout << "So du hien tai: " << accounts[x].SoDu << endl;
            cout << "Chi tiet giao dich da duoc tao thanh cong!" << endl;
        }
        else {
            cout << "Withdraw successful!" << endl;
            cout << "Transaction ID: " << mgd << endl;
            cout << "Current balance: " << accounts[x].SoDu << endl;
            cout << "Transaction details have been successfully created!" << endl;
        }
        inhoadon("ruttien", 0, tien, mgd);
        biendong(0, mgd, "ruttien", tien);
        pause_anykey();
        return;
    }
}
void chuyen(int point) {
    long long tien;
    header();
    string mgd = magiaodich();
    if (lang == 1) {
        cout << "Ten nguoi nhan: " << accounts[point].Ten << endl;
        cout << "Nhap so tien muon chuyen (Nhan 0 de quay tro ve menu): ";
    }
    else {
        cout << "Recipient name: " << accounts[point].Ten << endl;
        cout << "Enter the amount you want to transfer (Enter 0 to return to menu): ";
    }
    cin >> tien;
    if (tien == 0) return;
    else
    if (tien < 1000) {
        if (lang == 1)
            cout << "So tien da nhap phai lon hon 1000!";
        else cout << "The entered amount must be greater than 1000!";
        delay(1000);
        chuyen(-1);
    }
    else
    if (tien > accounts[x].SoDu) {
        if (lang == 1)
            cout << "So du khong du!";
        else cout << "Insufficient balance!";
        delay(1000);
        chuyen(-1);
    }
    else {
        accounts[x].SoDu -= tien;
        accounts[point].SoDu += tien;
        changefile();
        cls();
        if (lang == 1) {
            cout << "Giao dich thanh cong!\n";
            cout << "Da chuyen thanh cong " << tien << "VND toi " << accounts[point].Ten << endl;
            cout << "Ma giao dich: " << mgd << endl;
            cout << "So du con lai: " << accounts[x].SoDu << endl;
            cout << "Chi tiet giao dich da duoc tao thanh cong!" << endl;
        }
        else {
            cout << "Transaction successful!\n";
            cout << "Successfully transferred " << tien << "VND to " << accounts[point].Ten << endl;
            cout << "Transaction ID: " << mgd << endl;
            cout << "Remaining balance: " << accounts[x].SoDu << endl;
            cout << "Transaction details have been successfully created!" << endl;
        }
        inhoadon("chuyentien", point, tien, mgd);
        biendong(point, mgd, "chuyentien", tien);
        biendongnhantien(point, mgd, tien, x);
        pause_anykey();
        return;
    }
}
void chuyentien() {
    string sotaikhoan;
    header();
    if (lang == 1) {
        cout << "Ban dang thuc hien chuyen tien (nhan 0 de quay lai): \n";
        cout << "Nhap so tai khoan nguoi nhan: ";
    }
    else {
        cout << "You are making a transfer (press 0 to return): \n";
        cout << "Enter the recipient's account number: ";
    }
    cin >> sotaikhoan;
    if (sotaikhoan == "0") return;
    int point = -1;
    for (int i = 0; i < accounts.size(); ++i)
        if (sotaikhoan == accounts[i].SoTaiKhoan) {
            point = i;
            break;
        }
    if (point == -1) {
        if (lang == 1)
            cout << "So tai khoan khong dung hoac khong ton tai, vui long nhap lai!\n";
        else cout << "Invalid or non-existent account number, please re-enter!\n";
        pause_anykey();
        chuyentien();
    }
    else
    if (point == x) {
        if (lang == 1)
            cout << "Khong the chuyen cho chinh minh, vui long nhap lai!\n";
        else cout << "Cannot transfer to yourself, please re-enter!\n";
        pause_anykey();
        chuyentien();
    }
    else chuyen(point);
}
void doimatkhau() {
    char k;
    string a, b, c;
    header();
    if (lang == 1)
        cout << "Dang tien hanh doi mat khau (Nhan 1 de tiep tuc, 0 de quay lai): ";
    else cout << "Processing password change (Press 1 to    continue, 0 to go back): ";
    cin >> k;
    if (k == '0') return;
    else
    if (k == '1') {
        p:
        cls();
        if (lang == 1)
            cout << "Nhap mat khau cu: ";
        else cout << "Enter current password: ";
        cin >> a;
        if (a != accounts[x].MatKhau) {
            if (lang == 1)
                cout << "Mat khau da nhap khong dung, vui long thu lai!";
            else cout << "The password entered is incorrect, please try again!";
            delay(1000);
            goto p;
        }
        pp:
        cls();
        if (lang == 1) {
            cout << "Nhap mat khau moi: ";
            cin >> b;
            cout << "Nhap lai mat khau moi: ";
            cin >> c;
        }
        else {
            cout << "Enter new password: ";
            cin >> b;
            cout << "Re-enter new password: ";
            cin >> c;
        }
        if (c != b) {
            if (lang == 1)
                cout << "Mat khau da nhap khong trung khop, vui long thu lai!";
            else cout << "The passwords entered do not match, please try again!";
            delay(1000);
            goto pp;
        }
        else {
            accounts[x].MatKhau = c;
            changefile();
            if (lang == 1)
                cout << "Thay doi mat khau thanh cong!";
            else cout << "Password changed successfully!";
            pause_anykey();
        }
    }
    else {
        luachonsai();
        doimatkhau();
    }
}
void biendongsodu() {
    header();
    ifstream file(accounts[x].Ten + "_Balance_Fluctuations.txt");
    if (lang == 1)
        cout << "     Thoi Gian	   |     Ma GD     |     Loai     |     So tien      |       Doi tac        |  Trang thai  |     So du sau    |\n";
    else cout << "       Time        |Transaction ID |     Type     |      Amount      |        Partner       |    Status    |   Balance After  |\n";
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
    pause_anykey();
}
void menu() {
    while (true) {
        header();
        if (lang == 1) {
            cout << "Xin chao " << accounts[x].Ten << "! Vui long chon: \n";
            cout << "   1. Tra cuu\n";
            cout << "   2. Nap tien\n";
            cout << "   3. Rut tien\n";
            cout << "   4. Chuyen tien noi bo\n";
            cout << "   5. Doi mat khau\n";
            cout << "   6. Bien dong so du\n";
            cout << "   7. Change language (Vietnamese - English)\n";
            cout << "   8. Doi giao dien\n";
            cout << "   0. Dang xuat\n";
            cout << "Vui long chon: ";
        }
        else {
            cout << "Hi " << accounts[x].Ten << "! Please select: \n";
            cout << "   1. Inquiry\n";
            cout << "   2. Deposit\n";
            cout << "   3. Withdraw\n";
            cout << "   4. Internal transfer\n";
            cout << "   5. Change password\n";
            cout << "   6. Balance fluctuations\n";
            cout << "   7. Doi ngon ngu (Tieng Viet - Tieng Anh)\n";
            cout << "   8. Change theme\n";
            cout << "   0. Log out\n";
            cout << "Please select: ";
        }
        cin >> choose;
        if (choose == '0') {
            if (lang == 1)
                cout << "Dang xuat thanh cong, vui long cho...";
            else cout << "Logout successful, please wait...";
            delay(1000);
            dangnhapdangky();
            if (choose == -1) return;
        }
        else
        if (choose == '1') {
            tracuu();
        }
        else
        if (choose == '2') {
            naptien();
        }
        else
        if (choose == '3') {
            ruttien();
        }
        else
        if (choose == '4') {
            chuyentien();
        }
        else
        if (choose == '5') {
            doimatkhau();
        }
        else
        if (choose == '6') {
            biendongsodu();
        }
        else
        if (choose == '7') {
            if (lang == 1) lang = 2;
            else lang = 1;
            menu();
        }
        else
        if (choose == '8') {
            doigiaodien();
            menu();
        }
        else {
            luachonsai();
            menu();
        }
    }
}

//===================CHUONG TRINH=====================

int main() {
    ifstream file("accounts_data.txt");
    srand(time(0));
    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        string c;
        stringstream s(line);
        vector<string> TaiKhoan;
        while (getline(s, c, '|'))
            if (!c.empty()) TaiKhoan.push_back(c);
        if (TaiKhoan.size() == 5) {
            Account acc;
            acc.TenDangNhap = TaiKhoan[0];
            acc.MatKhau = TaiKhoan[1];
            acc.Ten = TaiKhoan[2];
            acc.SoTaiKhoan = TaiKhoan[3];
            acc.SoDu = stoll(TaiKhoan[4]);
            accounts.push_back(acc);
        }
    }
    dangnhapdangky();
    if (ec == 1) {
        menu();
    }
    else exit(0);
    file.close();
}
