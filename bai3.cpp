/*
Cho tệp văn bản “hinhtru.txt” chứa bán kính r và chiều cao h của n hình trụ. Tính tổng
diện tích toàn phần của n hình trụ. Đưa ra màn hình diện tích của từng hình trụ và tổng
diện tích của n hình trụ. Biết rằng hình trụ là một loại hình tròn có bán kính r được kéo
dài với chiều cao h. Yêu cầu sử dụng mảng động chứa n hình trụ, các hình trụ được tự
động khởi tạo bán kính và chiều cao bằng 0. 
*/

#include<iostream>
#include<stdio.h>
#include<fstream>
#include<math.h>
#define PI 3.14

using namespace std;
class HinhTru
{
    private:
        float r, h;

    public:
        HinhTru();
        HinhTru(float banKinh, float chieuCao);
        float tongDT();
        void duaRaMH();
};


int main(){
    HinhTru h;
    int n;
    float tong = 0;

    ifstream fin("hinhtru.txt");
    
    //Doc hinh tru tu tep
    fin>>n;
    
    //Mang dong
    HinhTru *ht = new HinhTru[n];

    for(int i=0; i<n; i++)
    {
        float r, h;
        fin>>r>>h;
        ht[i]=HinhTru(r,h);
    }

    //Dua ra mh va tong tp
    cout<<"\nTong dien tich toan phan hinh tru: \n";
    for(int i = 0; i<n; i++)
    {
        ht[i].duaRaMH();
        tong += ht[i].tongDT();
    }
    
    cout<<endl;
    return 0;
}
HinhTru::HinhTru():r(0), h(0)
{

}

HinhTru::HinhTru(float banKinh, float chieuCao):r(banKinh),h(chieuCao)
{

}

float HinhTru::tongDT()
{
    return 2 * PI * r * (r + h);
}

void HinhTru::duaRaMH()
{
    cout<<"\nHinh tru co ban kinh r="<<r<<" va chieu cao h="<<h<<"co dien tich la: "<<tongDT();
}
