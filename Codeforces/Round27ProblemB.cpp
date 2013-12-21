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
set<pair<int,int> > all;
int x[2500], y[2500];

bool inside(int a, vector<int> v) {
    for (int i=0; i<v.size(); i++) if (v[i]==a) return true;
    return false;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n*(n-1)/2-1; i++) {
        int a,b;
        cin>>a>>b;
        x[i] = a;
        y[i] = b;
        if (a>b) swap(a,b);
        all.insert(make_pair(a,b));
    }
    int a,b;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (all.find(make_pair(i+1,j+1))==all.end()) {
                a = i+1;
                b = j+1;
                break;
            }
        }
    }

    vector<int> l1,l2,r1,r2;
    for (int i=0; i<n*(n-1)/2-1; i++) {
        if (x[i]==a) {
            r1.push_back(y[i]);
        }
        if (y[i]==a) {
            l1.push_back(x[i]);
        }
        if (x[i]==b) {
            r2.push_back(y[i]);
        }
        if (y[i]==b) {
            l2.push_back(x[i]);
        }
    }

    //for (int i=0; i<r1.size(); i++) cout<<r1[i]<<" "; cout<<endl;
    //for (int i=0; i<l1.size(); i++) cout<<l1[i]<<" "; cout<<endl;
    //for (int i=0; i<r2.size(); i++) cout<<r2[i]<<" "; cout<<endl;
    //for (int i=0; i<l2.size(); i++) cout<<l2[i]<<" "; cout<<endl;

    for (int i=0; i<r1.size(); i++) {
        if (inside(r1[i], l2)) {
            cout<<a<<" "<<b<<endl;
            return 0;
        }
    }
    cout<<b<<" "<<a<<endl;

    return 0;

}
