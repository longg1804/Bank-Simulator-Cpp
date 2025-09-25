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
        cout << "Nhấn Phím Bất Kì Để Quay Lại...";
    else cout << "Press Any Key To Return...";
    _getch();
}
void luachonsai() {
    cls();
    if (lang == 1)
        cout << "Lựa Chọn Không Hợp Lệ, Vui Lòng Chọn Lại!";
    else cout << "Invalid Choice, Please Select Again!";
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
    cout << "            NHLongg Bank\n";
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
        cout << "Đổi Giao Diện : \n\n";
        cout << "   1. Giao Diện Sáng\n";
        cout << "   2. Giao Diện Tối\n";
        cout << "   3. Giao Diện Tùy Chỉnh\n";
        cout << "   0. Quay Lại\n\n";
        cout << "------------------------------------\n";
        cout << "Nhập Lựa Chọn: ";
    }
    else {
        cout << "Change Theme (Press 0 To Return): \n";
        cout << "   1. Light Theme\n";
        cout << "   2. Dark Theme\n";
        cout << "   3. Custom Theme\n";
        cout << "Please Select: ";
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
            cout << "Đổi Giao Diện Thành Công!\n";
        else cout << "Theme Changed Successfully!\n";
        return;
    }
    else
    if (k == 2) {
        a = 15;
        b = 0;
        setcolor(a, b);
        header();
        if (lang == 1)
            cout << "Đổi Giao Diện Thành Công!\n";
        else cout << "Theme Changed Successfully!\n";
        return;
    }
    else
    if (k == 3) {
        p:
        header();
        if (lang == 1) {
            cout << "Tùy Chỉnh Giao Diện:\n";
            cout << "   1. Đen\n";
            cout << "   2. Xanh Dương\n";
            cout << "   3. Xanh Lá\n";
            cout << "   4. Xanh Ngọc\n";
            cout << "   5. Đỏ\n";
            cout << "   6. Tím\n";
            cout << "   7. Vàng\n";
            cout << "   8. Xám Nhạt\n";
            cout << "   9. Xám\n";
            cout << "   10. Xanh Dương Sáng\n";
            cout << "   11. Xanh Lá Sáng\n";
            cout << "   12. Xanh Ngọc Sáng\n";
            cout << "   13. Đỏ Sáng\n";
            cout << "   14. Tím Sáng\n";
            cout << "   15. Vàng Sáng\n";
            cout << "   16. Trắng\n";
            cout << "   0. Quay Lại\n";
            cout << "Chọn Màu Chữ (1 - 16): ";
        }
        else {
            cout << "Theme Customization:\n";
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
            cout << "   0. Return\n";
            cout << "Choose Text Color: (1 - 16): ";
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
            cout << "Chọn Màu Nền (1 - 16): ";
        else cout << "Choose Background Color (1 - 16): ";
        cin >> b;
        if (b > 16) {
            luachonsai();
            goto p;
        }
        if (a == b) {
            if (lang == 1)
                cout << "Màu Chữ Không Được Trùng Với Màu Nền!\n";
            else cout << "Text Color Cannot Be The Same As The Background Color!\n";
            pause_anykey();
            goto p;
        }
        setcolor(a - 1, b - 1);
        header();
        if (lang == 1)
            cout << "Đổi Giao Diện Thành Công!\n";
        else cout << "Theme Changed Successfully!\n";
        return;
    }
}
void dangnhap() {
    string tendangnhap, matkhau;
    header();
    int dangnhapcheck = 0;
    if (lang == 1) {
        cout << "Điền Tên Đăng Nhập Và Mật Khẩu: \n";
        cout << "   Tên Đăng Nhập: ";
        cin >> tendangnhap;
        cout << "   Mật Khẩu: ";
        cin >> matkhau;
    }
    else {
        cout << "Enter User Name And Password: \n";
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
            cout << "Đăng Nhập Thành Công, Đang Trở Về Menu!\n";
        else cout << "Login Successful, Returning To Menu!\n";
        delay(1000);
        ec = 1;
    }
    else {
        if (lang == 1)
            cout << "Thông Tin Không Hợp Lệ, Vui Lòng Kiểm Tra Lại!\n";
        else cout << "Invalid Information, Please Check Again!\n";
        delay(1000);
        dangnhap();
    }
}
void dangky() {
    header();
    string tendangnhap, matkhau, sotaikhoan, hoten;
    ofstream out("accounts_data.txt", ios::app);
    if (lang == 1) {
        cout << "Bạn Đang Thực Hiện Đăng Ký Tài Khoản, Vui Lòng Nhập Tài Khoản Và Mật Khẩu: " << endl;
        cout << "   Tên Đăng Nhập: ";
    }
    else {
        cout << "You Are Registering An Account, Please Enter Username And Password:\n";
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
            cout << "Tên Đăng Nhập Đã Tồn Tại, Vui Lòng Thử Lại!" << endl;
        else cout << "Username Already Exists, Please Try Again!" << endl;
        delay(1000);
        dangky();
    }
    if (lang == 1) {
        cout << "   Mật Khẩu: ";
        cin >> matkhau;
        cout << "   Họ Và Tên: ";
        cin.ignore();
        getline(cin, hoten);
        hoten = chuanhoa(hoten);
        cout << "   Số Tài Khoản: ";
        cin >> sotaikhoan;
    }
    else {
        cout << "   Password: ";
        cin >> matkhau;
        cout << "   Fullname: ";
        cin.ignore();
        getline(cin, hoten);
        hoten = chuanhoa(hoten);
        cout << "   Account Number: ";
        cin >> sotaikhoan;
    }
    for (int i = 0; i < accounts.size(); ++i)
        if (sotaikhoan == accounts[i].SoTaiKhoan) {
            kt = false;
            break;
        }
    if (!kt) {
        if (lang == 1)
            cout << "Số Tài Khoản Đã Tồn Tại, Vui Lòng Thử Lại!" << endl;
        else cout << "Account Number Already Exists, Please Try Again!" << endl;
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
            cout << "Đăng Ký Tài Khoản Thành Công, Đang Đăng Nhập!";
        else cout << "Account Registration Successful, Logging In!";
        delay(1000);
        ec = 1;
    }
}
void dangnhapdangky() {
    header();
    if (lang == 1) {
        cout << "Vui Lòng Chọn:\n\n";
        cout << "   1. Đăng Nhập\n";
        cout << "   2. Đăng Ký\n";
        cout << "   3. Đổi Ngôn Ngữ (Vi-En)\n";
        cout << "   4. Đổi giao diện\n";
        cout << "   0. Quay Lai\n\n";
        cout << "------------------------------------\n";
        cout << "Nhập Lựa Chọn: ";
        cin >> choose;
    }
    else {
        cout << "Please Select:\n\n";
        cout << "   1. Login\n";
        cout << "   2. Register\n";
        cout << "   3. Change Language (Vi-En)\n";
        cout << "   4. Custom Theme\n";
        cout << "   0. Return\n\n";
        cout << "------------------------------------\n";
        cout << "Enter Your Choice: ";
        cin >> choose;
    }
    if (choose == '0') {
        if (lang == 1)
            cout << "Xin Chào Và Hẹn Gặp Lại Quý Khách!\n\n";
        else cout << "Thank You And See You Again!\n\n";
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
        cout << "Họ Tên      : " << accounts[x].Ten << endl;
        cout << "Số Tài Khoản: " << accounts[x].SoTaiKhoan << endl;
        cout << "Số Dư       : " << accounts[x].SoDu << "VND" << endl;
    }
    else {
        cout << "Fullname      : " << accounts[x].Ten << endl;
        cout << "Account Number: " << accounts[x].SoTaiKhoan << endl;
        cout << "Balance       : " << accounts[x].SoDu << "VND" << endl;
    }
    pause_anykey();
    return;
}
void inhoadon(string s, int point, long long tien, string mgd) {
    ofstream out("transaction_details.txt", ios::binary);
    const unsigned char bom[] = {0xEF, 0xBB, 0xBF};
    out.write((const char*)bom, 3);
    out << "===================NHLongg Bank===================\n";
    if (lang == 1)
        out << "Cảm Ơn Bạn Đã Sử Dụng Dịch Vụ, Chi Tiết Giao Dịch:" << endl;
    else out << "Thank You For Using Our Service, Transaction Details:\n\n";
    out << endl;
    if (s == "naptien") {
        if (lang == 1) {
            out << "Thời Gian Giao Dịch:   " << realtime() << endl;
            out << "Mã Giao Dịch       :   " << mgd << endl;
            out << "Loại Giao Dịch     :   Nạp Tiền Trực Tuyến" << endl;
            out << "Tài Khoản Thực Hiện:   " << accounts[x].Ten << " - " << accounts[x].SoTaiKhoan << endl;
            out << "Số Tiền Giao Dịch  :   " << tien << endl;
            out << "Tình Trạng         :   Giao Dịch Thành Công \n\n";
        }
        else {
            out << "Transaction Time  :   " << realtime() << endl;
            out << "Transaction ID    :   " << mgd << endl;
            out << "Transaction Type  :   Online Deposit" << endl;
            out << "From Account      :   " << accounts[x].Ten << " - " << accounts[x].SoTaiKhoan << endl;
            out << "Transaction Amount:   " << tien << endl;
            out << "Status            :   Transaction Successful \n\n";
        }
    }
    else
    if (s == "ruttien") {
        if (lang == 1) {
            out << "Thời Gian Giao Dịch:   " << realtime() << endl;
            out << "Mã Giao Dịch       :   " << mgd << endl;
            out << "Loại Giao Dịch     :   Rút Tiền Trực Tuyến" << endl;
            out << "Tài Khoản Thực Hiện:   " << accounts[x].Ten << " - " << accounts[x].SoTaiKhoan << endl;
            out << "Số Tiền Giao Dịch  :   " << tien << endl;
            out << "Tình Trạng         :   Giao Dịch Thành Công \n\n";
        }
        else {
            out << "Transaction Time  :   " << realtime() << endl;
            out << "Transaction ID    :   " << mgd << endl;
            out << "Transaction Type  :   Online Withdrawal" << endl;
            out << "From Account      :   " << accounts[x].Ten << " - " << accounts[x].SoTaiKhoan << endl;
            out << "Transaction Amount:   " << tien << endl;
            out << "Status            :   Transaction Successful \n\n";
        }
    }
    if (s == "chuyentien") {
        if (lang == 1) {
            out << "Thời Gian Giao Dịch:   " << realtime() << endl;
            out << "Mã Giao Dịch       :   " << mgd << endl;
            out << "Loại Giao Dịch     :   Chuyển Tiền Trực Tuyến" << endl;
            out << "Tài Khoản Thực Hiện:   " << accounts[x].Ten << " - " << accounts[x].SoTaiKhoan << endl;
            out << "Tai khoan thu huong:   " << accounts[point].Ten << " - " << accounts[point].SoTaiKhoan << endl;
            out << "Số Tiền Giao Dịch  :   " << tien << endl;
            out << "Tình Trạng         :   Giao Dịch Thành Công \n\n";
        }
        else {
            out << "Transaction Time  :   " << realtime() << endl;
            out << "Transaction ID    :   " << mgd << endl;
            out << "Transaction Type  :   Online Transfer" << endl;
            out << "From Account      :   " << accounts[x].Ten << " - " << accounts[x].SoTaiKhoan << endl;
            out << "Receiving Account :   " << accounts[point].Ten << " - " << accounts[point].SoTaiKhoan << endl;
            out << "Transaction Amount:   " << tien << endl;
            out << "Status            :   Transaction Successful \n\n";
        }
    }
    out << "==================================================\n";
    if (lang == 1)
        out << "Xin Chân Thành Cảm Ơn!";
    else out << "Sincerely Thank You!";
    out.close();
}
void biendong(int point, string mgd, string type, long long tien) {
    ofstream out(accounts[x].Ten + "_Balance_Fluctuations.txt", ios::app);
    const unsigned char bom[] = {0xEF, 0xBB, 0xBF};
    out.write((const char*)bom, 3);
    out << realtime() << "|" << mgd << "|";
    if (type == "naptien") {
        if (lang == 1)
            out << "Nạp Tiền      |+" << tien << " VND";
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
            out << "Rút Tiền      |-" << tien << " VND";
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
            out << "Chuyển Tiền   |-" << tien << " VND";
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
    const unsigned char bom[] = {0xEF, 0xBB, 0xBF};
    out.write((const char*)bom, 3);
    out << realtime() << "|" << mgd << "|";
    if (lang == 1)
        out << "Nhận Tiền     |+" << tien << " VND";
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
        cout << "Nhập Số Tiền Muốn Nạp (Nhập 0 Để Quay Trở Lại): ";
    else cout << "Enter The Amount You Want To Deposit (Enter 0 To Return): ";
    cin >> tien;
    if (tien == 0) return;
    else
    if (tien < 1000) {
        if (lang == 1)
            cout << "Số Tiền Phải Lớn Hơn 1000!\n";
        else cout << "The amount Must Be Greater Than 1000!\n";
        delay(1000);
        naptien();
    }
    else {
        accounts[x].SoDu += tien;
        changefile();
        cls();
        if (lang == 1) {
            cout << "Nạp Tiền Thành Công!" << endl;
            cout << "Mã Giao Dịch: " << mgd << endl;
            cout << "Số Tiền Đã Nạp: " << tien << "VND" << endl;
            cout << "Số Dư Hiện Tại: " << accounts[x].SoDu << "VND" << endl;
            cout << "Chi Tiết Giao Dịch Đã Được Tạo Thành Công!" << endl;
        }
        else {
            cout << "Deposit Successful!" << endl;
            cout << "Transaction ID: " << mgd << endl;
            cout << "Deposited Amount: " << tien << "VND" << endl;
            cout << "Current Balance: " << accounts[x].SoDu << "VND" << endl;
            cout << "Transaction Details Have Been Successfully Created!" << endl;
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
        cout << "Nhập Số Tiền Muốn Rút (Nhập 0 Để Quay Trở Lại)): ";
    else cout << "Enter The Amount You Want To Withdraw (Enter 0 To Return): ";
    cin >> tien;
    if (tien == 0) return;
    else
    if (tien < 1000) {
        if (lang == 1)
            cout << "Số Tiền Phải Lớn Hơn 1000!\n";
        else cout << "The amount Must Be Greater Than 1000!\n";
        delay(1000);
        ruttien();
    }
    else
    if (tien > accounts[x].SoDu) {
        if (lang == 1)
            cout << "Số Dư Không Đủ, Vui Long Nhap lai!" << endl;
        else cout << "Insufficient Balance, Please Re-Enter!" << endl;
        delay(1000);
        ruttien();
    }
    else {
        accounts[x].SoDu -= tien;
        changefile();
        cls();
        if (lang == 1) {
            cout << "Rút Tiền Thành Công!" << endl;
            cout << "Mã Giao Dịch: " << mgd << endl;
            cout << "Số Dư Hiện Tại: " << accounts[x].SoDu << endl;
            cout << "Chi Tiết Giao Dịch Đã Được Tạo Thành CÔng!" << endl;
        }
        else {
            cout << "Withdraw Successful!" << endl;
            cout << "Transaction ID: " << mgd << endl;
            cout << "Current Balance: " << accounts[x].SoDu << endl;
            cout << "Transaction Details Have Been Successfully Created!" << endl;
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
        cout << "Tên Người Nhận: " << accounts[point].Ten << endl;
        cout << "Nhập Số Tiền Muốn Chuyển (Nhấn 0 Để Quay Trở Về Menu): ";
    }
    else {
        cout << "Recipient Name: " << accounts[point].Ten << endl;
        cout << "Enter The Amount You Want To Transfer (Enter 0 To Return To Menu): ";
    }
    cin >> tien;
    if (tien == 0) return;
    else
    if (tien < 1000) {
        if (lang == 1)
            cout << "Số Tiền Phải Lớn Hơn 1000!\n";
        else cout << "The amount Must Be Greater Than 1000!\n";
        delay(1000);
        chuyen(-1);
    }
    else
    if (tien > accounts[x].SoDu) {
        if (lang == 1)
            cout << "Số Dư Không Đủ!";
        else cout << "Insufficient Balance!";
        delay(1000);
        chuyen(-1);
    }
    else {
        accounts[x].SoDu -= tien;
        accounts[point].SoDu += tien;
        changefile();
        cls();
        if (lang == 1) {
            cout << "Giao Dịch Thành Công!\n";
            cout << "Đã Chuyển Thành Công " << tien << "VND tới " << accounts[point].Ten << endl;
            cout << "Mã Giao Dịch: " << mgd << endl;
            cout << "Số Dư Còn Lại: " << accounts[x].SoDu << endl;
            cout << "Chi Tiết Giao Dịch Đã Được Tạo Thành Công!" << endl;
        }
        else {
            cout << "Transaction successful!\n";
            cout << "Successfully Transferred " << tien << "VND To " << accounts[point].Ten << endl;
            cout << "Transaction ID: " << mgd << endl;
            cout << "Remaining Balance: " << accounts[x].SoDu << endl;
            cout << "Transaction Details Have Been Successfully C8reated!" << endl;
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
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
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
