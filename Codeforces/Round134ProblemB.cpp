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

int n,r;

int rec1(int a, int b) {
    if (a<b) return rec1(b,a);
    if (b==0 && a==1) return 0;
    if (b==0 && a!=1) return 10000000;

    return a/b + rec1(b,a%b);
}

int rec2(int a, int b) {
    if (a<b) return rec2(b,a);
    if (b==1) return a-2;
    if (b==0) return 0;

    return a/b - 1 + rec2(b,a%b);
}

void print(int a, int b, int p) {
    if (a<b) {print(b,a,p); return;}
    if (a==2 && b==1) {
        p==1 ? cout<<"TB" : cout<<"BT";
        return;
    }
    if (b==0) return;

    for (int i=0; i<a/b; i++) {
        if (b==1 && i==a/b-1) {
            p==1 ? cout<<"B": cout<<"T";
            return;
        }
        p==1 ? cout<<"T": cout<<"B";
    }
    print(b,a%b,1-p);
    return;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>r;

    int best = 1000010;
    int sol;

    if (n==1 && r==1) {
        cout<<0<<endl;
        cout<<"T"<<endl;
        return 0;
    }

    for (int i=1; i<r; i++) {
        int t = rec1(r,i);

        if (t==n) {
            //cout<<t<<" "<<rec2(r,i)<<" "<<i<<endl;
            t = rec2(r,i);
            if (t<best) {
                best = t;
                sol = i;
            }
        }
        //cout<<t<<endl;
    }

    if (best == 1000010) {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }

    cout<<best<<endl;
    print(r,sol,1);

    return 0;

}
