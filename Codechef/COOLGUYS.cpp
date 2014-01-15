#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

long long gcd(long long a, long long b) {
    if (b==0) return a;
    return gcd(b,a%b);
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    while (t--) {
        int n;
        scanf("%d",&n);
        long long sum = 0;
        int root = sqrt((double)n);
        for (int i=1; i<=root; i++) {
            sum += n/i;
        }
        sum = 2LL*sum - (long long)root*root;
        long long den = (long long)n*n;
        long long g = gcd(sum, den);
        cout<<(sum/g)<<"/"<<(den/g)<<"\n";
    }

    return 0;

}
