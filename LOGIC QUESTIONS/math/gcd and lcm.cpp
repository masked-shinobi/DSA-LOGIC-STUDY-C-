#include <bits/stdc++.h>

// gcd iterative
while(b != 0) {
    int rem = a % b;
    a = b;
    b = rem;
}

return a;
// gcd recursive
if(b == 0)
    return a;

return gcd(b, a % b);
// LCM
LCM(a, b) = (a / GCD(a, b)) * b;