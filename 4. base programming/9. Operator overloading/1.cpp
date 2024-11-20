#include <iostream>

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

	bool operator==(Fraction &l) {
		return (numerator_ * l.denominator_ == denominator_ * l.numerator_);
	}
	bool operator!=(Fraction& l) {
		return !(*this == l);
	}
	bool operator>(Fraction& l) {
		return (numerator_ * l.denominator_ > denominator_* l.numerator_);
	}
	bool operator>=(Fraction& l) {
		return ((*this > l) || (*this == l));
	}
	bool operator<(Fraction& l) {
		return !(*this > l);
	}
	bool operator<=(Fraction& l) {
		return (!(*this > l) || (*this == l));
	}
};

int main()
{
	Fraction f1(4, 3);
	Fraction f2(6, 11);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}