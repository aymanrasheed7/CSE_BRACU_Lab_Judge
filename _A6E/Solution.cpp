#include<bits/extc++.h>
using namespace std;
using lll = long long;
lll t, n, m, s, r, u, v, i, w[50008];
vector<lll> a[50008];
queue<lll> q;
int main() {
    for (scanf("%lld", &t); t--; i = 0) {
        for (scanf("%lld%lld%lld%lld", &n, &m, &s, &r);
            i++ != n; w[i] = -1, a[i].clear());
        for (i = 0; i != m; scanf("%lld%lld", &u, &v),
            a[u].push_back(v), a[v].push_back(u), ++i);
        for (i = 0; i != s; ++i) scanf("%lld", &u), w[u] = 0, q.push(u);
        for (; !q.empty(); q.pop())
            for (auto& j : a[i = q.front()])
                if (w[j] == -1) w[j] = 1 + w[i], q.push(j);
        for (i = 0; i != r; ++i)
            scanf("%lld", &v), printf("%d%c", w[v], i + 1 == r ? '\n' : ' ');
    }
    exit(0);
}