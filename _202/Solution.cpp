#include<bits/extc++.h>
using namespace std;
using lll = long long;
lll t, n, m, l, k, h, i, j, a[500008], b[500008], c[500008];
int main() {
    for (scanf("%lld", &t); t--; h = i = j = 0) {
        for (scanf("%lld%lld%lld%lld", &n, &m, &l, &k);
            h != n; scanf("%lld", a + h++));
        for (a[n] = b[m] = c[l] = 2e9; i != m; scanf("%lld", b + i++));
        for (; j != l; scanf("%lld", c + j++));
        for (h = i = j = 0; --k;)
            if (a[h] <= b[i] && a[h] <= c[j]) ++h;
            else if (b[i] <= a[h] && b[i] <= c[j]) ++i;
            else ++j;
        printf("%lld\n", min(a[h], min(b[i], c[j])));
    }
    exit(0);
}