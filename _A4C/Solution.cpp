#include<bits/extc++.h>
using namespace std;
using lll = long long;
lll t, n, i, j, k, a[108];
int main() {
    for (scanf("%lld", &t); t--; i = 0) {
        for (scanf("%lld", &n); i != n; puts(""), ++i) {
            for (scanf("%lld", &k); k--; scanf("%lld", &j), a[j] = 1);
            for (j = 0; j != n; printf("%lld ", a[j]), a[j++] = 0);
        }
    }
    exit(0);
}