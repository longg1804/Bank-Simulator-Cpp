#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
using namespace std;
class Account { 
    public:
        string TenDangNhap;
        string MatKhau;
        string Ten;
        string SoTaiKhoan;
        long long SoDu;
        Account (string s = "", string a = "", string b = "", string c = "", long long d = 0) {
            TenDangNhap = s;
            MatKhau = a;
            Ten = b;
            SoTaiKhoan = c;
            SoDu = d;
        }
};
#endif
