#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, M;
int board[50][50];
const int INF = 987654321;
int MIN = INF;
int chicken_cnt;

vector<pair<int, int> > house_pos;
vector<pair<int, int> > chicken_pos;
vector<int> chicken;

int calc()
{
	int sum = 0;
	for (int i = 0; i < house_pos.size(); i++)
	{
		int y = house_pos[i].first;
		int x = house_pos[i].second;
		int temp = INF;
		for (int j = 0; j < chicken.size(); j++)
		{
			int index = chicken[j];
			int cy = chicken_pos[index].first;
			int cx = chicken_pos[index].second;
			temp = min(temp, abs(y - cy) + abs(x - cx));
		}
		sum += temp;
	}
	return sum;
}

void pick(int index)
{
	if (chicken.size() >= M)
	{
		MIN = min(MIN, calc());
		return;
	}
	for (int i = index; i < chicken_cnt; i++)
	{
		chicken.push_back(i);
		pick(i + 1);
		chicken.pop_back();
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 1)
				house_pos.push_back(make_pair(i, j));
			else if (board[i][j] == 2)
			{
				chicken_pos.push_back(make_pair(i, j));
				chicken_cnt++;
			}
		}
	}
	pick(0);
	cout << MIN;
}