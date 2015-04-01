#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	int n;
	while (cin >> n)
	{
		int sum = 0;
		int cnt = 1;
		while (sum + cnt < n)
		{
			sum += cnt;
			cnt++;
		}
		int index = n - sum;
		int l, r;
		if (cnt % 2)
		{
			l = cnt + 1 - index;
			r = cnt + 1 - l;
		}
		else
		{
			r = cnt + 1 - index;
			l = cnt + 1 - r;
		}
		printf("TERM %d IS %d/%d\n", n, l, r);
	}
	return 0;
}
