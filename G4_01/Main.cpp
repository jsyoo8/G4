#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// #define USE_TXT

void cppReady() {
#if defined(USE_TXT)
    // ios_base::sync_with_stdio(false); cin.tie(NULL); freopen("TestCases.txt", "r", stdin); freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL); freopen("TestCases.txt", "r", stdin);
#else
    ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
}
// pair < dist, end >
vector<pair<int, int>> edge[10001];
bool visited[10001];

int main(void) {
    cppReady();
    unsigned int V, E;
    cin >> V;
    cin >> E;

    for (unsigned int e = 0; e < E; e++) {
        int vS, vE, dist;
        cin >> vS;
        cin >> vE;
        cin >> dist;
        edge[vS].push_back(make_pair(dist, vE));
        edge[vE].push_back(make_pair(dist, vS));
    }

    int totalCost = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    pq.push(make_pair(0,1));

    while (!pq.empty()) {
		int curV = pq.top().second;
		int curD = pq.top().first;
		pq.pop();

		if (visited[curV]) continue;

		visited[curV] = true;
		totalCost += curD;

		for (int e = 0; e < edge[curV].size(); e++) {
			int nextV = edge[curV][e].second;
			int nextD = edge[curV][e].first;

			if (visited[nextV]) continue;

			pq.push(make_pair(nextD, nextV));
		}
    }

    cout << totalCost;

    return 0;
}
