#include<bits/extc++.h>
using namespace std;
using lll = long long;
lll t, n, l, h, i, a[100008], b[100008];
lll rec(lll x, lll y) {
    if (x + 1 == y) return 0;
    lll z = x + y >> 1, c = rec(x, z) + rec(z, y), p, q, r;
    for (p = q = x, r = z; r < y; c += q - p, ++r) {
        while (p < z && a[r] - a[p] < l) ++p;
        while (q < z && a[r] - a[q] <= h) ++q;
    }
    for (r = p = x, q = z; p < z && q < y;)
        if (a[p] < a[q]) b[r++] = a[p++];
        else b[r++] = a[q++];
    while (p < z) b[r++] = a[p++];
    while (q < y) b[r++] = a[q++];
    for (r = x; r < y; a[r] = b[r], ++r);
    return c;
}
int main() {
    for (scanf("%lld", &t); t--; printf("%lld\n", rec(0, n)), i = 0)
        for (scanf("%lld%lld%lld", &n, &l, &h); i != n; scanf("%lld", a + i++));
    exit(0);
}