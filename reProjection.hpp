#pragma once

void transform(const double Pw[], double Pc[], const double R[][3], const double t[]);

void check_error(const double Pc[]);

void calculate(double& Xcal, double& Ycal, const double Pc[], const double fx, const double fy, const double cx, const double cy);

void distance_error(const double Xcal,const double Ycal,const double Xreal,const double Yreal,double& d_error);