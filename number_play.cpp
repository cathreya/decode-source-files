#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

vector<long long> primes;
vector<bool> prime(1000005);
map<long long, long long> fac;

void get_factors(long long n) {
    long long i, j;
    for (i = 2; i <= 1000000; i++)
        prime[i] = true;
    prime[0] = false;
    prime[1] = false;
    for (i = 2; i <= 1000000; i++)
        for (j = 2 * i; j <= 1000000; j += i)
            prime[j] = false;
    for (i = 2; i <= 1000000; i++)
        if (prime[i])
            primes.push_back(i);
    for (i = 0; i < primes.size(); i++) {
        long long x = primes[i];
        while (n % x == 0) {
            fac[x]++;
            n /= x;
        }
    }
    if (n != 1)
        fac[n]++;
}

long long get_occurrences(long long n, long long x) {
    long long ans = 0;
    long long tmp = x;
    while (true) {
        long long xx = n / x;
        if (xx == 0)
            break;
        ans += xx;
        x *= tmp;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n, b;
    cin >> n >> b;

    get_factors(b);
    long long ans = INF;
    for (auto it = fac.begin(); it != fac.end(); it++) {
        long long pri = it->first;
        long long cnt = it->second;
        ans = min(ans, (get_occurrences(n, pri) / cnt));
    }
    cout << ans << endl;
    return 0;
}
