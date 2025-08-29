#include<bits/extc++.h>
using namespace std;
using lll = long long;
lll t, n, m, s, d, u, v, i, w[200008], x[200008];
priority_queue<pair<lll, lll>> q;
vector<lll> a[200008];
int main() {
    for (scanf("%lld", &t); t--;
        printf("%lld\n", x[d] < 1e17 ? x[d] : -1), i = 0) {
        for (scanf("%lld%lld%lld%lld", &n, &m, &s, &d);
            i++ != n; scanf("%lld", w + i), x[i] = 1e18, a[i].clear());
        for (i = 0; i != m; scanf("%lld%lld", &u, &v), a[u].push_back(v), ++i);
        for (x[s] = 0, q.push(make_pair(0, s)); !q.empty();)
            if (tie(v, u) = q.top(), q.pop(), v = -v, v == x[u])
                for (auto& z : a[u]) if (v + w[u] + w[z] * w[z] < x[z])
                    x[z] = v + w[u] + w[z] * w[z], q.push(make_pair(-x[z], z));
    }
    exit(0);
}