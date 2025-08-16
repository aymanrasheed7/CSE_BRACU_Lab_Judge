#include<bits/extc++.h>
using namespace std;
using lll = long long;
lll t, n, m, s, d, k, u, v, i, w[200008];
vector<lll> a[200008], b;
queue<lll> q;
lll bfs(lll p, lll o) {
    for (i = 0; i++ != n; w[i] = i);
    for (w[p] = 0, q.push(p); !q.empty();) {
        p = q.front(), q.pop();
        for (auto& r : a[p]) if (w[r] == r) w[r] = p, q.push(r);
    }
    if (w[o] == o) return n + n;
    for (p = 0; o = w[o]; ++p, b.push_back(o));
    return p;
}
int main() {
    for (scanf("%lld", &t); t--; i = 0) {
        for (scanf("%lld%lld%lld%lld%lld", &n, &m, &s, &d, &k); i != m;
            scanf("%lld%lld", &u, &v), a[u].push_back(v), ++i);
        if (i = bfs(k, d) + bfs(s, k), i < n + n) {
            for (printf("%lld\n", i = b.size()); i--; printf("%lld ", b[i]));
            printf("%lld\n", d);
        }
        else puts("-1");
        for (b.clear(), i = 0; i++ != n; a[i].clear());
    }
    exit(0);
}