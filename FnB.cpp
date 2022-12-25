#include <iostream>
#include <cmath>
#include <math.h>
#include <stdio.h>
#include <iomanip>
using namespace std;

int main(){
    setlocale(LC_ALL, "Russian");
    int z;
    cout << "Что решать?" << endl << "1. Прямая" << endl << "2. Обрятная" << endl;
    cout << ":";
    cin >> z;
    if (z == 1) {
        double cos(double x), sqrt(double x), pow(double x, double y);
        double dx, dy, xn, yn, s, az, xk, yk, grad, min, sec, controlll;
        cout << "Введите координаты начальной точки" << endl;
        cout << "Xn = ";
        cin >> xn;
        cout << "Yn = ";
        cin >> yn;
        cout << "Введите расстояние S: ";
        cin >> s;
        cout << "Введите угол α" << endl;
        cout << "Grad: "; cin >> grad;  
        cout << "Min: "; cin >> min;
        cout << "Sec: "; cin >> sec;
        az = (grad+(min/60)+(sec/3600))*(3.14159265359/180);
        

        dx = s*cos(az);
        cout << "dx= " << setprecision(12) << dx  << "(округлить до 6)" << endl;

        dy = s*sin(az);
        cout << "dy= " << setprecision(12) << dy << "(округлить до 6)" << endl;


        xk = xn+dx;
        cout << "Xk= " << setprecision(12) << xk << "(округлить до 2-3)" << endl;
        yk = yn+dy;
        cout << "Yk= " << setprecision(12) << yk << "(округлить до 2-3)" << endl;


        cout << "КОНТРОЛЬ" << endl;
        controlll = sqrt((pow(dx, 2))+(pow(dy, 2)));
        cout << "S= " << setprecision(8) << controlll;
    }
    if (z == 2) {
        double atan(double x), cos(double x), sqrt(double x), pow(double x, double y), sin(double x);
        double dx, dy, xn, yn, s, az, rrad, rgrad, grad, tgr, xk, yk, min, sec, controlll, controlll2, controlll3;
        cout << "Введите координаты точек\n";
        cout << "Xn= "; cin >> xn;
        cout << "Xk= "; cin >> xk;
        cout << "Yn= "; cin >> yn;
        cout << "Yk= "; cin >> yk;
        dx = xk - xn;
        dy = yk - yn;
        cout << "dx= " << setprecision(10) << dx << endl;
        cout << "dy= " << setprecision(10) << dy << endl;
        tgr = dy/dx;
        cout << "tgr= " << setprecision(13) << tgr << endl;
        rrad = atan(tgr);
        grad=rrad*180/M_PI;
        min=(grad-int(grad))*60;
        sec=(min-int(min))*60;
        cout << "r= " << int(grad) << "°" << int(min) << "'" << sec << '"' << "(Секунды округлить)" << endl;
        if (dx>0 && dy>0){
            cout << "α = r" << " | " << int(grad) << "°" << int(min) << "'" << sec << '"' << "(Секунды округлить)" << endl;
        }
        if (dx<0 && dy>0){ 
            az=M_PI-fabs(rrad);
            grad=az*180/M_PI;
            min=(grad-int(grad))*60;
            sec=(min-int(min))*60;
            cout << "α = 180° - r | " << int(grad) << "°" << int(min) << "'" << sec << '"' << "(Секунды округлить)" << endl;
        }
        if (dx<0 && dy<0) {
            az=M_PI+fabs(rrad);
            grad=az*180/M_PI;
            min=(grad-int(grad))*60;
            sec=(min-int(min))*60;
            cout << "α = 180° + r | " << int(grad) << "°" << int(min) << "'" << sec << '"' << "(Секунды округлить)" << endl;
        }
        if(dx>0 && dy<0){
            az=2*M_PI-fabs(rrad);
            grad=az*180/M_PI;
            min=(grad-int(grad))*60;
            sec=(min-int(min))*60;
            cout << "α = 360° - r | " << int(grad) << "°" << int(min) << "'" << sec << '"' << "(Секунды округлить)" << endl;
        }
        //ОКОНЧАТЕЛЬНЫЙ КОНТРОЛЬ
        controlll = sqrt((pow(dx, 2))+(pow(dy, 2))); //10. S
        cout << "S= " << setprecision(8) << controlll << endl;

        controlll2 = cos(rrad);
        cout << "cos r= " << controlll2 << endl;
        cout << "S= " << dx/controlll2 <<endl;

        controlll3 = sin(rrad);
        cout << "sin r= " << controlll3 << endl;
        cout << "S= " << dy/controlll3 << endl;

    }
}