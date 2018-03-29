#include <iostream>
#include <fstream>
#include <math.h>

int NoD[10000001];

void sieve(int lmt)
{
	for (int i = 2; i <= lmt; i++)
	{
		for (int j = i; j <= lmt; j += i)
			NoD[j]++;
	}
}

int main()
{
	std::ifstream ipfl;
	ipfl.open("input.txt");
	int k;
	ipfl >> k;
	ipfl.close();

	sieve(k);

	int maxIndex = 0;
	for (int d = 2; d <= k; d++)
	{
		if (NoD[d] > NoD[maxIndex])
			maxIndex = d;
	}

	std::ofstream opfl;
	opfl.open("output.txt");
	opfl << k - maxIndex + 1;
	opfl.close();
	return 0;
}