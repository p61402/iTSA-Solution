#include <iostream> 
using namespace std;

int main()
{
	int num_of_case;
	cin >> num_of_case;

	int num_of_store;
	while (num_of_case--)
	{
		cin >> num_of_store;

		int *a = new int[num_of_store];
		int width = 0;
		int total_length = 0;
		for (int i = 0; i < num_of_store; i++)
		{
			cin >> a[i];

			if (i >= 1)
			{
				width += a[i - 1];
			}

			total_length += (width + a[i] / 2);
		}

		cout << total_length << endl;

		delete[]a;
	}

	return 0;
}