#include<bits/extc++.h>
using namespace std;
using lll = long long;
lll t, n, k, i, j, b[100008];
pair<lll, lll> a[100008];
int main() {
    for (scanf("%lld", &t); t--;) {
        for (scanf("%lld", &n), k = 1e9, i = j = 0; i != n;
            scanf("%lld%lld", &a[i].first, &a[i].second), ++i);
        for (sort(a, a + n), i = n; i--;)
            if (a[i].second < k) k = a[i].first, b[j++] = i;
        for (printf("%lld\n", j); j--;
            printf("%lld %lld\n", a[b[j]].first, a[b[j]].second));
    }
    exit(0);
}