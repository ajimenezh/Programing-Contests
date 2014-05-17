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


int main() {

    long long q;
    cin>>q;

    bool prime = true;
    for (int i=2; i<(int)(sqrt(q)+2.0); i++)
    {
        if (q%i==0 && q!=i)
        {
            prime = false;
            break;
        }
    }

    if (prime || q==1)
    {
        cout<<1<<endl;
        cout<<0<<endl;
        return 0;
    }

    int p[2];
    int n = 0;

    int k = (int)(sqrt(q)+2.0);

    for (int i=2; i<k; i++)
    {
        if (q%i==0)
        {
            while (q%i==0)
            {
                p[n++] = i;
                q /= i;
                if (n==2) break;
            }
            if (n==2) break;
        }
    }

    if (q!=1 && n==2)
    {
        cout<<1<<endl;
        cout<<p[0]*p[1]<<endl;
    }
    else cout<<2<<endl;

	return 0;

}
