#include <iostream>
#include <fstream>
#include <iomanip>

int main()
{
	std::ifstream ipfl;
	ipfl.open("input.txt");
	double a, b, c;
	ipfl >> a >> b >> c;
	ipfl.close();

	std::ofstream opfl;
	opfl.open("output.txt");
	opfl << std::fixed << std::setprecision(16) << (a + b + c) / 6;
	opfl.close();
	return 0;
}