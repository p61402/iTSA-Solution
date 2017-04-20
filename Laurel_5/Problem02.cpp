#include <iostream> 
#include <vector> 
using namespace std;

int main()
{
	int num_of_case;
	cin >> num_of_case;

	int num_of_suffle;
	while (num_of_case--)
	{
		cin >> num_of_suffle;

		vector<int> v;
		for (int i = 1; i <= 52; i++)
		{
			v.push_back(i);
		}

		int number;
		int a;
		for (int i = 0; i < num_of_suffle; i++)
		{
			cin >> number;
			for (int k = 52; k >= number; k--)
			{
				a = v.back();
				v.insert(v.begin(), a);
				v.pop_back();
			}
		}

		cout << v.back() << endl;
	}

	return 0;
}
