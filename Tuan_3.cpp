#include<iostream>
using namespace std;
class M1C {
private:
    int spt=0;
    int a[200];
public:
    void nhap();
    void xuat();
    int timkiem(int x);
    void sapxep();
    void xoa(int k);
    void chen(int k);
    void tach_chan(M1C t);
    void tach_le(M1C t);
    void gop(M1C t);
};
void M1C::nhap() {
    cout<<"nhap spt:";cin>>spt;
    for(int i=0;i<spt;i++) {
        cout<<"ptu"<<i+1<<": ";cin>>a[i];
    }
}
void M1C::xuat() {
    for(int i=0;i<spt;i++) {
        cout<<"ptu"<<i+1<<" la: "<<a[i]<<endl;
    }
}
int M1C::timkiem(int x) {
    int vt=-1;
    for(int i=0;i<spt;i++) {
        if(a[i]==x) {
            vt=i;
        }
    }
    return vt;
}
void M1C::sapxep() {
    for(int i=0;i<spt;i++) {
        for(int j=0;j<spt-1;j++) {
            if(a[j]>a[j+1]) {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
void M1C::xoa(int k) {
    while (k<0||k>spt-1) {
        cout<<"nhap lai:";cin>>k;
    }
    for(int i=k;i<spt-1;i++) {
        a[i]=a[i+1];
    }
    spt-=1;
}
void M1C::chen(int k) {
    while (k<0||k>spt-1) {
        cout<<"nhap lai:";cin>>k;
    }
    int c;
    cout<<"gia tri can chen:";cin>>c;
    for(int i=spt;i>k;i--) {
        a[i]=a[i-1];
    }
    a[k]=c;
    spt+=1;
}
void M1C::tach_chan(M1C t) {
    for(int i=0;i<t.spt;i++) {
        if (a[i]%2==0) {
            a[spt]=t.a[i];
            spt++;
        }
    }
}
void M1C::tach_le(M1C t) {
    for(int i=0;i<spt;i++) {
        if (a[i]%2==0) {
            a[spt]=t.a[i];
            spt++;
        }
    }
}
void M1C::gop(M1C t) {
    for(int i=0;i<t.spt;i++) {
        a[i+spt]=t.a[i];
    }
    spt+=t.spt;
}
int main() {
    M1C h;
    h.nhap();
    cout<<"--------------------------------------------------------"<<endl;
    h.xuat();
    cout<<"--------------------------------------------------------"<<endl;
    int x;
    cout<<"nhap x:";cin>>x;
    if (h.timkiem(x)>-1) {
        cout<<"x o vi tri thu"<<h.timkiem(x)+1<<endl;
    }
    else {
        cout<<"khong tim thay x"<<endl;
    }
    cout<<"--------------------------------------------------------"<<endl;
    h.sapxep();
    cout<<"ds sau sap xep:";
    h.xuat();
    int k;
    cout<<"nhap k:";cin>>k;
    cout<<"--------------------------------------------------------"<<endl;
    h.xoa(k);
    cout<<"ds sau xoa:";
    h.xuat();
    cout<<"--------------------------------------------------------"<<endl;
    cout<<"nhap k de chen:";cin>>k;
    h.chen(k);
    cout<<"ds sau chen:";
    h.xuat();
    cout<<"--------------------------------------------------------"<<endl;
    cout<<"tach mang chan le";
    M1C chan,le;
    chan.tach_chan(h);
    le.tach_le(h);
    cout<<"ds chan :";
    chan.xuat();
    cout<<"ds le :";
    le.xuat();
    chan.gop(le);
    cout<<"ds gop :";
    chan.xuat();
}