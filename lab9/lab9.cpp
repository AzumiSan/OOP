/*
*rational number
*/
#include<iostream>
#include<ratio>
using namespace std;
class rational
{
private:
    int numerator;//huvaari
    int denominator;//hurtver
    float hariu;
public:
    void add(int);
    void sub(int);
    void multi(int);
    void div(int);
    setdata();
    getdata();
    void huraah();
};
// butarhai toon deer butarhai too nemeh
rational :: void add(rational b)
{
    int denominator = this.denominator * b.numerator + b.denominator * this.numerator;
    int numerator  = this.numerator * b.numerator;
    huraah();
    return (numerator,denominator);

}

//butarhai toon deer buhel toog nemeh
rational :: void add(int b) {
		int denominator = this.numerator * b + this.denominator;
		int  numerator = this.numerator;
		huraah();
		return (numerator, denominator);
	}
//butarhai toonoos butarhai toog hasah
rational :: sub(int b) {
		int denominator = this.numerator * b - this.denominator;
		int numerator = this.numerator;
        huraah();
		return (hur, huv);
	}

// butarhai toog butarhaig toogoop upjuuleg
rational :: void multi(rational b) {

		int denominator = this.hurtver * b.denominator
		int numerator = this.numerator * b.numerator;
        huraah();
		return (numerator, denominator);

	}
//butarhai toog buhel toogop upjuleh
rational:: multi(int b) {
		int denominator = this.denominator * b;
		int numerator = this.numerator;
		huraah();
		return (numerator, denominator);
	}
//butarhai toog butarhai toond huvaah
rational:: div(int b) {
		int denominator = this.denominator;
		int numerator = this.numerator * b;
		huraah();
		return (denominator,numerator);
	}
//butarhai toog buhel toond huvaah
rational :: div(Rational b) {
		int denominator = this.denominator * b.numerator;
		int numerator = this.numerator * b.denominator;
		huraah();
		return (numerator,denominator);
	}
// emhetgeh
rational :: void huraah() {
		int a = numerator;
		int b = denominator;
		while (a != b) {
			if (a > b)
				a = a - b;
			else
				b = b - a;
		}
		denominator /= a;
		numerator /= a;
	}

}
