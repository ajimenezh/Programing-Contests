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
#define forit(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

long long n,K;
long long fact[15];
long long per[15];
long long vi[15];
long long vf[15];

bool lucky(int a) {
    while (a>0)
    {
        if (a%10!=4 && a%10!=7) return false;
        a = a/10;
    }
    return true;
}

long long next(long long a)
{
    long long b = a;
    long long c = 0;
    long long f = 1;
    int si = 0;
    while (b>0) {
        int tmp = b%10;
        if (tmp==4) {
            b = b - 4 + 7;
            c = 0;
            f = 1;
            for (int i=0; i<si; i++) {
                c += 4*f;
                f *= 10;
            }
            return b*f + c;
        }
        c = c + tmp*f;
        f *= 10;
        si++;
        b /= 10;
    }
    c = 0;
    f = 1;
    for (int i=0; i<=si; i++) {
        c += 4*f;
        f *= 10;
    }
    return c;
}

int main() {

	//freopen("input.txt","r",stdin);
   	//freopen("output.txt","w",stdout);

   	cin>>n>>K;
   	K--;

    int t;
    fact[0] = 1;
    for (t=1; t<15; t++) {
        fact[t] = fact[t-1]*(long long)(t);
        if (fact[t]>K) break;
    }

    if (t>n) {cout<<-1; return 0;}

    //cout<<t<<endl;

    for (int i=0; i<t; i++) vi[i] = n-t+i+1;
    //for (int i=0; i<t; i++) cout<<vi[i]<<" "; cout<<endl;
    for (int i=0; i<t; i++) per[i] = i;

    long long k = K;
    for (int i=0; i<t; i++) {
        per[i] = k/fact[t-1-i];
        k = k%fact[t-1-i];
    }

    //for (int i=0; i<t; i++) cout<<per[i]<<" "; cout<<endl;

    for(int i=t-1; i>0; i--) {
        for (int j=i-1; j>=0; j--) {
            if (per[j] <= per[i])
                per[i]++;
        }
    }

    //for (int i=0; i<t; i++) cout<<per[i]<<" "; cout<<endl;

    for (int i=0; i<t; i++) vf[i] = vi[per[i]];
    //for (int i=0; i<(n-t); i++) cout<<(i+1)<<" ";
    //for (int i=0; i<t; i++) cout<<vf[i]<<" "; cout<<endl;

    int res = 0;

    for (int i=0; i<t; i++) {
        //cout<<n-t+i+1<<" "<<vf[i]<<endl;
        if (lucky(n-t+i+1) && lucky(vf[i]))
            res++;
    }

    long long a = 4;

    while (a<=(n-t))
    {
        res++;
        a = next(a);
        //cout<<a<<endl;
    }

    cout<<res<<endl;

	return 0;

}
