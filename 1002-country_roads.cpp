#include <bits/stdc++.h>
#define MAX 600
#define oo 100000000

using namespace std;
typedef pair<int,int> pii;

vector<pii> graph[MAX];
int dist[MAX];

void dijkstra(int o) {
  set<pii> pq;
  set<pii>::iterator it;
  int u, v, wt;

  for (int i = 0; i < MAX; i++)
    dist[i] = oo;

  dist[o] = 0;
  pq.insert(make_pair(0, o));

  while (pq.size() != 0) {
    it = pq.begin();
    u = it->second;
    pq.erase(it);

    for (int i = 0; i < graph[u].size(); i++) {
      v = graph[u][i].first;
      wt = graph[u][i].second;

      if (dist[v] > max(dist[u], wt)) {
        if (dist[v] != oo)
          pq.erase(pq.find(make_pair(dist[v], v)));

        dist[v] = max(dist[u], wt);
        pq.insert(make_pair(dist[v], v));
      }
    }
  }
}

int main() {
  int T, n, m, t, u, v, w;
  int cas = 1;

  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
      graph[i].clear();

    for (int i = 0; i < m; i++) {
      scanf("%d %d %d", &u, &v, &w);
      graph[u].push_back(pii(v, w));
      graph[v].push_back(pii(u, w));
    }

    scanf("%d", &t);
    printf("Case %d:\n", cas++);

    dijkstra(t);

    for (int i = 0; i < n; i++) {
      if (dist[i] == oo)
        printf("Impossible\n");
      else
        printf("%d\n", dist[i]);
    }
  }
  return 0;
}
