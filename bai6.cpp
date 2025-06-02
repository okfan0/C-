/* Cho tệp văn bản “diemmonhoc.txt” chứa danh sách điểm môn học của n sinh viên, mỗi 
sinh viên có thông tin về mã sinh viên, tên (không có họ đệm), điểm kiểm tra, điểm thi. 
Điểm môn học được tính bằng 0,3 x Điểm kiểm tra + 0,7 x Điểm thi. Đếm số lượng và 
đưa ra màn hình danh sách các sinh viên chưa đạt (có điểm môn học < 4). Yêu cầu sử 
dụng toán tử nhập >> và toán tử xuất << để nhập vào và đưa ra thông tin của từng sinh 
viên.
*/

#include<iostream>
#include<stdio.h>
#include<math.h>
#include<fstream>

using namespace std;
class SV
{
    private:
        char tenSV[35];
        char maSV[10];
        float diemKT, diemThi;


    public:
        float tinhDiem();
        bool loc();

        //HAm ban
        friend istream& operator>>(istream &cin, SV &sv);
        friend ostream& operator<<(ostream &cout, SV &sv);
};
int main()
{
    //Tao doi tuong sinh  vien
    SV sv;

    //Khai bao bien
    int n;

    //Tao doi tuong de doc tep
    ifstream fin("diemmonhoc.txt");
    fin>>n;

    //Tao mang dong luu tru SV
    SV *SinhVien =new SV[n];

    for(int i=0; i<n; i++)
    {
        cout<<"\nSinh vien thu "<<i+1<<":\n";
        fin>>SinhVien[i];
        cout<<SinhVien[i];
    }

    int dem = 0;
    cout<<"\n\nDanh sach sinh vien chua dat (Diem mon hoc < 4): \n";
    for(int i=0; i<n;i++)
    {
        if(SinhVien[i].loc())
        {
            cout<<"\nSinh vien thu "<<i+1<<":\n";
            cout<<SinhVien[i];
            dem++;
        }
    }

    cout<<"\nTong sinh vien chua dat la: "<<dem<<endl;

    cout<<endl;
    return 0;
}
float SV::tinhDiem()
{
    return diemKT * 0.3 + diemThi * 0.7;
}

bool SV::loc()
{
    return tinhDiem()<4;
}

//Ham ban
istream& operator>>(istream &cin, SV &sv)
{
    cin>>sv.maSV>>sv.tenSV>>sv.diemKT>>sv.diemThi;
    return cin;
}

ostream& operator<<(ostream &cout, SV &sv)
{
    cout<<"\tMa sinh vien: "<<sv.maSV;
    cout<<"\n\tTen sinh vien: "<<sv.tenSV;
    cout<<"\n\tDiem kiem tra: "<<sv.diemKT;
    cout<<"\n\tDiem thi: "<<sv.diemThi;
    cout<<"\n\tDiem mon hoc: "<<sv.tinhDiem();
    return cout;
}
