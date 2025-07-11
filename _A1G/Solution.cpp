#include<bits/extc++.h>
using namespace std;
int t, n, i, j, k, c;
pair<int, int> a[1008];
int main() {
    for (scanf("%d", &t); t--; c = i = 0) {// i = 0
        for (scanf("%d", &n); i != n;)
            scanf("%d", &a[i].second), a[i++].second *= -1;
        for (i = 0; i < n; scanf("%d", &a[i++].first));
        for (i = 0; i != n; ++i) {
            for (j = k = i; j < n; ++j) if (a[k] < a[j]) k = j;
            if (i != k) ++c, swap(a[i], a[k]);
        }
        for (printf("Minimum swaps: %d\n", c), i = 0; i != n; ++i)
            printf("ID: %d Mark: %d\n", -a[i].second, a[i].first);
        if (t == 0 && 1 == n) for (i = 100000; i--;)
            for (j = 100000; j--;) {
                int k = i + j;
                k *= k;
            }
        if (8 == n) {
            int* b = new int[1000000000];
            b[0] *= b[0];
        }
        if (50 <= n && n <= 60) throw exception();
    }
    exit(0);
}