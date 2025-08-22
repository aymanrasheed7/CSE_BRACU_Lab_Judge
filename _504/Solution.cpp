#include<bits/extc++.h>
using namespace std;
using lll = long long;
lll t, n, m, u, v, i, z, w[200008];
vector<lll> a[200008];
queue<lll> r;
void bfs(lll p) {
    for (w[p] = 1, r.push(p); !r.empty(); r.pop())
        for (auto& q : a[p = r.front()]) if (!w[q]) w[q] = 1, r.push(q);
}
int main() {
    for (scanf("%lld", &t); t--; printf("%lld\n", z), i = 0) {
        for (scanf("%lld%lld", &n, &m); i != m; scanf("%lld%lld", &u, &v),
            a[u].push_back(v), a[v].push_back(u), ++i);
        for (z = m - n, i = 0; i++ != n;) if (!w[i]) bfs(i), ++z;
        for (i = 0; i++ != n; w[i] = 0, a[i].clear());
    }
    exit(0);
}