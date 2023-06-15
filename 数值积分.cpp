//显示中文
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>//用于函数SetConsoleOutputCP(65001);更改cmd编码为utf8 
#include<iostream>
#include<stdio.h>
#include<math.h>
#define f(x) 4.0/(1+(x)*(x)) 
using namespace std;
 

//数值积分   复化梯形公式和复化Simpson公式
void test02()
{
    float h = (1.0-0)/4,temp,xk,yk,xkh,ykh,xk1,yk1;
    int i;
    temp = f(0);
    xk = 0;
    for(i=1;i<4;i++)
    {
        xk = xk + h;
        temp = temp + 2*f(xk);
    }
    temp = temp + f(1);
    temp = temp*h/2;      //简化公式
    printf("\n复化梯形公式计算的结果：%f",temp);
    cout<<endl;

    temp = 0;
    h = (1.0-0)/2;  //复化Simpson公式分两个区间
    xk = 0;
    yk = f(0);
    for(i<0;i<2;i++)
    {
        //xkh————x[k+1/2]
        xkh = xk + h/2;
        ykh = f(xkh);
        //xkl————x[k+1]
        xk1 = xk + h;
        yk1 = f(xk1);
        //加上每个小区间上的面积
        temp = temp + h*(yk+4*ykh+yk1)/6;
        //右端点是下一个小区间的左端点
        xk = xk1;
        yk = yk1;
    }
    cout<<"复化Simpson公式计算的结果："<<temp<<endl;
} 



int main()
{
    //显示中文
    SetConsoleOutputCP(65001);


    test02();


    system("pause");
    return 0;
}
