// prime check - optimized
bool isPrime(int n) {
    if(n < 2)
        return false;

    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0)
            return false;
    }

    return true;
}

// Sieve of Eratosthenes
vector<bool> prime(n + 1, true);

prime[0] = prime[1] = false;

for(int i = 2; i * i <= n; i++) {

    if(prime[i]) {

        for(int j = i * i; j <= n; j += i) {
            prime[j] = false;
        }

    }
}
// then print 
for(int i = 2; i <= n; i++) {
    if(prime[i])
        cout << i << " ";
}