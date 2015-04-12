#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

class poker
{
	public:
		char ch[2];
};

bool match(const poker& a, const poker& b)
{
	return ((a.ch[0] == b.ch[0]) || (a.ch[1] == b.ch[1]));
}

typedef std::vector<poker> Pile;
typedef std::vector<Pile> Piles;
Piles piles;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	while (true)
	{
		std::string s1;
		std::string s2;
		std::getline(std::cin, s1);
		if (s1[0] == '#') break;
		std::getline(std::cin, s2);
		std::string s = s1 + " " + s2;
		int i = 0;
		piles.clear();
		while (s[i] != 0)
		{
			poker p;
			p.ch[0] = s[i++];
			p.ch[1] = s[i++];
			i++;
			Pile pile;
			pile.push_back(p);
			piles.push_back(pile);
			for (int j = piles.size()-1; j < piles.size(); j++)
			{
				int k = j;
				poker b = piles[j].back();
				while (true)
				{
					if (k - 3 >= 0)
					{
						poker a = piles[k-3].back();
						if (match(a, b)) {
							k -= 3;
							continue;
						}
					}
					if (k - 1 >= 0){
						poker a = piles[k-1].back();
						if (match(a, b)){
							k -= 1;
							continue;
						}
					}
					break;
				}
				if (k != j) {
					piles[k].push_back(b);
					piles[j].pop_back();
					if (piles[j].empty()) piles.erase(piles.begin() + j);
				}
				j = k;
			}
		}
		std::cout << piles.size() << " " << "pile";
		if (piles.size() > 1) std::cout << "s";
		std::cout << " remaining:";
		for (int j = 0; j < piles.size(); j++)
		{
			std::cout << " " << piles[j].size();
		}
		std::cout << std::endl;
	}
		return 0;
}
