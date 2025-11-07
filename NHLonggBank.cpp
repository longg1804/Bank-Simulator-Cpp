#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
using namespace std;

//=====================KHAI BÁO========================

class Account {
    public:
        string TenDangNhap;
        string MatKhau;
        string Ten;
        string SoTaiKhoan;
        int PIN;
        long long SoDu;
        Account (string s = "", string a = "", string b = "", string c = "", int e = 0, long long d = 0) {
            TenDangNhap = s;
            MatKhau = a;
            Ten = b;
            SoTaiKhoan = c;
            PIN = e;
            SoDu = d;
        }
};

int ec = 0, x, point, lang = 1, pinec = 1;
char choose;
string theme = "dark";
vector<Account> accounts;

//=====================TIỆN ÍCH========================

void header();
void delay(int ms) {Sleep(ms);}
void dangxacthuc() {
    header();
    if (lang == 1)
        cout << "Đang Xác Thực...";
    else cout << "Verifying...";
    delay(500);
}
void pause_anykey() {
    cout << endl;
    cout << "--------------------------------------------\n";
    if (lang == 1)
        cout << "Nhấn Phím Bất Kì Để Quay Lại...";
    else cout << "Press Any Key To Return...";
    _getch();
}
void luachonsai() {
    header();
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
string chuanhoatien (long long n) {
    string s = "";
    int t = 0;
    while (n) {
        s = char((n % 10) + '0') + s;
        n /= 10;
        ++t;
        if (t % 3 == 0) s = '.' + s;
    }
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
    ofstream out("Accounts_Data.txt");
    for (int i = 0; i < accounts.size(); ++i)
        out << accounts[i].TenDangNhap << '|' << accounts[i].MatKhau << '|' << accounts[i].Ten << '|' << accounts[i].SoTaiKhoan << '|' << accounts[i].PIN << '|' << accounts[i].SoDu << '|' << "\n";
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
    system("cls");
    cout << "<>========================================<>\n";
    cout << "||              NHLongg Bank              ||\n";
    cout << "<>========================================<>\n";
}
void xacnhanpin() {
    pinec = 1;
    int s;
    cout << "Nhập Mã PIN Để Xác Nhận: ";
    cin >> s;
    if (s == accounts[x].PIN) pinec = 1;
    else {
        cout << "Mã Pin Không Đúng, Vui Lòng Nhập Lại!\n";
        pinec = 0;
        delay(1000);
    }
}
void doigiaodien();
void dangnhap();
void dangky();
void dangnhapdangky();
void tracuu();
void inhoadon();
void biendong();
void biendongnhantien();
void naptien();
void ruttien();
void chuyen();
void chuyentien();
void doimatkhau();
void biendongsodu();
void menu();

//======================TÍNH NĂNG=======================

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
    if (lang == 1) {
        cout << "Đổi Giao Diện : \n\n";
        cout << "   1. Giao Diện Sáng\n";
        cout << "   2. Giao Diện Tối\n";
        cout << "   3. Giao Diện Tùy Chỉnh\n";
        cout << "   0. Quay Lại\n\n";
        cout << "--------------------------------------------\n";
        cout << "Nhập Lựa Chọn: ";
    }
    else {
        cout << "Change Theme (Press 0 To Return): \n\n";
        cout << "   1. Light Theme\n";
        cout << "   2. Dark Theme\n";
        cout << "   3. Custom Theme\n\n";
        cout << "--------------------------------------------\n";
        cout << "Please Select: ";
    }
    cin >> k;
    if ((k < 0) || (k > 3)) {
        luachonsai();
        delay(1000);
        doigiaodien();
    }
    else
    if (k == 0) {
        if (ec == 1) menu();
        else dangnhapdangky();
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
        pause_anykey();
        if (ec == 1) menu();
        else dangnhapdangky();
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
        pause_anykey();
        if (ec == 1) menu();
        else dangnhapdangky();
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
            doigiaodien();
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
        pause_anykey();
        if (ec == 1) menu();
        else dangnhapdangky();
    }
}
void dangnhap() {
    string tendangnhap, matkhau;
    header();
    int dangnhapcheck = 0;
    if (lang == 1) {
        cout << "Điền Tên Đăng Nhập Và Mật Khẩu (Nhập 0 Để Quay Lại): \n";
        cout << "   Tên Đăng Nhập: ";
        cin >> tendangnhap;
        if (tendangnhap == "0") dangnhapdangky();
        cout << "   Mật Khẩu: ";
        cin >> matkhau;
    }
    else {
        cout << "Enter User Name And Password (Press 0 To Return): \n";
        cout << "   Username: ";
        cin >> tendangnhap;
        if (tendangnhap == "0") dangnhapdangky();
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
        cout << endl;
        cout << "--------------------------------------------\n";
        if (lang == 1)
            cout << "Đăng Nhập Thành Công, Đang Trở Về Menu!\n";
        else cout << "Login Successful, Returning To Menu!\n";
        delay(1000);
        ec = 1;
        menu();
    }
    else {
        cout << endl;
        cout << "--------------------------------------------\n";
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
    int pin;
    ofstream out("Accounts_Data.txt", ios::app);
    if (lang == 1) {
        cout << "Bạn Đang Thực Hiện Đăng Ký Tài Khoản, Vui Lòng Nhập Tài Khoản Và Mật Khẩu (Nhập 0 Để Quay Lại): " << endl;
        cout << "   Tên Đăng Nhập: ";
    }
    else {
        cout << "You Are Registering An Account, Please Enter Username And Password:\n";
        cout << "   Username: ";
    }
    cin >> tendangnhap;
    if (tendangnhap == "0") dangnhapdangky();
    bool kt = true;
    for (int i = 0; i < accounts.size(); ++i)
        if (tendangnhap == accounts[i].TenDangNhap) {
            kt = false;
            break;
        }
    if (!kt) {
        cout << endl;
        cout << "--------------------------------------------\n";
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
        cout << endl;
        cout << "--------------------------------------------\n";
        if (lang == 1)
            cout << "Số Tài Khoản Đã Tồn Tại, Vui Lòng Thử Lại!" << endl;
        else cout << "Account Number Already Exists, Please Try Again!" << endl;
        delay(1000);
        dangky();
    }
    p:
    if (lang == 1)
        cout << "   Mã Pin 6 Kí Tự: ";
    else cout << "   6-Digits PIN Code: ";
    cin >> pin;
    if ((pin < 100000) || (pin > 999999)) {
        if (lang == 1)
            cout << "Mã PIN Không Hợp Lệ, Vui Lòng Nhập Lại!\n";
        else cout << "PIN Code Invalid, Please Try Again!\n";
        goto p;
    }
    if (kt) {
        string s = "";
        Account newacc;
        newacc.TenDangNhap = tendangnhap;
        newacc.MatKhau = matkhau;
        newacc.Ten = hoten;
        newacc.SoTaiKhoan = sotaikhoan;
        newacc.PIN = pin;
        newacc.SoDu = 0;
        s = s + tendangnhap + '|' + matkhau + '|' + hoten + '|' + sotaikhoan + '|' + to_string(pin) + "|0|";
        accounts.push_back(newacc);
        out << s << "\n";
        out.close();
        x = accounts.size() - 1;
        cout << endl;
        cout << "--------------------------------------------\n";
        if (lang == 1)
            cout << "Đăng Ký Tài Khoản Thành Công, Đang Đăng Nhập!";
        else cout << "Account Registration Successful, Logging In!";
        delay(1000);
        ec = 1;
        menu();
    }
}
void dangnhapdangky() {
    header();
    if (lang == 1) {
        cout << "Vui Lòng Chọn:\n\n";
        cout << "   1. Đăng Nhập\n";
        cout << "   2. Đăng Ký\n";
        cout << "   3. Đổi Ngôn Ngữ (Vi/En)\n";
        cout << "   4. Đổi Giao Diện\n";
        cout << "   0. Thoát\n\n";
        cout << "--------------------------------------------\n";
        cout << "Nhập Lựa Chọn: ";
        cin >> choose;
    }
    else {
        cout << "Please Select:\n\n";
        cout << "   1. Login\n";
        cout << "   2. Register\n";
        cout << "   3. Change Language (Vi/En)\n";
        cout << "   4. Custom Theme\n";
        cout << "   0. Exit\n\n";
        cout << "--------------------------------------------\n";
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
        cout << "Thông Tin Tài Khoản:\n\n";
        cout << "Họ Tên      : " << accounts[x].Ten << endl;
        cout << "Số Tài Khoản: " << accounts[x].SoTaiKhoan << endl;
        cout << "Số Dư       : " << chuanhoatien(accounts[x].SoDu) << " VND" << endl;
    }
    else {
        cout << "Account Info: \n\n";
        cout << "Fullname      : " << accounts[x].Ten << endl;
        cout << "Account Number: " << accounts[x].SoTaiKhoan << endl;
        cout << "Balance       : " << chuanhoatien(accounts[x].SoDu) << " VND" << endl;
    }
    pause_anykey();
    return;
}
void inhoadon(string s, int point, long long tien, string mgd) {
    ofstream out("Transaction_Details.txt", ios::binary);
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
            out << "Số Tiền Giao Dịch  :   " << chuanhoatien(tien) << " VND" << endl;
            out << "Tình Trạng         :   Giao Dịch Thành Công \n\n";
        }
        else {
            out << "Transaction Time  :   " << realtime() << endl;
            out << "Transaction ID    :   " << mgd << endl;
            out << "Transaction Type  :   Online Deposit" << endl;
            out << "From Account      :   " << accounts[x].Ten << " - " << accounts[x].SoTaiKhoan << endl;
            out << "Transaction Amount:   " << chuanhoatien(tien) << " VND" << endl;
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
            out << "Số Tiền Giao Dịch  :   " << chuanhoatien(tien) << " VND" << endl;
            out << "Tình Trạng         :   Giao Dịch Thành Công \n\n";
        }
        else {
            out << "Transaction Time  :   " << realtime() << endl;
            out << "Transaction ID    :   " << mgd << endl;
            out << "Transaction Type  :   Online Withdrawal" << endl;
            out << "From Account      :   " << accounts[x].Ten << " - " << accounts[x].SoTaiKhoan << endl;
            out << "Transaction Amount:   " << chuanhoatien(tien) << " VND" <<  endl;
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
            out << "Số Tiền Giao Dịch  :   " << chuanhoatien(tien) << " VND" << endl;
            out << "Tình Trạng         :   Giao Dịch Thành Công \n\n";
        }
        else {
            out << "Transaction Time  :   " << realtime() << endl;
            out << "Transaction ID    :   " << mgd << endl;
            out << "Transaction Type  :   Online Transfer" << endl;
            out << "From Account      :   " << accounts[x].Ten << " - " << accounts[x].SoTaiKhoan << endl;
            out << "Receiving Account :   " << accounts[point].Ten << " - " << accounts[point].SoTaiKhoan << endl;
            out << "Transaction Amount:   " << chuanhoatien(tien) << " VND" << endl;
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
    out << realtime() << "|" << mgd << "|";
    if (type == "naptien") {
        if (lang == 1)
            out << "Nap Tien      |+" << chuanhoatien(tien) << " VND";
        else out << "Deposit       |+" << chuanhoatien(tien) << " VND";
        string c = chuanhoatien(tien);
        for (int i = 17; i >= c.size() + 5; --i) out << " ";
        out << "|     NHLongg Bank     |SUCCESS       |" << chuanhoatien(accounts[x].SoDu) << " VND";
        c = chuanhoatien(accounts[x].SoDu);
        for (int i = 17; i >= c.size() + 4; --i) out << " ";
        out << "|";
    }
    else
    if (type == "ruttien") {
        if (lang == 1)
            out << "Rut Tien      |-" << chuanhoatien(tien) << " VND";
        else out << "Withdrawal    |-" << chuanhoatien(tien) << " VND";
        string c = chuanhoatien(tien);
        for (int i = 17; i >= c.size() + 5; --i) out << " ";
        out << "|     NHLongg Bank     |SUCCESS       |" << chuanhoatien(accounts[x].SoDu) << " VND";
        c = chuanhoatien(accounts[x].SoDu);
        for (int i = 17; i >= c.size() + 4; --i) out << " ";
        out << "|";
    }
    else
    if (type == "chuyentien") {
        if (lang == 1)
            out << "Chuyen Tien   |-" << chuanhoatien(tien) << " VND";
        else out << "Transfer      |-" << chuanhoatien(tien) << " VND";
        string c = chuanhoatien(tien);
        for (int i = 17; i >= c.size() + 5; --i) out << " ";
        out << "|" << accounts[point].Ten;
        for (int i = 21; i >= accounts[point].Ten.size(); --i) out << " ";
        out << "|SUCCESS       |" << chuanhoatien(accounts[x].SoDu) << " VND";
        c = chuanhoatien(accounts[x].SoDu);
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
        out << "Nhan Tien     |+" << chuanhoatien(tien) << " VND";
    else out << "Incoming      |+" << chuanhoatien(tien) << " VND";
    string c = chuanhoatien(tien);
    for (int i = 17; i >= c.size() + 5; --i) out << " ";
    out << "|" << accounts[x].Ten;
    for (int i = 21; i >= accounts[x].Ten.size(); --i) out << " ";
    out << "|SUCCESS       |" << chuanhoatien(accounts[point].SoDu) << " VND";
    c = chuanhoatien(accounts[point].SoDu);
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
        p:
        xacnhanpin();
        if (pinec == 1) {
            accounts[x].SoDu += tien;
            changefile();
            dangxacthuc();
            header();
            if (lang == 1) {
                cout << "Nạp Tiền Thành Công!\n" << endl;
                cout << "Mã Giao Dịch  : " << mgd << endl;
                cout << "Số Tiền Đã Nạp: " << chuanhoatien(tien) << " VND" << endl;
                cout << "Số Dư Hiện Tại: " << chuanhoatien(accounts[x].SoDu) << " VND" << endl;
                cout << "Chi Tiết Giao Dịch Đã Được Tạo Thành Công!" << endl;
            }
            else {
                cout << "Deposit Successful!" << endl;
                cout << "Transaction ID  : " << mgd << endl;
                cout << "Deposited Amount: " << chuanhoatien(tien) << " VND" << endl;
                cout << "Current Balance : " << chuanhoatien(accounts[x].SoDu) << " VND" << endl;
                cout << "Transaction Details Have Been Successfully Created!" << endl;
            }
            inhoadon("naptien", 0, tien, mgd);
            biendong(0, mgd, "naptien", tien);
            pause_anykey();
            return;
        }
        else {
            goto p;
        }
    }
}
void ruttien() {
    header();
    long long tien;
    string mgd = magiaodich();
    if (lang == 1)
        cout << "Nhập Số Tiền Muốn Rút (Nhập 0 Để Quay Trở Lại): ";
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
            cout << "Số Dư Không Đủ, Vui Lòng Nhập Lại!" << endl;
        else cout << "Insufficient Balance, Please Re-Enter!" << endl;
        delay(1000);
        ruttien();
    }
    else {
        p:
        xacnhanpin();
        if (pinec == 1) {
            accounts[x].SoDu -= tien;
            changefile();
            dangxacthuc();
            header();
            if (lang == 1) {
                cout << "Rút Tiền Thành Công!\n" << endl;
                cout << "Mã Giao Dịch  : " << mgd << endl;
                cout << "Số Tiền Đã Rút: " << chuanhoatien(tien) << " VND" << endl;
                cout << "Số Dư Hiện Tại: " << chuanhoatien(accounts[x].SoDu) << " VND" << endl;
                cout << "Chi Tiết Giao Dịch Đã Được Tạo Thành Công!" << endl;
            }
            else {
                cout << "Withdraw Successful!\n" << endl;
                cout << "Transaction ID   : " << mgd << endl;
                cout << "Withdrawal Amount: " << chuanhoatien(tien) << " VND" << endl;
                cout << "Current Balance  : " << chuanhoatien(accounts[x].SoDu) << " VND" << endl;
                cout << "Transaction Details Have Been Successfully Created!" << endl;
            }
            inhoadon("ruttien", 0, tien, mgd);
            biendong(0, mgd, "ruttien", tien);
            pause_anykey();
            return;
        }
        else {
            goto p;
        }
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
        chuyen(point);
    }
    else
    if (tien > accounts[x].SoDu) {
        if (lang == 1)
            cout << "Số Dư Không Đủ!";
        else cout << "Insufficient Balance!";
        delay(1000);
        chuyen(point);
    }
    else {
        p:
        xacnhanpin();
        if (pinec == 1) {
            accounts[x].SoDu -= tien;
            accounts[point].SoDu += tien;
            changefile();
            dangxacthuc();
            header();
            if (lang == 1) {
                cout << "Giao Dịch Thành Công!\n\n";
                cout << "Mã Giao Dịch  : " << mgd << endl;
                cout << "Người nhận    : " << accounts[point].Ten << endl;
                cout << "Số Tiền Chuyển: " << chuanhoatien(tien) << " VND" << endl;
                cout << "Số Dư Còn Lại : " << chuanhoatien(accounts[x].SoDu) << " VND" << endl;
                cout << "Chi Tiết Giao Dịch Đã Được Tạo Thành Công!" << endl;
            }
            else {
                cout << "Transaction successful!\n\n";
                cout << "Transaction ID    : " << mgd << endl;
                cout << "Recipient Name    : " << accounts[point].Ten << endl;
                cout << "Transferred Amount: " << chuanhoatien(tien) << " VND" << endl;
                cout << "Remaining Balance : " << chuanhoatien(accounts[x].SoDu) << " VND" << endl;
                cout << "Transaction Details Have Been Successfully C8reated!" << endl;
            }
            inhoadon("chuyentien", point, tien, mgd);
            biendong(point, mgd, "chuyentien", tien);
            biendongnhantien(point, mgd, tien, x);
            pause_anykey();
            return;
        }
        else {
            goto p;
        }
    }
}
void chuyentien() {
    string sotaikhoan;
    header();
    if (lang == 1) {
        cout << "Bạn Đang Thực Hiện Chuyển Tiền (Nhập 0 Để Quay Lại): \n";
        cout << "Nhập Số Tài Khoản Người Nhận: ";
    }
    else {
        cout << "You Are Making A Transfer (Enter 0 To Return): \n";
        cout << "Enter The Recipient's Account Number: ";
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
            cout << "Số Tài Khoản Không Đúng Hoặc Không Tồn Tại, Vui Lòng Nhập Lại!\n";
        else cout << "Invalid Or Non-Existent Account Number, Please Re-Enter!\n";
        delay(1000);
        chuyentien();
    }
    else
    if (point == x) {
        if (lang == 1)
            cout << "Không Thể Chuyển Cho Chính Mình, Vui Lòng Nhập Lại!\n";
        else cout << "Cannot Transfer To Yourself, Please Re-Enter!\n";
        delay(1000);
        chuyentien();
    }
    else chuyen(point);
}
void doimatkhau() {
    char k;
    string a, b, c;
    header();
    if (lang == 1)
        cout << "Đang Tiến Hành Đổi Mật Khẩu (Nhập 1 Để Tiếp Tục, 0 Để Quay Lại): ";
    else cout << "Processing Password Change (Enter 1 To Continue, 0 To Go Back): ";
    cin >> k;
    if (k == '0') menu();
    else
    if (k == '1') {
        p:
        header();
        if (lang == 1)
            cout << "Nhập Mật Khẩu Hiện Tại: ";
        else cout << "Enter Current Password: ";
        cin >> a;
        if (a != accounts[x].MatKhau) {
            if (lang == 1)
                cout << "Mật Khẩu Đã Nhập Không Đúng, Vui Lòng Thử Lại!";
            else cout << "The Password Entered Is incorrect, Please Try Again!";
            delay(1000);
            goto p;
        }
        pp:
        header();
        if (lang == 1) {
            cout << "Nhập Mật Khẩu Mới: ";
            cin >> b;
            cout << "Nhập Lại Mật Khẩu Mới: ";
            cin >> c;
        }
        else {
            cout << "Enter New Password: ";
            cin >> b;
            cout << "Re-Enter New Password: ";
            cin >> c;
        }
        if (c != b) {
            if (lang == 1)
                cout << "Mật Khẩu Đã Nhập Không Trùng Khớp, Vui Lòng Thử Lại!";
            else cout << "The Passwords Entered Do Not Match, Please Try Again!";
            delay(1000);
            goto pp;
        }
        else {
            accounts[x].MatKhau = c;
            changefile();
            if (lang == 1)
                cout << "Thay Đổi Mật Khẩu Thành Công!\n";
            else cout << "Password Changed Successfully!\n";
            pause_anykey();
        }
    }
    else {
        luachonsai();
        doimatkhau();
    }
}
void doipin() {
    char k;
    int a, b, c;
    header();
    if (lang == 1)
        cout << "Đang Tiến Hành Đổi Mã PIN (Nhập 1 Để Tiếp Tục, 0 Để Quay Lại): ";
    else cout << "Processing PIN Code Change (Enter 1 To Continue, 0 To Go Back): ";
    cin >> k;
    if (k == '0') menu();
    else
    if (k == '1') {
        p:
        header();
        if (lang == 1)
            cout << "Nhập Mã PIN Hiện Tại: ";
        else cout << "Enter Current PIN Code: ";
        cin >> a;
        if (a != accounts[x].PIN) {
            if (lang == 1)
                cout << "Mã PIN Đã Nhập Không Đúng, Vui Lòng Thử Lại!";
            else cout << "The PIN Code Entered Is incorrect, Please Try Again!";
            delay(1000);
            goto p;
        }
        pp:
        header();
        if (lang == 1) {
            cout << "Nhập Mã PIN Mới: ";
            cin >> b;
            cout << "Nhập Lại Mã PIN Mới: ";
            cin >> c;
        }
        else {
            cout << "Enter New PIN Code: ";
            cin >> b;
            cout << "Re-Enter New PIN Code: ";
            cin >> c;
        }
        if (c != b) {
            if (lang == 1)
                cout << "Mã PIN Đã Nhập Không Trùng Khớp, Vui Lòng Thử Lại!";
            else cout << "The PIN Codes Entered Do Not Match, Please Try Again!";
            delay(1000);
            goto pp;
        }
        else {
            accounts[x].PIN = c;
            changefile();
            if (lang == 1)
                cout << "Thay Đổi Mã PIN Thành Công!\n";
            else cout << "PIN Code Changed Successfully!\n";
            pause_anykey();
        }
    }
    else {
        luachonsai();
        doipin();
    }
}
void biendongsodu() {
    ifstream file(accounts[x].Ten + "_Balance_Fluctuations.txt");
    header();
    if (lang == 1)
        cout << "Biến Động Số Dư: \n";
    else cout << "Balance Fluctuations: \n";
    cout << "--------------------------------------------------------------------------------------------------------------------------------\n";
    if (lang == 1)
        cout << "|     Thoi Gian	    |     Ma GD     |     Loai     |     So Tien      |       Đoi Tac        |  Trang Thai  |     So Du Sau    |\n";
    else cout << "|       Time        |Transaction ID |     Type     |      Amount      |        Partner       |    Status    |   Balance After  |\n";
    cout << "--------------------------------------------------------------------------------------------------------------------------------\n";
    string line;
    while (getline(file, line)) {
        cout << "|" << line << endl;
    }
    cout << "--------------------------------------------------------------------------------------------------------------------------------\n";
    file.close();
    pause_anykey();
}
void menu() {
    while (true) {
        header();
        if (lang == 1) {
            cout << "Xin Chào " << accounts[x].Ten << "! Vui Lòng Chọn: \n\n";
            cout << "   1. Tra Cứu\n";
            cout << "   2. Nạp Tiền\n";
            cout << "   3. Rút Tiền\n";
            cout << "   4. Chuyển Tiền Nội Bộ\n";
            cout << "   5. Đổi Mật Khẩu\n";
            cout << "   6. Biến Động Số Dư\n";
            cout << "   7. Đổi Ngôn Ngữ (Vi/En)\n";
            cout << "   8. Đổi Giao Diện\n";
            cout << "   9. Đổi Mã PIN\n";
            cout << "   0. Đăng Xuất\n\n";
            cout << "--------------------------------------------\n";
            cout << "Vui Lòng Chọn: ";
        }
        else {
            cout << "Hi " << accounts[x].Ten << "! Please Select: \n\n";
            cout << "   1. Inquiry\n";
            cout << "   2. Deposit\n";
            cout << "   3. Withdraw\n";
            cout << "   4. Internal Transfer\n";
            cout << "   5. Change Password\n";
            cout << "   6. Balance Fluctuations\n";
            cout << "   7. Change Language (Vi/En)\n";
            cout << "   8. Change Theme\n";
            cout << "   9. Change PIN Code\n";
            cout << "   0. Log Out\n\n";
            cout << "--------------------------------------------\n";
            cout << "Please Select: ";
        }
        cin >> choose;
        if (choose == '0') {
            if (lang == 1)
                cout << "Đăng Xuất Thành Công, Vui Lòng Chờ...";
            else cout << "Logout Successful, Please Wait...";
            delay(1000);
            ec = 0;
            dangnhapdangky();
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
        else
        if (choose == '9') {
            doipin();
        }
        else {
            luachonsai();
            menu();
        }
    }
}

//===================CHƯƠNG TRÌNH=====================

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    ifstream file("Accounts_Data.txt");
    srand(time(0));
    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        string c;
        stringstream s(line);
        vector<string> TaiKhoan;
        while (getline(s, c, '|'))
            if (!c.empty()) TaiKhoan.push_back(c);
        if (TaiKhoan.size() == 6) {
            Account acc;
            acc.TenDangNhap = TaiKhoan[0];
            acc.MatKhau = TaiKhoan[1];
            acc.Ten = TaiKhoan[2];
            acc.SoTaiKhoan = TaiKhoan[3];
            acc.PIN = stoll(TaiKhoan[4]);
            acc.SoDu = stoll(TaiKhoan[5]);
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
