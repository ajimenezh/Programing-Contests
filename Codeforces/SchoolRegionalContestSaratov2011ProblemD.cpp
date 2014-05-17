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

int n,m;
int a[55][55];
int sum[55];
int A,B,C;

int main() {

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) cin>>a[i][j];
    cin>>A>>B>>C;
    int tot = 0;
    for (int i=0; i<n; i++) {
        sum[i] = 0;
        for (int j=0; j<m; j++) sum[i] += a[i][j];
    }
    for (int i=1; i<n; i++) sum[i] += sum[i-1];

    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n-1; j++) {
            if (sum[i]==A && (sum[j]-sum[i])==B && (sum[n-1]-sum[j])==C) tot++;
            else if (sum[i]==A && (sum[j]-sum[i])==C && (sum[n-1]-sum[j])==B) tot++;
            else if (sum[i]==B && (sum[j]-sum[i])==A && (sum[n-1]-sum[j])==C) tot++;
            else if (sum[i]==B && (sum[j]-sum[i])==C && (sum[n-1]-sum[j])==A) tot++;
            else if (sum[i]==C && (sum[j]-sum[i])==A && (sum[n-1]-sum[j])==B) tot++;
            else if (sum[i]==C && (sum[j]-sum[i])==B && (sum[n-1]-sum[j])==A) tot++;
        }
    }

    for (int i=0; i<m; i++) {
        sum[i] = 0;
        for (int j=0; j<n; j++) sum[i] += a[j][i];
    }
    for (int i=1; i<m; i++) sum[i] += sum[i-1];

    for (int i=0; i<m; i++) {
        for (int j=i+1; j<m-1; j++) {
            //cout<<i<<" "<<j<<" "<<sum[i]<<" "<<(sum[j]-sum[i])<<" "<<(sum[m-1]-sum[j])<<endl;
            if (sum[i]==A && (sum[j]-sum[i])==B && (sum[m-1]-sum[j])==C) tot++;
            else if (sum[i]==A && (sum[j]-sum[i])==C && (sum[m-1]-sum[j])==B) tot++;
            else if (sum[i]==B && (sum[j]-sum[i])==A && (sum[m-1]-sum[j])==C) tot++;
            else if (sum[i]==B && (sum[j]-sum[i])==C && (sum[m-1]-sum[j])==A) tot++;
            else if (sum[i]==C && (sum[j]-sum[i])==A && (sum[m-1]-sum[j])==B) tot++;
            else if (sum[i]==C && (sum[j]-sum[i])==B && (sum[m-1]-sum[j])==A) tot++;
        }
    }

    cout<<tot<<endl;

    return 0;

}
