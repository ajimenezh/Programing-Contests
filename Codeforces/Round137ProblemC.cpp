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

int n,m;
int num[100010];
int den[100010];
int isprime[10000010];
int prime[10000000];
map<int,int> cnt;
vector<int> numsol;
vector<int> densol;

int main() {

	//freopen("input.txt","r",stdin);
   	//freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<n; i++) scanf("%d",&num[i]);
    for (int i=0; i<m; i++) scanf("%d",&den[i]);

    for (int i=0; i<10000002; i++) isprime[i] = i;

    int tot = 0;

    for (long long i=2; i<=10000000; i++) {
        if (isprime[i]==i) prime[tot++] = i;
        for (int j=0; j<tot && prime[j]<=isprime[i]; j++) {
            long long t = (long long)prime[j]*(long long)i;
            if (t>10000002) break;
            isprime[t] = prime[j];
        }
    }

    for (int i=2; i<=10000000; i++) if (isprime[i]==i) cnt[i] = 0;

    //for (int i=2; i<20; i++) cout<<i<<" "<<isprime[i]<<endl;

    for (int i=0; i<n; i++) {
        int k = num[i];
        while (isprime[k]!=k) {
            int j = isprime[k];
            while (k>0 && k%j==0) {
                cnt[j]++;
                k /= j;
            }
        }
        if (k!=1) cnt[k]++;
    }

    for (int i=0; i<m; i++) {
        int k = den[i];
        while (isprime[k]!=k) {
            int j = isprime[k];
            while (k>0 && k%j==0) {
                cnt[j]--;
                k /= j;
            }
        }
        if (k!=1) cnt[k]--;
    }


    for (int i=0; i<n; i++) {
        int k = num[i];
        int t=1;
        while (isprime[k]!=k) {
            int j = isprime[k];
            while (k>0 && k%j==0) {
                if (cnt[j]>0) {t*=j; cnt[j]--;}
                k /= j;
            }
        }
        if (k!=1) if (cnt[k]>0) {t*=k; cnt[k]--;}
        numsol.push_back(t);
    }

    for (int i=0; i<m; i++) {
        int k = den[i];
        int t=1;
        while (isprime[k]!=k) {
            int j = isprime[k];
            while (k>0 && k%j==0) {
                if (cnt[j]<0) {t*=j; cnt[j]++;}
                k /= j;
            }
        }
        if (k!=1) if (cnt[k]<0) {t*=k; cnt[k]++;}
        densol.push_back(t);
    }

    if (densol.size()==0) densol.push_back(1);
    if (numsol.size()==0) numsol.push_back(1);

    cout<<numsol.size()<<" "<<densol.size()<<endl;
    for (int i=0; i<numsol.size(); i++) printf("%d ",numsol[i]);
    cout<<endl;
    for (int i=0; i<densol.size(); i++) printf("%d ",densol[i]);
    cout<<endl;

	return 0;

}
