#include<iostream>
using namespace std;
class PhanSo {
private:
    int TS,MS;
public:
    PhanSo() {
        TS=0,MS=0;
    }
    PhanSo(int a,int b) {
        TS=a,MS=b;
    }
    void nhap();
    void xuat();
    PhanSo cong(PhanSo b);
    PhanSo cong(int b);
    void rutgon();
    friend PhanSo nhan(PhanSo b,PhanSo a);
};
int UCLN(int a, int b) {
    while (a != b) {
        if (a>b) {
            a-=b;
        }
        else {
            b-=a;
        }
    }
    return a;
}
void PhanSo::rutgon() {
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
    while (MS==0) {
        cout<<"Nhap lai!"<<endl;
        cout<<"Nhap mau so: ";cin>>MS;
    }
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
PhanSo PhanSo::cong(int b) {
    PhanSo c;
    c.TS=TS+b*MS;
    c.MS=MS;
    return c;
}
PhanSo nhan(PhanSo b,PhanSo a) {
    PhanSo c;
    c.TS=b.TS*a.TS;
    c.MS=b.MS*a.MS;
    return c;
}
int main() {
    PhanSo a,b,c;
    a.nhap();
    b.nhap();
    PhanSo d(b);
    int t;
    cout<<"Nhap so nguyen: ";cin>>t;
    c=a.cong(b);
    c.rutgon();
    c.xuat();
    a=a.cong(t);
    a.xuat();
}