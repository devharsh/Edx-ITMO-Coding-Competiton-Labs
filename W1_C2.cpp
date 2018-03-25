#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream ipfl;
	ofstream opfl;

	ipfl.open("input.txt");
	opfl.open("output.txt");

	long long a, b;

	ipfl >> a >> b;
	opfl << a + (b * b);

	ipfl.close();
	opfl.close();

	return 0;
}