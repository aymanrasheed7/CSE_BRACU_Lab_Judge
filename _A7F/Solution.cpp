#include<bits/extc++.h>
using namespace std;
using lll = long long;
lll t, n, m, s, d, u, v, w, i, x[2][200008];
priority_queue<pair<lll, lll>> q;
vector<pair<lll, lll>> a[200008];
int main() {
    for (scanf("%lld", &t); t--;
        printf("%lld\n", x[1][d] < 1e17 ? x[1][d] : -1), i = 0) {
        for (scanf("%lld%lld%lld%lld", &n, &m, &s, &d);
            i++ != n; x[0][i] = x[1][i] = 1e18, a[i].clear());
        for (i = 0; i != m; scanf("%lld%lld%lld", &u, &v, &w), ++i,
            a[u].push_back(make_pair(w, v)), a[v].push_back(make_pair(w, u)));
        for (x[0][s] = 0, q.push(make_pair(0, s)); !q.empty();)
            if (tie(w, u) = q.top(), q.pop(), w = -w, w <= x[1][u])
                for (auto& [y, z] : a[u])
                    if (w + y < x[0][z]) x[1][z] = x[0][z],
                        x[0][z] = w + y, q.push(make_pair(-x[0][z], z));
                    else if (x[0][z] < w + y && w + y < x[1][z])
                        x[1][z] = w + y, q.push(make_pair(-x[1][z], z));
    }
    exit(0);
}