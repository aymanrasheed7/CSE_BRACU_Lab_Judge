#include<bits/extc++.h>
using namespace std;
int t, n, i, j, k, a[1008];
int main() {
    for (scanf("%d", &t); t--;) {// i = 0
        for (scanf("%d", &n); i != n; scanf("%d", a + i++));
        for (i = 0; i != n; ++i)
            for (j = i; 0 < j; --j)
                if (a[j - 1] > a[j] && ((a[j - 1] ^ a[j] ^ 1) & 1))
                    swap(a[j - 1], a[j]);
        for (i = 0; i != n; ++i) printf("%d ", a[i]);
    }
    exit(0);
}
