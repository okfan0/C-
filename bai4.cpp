/*
Cho tệp văn bản “phanso1.txt” và “phanso2.txt”, mỗi tệp có một dòng chứa phân số ở
dạng a/b. Tính tổng hai phân số đọc vào từ tệp. Đưa các phân số ra màn hình ở dạng rút
gọn và chưa rút gọn. Yêu cầu sử dụng toán tử nhập >> để đọc vào phân số từ tệp; sử
dụng toán tử xuất << để đưa phân số ra màn hình ở dạng a/b; sử dụng toán tử + để cộng
hai phân số; phân số được tự động khởi tạo tử số bằng 0 và mẫu số bằng 1 hoặc được
khởi tạo tử số và mẫu số bằng giá trị cho trước. 
*/

#include<iostream>
#include<stdio.h>
#include<fstream>
#include<math.h>

using namespace std;
class PhanSo
{
    private:
        int tu, mau;

    public:
        PhanSo();
        PhanSo(int t, int m);
        PhanSo operator+(const PhanSo &p);

        //ham ban
        friend istream& operator>>(istream &cin, PhanSo &p);
        friend ostream& operator<<(ostream &cout, PhanSo &p);
};
int main()
{
    PhanSo a, b;

    
    ifstream finA("phanso1.txt");
    ifstream finB("phanso2.txt");

    finA>>a;
    finB>>b;

    cout<<"\nPhan so thu hai: "<<a;
    cout<<"\nPhan so thu nhat: "<<b;

    PhanSo tong = a + b;

    cout<<"\nPhan so ch rut gon: "<<tong;
    cout<<"\nPhan so rut gon: "<<tong;

    return 0;
    cout<<endl;
}
PhanSo::PhanSo():tu(0),mau(1)
{

}

PhanSo::PhanSo(int t, int m):tu(t),mau(m==0 ? 1:m)
{

}
PhanSo PhanSo::operator+(const PhanSo &p)
{
    int tunew = tu * p.mau + p.tu * mau;
    int maunew = mau * p.mau;

    return PhanSo(tunew, maunew);
}

//ham ban
istream& operator>>(istream &cin, PhanSo &p)
{
    cin>>p.tu>>p.mau;
    if(p.mau==0) p.mau = 1;
    return cin;
}

ostream& operator<<(ostream &cout, PhanSo &p)
{
    cout<<"("<<p.tu<<"/"<<p.mau<<")";
    return cout;
}
        