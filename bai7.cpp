/*Một nhân sự nói chung có họ tên và ngày sinh. Nhân viên trong một công ty là một loại 
nhân sự nhưng có thêm mã nhân viên và hệ số lương. Cán bộ quản lý trong công ty là 
một loại nhân viên nhưng có thêm chức vụ và hệ số phụ cấp chức vụ. Nhập vào thông 
tin của n cán bộ quản lý trong công ty. Đưa ra thông tin của các cán bộ quản lý đã nhập. 
Tìm cán bộ quản lý có lương cao nhất. Lương của cán bộ quản lý được tính theo công 
thức: (hệ số lương + hệ số phụ cấp chức vụ) * 1800. */

#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;
class NhanSu
{
    private:
        char hoTen[35];
        int ngaySinh;

    public:
        void nhapNS();
        void xuatNS();

};

class NhanVien:public NhanSu
{
    protected:
        char maNV[10];
        float heSoLuong;

    public:
        void nhapNV();
        void xuatNV();
    
};

class CanBoQuanLy:public NhanVien
{
    private:
        char chucVu[35];
        float heSoPhuCap;
    
    public:
        void nhapCB();
        void xuatCB();
        float tinhLuongCB();
};

int main()
{
    //Tao doi tuong
    NhanSu NS;
    NhanVien NV;
    CanBoQuanLy CBQL;

    //Khai bao bien
    int n;

    cout<<"\nCHUONG TRINH TIM CAM BO CO LUONG CAO NHAT";
    cout<<"\nNhap n danh sach can bo: ";
    cin>>n;

    //Tao mang dong
    CanBoQuanLy *CB = new CanBoQuanLy[n];

    //Nhap thong tin
    for(int i=0; i<n; i++)
    {
        cout<<"\n\nNhap can bo thu "<<i + 1;
        cout<<"\n";
        CB[i].nhapCB();
    }

    //Dua ra man hinh
    cout<<"\n\nDANH SACH CAN BO";
    for(int i=0; i<n; i++)
    {
        cout<<"\nCan bo thu "<<i + 1<<"\n";
        CB[i].xuatCB();
        cout<<"\nLuong phu cap: ";
        CB[i].tinhLuongCB();
    }

    cout<<endl;
    return 0;
}
void NhanSu::nhapNS()
{
    cout<<"Nhap ho ten: ";
    cin>>hoTen;
    cout<<"Nhap ngay sinh(mm/dd/yyy): ";
    cin>>ngaySinh;
}

void NhanSu::xuatNS()
{
    cout<<"\nHo ten: "<<hoTen;
    cout<<"\nNgay sinh: "<<ngaySinh;
}

void NhanVien::nhapNV()
{
    NhanSu::nhapNS();

    cout<<"Nhap ma nhan vien: ";
    cin>>maNV;
    cout<<"Nhap he so luong: ";
    cin>>heSoLuong;
}
void NhanVien::xuatNV()
{
    NhanSu::xuatNS();

    cout<<"\nMa nhan vien: "<<maNV;
    cout<<"\nHe so luong: "<<heSoLuong;
}

void CanBoQuanLy::nhapCB()
{
    NhanVien::nhapNV();

    cout<<"Nhap chuc vu: ";
    cin>>chucVu;
    cout<<"Nhap he so phu cap: ";
    cin>>heSoPhuCap;
}

void CanBoQuanLy::xuatCB()
{
    NhanVien::xuatNV();
    cout<<"\nChuc vu: "<<chucVu;
    cout<<"\nHe so phu cap: "<<heSoPhuCap;
}

float CanBoQuanLy::tinhLuongCB()
{
    return (heSoLuong + heSoPhuCap) * 1800;
}
