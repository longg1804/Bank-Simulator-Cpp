#include <bits/stdc++.h>
#include "bank.h"
#include <windows.h>
#include <conio.h>
//#include <filesystem>
//#include <chrono>
//#include <ctime>
//#include <iomanip>
using namespace std;

//=====================================================

int choose, ec, x;
vector<Account> accounts;

//=====================================================

void delay(int ms) {Sleep(ms);}
void cls() {system("cls");}
void pause_anykey() {
    cout << "Nhan phim bat ki de quay tro lai...";
    _getch();
}
void luachonsai() {
    cls();
    cout << "Lua chon khong hop le, vui long chon lai!";
    delay(2000);
}
//=====================================================

//void inbill(const string &noidung, const string &foldername = "bills") {
//    if (!fs::exists(foldername)) fs::create_directory(foldername);
//    int maxnum = 0;
//    for (auto &i : fs::directory_iterator(foldername)) {
//        string name = i.path().filename().string();
//        if ((name.rfind("bill_", 0) == 0) && (name.size() > 9) && (name.substr(name.size() - 4) == ".txt"))
//            try {
//                int num = stoi(name.substr(5, name.size() - 9));
//                maxnum = max(maxnum, num);
//            } catch(...)
//    }
//    ++maxnum;
//    string filename = foldername + "/bill_" + to_string(maxnum) + ".txt";
//    ofstream out(filename);
//    out << "===== HOA DON NHLongg Bank =====\n";
//    out << "-------------------------------\n";
//    out << noidung << endl;
//    out << "-------------------------------\n";
//    out << "Cam on ban da su dung dich vu!";
//    out.close();
//    cout << "Tao hoa don thanh cong!";
//}
void dangnhap() {
    string tendangnhap, matkhau;
    cls();
    int dangnhapcheck = 0;
    cout << "Dien ten dang nhap va mat khau: \n";
    cout << "   Ten dang nhap: ";
    cin >> tendangnhap;
    cout << "   Mat khau: ";
    cin >> matkhau;
    for (int i = 0; i < accounts.size(); ++i)
        if ((accounts[i].TenDangNhap == tendangnhap) && (accounts[i].MatKhau == matkhau)) {
            dangnhapcheck = 1;
            x = i;
            break;
        }
    if (dangnhapcheck) {
        cout << "Dang nhap thanh cong, dang tro ve menu!\n";
        delay(2000);
        ec = 1;
    }
    else {
        cout << "Thong tin khong hop le, vui long kiem tra lai!\n";
        delay(2000);
        dangnhap();
    }
}
void dangnhapdangky() {
    cls();
    cout << "NHLongg Bank\n";
    cout << "Vui long chon:\n";
    cout << "   1. Dang nhap\n";
    cout << "   2. Dang ky\n";
    cout << "   0. Thoat\n";
    cout << "Nhap lua chon: ";
    cin >> choose;
    if (choose == 0) {
        cout << "Xin chao va hen gap lai quy khach!";
        delay(2000);
        choose = -1;
        return;
    }
    else
    if (choose == 1) {
        dangnhap();
    }
    else
    if (choose == 2) {
        cls();
        cout << "Dien ten dang nhap va mat khau: ";
    }
    else {
        luachonsai();
        dangnhapdangky();
    }
}
void tracuu() {
    cls();
    cout << "NHLongg Bank\n";
    cout << "Ho ten:       " << accounts[x].Ten << endl;
    cout << "So tai khoan: " << accounts[x].SoTaiKhoan << endl;
    cout << "So du:        " << accounts[x].SoDu << "VND" << endl;
    pause_anykey();
    return;
}
void naptien() {
    cls();
    long long tien;
    cout << "Nhap so tien muon nap (Nhap 0 de quay tro lai): ";
    cin >> tien;
    if (tien == 0) return;
    else
    if (tien % 1000 != 0) {
        cout << "So tien phai la boi so cua 1000!\n";
        delay(2000);
        naptien();
    }
    else {
        accounts[x].SoDu += tien;
        cout << "Nap tien thanh cong!" << endl;
        cout << "So tien da nap: " << tien << "VND" << endl;
        cout << "So du hien tai: " << accounts[x].SoDu << "VND" << endl;
        cout << "Nhan phim bat ki de quay tro lai...";
        _getch();
        return;
    }
}
void ruttien() {
    cls();
    long long tien;
    cout << "Nhap so tien muon rut (Nhap 0 de quay tro lai): ";
    cin >> tien;
    if (tien == 0) return;
    else
    if (tien % 1000 != 0) {
        cout << "So tien phai la boi so cua 1000!\n";
        delay(2000);
        ruttien();
    }
    else
    if (tien > accounts[x].SoDu) {
        cout << "So du khong du, vui long nhap lai!" << endl;
        delay(2000);
    }
    else {
        accounts[x].SoDu -= tien;
        cout << "Rut tien thanh cong!" << endl;
        cout << "So du hien tai: " << accounts[x].SoDu << endl;
        cout << "Nhan phim bat ki de quay tro lai...";
        _getch();
        return;
    }
}
void menu() {
    while (true) {
        cls();
        cout << "Xin chao " << accounts[x].Ten << "! Vui long chon: \n";
        cout << "   1. Tra cuu\n";
        cout << "   2. Nap tien\n";
        cout << "   3. Rut tien\n";
        cout << "   0. Dang xuat\n";
        cout << "Vui long chon: ";
        cin >> choose;
        if ((choose < 0) || (choose > 3)) {
            luachonsai();
            menu();
        }
        else
        if (choose == 0) {
            cout << "Dang xuat thanh cong, vui long cho...";
            delay(2000);
            dangnhapdangky();
            if (choose == -1) return;
        }
        else
        if (choose == 1) {
            tracuu();
        }
        else
        if (choose == 2) {
            naptien();
        }
        else
        if (choose == 3) {
            ruttien();
        }
    }
}
int main() {
    ifstream file("accountdata.txt");
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
    file.close();
}
