/*Cho tệp văn bản “matran.txt” chứa ma trận số thực Amxn. Đọc vào ma trận A từ tệp. 
Tính trung bình cộng các phần tử của ma trận A. Nhân ma trận A với một số thực x nhập 
vào từ bàn phím để được ma trận B (B = A*x). Đưa ma trận A và B ra màn hình theo 
định dạng hàng, cột. Yêu cầu sử dụng toán tử nhập >> để đọc vào ma trận từ tệp; sử 
dụng toán tử xuất << để đưa ma trận ra màn hình theo định dạng hàng, cột; sử dụng toán 
tử nhân * để nhân ma trận với một số; ma trận được tự động khởi tạo kích thước m, n 
bằng 0. */

#include<iostream>
#include<fstream>
#include<stdio.h>
#include<math.h>

using namespace std;
class MaTran
{
    private:
        enum {size=10};
        int a[size][size];
        int m, n;

    public:
        MaTran();
        MaTran operator*(int x);
        int tinhTBC();

        //Ham ban
        friend istream& operator>>(istream &fin, MaTran &mt);
        friend ostream& operator<<(ostream &cout, MaTran &mt);
};
int main()
{
    //Tao 3 doi truong ma tran
    MaTran A, B;
    int x;

    //Tao odoi tuong tep doc vao
    ifstream fin("matran.txt");

    //Doc ma tran A vao doi tuong A tuong ung
    fin>>A;

    //Nhap x
    cout<<"CHUONG TRINH NHAN 2 MA TRAN NGUYEN: Cmxn = Amxn + Bmxn\n\n";
    cout<<"\nMa tran A: \n"<<A;

    int tbc = A.tinhTBC();

    cout<<"\nTong TBC ma tran A la: "<<tbc;
    cout<<"\nNhap so thuc x: ";
    cin>>x;

    //Cong thuc tinh ma tran B
    B = A * x;

    //Dua ma tran ra ma hinh
    cout<<"\nMa tran B=A*x: \n"<<B;

    cout<<endl;
    return 0;
}
MaTran::MaTran():m(0),n(0)
{

}

MaTran MaTran::operator*(int x)
{
    //Tao dioi tuong de chua ma tran nhan
    MaTran nhan;
    nhan.m=m;
    nhan.n=n;
    for(int i=0; i<m;i++)
        for(int j=0; j<n; j++)
            nhan.a[i][j] = a[i][j] * x;

    //Tra ve nhan
    return nhan;
}

int MaTran::tinhTBC()
{
    int tong = 0;
    for(int i=0; i<m;i++)
        for(int j=0; j<n; j++)
            tong += a[i][i];
    
    return tong/(m*m);
}

//Ham ban
istream& operator>>(istream &fin, MaTran &mt)
{
    //Doc tkich thuoc ma tran tu tep
    fin>>mt.m>>mt.n;

    //Doc cac ma tran tu tep
    for(int i=0; i<mt.m;i++)
        for(int j=0; j<mt.n; j++)
            fin>>mt.a[i][j];

    return fin;

}

ostream& operator<<(ostream &cout, MaTran &mt)
{
    for(int i=0; i<mt.m;i++)
    {
        //Dua ra hang i
        for(int j=0; j<mt.n; j++)
        printf("%6d", mt.a[i][j]);

        //Xuong dong
        cout<<endl;
    }

    //Tra ve ket qua
    return cout;
}
