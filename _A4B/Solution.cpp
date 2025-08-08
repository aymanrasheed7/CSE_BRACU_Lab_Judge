#include<bits/extc++.h>
using namespace std;
using lll = long long;
lll t, n, m, i, j, u[10008], v[10008], w[10008];
vector<lll> a[108], b[108];
int main() {
    for (scanf("%lld", &t); t--; i = 0) {
        for (scanf("%lld%lld", &n, &m); i != n;
            ++i, a[i].clear(), b[i].clear());
        for (i = 0; i != m; scanf("%lld", u + i++));
        for (i = 0; i != m; scanf("%lld", v + i++));
        for (i = 0; i != m; scanf("%lld", w + i),
            a[u[i]].push_back(v[i]), b[u[i]].push_back(w[i]), ++i);
        for (i = 0; i != n; puts(""))
            for (printf("%lld:", ++i), j = 0; j < a[i].size(); ++j)
                printf(" (%lld,%lld)", a[i][j], b[i][j]);
    }
    exit(0);
}