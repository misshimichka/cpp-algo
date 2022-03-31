// Пошаговый обход графа


#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> graph;
vector<int> is_visited;
vector<int> result;

void dfs(int v) {
    is_visited[v] = 1;
    for (int i = 0; i < graph[v].size(); i++) {
        if (!is_visited[graph[v][i]]) {
            result.push_back(v);
            dfs(graph[v][i]);
        }
    }
    result.push_back(v);
}

int main() {
    int n, m;
    cin >> n >> m;
    graph.resize(n + 1);
    is_visited.resize(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int v;
    cin >> v;
    dfs(v);
    cout << result.size() << "\n";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}
