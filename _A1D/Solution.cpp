#include<bits/extc++.h>
using namespace std;
int t, n, i, f, a[10008];
int main() {
    for (scanf("%d", &t); t--; puts(f ? "YES" : "NO"), i = f = 0) {
        for (scanf("%d", &n); i != n; scanf("%d", a + i++));
        for (i = f = 1; i != n; f &= a[i - 1] <= a[i], ++i);
    }
    exit(0);
}