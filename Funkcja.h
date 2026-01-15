#ifndef CPP_LAB_FOURIER
#define CPP_LAB_FOURIER
 
class iloczyn;

class funkcja {
public:
funkcja();
//double integrate(double a, double b);
double integrate() const;

void dft(int n) const;
iloczyn operator*(const funkcja& a) const;
virtual double calculate(double xi) const=0;
virtual funkcja *clone() const=0;
virtual ~funkcja();

};
class iloczyn:public funkcja{
    funkcja *f1;
    funkcja *f2;
    public:
    iloczyn(const funkcja& a, const funkcja& b);
    ~iloczyn();
    double calculate(double xi) const;
    iloczyn *clone() const ; 


};

class StepFunc: public funkcja{
    public:


    StepFunc();
    double calculate(double xi) const;    
    StepFunc *clone() const;

};
 
class SinFunc: public funkcja{
public:
double n;


SinFunc(double n);
double calculate(double xi) const;
SinFunc *clone() const;


};




class CosFunc: public funkcja{

public:
double n;
CosFunc(double n);
double calculate(double xi) const;
CosFunc *clone() const;
};


#endif