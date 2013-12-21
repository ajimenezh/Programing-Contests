#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
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

vector<int> e1, e2;
long long sum1[100010];
long long sum2[100010];
int n,d,s;
int all;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>d>>s;
    for (int i=0; i<n; i++) {
        int c,f,l;
        scanf("%d%d%d",&c,&f,&l);
        if (c==0 && l>=d) e1.push_back(f);
        else {
            all = min(all + c, n);
            if (l>=d) e2.push_back(f);
        }
    }
    e1.push_back(0);
    e2.push_back(0);
    sort(e1.begin(),e1.begin());
    sort(e2.begin(),e2.begin());

    for (int i=1; i<e2.size(); i++) sum2[i] = sum2[i-1] + e2[i];
    for (int i=1; i<e1.size(); i++) sum1[i] = sum1[i-1] + e1[i];


    int i = e1.size()-1;

    int p = 0, q = 1000000;
    for (int j=0; j<e2.size(); j++) {
        if (sum2[j]>s) break;
        while (sum1[i]+sum2[j]>s) i--;
        while (i>0&&i+j+(j?all:0)>n) i--;
        int tmp = i+j+(j?all:0);
        tmp = min(tmp, n);
        if (p<tmp || (p==tmp && sum1[i]+sum2[j]<q)) {
            p = tmp;
            q = sum1[i]+sum2[j];
        }
    }

    cout<<p<<" "<<q<<endl;

    return 0;

}
