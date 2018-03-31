#include <iostream>
#include <fstream>

int NoD[10000001];

int main()
{
	std::ifstream ipfl;
	ipfl.open("input.txt");
	int k;
	ipfl >> k;
	ipfl.close();

	int maxIndex = 0;
	for (int i = 2; i <= k; i++)
	{
		for (int j = i; j <= k; j += i)
			NoD[j]++;
		if (NoD[i] > NoD[maxIndex])
			maxIndex = i;
	}

	std::ofstream opfl;
	opfl.open("output.txt");
	opfl << k - maxIndex + 1;
	opfl.close();
	return 0;
}