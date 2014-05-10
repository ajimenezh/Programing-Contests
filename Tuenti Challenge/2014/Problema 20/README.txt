Challenge 20 - forfor

First, let's understand what the problem is asking us to so, it seems that it is the problem number partition with two important differences, the first one, it has to be divided in seven POSITIVE numbers, but if we make the transformation n = n'-7, we simplify the problem into finding a partition of NON-NEGATIVE numbers.

The second difficulty is that we don't have to find the number of partitions, which would be C(n + (k-1), k-1) where C() is the binomial coefficient (This number gives the number of ways of distributing n objects into k categories allowing repetition), but what we have to find is the some of every weight, whre we define  the weight as the square of each element of the partition.

This problem can be solved by dynamic programing defining the state (s,k) as being in category (for loop) k-th with s elements remaining to distribute.
The recursion of the dp problem is:

long long solve(int n, int k) {
    if (k==6) return (n+1)*(n+1);
    if (dp[n][k]>=0) return dp[n][k];

    long long tmp = 0;
    for (int i=0; i<=n; i++) {
        long long t = solve(n-i, k+1);
        tmp = (tmp + t)%mod;
        tmp = (tmp + c[n-i+(7-k-2)][(7-k-2)]*(i+1)*(i+1))%mod;
    }

    dp[n][k] = tmp;

    return tmp;
}

where as before c[a][b] is the binomial coefficient. This solution has complexity O(n^2*k), and although it can be optimized, it isn't enough.

Here, I just thought that maybe the solution would be a polynomial on n, and in this case the order of the solution would be O(C(n + (k-1), k-1) * weight). It is clear that tha binomial coefficient has order n^6 and the weight has order n^2 by definition, so the polynomial, if it exists, has order 8.

To find the polynomial coefficients we solve the system of equation for the first 8 solutions (we know thta P(0)=0), finding the value P(n_i) by the given formula. As this system of equation is small (8x8) we use the Gauss elimination method.

All the coefficients are doubles, but if we divide by a_8 (being a_8 the term that multiplies n^8) we obtain that every coefficient is an integer, but we have to remember that later we have to divide by 1/a_8. We do this because the problem ask us for the solution modulo a number, an it's easier to work with integers.

The solution to the problem is P(n) (remember that n is N-7, whre N is the original parameter n) divided by (1/a_8).

Then the last problem is how to find (P'(n)/(1/a_8))%mod, to solve this we use Fermat Little Theorem that says a^p-2 = 1/a (mod p), so to obtain (P'(n)/(1/a_8))%mod, we have to find P'(n)*(1/a_8^(mod-2))%mod using exponentation by squaring.


