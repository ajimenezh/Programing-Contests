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

int n;
int a[100010];
set<int> s;

int main() {

    cin>>n;
    fo(i,n) scanf("%d",&a[i]);

    for (int i=0; i<21; i++)
    {
        int est = 0;
        int act = 0;
        for (int j=0; j<n; j++)
        {
            if (est==0 && ((1<<i)&a[j]) || est==1 && !((1<<i)&a[j]))
            {
                est = 1-est;
                s.insert(a[j]|act);
                act = 0;
            }
            act |= a[j];
            s.insert(act);
            //cout<<act<<endl;
        }
    }

    cout<<s.size();


	return 0;

}
