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

int sumx[110];
int sumy[110];
string s;
long long a,b;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>a>>b;
    cin>>s;

    sumx[0] = 0;
    sumy[0] = 0;
    for (int i=0; i<s.length(); i++) {
        if (s[i]=='U') {
            sumx[i+1] = sumx[i];
            sumy[i+1] = sumy[i] + 1;
        }
        if (s[i]=='D') {
            sumx[i+1] = sumx[i];
            sumy[i+1] = sumy[i] - 1;
        }
        if (s[i]=='L') {
            sumx[i+1] = sumx[i]-1;
            sumy[i+1] = sumy[i];
        }
        if (s[i]=='R') {
            sumx[i+1] = sumx[i]+1;
            sumy[i+1] = sumy[i];
        }
    }

    int n = s.length();
    for (int i=0; i<s.length(); i++) {
        if (sumx[n]!=0) {
            if ((a-sumx[i])%sumx[n]==0) {
                long long x = (a-sumx[i])/sumx[n];
                if (x>=0) {
                    if (sumy[n]!=0) {
                        if ((b-sumy[i])%sumy[n]==0&&(b-sumy[i])/sumy[n]==x) {
                            cout<<"Yes"<<endl;
                            return 0;
                        }
                    }
                    else {
                        if (sumy[i]==b) {
                            cout<<"Yes";
                            return 0;
                        }
                    }
                }
            }
        }
        else {
            if (sumx[i]==a) {
                if (sumy[n]!=0) {
                    if ((b-sumy[i])%sumy[n]==0&&(b-sumy[i])/sumy[n]>=0) {
                        cout<<"Yes"<<endl;
                        return 0;
                    }
                }
                else {
                    if (sumy[i]==b) {
                        cout<<"Yes";
                        return 0;
                    }
                }
            }
        }
    }
    cout<<"No"<<endl;

    return 0;

}
