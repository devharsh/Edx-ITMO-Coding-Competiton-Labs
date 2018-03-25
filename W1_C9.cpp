#include <iostream>
#include <fstream>

int main()
{
	std::ifstream ipfl;
	ipfl.open("input.txt");

	int n;
	ipfl >> n;

	float nary[15];

	for (int i = 0; i < n; i++)
	{
		ipfl >> nary[i];
		nary[i] /= 60;
	}

	ipfl.close();

	float sum = 0;
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		sum += nary[i];
		if (sum <= 300)
			count++;
		else
			sum -= nary[i];
	}

	std::ofstream opfl;
	opfl.open("output.txt");
	opfl << count;
	opfl.close();

	return 0;
}