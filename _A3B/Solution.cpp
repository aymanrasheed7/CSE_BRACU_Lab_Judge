#include<bits/extc++.h>
using namespace std;
using lll = long long;
lll t, n, i, a[100008], b[100008];
lll rec(lll x, lll y) {
    if (x + 1 == y) return 0;
    lll z = x + y >> 1, c = rec(x, z) + rec(z, y), p, q, r;
    for (p = q = z; q < y; c += z - p, ++q) {
        while (x < p && a[q] * a[q] < a[p - 1]) --p;
        while (p < z && a[p] <= a[q] * a[q]) ++p;
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
        for (scanf("%lld", &n); i != n; scanf("%lld", a + i++));
    exit(0);
}