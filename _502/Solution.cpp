#include<bits/extc++.h>
using namespace std;
using lll = long long;
lll t, n, u, v, w, i, z[100008];
vector<pair<lll, lll>> a[100008];
lll dfs(lll x, lll y) {
    if (x == 1) return 0;
    lll r = 2e9;
    for (auto& s : a[x]) if (s.first != y)
        r = min(r, s.second + dfs(s.first, x));
    return r;
}
int main() {
    for (scanf("%lld", &t); t--;) {
        for (scanf("%lld", &n), i = n; --i; scanf("%lld%lld%lld", &u, &v, &w),
            a[u].push_back(make_pair(v, w)), a[v].push_back(make_pair(u, w)));
        for (printf("%lld\n", dfs(n, n)), i = 0; i++ != n; a[i].clear());
    }
    exit(0);
}