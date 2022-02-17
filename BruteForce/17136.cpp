#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int board[10][10];
int cnt[5];
bool covered[10][10];
const int INF = 987654321;
int MIN = INF;
int N = 10;
int M = 10;

vector<pair<int, int> > one;

bool inRange(int y, int x)
{
	if (x<0 || y<0 || x>M - 1 || y>N - 1)
		return false;
	return true;
}

bool canCover(int y, int x, int length)
{
	if (!inRange(y + length - 1, x + length - 1) || cnt[length - 1] >= 5)
		return false;
	for (int i = y; i < y + length; i++)
	{
		for (int j = x; j < x + length; j++)
		{
			if (board[i][j] == 0 || covered[i][j])
				return false;
		}
	}
	return true;
}

void cover(int y, int x, int length, bool isReverse)
{
	for (int i = y; i < y + length; i++)
	{
		for (int j = x; j < x + length; j++)
		{
			covered[i][j] = isReverse;
		}
	}
}

void pick(int index)
{
	if (index >= one.size())
	{
		int temp = 0;
		for (int i = 0; i < 5; i++)
		{
			temp += cnt[i];
		}
		MIN = min(MIN, temp);
		return;
	}

	int y = one[index].first;
	int x = one[index].second;

	for (int i = 0; i < 5; i++)
	{
		if (canCover(y, x, i + 1))
		{
			cover(y, x, i + 1, true);
			cnt[i]++;
			pick(index + 1);
			cnt[i]--;
			cover(y, x, i + 1, false);
		}
	}
}

int main()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 1)
				one.push_back(make_pair(i, j));
		}
	}
	pick(0);
	cout << (MIN == INF ? -1 : MIN);
}