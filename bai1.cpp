/*
Cho tệp văn bản ‘sophuc.txt’ chứa phần thực và phần ảo của n số phức. Tính tổng của
n số phức. Đưa các số phức ra màn hình ở dạng a + jb. Yêu cầu sử dụng toán tử xuất <<
để đưa số phức ra màn hình; sử dụng toán tử + để cộng hai số phức; số phức được tự
động khởi tạo phần thực và phần ảo bằng 0; sử dụng mảng động để chứa n số phức. 
*/

#include<iostream>
#include<stdio.h>
#include<fstream>

using namespace std;
class SoPhuc
{
    private:
        float thuc, ao;

    public:
        SoPhuc();
        SoPhuc(float t, float a);
        SoPhuc operator+(SoPhuc &p2);

        //Ham ban
        friend ostream& operator<<(ostream &cout, SoPhuc &p);
};
int main(){
    SoPhuc tong;
    int n;

    ifstream fin("sophuc.txt");

    //Doc so phuc tu tep
    fin>>n;

    //Mang dong
    SoPhuc *sp = new SoPhuc[n];

    for (int i = 0; i < n; i++) {
        float t, a;
        fin >> t >> a;
        sp[i] = SoPhuc(t, a);
    }

    cout<<"Cac so phuc duoc doc tu tep: \n";
    for(int i=0; i<n;i++){
        cout<<"So phuc thu: "<<i+1<<": "<<sp[i]<<endl;
        tong = tong + sp[i];
    }
    cout<<"\nTong cac so phuc: "<<tong;

    cout<<endl;
    return 0;
}

SoPhuc::SoPhuc():thuc(0),ao(0)
{

}

SoPhuc::SoPhuc(float t, float a):thuc(t),ao(a)
{

}

SoPhuc SoPhuc::operator+(SoPhuc &p2)
{
    SoPhuc tg;

    tg.thuc = thuc + p2.thuc;
    tg.ao = ao + p2.ao;

    return tg;
}

//Ham ban
ostream& operator<<(ostream &cout, SoPhuc &p)
{
    cout<<p.thuc;

    if(p.ao>=0)
        cout<<" + j"<<p.ao;
    else
        cout<<" - j"<<-p.ao;

    return cout;
}
