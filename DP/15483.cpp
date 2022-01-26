#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <queue>

#define ll long long

using namespace std;

string A, B;
int cache[1001][1001];

int getAns(int a, int b)
{
	if (a > A.length() - 1)
		return B.length() - b;
	else if (b > B.length() - 1)
		return A.length() - a;
	if (cache[a][b] != -1)
		return cache[a][b];
	if (A[a] == B[b])
		return cache[a][b] = getAns(a + 1, b + 1);
	return cache[a][b] = 1 + min(getAns(a + 1, b), min(getAns(a, b + 1), getAns(a + 1, b + 1)));

}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> A >> B;
	memset(cache, -1, sizeof(cache));
	cout << getAns(0, 0);
}

