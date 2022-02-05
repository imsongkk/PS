#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
string str[10];
vector<pair<int, int> > list(26, make_pair(0, 0));

bool compare(pair<int, int> a, pair<int, int> b)
{
	return a.first > b.first;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < 26; i++)
	{
		list[i].second = i;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> str[i];
		for (int j = 0; j < str[i].size(); j++)
		{
			int temp = (int)str[i][j] - 65;
			list[temp].first += pow(10, (str[i].size() - 1 - j));
		}
	}
	sort(list.begin(), list.end(), compare);
	int ans = 0;
	int temp = 9;
	for (int i = 0; i < list.size(); i++)
	{
		ans += list[i].first * temp;
		temp--;
	}
	cout << ans;
}