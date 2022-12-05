#include <iostream>
#include <regex>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
	ifstream f("html.txt");
	string str;
	smatch match;
	
	const auto r = regex(R"(<a.+href=".+"(.+>|>).+<\/a>)");
	while (getline(f, str))
	{
		regex_search(str, match, r);
		for (int i = 0; i < match.size(); i++) cout << match[i] << "\n";
	}
}