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

int n;
int a[100010];
map<int,int> cnt;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) scanf("%d", a+i);

    if (n==1) {
        cout<<-1;
    }
    else {
        sort(a,a+n);
        for (int i=0; i<n-1; i++) cnt[a[i+1]-a[i]]++;
        int t = 0;
        rep(it, cnt) t++;
        if (t==1) {
            int k = a[1]-a[0];
            if (k!=0) {
                if (n==2 && k%2==0) {
                    cout<<3<<endl;
                    cout<<a[0]-k<<" "<<a[0]+k/2<<" "<<a[n-1]+k<<endl;
                }
                else {
                    cout<<2<<endl;
                    cout<<a[0]-k<<" "<<a[n-1]+k<<endl;
                }
            }
            else {
                cout<<1<<endl;
                cout<<a[0]<<endl;
            }
        }
        else if (t>2) cout<<0<<endl;
        else {
            int p = -1;
            int u = -1;
            int k = -1;
            rep(it, cnt) {
                if ((*it).second==1) {
                    if (p==-1) p = (*it).first;
                    else u = (*it).first;
                }
                else k = (*it).first;
            }
            vector<int> v;
            for (int i=0; i<n-1; i++) {
                if (a[i+1]-a[i]==p && p!=-1) {
                    if (u!= -1 && a[i]+2*u==a[i+1]) v.push_back(a[i]+u);
                    else if (k!= -1 && a[i]+2*k==a[i+1]) v.push_back(a[i]+k);
                }
                if (a[i+1]-a[i]==u && u!=-1) {
                    if (p!=-1 && a[i]+2*p==a[i+1]) v.push_back(a[i]+p);
                    else if (k!= -1 && a[i]+2*k==a[i+1]) v.push_back(a[i]+k);
                }
            }
            cout<<v.size()<<endl;
            for (int i=0; i<v.size(); i++) {
                cout<<v[i]<<" ";
            }
        }
    }

    return 0;

}
