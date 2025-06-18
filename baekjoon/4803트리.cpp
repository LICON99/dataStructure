#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'

using namespace std;

int N, M, answer;
bool visited[503];
vector<int> adj[503];

bool DFS(int index, int parentIndex)
{
	visited[index] = true;
	for (auto head : adj[index])
	{
		if (!visited[head])
		{
			if (DFS(head, index))
				return true;
		}
		else if (parentIndex != head)
			return true;
	}
	return false;
}

int main()
{
	fastio;
	int count = 0;
	while (1)
	{
		answer = 0;
		cin >> N >> M;
		if (N == 0 && M == 0)
			break;
		for (int i = 1; i <= 500; i++)
			adj[i].clear();

		while (M--)
		{
			int from, to;
			cin >> from >> to;
			adj[from].push_back(to);
			adj[to].push_back(from);
		}
		memset(visited, false, sizeof(visited));
		for (int i = 1; i <= N; i++)
		{
			if (!visited[i])
			{
				if (!DFS(i, -1))
					answer++;
			}
		}

		cout << "Case " << ++count;
		if (answer == 0)
			cout << ": No trees." << endl;
		else if (answer == 1)
			cout << ": There is one tree." << endl;
		else
			cout << ": A forest of " << answer << " trees." << endl;
	}
	return 0;
}