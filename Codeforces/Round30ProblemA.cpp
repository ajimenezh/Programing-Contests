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

int fpow(int a, int b) {
    if (b==0) return 1;
    return a*fpow(a,b-1);
}

int f(int a, int b) {
    for (int i=0; i<=1000; i++) {
        if (a*fpow(i,n)>b) break;
        if (a*fpow(i,n)==b) return i;
    }
    return -1;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int a,b;
    cin>>a>>b>>n;

    if (a==0) {
        if (b==0) cout<<0<<endl;
        else cout<<"No solution"<<endl;
    }
    else {
        if (a<0) {
            if (b>0) {
                if (n%2==0) cout<<"No solution"<<endl;
                else {
                    if (f(-a,b)>=0) cout<<-f(-a,b)<<endl;
                    else cout<<"No solution"<<endl;
                }
            }
            else if (b==0) cout<<0<<endl;
            else {
                if (f(-a,-b)>=0) cout<<f(-a,-b)<<endl;
                else cout<<"No solution"<<endl;
            }
        }
        else {
            if (b<0) {
                if (n%2==0) cout<<"No solution"<<endl;
                else {
                    if (f(a,-b)>=0) cout<<-f(a,-b)<<endl;
                    else cout<<"No solution"<<endl;
                }
            }
            else if (b==0) cout<<0<<endl;
            else {
                if (f(a,b)>=0) cout<<f(a,b)<<endl;
                else cout<<"No solution"<<endl;
            }
        }
    }

    return 0;

}
