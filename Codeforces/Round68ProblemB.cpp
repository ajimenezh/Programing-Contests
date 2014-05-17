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

int n,m,k;
int to;
string s;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m>>k;
    m--; k--;
    swap(m,k);
    cin>>s>>s;
    if (s[0]=='t') to = -1;
    else to = 1;
    cin>>s;
    bool win = 0;
    int p = 0;
    for (int i=0; i<s.length(); i++) {
        //cout<<m<<" "<<k<<endl;
        if (s[i]=='1') {
            if (m==1 && to==1) {
                m = 0;
                to = -1;
                k = n-1;
            }
            else if (m==n-2 && to==-1) {
                m = n-1;
                to = 1;
                k = 0;
            }
            else {
                if (to==1) {
                    k = n-1;
                    m = m-1;
                }
                else {
                    k = 0;
                    m = m+1;
                }
            }
        }
        else {
            if (to==1) {
                if (k<=m) {
                    k = max(0, k-1);
                    m--;
                    if (m==0) {
                        to = -1;
                    }
                }
                else {
                    k = min(n-1, k+1);
                    m--;
                    if (m==0) {
                        to = -1;
                    }
                }
            }
            else {
                if (k>=m) {
                    k = min(n-1, k+1);
                    m++;
                    if (m==n-1) {
                        to = 1;
                    }
                }
                else {
                    k = max(0, k-1);
                    m++;
                    if (m==n-1) {
                        to = 1;
                    }
                }
            }
        }
        if (k==m) {
            win = 1;
            p = i+1;
            break;
        }
    }

    if (win) cout<<"Controller "<<p<<endl;
    else cout<<"Stowaway"<<endl;

    return 0;

}
