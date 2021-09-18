#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
const int N = 2e5 + 7;
ll arr[N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll i, j, k, z, l, f, n, m, p, q, r, sum, t, x1, y1, g, x, y, ans, mx, mn, d;
	cin >> n >> k;
	set<ll> s;
	multiset<ll> s2;
	for (i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	j = 1;
	sum = 0;
	for (i = 1; i <= k; i++)
	{
		sum += n - (i - 1);//all subarrays of length i less than or equal to length k are added to ans
		s.insert(arr[i]);
		s2.insert(arr[i]);
	}
	i = k + 1;
	for (; i <= n; i++)
	{
		s2.insert(arr[i]);
		s.insert(arr[i]);
		if (s.size() > k)
		{
			while (j <= n && s.size() > k)
			{
				s2.erase(s2.find(arr[j]));
				j++;
				if (!s2.count(arr[j - 1]))
				{
					s.erase(arr[j - 1]);
				}
			}
		}

		if (j <= n)
			sum += i - j + 1 - k;// all subarrys of length greater than k that end at i and  begin from or after j are added  
	}
	cout << sum << endl;
	return 0;
}