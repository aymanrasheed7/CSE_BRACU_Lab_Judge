#include<bits/extc++.h>
using namespace std;
using lll = long long;
lll t, n, u, v, x, i, w[100008];
vector<lll> a[100008];
queue<lll> q;
lll bfs(lll p) {
    for (i = 0; i++ != n; w[i] = 0);
    for (w[p] = x = 1, q.push(p); !q.empty(); q.pop())
        for (auto& r : a[p = q.front()])
            if (!w[r]) x = max(x, w[r] = 1 + w[p]), q.push(r);
    return p;
}
int main() {
    for (scanf("%lld", &t); t--;) {
        for (scanf("%lld", &n), i = n; --i;
            scanf("%lld%lld", &u, &v), a[u].push_back(v), a[v].push_back(u));
        u = bfs(1), v = bfs(u), printf("%lld\n%lld %lld\n", x - 1, u, v);
        for (i = 0; i++ != n; a[i].clear());
    }
    exit(0);
}