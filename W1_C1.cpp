#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream ipfl;
	ofstream opfl;

	ipfl.open("input.txt");
	opfl.open("output.txt");

	int a, b;

	ipfl >> a >> b;
	opfl << a + b << "\n";
	
	ipfl.close();
	opfl.close();

	return 0;
}