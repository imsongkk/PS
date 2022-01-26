#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>

#define ll long long

using namespace std;

int N, K;
vector<pair<int, int> > list;
int cache[101][100001];

int getAns(int n, int k)
{
	if (n == N - 1)
	{
		if (list[n].first > k)
			return cache[n][k] = 0;
		return cache[n][k] = list[n].second;
	}
	if (cache[n][k] != -1)
		return cache[n][k];
	int ret = -1;
	if (list[n].first <= k)
		ret = list[n].second + getAns(n + 1, k - list[n].first);
	ret = max(ret, getAns(n + 1, k));
	return cache[n][k] = ret;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> K;
	int w, v;
	for (int i = 0; i < N; i++)
	{
		cin >> w >> v;
		list.push_back(make_pair(w, v));
	}
	memset(cache, -1, sizeof(cache));
	cout << getAns(0, K);
}

