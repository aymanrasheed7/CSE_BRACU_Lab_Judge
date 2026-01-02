#include<bits/extc++.h>
using namespace std;
using lll = long long;
lll t, n, m, u, v, w, i, a, d[40008];
tuple<lll, lll, lll> e[60008];
lll frt(lll x) {
    return d[x] < 0 ? x : d[x] = frt(d[x]);
}
lll uni(lll x, lll y) {
    if (x = frt(x), y = frt(y), x == y) return 0;
    if (d[x] < d[y]) swap(x, y);
    return d[y] += d[x], d[x] = y;
}
int main() {
    for (scanf("%lld", &t); t--; printf("%lld\n", a), a = 0) {
        for (scanf("%lld%lld", &n, &m), i = m; i--;)
            scanf("%lld%lld%lld", &u, &v, &w), e[i] = tie(w, u, v);
        for (i = 0; i++ != n; d[i] = -1);
        for (sort(e, e + m), i = m; i--;)
            if (tie(w, u, v) = e[i], uni(u, v)) a += w;
    }
    exit(0);
}