/*
Thời gian có giờ và phút, giờ có giá trị trong khoảng 0-23, phút có giá trị trong khoảng
0-59. Nhập vào thời gian bắt đầu một ca thi và số phút làm bài thi. Tính thời gian kết
thúc ca thi. Yêu cầu sử dụng toán tử nhập >> và toán tử xuất << để nhập vào và đưa ra
thời gian ở dạng h:mm, sử dụng toán tử + để cộng thời gian với số phút, thời gian được
khởi tạo tự động với giờ và phút bằng 0 hoặc khởi tạo bằng giờ, phút cho trước
*/

#include<stdio.h>
#include<iostream>

using namespace std;
class ThoiGian
{
    private:
        int gio, phut;

    public:
        ThoiGian();
        ThoiGian(int g, int p);
        void chuanhoa();
        ThoiGian operator+(int p);

        //Ham ban
        friend istream& operator>>(istream &cin, ThoiGian &h);
        friend ostream& operator<<(ostream &cout, ThoiGian &h);
};
int main()
{
    ThoiGian H;
    int soPhut;
    cout<<"Nhap thoi gian lam bai ";
    cin>>H;

    cout<<"Nhap so phut lam bai: ";
    cin>>soPhut;

    ThoiGian ketthuc = H + soPhut;

    cout<<"Thoi gian ket thuc bai thi: "<<ketthuc;

    cout<<endl;
    return 0;
}

ThoiGian::ThoiGian():gio(0),phut(0)
{
  
}

ThoiGian::ThoiGian(int g, int p):gio(g),phut(p)
{
    gio = g;
    phut = p;
    chuanhoa();
}

void ThoiGian::chuanhoa()
{
    gio += phut/60;
    phut %= 60;
    gio %= 24;
}

ThoiGian ThoiGian::operator+(int p)
{
    ThoiGian kq=*this;
    kq.phut+=p;
    kq.chuanhoa();
    return kq;
}

istream& operator>>(istream &cin, ThoiGian &h)
{
    cout<<"(dang h:mm): ";
    cin>>h.gio>>h.phut;
    h.chuanhoa();

    return cin;
}

ostream& operator<<(ostream &cout, ThoiGian &h)
{
    cout<<"("<<h.gio<<"h"<<h.phut<<")";

    return cout;
}
