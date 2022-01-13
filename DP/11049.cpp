#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>

#define ll long long

using namespace std;

int N;
int cache[501][501];
vector<pair<int, int> > list;

int getAns(int s, int e)
{
	if (cache[s][e] != -1)
		return cache[s][e];
	if (s == e)
		return cache[s][e] = 0;
	int ret = 987654321;
	for (int i = s; i < e; i++)
	{
		ret = min(ret, getAns(s, i) + getAns(i + 1, e) + list[s].first * list[i].second * list[e].second);
	}
	return cache[s][e] = ret;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	int r, c;
	for (int i = 0; i < N; i++)
	{
		cin >> r >> c;
		list.push_back(make_pair(r, c));
	}
	memset(cache, -1, sizeof(cache));
	cout << getAns(0, N - 1);
}

