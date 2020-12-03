#include <iostream>
#include <string>
using namespace std;

int CommonSubsequence(string U, string V) 
{
	int max = 0, i, len1, len2;
	len1 = U.length();
	len2 = V.length();
	int matrix[1001][1001];

	for (int j = 0; j < len1; j++)
	{
		for (int k = 0; k < len2; k++) 
		{
			if (U[j] == V[k])
			{
				matrix[j + 1][k + 1] = 1 + matrix[j][k];
			}
			else 
			{
				max = matrix[j + 1][k];

				if (matrix[j][k + 1] > max)
				{
					max = matrix[j][k + 1];
				}

				matrix[j + 1][k + 1] = max;
			}
		}
	}
	return matrix[len1][len2];
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, i, len1, len2, result;
	string u, v;

	cin >> t;

	for (i = 0; i < t; i++)
	{
		cin >> len1 >> u;
		cin >> len2 >> v;

		result = CommonSubsequence(u, v);

		cout << result << "\n";
	}

	return 0;
}