﻿#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct dinic{
	static const int M = 10000;
	static const int INF = 1e9;
	struct Edge{
		int v;
		int f; //residual flow
		int re;
	};
	int n, s, t, level[M], now[M];
	vector<Edge> e[M];
	void init(int _n, int _s, int _t){
		n = _n; s = _s; t = _t;
		for (int i = 0; i <= n; i++)e[i].clear();
	}
	void add_edge(int u, int v, int f){
		e[u].push_back({ v, f, e[v].size() });
		e[v].push_back({ u, f, e[u].size() - 1 });
	}
	bool bfs(){
		fill(level, level + n + 1, -1);
		queue<int> q;
		q.push(s); level[s] = 0;
		while (!q.empty()){
			int u = q.front(); q.pop();
			for (auto it : e[u]){
				if (it.f > 0 && level[it.v] == -1){
					level[it.v] = level[u] + 1;
					q.push(it.v);
				}
			}
		}
		return level[t] != -1;
	}
	int dfs(int u, int nf){
		if (u == t)return nf;
		int res = 0;
		while (now[u] < e[u].size()){
			Edge &it = e[u][now[u]];
			if (it.f>0 && level[it.v] == level[u] + 1){
				int tf = dfs(it.v, min(nf, it.f));
				res += tf; nf -= tf; it.f -= tf;
				e[it.v][it.re].f += tf;
				if (nf == 0)return res;
			}
			else now[u]++;
		}
		if (!res)level[u] = -1;
		return res;
	}
	int flow(int res = 0){
		while (bfs()){
			int temp;
			memset(now, 0, sizeof(now));
			while (temp = (dfs(s, INF))){
				res += temp;
			}
		}
		return res;
	}
}d;

int main(){
	int nt = 1, n;
	while (cin >> n, n){
		int c, s, t, x, y, z;
		cin >> s >> t >> c;
		d.init(n, s, t);
		for (int i = 0; i <c; i++){
			cin >> x >> y >> z;
			d.add_edge(x, y, z);
		}
		printf("Network %d\n", nt++);
		printf("The bandwidth is %d.\n\n", d.flow());
	}
}