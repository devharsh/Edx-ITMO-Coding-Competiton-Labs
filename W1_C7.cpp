#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>

int main()
{
	std::ifstream ipfl;
	ipfl.open("input.txt");

	std::map<char, std::pair<int, int>> keyMap;
	std::pair<std::string, int> langMap[3];

	int width, height;
	ipfl >> width >> height;

	for (int h = 0; h < height; h++)
	{
		for (int w = 0; w < width; w++)
		{
			char c;
			ipfl >> c;
			keyMap[c] = { w, h };
		}
	}

	std::string str("%TEMPLATE-START%");
	std::string end("%TEMPLATE-END%");

	for (int f = 0; f < 3; f++)
	{
		ipfl >> langMap[f].first;
		std::string langCode = "";

		while (1)
		{
			std::string temp = "";
			ipfl >> temp;
			if (temp.find(str) != std::string::npos)
				continue;
			if (temp.find(end) != std::string::npos)
				break;
			langCode += temp;
		}

		int tsum = 0;

		for (int i = 1; i < langCode.length(); i++)
		{
			int x1 = keyMap[langCode[i - 1]].first;
			int y1 = keyMap[langCode[i - 1]].second;
			int x2 = keyMap[langCode[i]].first;
			int y2 = keyMap[langCode[i]].second;
			int diff = std::max(abs(x1 - x2), abs(y1 - y2));
			tsum += diff;
		}

		langMap[f].second = tsum;
	}

	std::string mlan = "";
	double gmin = std::numeric_limits<int>::max();

	for (int b = 0; b < 3; b++)
	{
		if (langMap[b].second < gmin)
		{
			gmin = langMap[b].second;
			mlan = langMap[b].first;
		}
	}

	ipfl.close();
	std::ofstream opfl;
	opfl.open("output.txt");
	opfl << mlan << "\n" << gmin;
	opfl.close();
	return 0;
}