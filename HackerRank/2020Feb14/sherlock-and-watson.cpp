#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int a[100010];

int main() {

    int n,k,q;
    cin>>n>>k>>q;
    for (int i=0; i<n; i++) scanf("%d",a+i);
    for (int i=0; i<q; i++) {
        int t;
        scanf("%d",&t);
        cout<<a[((t-k)%n+n)%n]<<"\n";
    }

    return 0;
}
