#include <cstdio>
#pragma warning(disable:4996)

int NoD[10000002];

int main()
{
	FILE* inf = fopen("input.txt", "rt");
	int k;
	fscanf(inf, "%d", &k);

	int maxIndex = 0;
	for (int i = 2; i <= k; i++)
	{
		for (int j = i; j <= k; j += i)
			NoD[j]++;
		if (NoD[i] > NoD[maxIndex])
			maxIndex = i;
	}

	FILE* ouf = fopen("output.txt", "wt");
	fprintf(ouf, "%d", k - maxIndex + 1);

	return 0;
}