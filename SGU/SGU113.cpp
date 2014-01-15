#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <stdio.h>

using namespace std;

#define fo(i,n) for(int i=0; i<(int)n; i++)
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

bool ispr[32000];
bool isprime(int a) {
    for (int i=2; i*i<=a; i++) if (a%i==0) return false;
    return true;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    for (int i=2; i<32000; i++) ispr[i] = 1;
    for (int i=2; i*i<32000; i++) if (ispr[i]) {
        for (int j=i*i; j<32000; j += i) ispr[j] = 0;
    }

    int n;
    cin>>n;
    while (n--) {
        int a;
        cin>>a;
        bool is = 0;
        for (int i=2; (long long)i*(long long)i<=a; i++) if (a%i==0 && ispr[i] && isprime(a/i)) {
            is = 1;
            break;
        }
        cout<<(is?"Yes":"No")<<endl;
    }

    return 0;

}
