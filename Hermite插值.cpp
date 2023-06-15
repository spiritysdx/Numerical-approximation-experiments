#include<iostream>
#include<stdio.h>
#include<math.h>
#include<cmath>
using namespace std;
//显示中文
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>//用于函数SetConsoleOutputCP(65001);更改cmd编码为utf8 


float X[10] = {0.10,0.15,0.30,0.45,0.55,0.60,0.70,0.85,0.90,1.00};

float Y[10] = {0.904837,0.860708,0.740818,0.637628,0.576950,0.548812,0.496585,0.427415,0.406570,0.367879};

float YY[10] = {-0.904837,-0.860708,-0.740818,-0.637628,-0.576950,-0.548812,-0.496585,-0.427415,-0.406570,-0.367879};

//#define f(x) e^(-x);
float f(float x) 
{
    return exp(-x);
}

float Hermite(float *x, float  *y, float  *dy, int n, float t)
{
    float result[10];
    for(int i = 0;i<n;i++)
    {
        float h = 1.0;
        float a = 0.0;
        for(int j = 0;j<n;j++)
        {
            if(j!=i)
            {
                h = h*(pow(t-x[j],2))/(pow(x[i]-x[j],2));
                a = a + 1/(x[i]-x[j]);
            }
        }
        result[i] = h*((x[i]-t)*(2*a*y[i]-dy[i])+y[i]);
    }
    float r = 0;
    for(int k = 0;k<n;k++)
    {
        r = r + result[k];
    }
    return r;
}


int main()
{
    //显示中文
    SetConsoleOutputCP(65001);
    float t = 0.356;
    cout<<"近似值为"<<Hermite(X, Y, YY, 10, t)<<endl;
    cout<<"实际值为"<<f(t)<<endl;
    system("pause");
    return 0;
}