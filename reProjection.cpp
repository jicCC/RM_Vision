#include "reProjection.hpp"
#include <iostream>
#include <math.h>

using namespace std;

void transform(const double Pw[], double Pc[], const double R[][3], const double t[])
{   
    for(int i=0 ; i<=2 ; i++)
    {
        Pc[i] = 0;
        for(int j=0 ; j<=2 ; j++)
        {
            Pc[i] += Pw[j] * R[i][j];
        }
        Pc[i] += t[i];
    }
}

void check_error(const double Pc[])
{
    if(Pc[2] <= 0)
        throw runtime_error("非正深度异常！");
}

void calculate(double& Xcal, double& Ycal, const double Pc[], const double fx, const double fy, const double cx, const double cy)
{
    Xcal = fx * Pc[0] / Pc[2] + cx;
    Ycal = fy * Pc[1] / Pc[2] + cy;
}

void distance_error(const double Xcal,const double Ycal,const double Xreal,const double Yreal,double& d_error)
{
    d_error = sqrt((Xreal - Xcal) * (Xreal - Xcal) + (Yreal - Ycal) * (Yreal - Ycal));
}