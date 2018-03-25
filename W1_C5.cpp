#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>

using namespace std;

double findMax(int smat[3][3], int a, int b, int c);

int main()
{
	ifstream ipfl;
	ofstream opfl;

	ipfl.open("input.txt");
	opfl.open("output.txt");

	int smat[3][3];

	ipfl >> smat[0][0] >> smat[0][1] >> smat[0][2] >> smat[1][0] >> smat[1][1] >> smat[1][2] >> smat[2][0] >> smat[2][1] >> smat[2][2];

	double imax[6];
	imax[0] = findMax(smat, 0, 1, 2);
	imax[1] = findMax(smat, 0, 2, 1);
	imax[2] = findMax(smat, 1, 0, 2);
	imax[3] = findMax(smat, 1, 2, 0);
	imax[4] = findMax(smat, 2, 0, 1);
	imax[5] = findMax(smat, 2, 1, 0);

	double gimax = 0;
	for (int i = 0; i < 6; i++)
	{
		if (imax[i] > gimax)
			gimax = imax[i];
	}

	opfl << std::fixed << std::setprecision(16) << gimax << "\n";

	ipfl.close();
	opfl.close();

	return 0;
}

double findMax(int smat[3][3], int a, int b, int c)
{
	int A = 0, B = 0, C = 0;
	int Arow, Acol, Brow, Bcol;

	for (int j = 0; j < 3; j++)
	{
		if (smat[a][j] > A)
		{
			A = smat[a][j];
			Arow = a;
			Acol = j;
		}
	}

	for (int j = 0; j < 3; j++)
	{
		if (b == Arow || j == Acol)
		{
		}
		else if (smat[b][j] > B)
		{
			B = smat[b][j];
			Brow = b;
			Bcol = j;
		}
	}

	for (int j = 0; j < 3; j++)
	{
		if (j == Acol || j == Bcol)
		{
		}
		else
		{
			C = smat[c][j];
		}
	}

	return sqrt((A*A) + (B*B) + (C*C));
}