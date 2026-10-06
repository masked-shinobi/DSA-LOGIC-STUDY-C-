#include <bits/stdc++.h>

using namespace std;

int main(){

    int n = 233;
// factorial iterative
    int ans = 1;

    for(int i = 1; i <= n; i++) {
        ans *= i;
    }
// recursive
    if(n == 0 || n == 1)
    return 1;

    return n * factorial(n - 1);

// fibonacci recursive
if(n == 0)
    return 0;

if(n == 1)
    return 1;

return fibonacci(n - 1) + fibonacci(n - 2);
// fibonacci iterative
int a = 0, b = 1;

for(int i = 0; i < n; i++) {
    int next = a + b;
    a = b;
    b = next;
}

return a;

    return 0;
}