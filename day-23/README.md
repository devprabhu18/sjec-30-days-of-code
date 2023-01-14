#include <iostream>
#include <cmath>
#include <vector>
#include <set>
using namespace std;

// Function to create a sieve of Eratosthenes
vector<long long int> sieve(long long int n) {
    vector<long longint> primes;
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (long long int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            if (i <= sqrt(n)) {
                for (long long int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }
    return primes;
}

// Function to find all prime factors of a number
vector<long long int> primeFactors(long long int n, vector<long long int>& primes) {
    vector<long long int> factors;
    long long int i = 0;
   long long int p = primes[i];
    while (p <= sqrt(n)) {
        while (n % p == 0) {
            factors.push_back(p);
            n = n / p;
        }
        i++;
        p = primes[i];
    }
    if (n > 1)
        factors.push_back(n);
    return factors;
}

long long int primeCount(long longint n) {
    if (n == 1) return 0;
    vector<long long int> primes = sieve(n);
    long long int maxPrimeFactors = 0;
    for (long long int i = 2; i <= n; i++) {
        vector<long long int> factors = primeFactors(i, primes);
        set<long long int> uniqueFactors(factors.begin(), factors.end());
        long long int count = uniqueFactors.size();
        maxPrimeFactors = max(maxPrimeFactors, count);
    }
    return maxPrimeFactors;
}
 
long long int main() {
    long long int n;
    cin >> n;
    for (long long int i = 0; i < n; i++) {
        long long int x;
        cin >> x;
        cout << primeCount(x) << endl;
    }
    return 0;
}

