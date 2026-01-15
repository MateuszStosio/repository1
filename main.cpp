#include <iostream>
#include "Funkcja.h"

int main(int argc, char* argv[]) {


int t= std::stoi(argv[1]);
int n=std::stoi(argv[2]);
funkcja* f=nullptr;

if(t==0){
    f = new StepFunc();
}
else if (t==1)
{
    f = new CosFunc(1);
}
else if (t==2)
{
    f = new SinFunc(2);
}
f ->dft(n);




//śinus.dft(5);
//sf.dft(5);
std::cout<<"popus napilbym sie piwka"<<std::endl;
    return 0;

}