#include<bits/extc++.h>
using namespace std;
using lll = long long;
lll t, n, r, q, u, v, x, i, w[200008];
vector<lll> a[200008];
void dfs(lll p) {
    w[p] = 1;
    for (auto& o : a[p]) if (!w[o]) dfs(o), w[p] = max(w[p], 1 + w[o]);
}
int main() {
    for (scanf("%lld", &t); t--;) {
        for (scanf("%lld%lld", &n, &r), i = n; --i;
            scanf("%lld%lld", &u, &v), a[u].push_back(v), a[v].push_back(u));
        for (dfs(r), scanf("%lld", &q); q--;
            scanf("%lld", &x), printf("%lld\n", w[x] - 1));
        for (i = 0; i++ != n; w[i] = 0, a[i].clear());
    }
    exit(0);
}