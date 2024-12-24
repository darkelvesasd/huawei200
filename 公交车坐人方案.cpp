#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int>v;
	int t;
	while (cin >> t)
	{
		v.push_back(t);
	}
	int n = v.back();
	v.pop_back();
	vector<vector<int>>dp(v.size() + 1, vector<int>(n + 1));
	for (int i = 0; i <= v.size(); i++)
	{
		dp[i][0] = 1;
	}
	for (int i = 1; i <= v.size(); i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (j>= v[i - 1])
			{
				dp[i][j] += dp[i - 1][j - v[i - 1]];
			}
		}
	}
	cout << dp[v.size()][n];
	return 0;
}/*5 4 2 3 2 4 9
10*/
