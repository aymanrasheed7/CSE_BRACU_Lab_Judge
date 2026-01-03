#include<bits/extc++.h>
using namespace std;
using lll = long long;
lll t, n, i, j, k;
pair<lll, lll> a[100008];
int main() {
    for (scanf("%lld", &t); t--; printf("%lld\n", k), j = k = 0) {
        for (scanf("%lld", &n), i = n; i--;
            scanf("%lld%lld", &a[i].first, &a[i].second));
        for (sort(a, a + n); n != ++i; j += a[i].first, k += a[i].second - j);
    }
    exit(0);
}