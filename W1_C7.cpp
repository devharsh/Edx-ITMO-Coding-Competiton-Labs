#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <math.h>
#include <vector>

#pragma warning(disable:4996)

int main()
{
	std::ifstream ipfl;
	ipfl.open("input.txt");

	std::map<char, int> keyMapX;
	std::map<char, int> keyMapY;
	std::map<std::string, double> langMap;
	std::vector<std::string> insertOrder;

	int width, height;
	ipfl >> width >> height;

	for (int h = 0; h < height; h++)
	{
		for (int w = 0; w < width; w++)
		{
			char c;
			ipfl >> c;
			keyMapX.insert(std::make_pair(c, h));
			keyMapY.insert(std::make_pair(c, w));
		}
	}

	std::string str("%TEMPLATE-START%");
	std::string end("%TEMPLATE-END%");
	std::string lang = "";
	std::string temp = "";

	std::getline(ipfl, temp); // remove CRLF from previous line

	double gmin = std::numeric_limits<double>::max();

	while (ipfl)
	{
		std::getline(ipfl, lang); // name of the language
		std::getline(ipfl, temp); // remove start of template from calculation
		char allKeys[100000] = {};
		int akind = 0;
		bool doit = false;
		while (ipfl)
		{
			doit = true;
			std::getline(ipfl, temp);
			if (temp.find(end) == std::string::npos)
			{
				char tempkeys[1000];
				size_t n = temp.length();
				strcpy(tempkeys, temp.c_str());

				for (int i = 0; i < n; i++)
				{
					if (int(tempkeys[i]) == 32)
						continue;
					allKeys[akind] = tempkeys[i];
					akind++;
				}
			}
			else
				break;
		}

		if (doit)
		{
			double tsum = 0;
			if (akind > 1)
			{
				for (int i = 1; i < akind; i++)
				{
					int x1 = keyMapX.at(allKeys[i - 1]);
					int y1 = keyMapY.at(allKeys[i - 1]);
					int x2 = keyMapX.at(allKeys[i]);
					int y2 = keyMapY.at(allKeys[i]);
					double diff = std::fmax(abs(x1 - x2), abs(y1 - y2));
					tsum += diff;
				}
			}

			if (tsum < gmin)
				gmin = tsum;
			langMap[lang] = tsum;
			insertOrder.push_back(lang);
		}
	}

	ipfl.close();
	std::ofstream opfl;
	opfl.open("output.txt");

	for (int i = 0; i < insertOrder.size(); ++i)
	{
		if (langMap.at(insertOrder[i]) == gmin)
		{
			opfl << insertOrder[i] << "\n" << gmin;
			break;
		}
	}

	opfl.close();
	return 0;
}