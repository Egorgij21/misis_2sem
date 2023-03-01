#include "rational/rational.h"

#include <iostream>


inline std::ostream& operator<<(std::ostream& ostrm, const Rational& temp) {
	return temp.writeTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Rational& temp) {
	return temp.readFrom(istrm);
}



void tests(Rational a, Rational b) {
    std::cout << '\n' << "Теcты ниже" << '\n' << '\n';
    std::cout << a << " + " << b << " -> " << a + b << std::endl;
    std::cout << a << " - " << b << " -> " << a - b << std::endl;
    std::cout << a << " * " << b << " -> " << a * b << std::endl;
    std::cout << a << " / " << b << " -> " << a / b << std::endl;


    std::cout << a << " < " << b << " -> " << (a < b) << std::endl;
    std::cout << a << " = " << b << " -> " << (a == b) << std::endl;
    std::cout << a << " > " << b << " -> " << (a > b) << std::endl;


    std::cout << a << " -> " << " x++ " << " -> " << a++ << " -> " << a << std::endl;
    std::cout << a << " -> " << " ++x " << " -> " << ++a << std::endl << '\n';
}

void default_test() {
    Rational a(2, 5), b(1, 7);
    tests(a, b);
}

void personal_test() {
    Rational a, b;
    std::cout << "Формат ввода рационального числа: num / denum" << '\n' << "Ведите первое рациональное число: " << '\n';
    std::cin >> a;
    std::cout << "Ведите второе рациональное число: " << '\n';
    std::cin >> b;
    tests(a, b);
}

int main() {
    std::cout << "Чтобы запустить обычный тест - введите 1;" << '\n' << "Чтобы запустить свой тест - введите 2:" << '\n';
    int flag = 0;
    std::cin >> flag;
    if (flag == 1) {
        default_test();
    }
    else if (flag == 2) {
        personal_test();
    }
    else {
        std::cout << "Вы ввели некорректное значение" << '\n';
    }
    return 0;
}