#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std;

int main()
{
	int test_case;

	cin >> test_case;

	int n, m;

	while (test_case--)
	{
		int a[100], b[50];

		cin >> n >> m;

		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		for (int j = 0; j < m; j++)
		{
			cin >> b[j];
		}

		sort(b, b + m);

		int dp[200001] = { 0 };

		for (int i = 0; i < n; i++)
		{
			for (int j = b[m - 1]; j >= a[i]; j--)
			{
				dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
			}
		}

		int count = 0;
		for (int i = 0; i < m; i++)
		{
			//cout << "dp[" << b[i] << "]: " << dp[b[i]] << endl; 
			if (dp[b[i]] == b[i])
			{
				count++;
			}
		}

		cout << count << endl;
	}

	return 0;
}