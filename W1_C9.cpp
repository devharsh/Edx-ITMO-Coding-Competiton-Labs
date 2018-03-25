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
	float used[15];
	float unused[15];
	int uc = 0, uuc = 0;

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		sum += nary[i];
		if (sum <= 300)
		{
			count++;
			used[uc] = nary[i];
			uc++;
		}
		else
		{
			sum -= nary[i];
			unused[uuc] = nary[i];
			uuc++;
		}
	}

	int count2 = count;
	for (int i = 0; i < uc; i++)
	{
		sum -= used[i];
		count2--;
		for (int j = 0; j < uuc; j++)
		{
			sum += unused[j];
			if (sum <= 300)
				count2++;
			else
				sum -= unused[j];
		}
	}

	count = count > count2 ? count : count2;
	std::ofstream opfl;
	opfl.open("output.txt");
	opfl << count;
	opfl.close();

	return 0;
}