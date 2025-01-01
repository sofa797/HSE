#include <stdio.h> 
 
void prinarr(long long a[], long long n) { 
    for (int i = 0; i < n; i++) { 
        printf("%lld ", a[i]); 
    } 
    printf("\n"); 
} 
 
void insertsortup(long long a[], long long l, long long r, long long n) { 
    for (long long i = l + 1; i <= r; i++) { 
        long long q = a[i]; 
        long long j = i - 1; 
        while (j >= l && a[j] > q) { 
            a[j + 1] = a[j]; 
            j--; 
        } 
        a[j + 1] = q; 
    } 
} 
 
void insertsortdown(long long a[], long long l, long long r, long long n, long long t) { 
    for (long long i = l + 1; i <= r; i++) { 
        long long q = a[i]; 
        long long j = i - 1; 
        while (j >= l && a[j] < q) { 
            a[j + 1] = a[j]; 
            j--; 
        } 
        a[j + 1] = q; 
         
    } 
    printf("Step %lld:\n", t); 
    prinarr(a, n); 
} 
 
 
int main() { 
    long long n; 
    scanf("%lld", &n); 
    long long a[n]; 
    for (long long i = 0; i < n; i++) { 
        scanf("%lld", &a[i]); 
    } 
    long long m = (n + 1) / 2; 
    printf("Step 0:\n"); 
    prinarr(a, n); 
    for (int i = 1; i <= n / 2 - 1; i++) { 
        insertsortup(a, 0, i, n); 
        insertsortdown(a, n - i - 1, n - 1, n, i); 
    } 
    return 0; 
}
