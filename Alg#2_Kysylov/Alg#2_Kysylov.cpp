#include <iostream>
#include <cmath>
#include <chrono>
#include<windows.h>

double taylorSeries(double x, int n) {
    if (n == 0) return 1; // e^0 = 1
    return std::pow(x, n) / std::tgamma(n + 1) + taylorSeries(x, n - 1);
}

double function(double x) {
    return (std::exp(x) + 1 / (x * x - 1)) / std::exp(x);
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "");

    double x;
    int n;
    std::cout << "������ �������� x: ";
    std::cin >> x;
    std::cout << "������ ������� ����� ���� (�������): ";
    std::cin >> n;

    auto start = std::chrono::high_resolution_clock::now();
    double result = taylorSeries(x, n);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;

    std::cout << "��������� (��� �������): " << result << std::endl;
    std::cout << "��������� (�������): " << function(x) << std::endl;
    std::cout << "��� ���������: " << duration.count() << " ������" << std::endl;

    return 0;
}
