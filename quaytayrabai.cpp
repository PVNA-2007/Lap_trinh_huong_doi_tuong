#include<iostream>
using namespace std;
class PhanSo {
private:
    int TS;
    int MS;
public:
    void nhap();
    void xuat();
    PhanSo cong(PhanSo b);
    void rutgon();
};
int UCLN(int a,int b) {
    while (a!=b) {
        if (a>b) {
            a%=b;
        }
        else {
            b%=a;
        }
    }
    return a;
}
void PhanSo::rutgon() { //ý tưởng là chia cả tử và mẫu cho ước chung lớn nhất
    if (TS==MS) {
        TS=1;MS=1;
    }
    else {
        int a=UCLN(TS,MS);
        if (a>1) {
            TS/=a;
            MS/=a;
        }
    }
}
void PhanSo::nhap() {
    cout<<"Nhap tu so: ";cin>>TS;
    cout<<"Nhap mau so: ";cin>>MS;
}
void PhanSo::xuat() {
    cout<<"PhanSo: "<<TS<<"/"<<MS<<endl;
}
PhanSo PhanSo::cong(PhanSo b) {
    PhanSo c;
    c.TS = TS*b.MS+b.TS*MS;
    c.MS = b.MS*MS;
    return c;
}
int main() {
    PhanSo a,b,c;
    a.nhap();
    b.nhap();
    c=a.cong(b);
    c.rutgon();
    c.xuat();
}