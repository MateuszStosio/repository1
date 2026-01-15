#include"Funkcja.h"
#include<iostream>
#include<math.h>
using namespace std;

funkcja::funkcja(){}
double funkcja::integrate() const {
    int N=1000;
    //double h = (b - a) / N;
    double sum = 0.0;
    for (int i = 0; i < N; i++) {
        //sum += calculate(a + i * h);
        sum += this->calculate(1.0/N * i); 
    }
    return sum / N;
}


iloczyn::iloczyn(const funkcja& a, const funkcja& b) {
    f1 = a.clone(); //jprld
    f2 = b.clone(); //parabole
}

double iloczyn::calculate(double xi) const {
    return f1->calculate(xi) * f2->calculate(xi);
}

iloczyn* iloczyn::clone() const {
    
    return new iloczyn(*f1, *f2);
}

iloczyn::~iloczyn(){
delete f1;
delete f2;
}
iloczyn funkcja::operator*(const funkcja& a) const{
    return iloczyn(a, *this);
}
    





void funkcja::dft(int n) const{
    for( int i=0; i<n; i++){
        CosFunc c(i);
        SinFunc s(i);

        //iloczyn ic(*this, c); 
        //iloczyn is(*this, s);
    
        //double an = 2*is.integrate();
        //double bn = 2*ic.integrate();
        double an= 2*(s * *this).integrate();
        double bn= 2*(c * *this).integrate();


        printf( "%i %.3f %3f\n" , i , an , bn ) ;
         //cout<<"bn: "<<bn<<" dla n równego="<<i<<endl;
         //cout<<"an: "<<an<<" dla n równego="<<i<<endl;



    }
}













StepFunc::StepFunc(){};

double StepFunc:: calculate(double xs)const {
    if(xs>0.5){
        return 1;
    } else{
        return -1;
    }
}

StepFunc* StepFunc::clone() const{
    return new StepFunc(*this);
};







SinFunc::SinFunc(double n_val){
    n=n_val;
}

double SinFunc::calculate(double xi) const {
    return std::sin(2*M_PI*n * xi);
}

SinFunc* SinFunc::clone() const{
    return new SinFunc(*this);
}




CosFunc::CosFunc(double n_val){
    n=n_val;
}

double CosFunc::calculate(double xi) const {
    return std::cos(2*M_PI*n * xi);
}

CosFunc* CosFunc::clone() const {
    return new CosFunc(*this);
}
funkcja::~funkcja() {}