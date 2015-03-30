#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int team[20];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	int n;
	cin >> n;
	int cnt = 0;
	while (n--)
	{
		cnt++;
		int nums;
		cin >> nums;
		for (int i = 0; i < nums; i++)
		{
			cin >> team[i];
		}
		sort(team, team+nums);
		cout << "Case " << cnt << ": " << team[nums/2] << endl;
	}
	return 0;
}
