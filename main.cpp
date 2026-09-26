//这是新的分支 first_homework中的改动


#include <iostream>
#include <math.h>
#include "reProjection.hpp"

using namespace std;

int main()
{
    //输入三维坐标点Pw，相机内参fx,fy,cx,cy，外参R,t,真实观测点
    double Pw[3];
    cout << "请输入三维坐标点(x,y,z),中间用空格隔开:" << endl;
    cin >> Pw[0] >> Pw[1] >> Pw[2];

    double fx,fy,cx,cy;
    cout << "请输入相机内参fx,fy,cx,cy,中间用空格隔开：" << endl;
    cin >> fx >> fy >> cx >> cy;

    double R[3][3];
    double t[3];
    cout << "请输入旋转矩阵:" << endl << "{R11} {R12} {R13}" << endl;
    cout << "{R21} {R22} {R23}" << endl << "{R31} {R32} {R33}" << endl;
    for(int i=0 ; i<=2; i++)
    {
        for(int j=0 ; j<=2; j++)
        {
            cout << "R" << i+1 << j+1 << ":";
            cin >> R[i][j];
        }
    }

    cout << "请输入平移向量(tx,ty,tz),中间用空格隔开:" << endl;
    cin >> t[0] >> t[1] >> t[2];

    double Xreal,Yreal;
    cout << "请输入真实观测点(Xreal,Yreal),中间用空格隔开:" << endl; 
    cin >> Xreal >> Yreal;

    //由世界观到相机的变换
    double Pc[3] = {0};
    transform(Pw,Pc,R,t);
    
    double Xcal,Ycal,d_error;
    try
    {
        //处理非正深度异常
        check_error(Pc);

        //计算预测二维坐标点
        calculate(Xcal,Ycal,Pc,fx,fy,cx,cy);
        cout << "计算得到的坐标为:(" << Xcal << "," << Ycal << ")" << endl;

        //计算像素欧式距离
        
        distance_error(Xcal,Ycal,Xreal,Yreal,d_error);
        cout << "像素欧式距离为:" << d_error << endl;
    }
    catch(runtime_error& e)
    {
        cout << e.what() << endl;
    }
    return 0;          
}