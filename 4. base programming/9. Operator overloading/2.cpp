#include <iostream>
#include <string>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
	int gcd(int a, int b) {
		while (b > 0) {
			int c = a % b;
			a = b;
			b = c;
		}
		return a;
	}
	void reduce(int& n, int& d) {
		int gcd1 = gcd(abs(n), d);
		if (gcd1 != 1) {
			n = n / gcd1;
			d = d / gcd1;
		}
	}

	std::string toString() const {
		std::string n = std::to_string(numerator_);
		std::string d = std::to_string(denominator_);
		return (n + "/" + d);
	}

	friend std::ostream& operator<<(std::ostream& s, const Fraction& f);
	
	Fraction operator+(Fraction l) {
		int numerator = (numerator_ * l.denominator_) + (l.numerator_ * denominator_);
		int denominator = denominator_ * l.denominator_;
		reduce(numerator, denominator);
		return Fraction(numerator, denominator);
	}
	Fraction operator-(Fraction l) {
		int numerator = (numerator_ * l.denominator_) - (l.numerator_ * denominator_);
		int denominator = denominator_ * l.denominator_;
		reduce(numerator, denominator);
		return Fraction(numerator, denominator);
	}
	Fraction operator*(Fraction l) {
		int numerator = numerator_ * l.numerator_;
		int denominator = denominator_ * l.denominator_;
		reduce(numerator, denominator);
		return Fraction(numerator, denominator);
	}
	Fraction operator/(Fraction l) {
		int numerator = numerator_ * l.denominator_;
		int denominator = denominator_ * l.numerator_;
		reduce(numerator, denominator);
		return Fraction(numerator, denominator);
	}
	Fraction operator++(int) {
		Fraction temp = *this;
		++(*this);
		return temp;
	}
	Fraction operator--(int) {
		Fraction temp = *this;
		--(*this);
		return temp;
	}
	friend Fraction& operator++(Fraction&);
	friend Fraction& operator--(Fraction&);
};

	std::ostream& operator<<(std::ostream& s, const Fraction& f) {
		s << f.toString();
		return s;
	}
	Fraction& operator++(Fraction& f) {
		f.numerator_++;
		return f;
	}
	Fraction& operator--(Fraction& f) {
		f.numerator_--;
		return f;
	}

int main()
{
	int n1, d1, n2, d2;
	std::cout << "enter the numerator of the fraction 1: ";
	std::cin >> n1;
	std::cout << "enter the denominator of the fraction 1: ";
	std::cin >> d1;
	std::cout << "enter the numerator of the fraction 2: ";
	std::cin >> n2;
	std::cout << "enter the denominator of the fraction 2: ";
	std::cin >> d2;
	Fraction f(n1, d1);
	Fraction f1(n2, d2); 
	std::cout << f.toString() <<  " + " << f1.toString() << " = " << f + f1 << std::endl;
	std::cout << f.toString() << " - " << f1.toString() << " = " << f - f1 << std::endl;
	std::cout << f.toString() << " * " << f1.toString() << " = " << f * f1 << std::endl;
	std::cout << f.toString() << " / " << f1.toString() << " = " << f / f1 << std::endl;
	std::cout << f.toString() << "++ * " << f1.toString() << "++ = ";
	std::cout<< f++ * f1++ << std::endl;
	std::cout << "Fraction 1: " << f << std::endl;
	std::cout << "Fraction 2: " << f1 << std::endl;
	std::cout << "--" << f.toString() << " * " << "--" << f1.toString() << " = ";
	std::cout<< --f * --f1 << std::endl;
	std::cout << "Fraction 1: " << f << std::endl;
	std::cout << "Fraction 2: " << f1 << std::endl;
}
