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
#include <windows.h>

using namespace std;

double PCFreq = 0.0;
__int64 CounterStart = 0;

void StartCounter()
{
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
	cout << "QueryPerformanceFrequency failed!\n";

    PCFreq = double(li.QuadPart)/1000.0;

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}
double GetCounter()
{
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/PCFreq;
}

#define fo(i,n) for(int i=0; i<(int)n; i++)
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

string s;
string rev;
int dp[2][20010][3];
int n;
vector<string> vs;

int main() {

    //freopen("input.txt","r",stdin);
    freopen("output2.txt","w",stdout);

    StartCounter();

    while (getline(cin,s) && s.length()>0) {
        //for (int i=0; i<10000; i++) s += char('A');
        //for (int j=0; j<10000; j++) s += char('N');
        rev = s;
        reverse(rev.begin(),rev.end());
        for (int i=0; i<rev.length(); i++) {
            if (rev[i]>='N') rev[i] = char('A' + rev[i]-'N');
            else rev[i] = char('N' + rev[i]-'A');
        }
        //cout<<s<<endl<<rev<<endl;
        n = s.length();

        for (int j=0; j<=n; ++j) {
            for (int k=0; k<3; ++k) {
                dp[0][j][k] = 0;
                dp[1][j][k] = 0;
            }
        }

        int best = 0;
        int p, q;
        int x1,x2,y1,y2;
        for (int i=0; i<n; i++) {
            int cur = i%2;
            int next = 1 - cur;
                for (int j=0; j<n; ++j) {
                    for (int k=0; k<3; ++k) {
                        dp[next][j][k] = 0;
                    }
                }
                for (int j=0; j<n; ++j) {
                    for (int k=0; k<3; ++k) {
                        if (s[i]==rev[j]) {
                            if (1 + dp[cur][j][k] > dp[next][j+1][k])
                                dp[next][j+1][k] = 1 + dp[cur][j][k];
                        }
                        else {
                            if (k>0 && dp[cur][j][k]>dp[cur][j+1][k-1]) dp[cur][j+1][k-1] = dp[cur][j][k];
                        }
                    }
                }
                for (int j=0; j<=n; ++j) {
                    for (int k=0; k<3; ++k) {
                        if (dp[cur][j][k]>best) {
                            x1 = i - dp[cur][j][k];
                            y1 = i - 1;
                            y2 = j - dp[cur][j][k] - (2-k);
                            x2 = j - 1;
                            y2 = n - 1 - y2;
                            x2 = n - 1 - x2;

                            if (x1>y2 || x2>y1) {
                                //cout<<dp[cur][j][k][t]<<" "<<i<<" "<<j<<" "<<k<<endl;
                                //cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;

                                best = dp[cur][j][k];
                                p = x1;
                                q = x2;
                            }
                        }
                    }
                }
        }

        int cur = n%2;
        int i = n;
        for (int j=0; j<=n; j++) {
            for (int k=0; k<3; k++) {
                if (dp[cur][j][k]>best) {
                    x1 = i - dp[cur][j][k];
                    y1 = i - 1;
                    y2 = j - dp[cur][j][k] - (2-k);
                    x2 = j - 1;
                    y2 = n - 1 - y2;
                    x2 = n - 1 - x2;

                    if (x1>y2 || x2>y1) {
                        //cout<<dp[cur][j][k][t]<<" "<<i<<" "<<j<<" "<<k<<endl;
                        //cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;

                        best = dp[cur][j][k];
                        p = x1;
                        q = x2;
                    }
                }
            }
        }

        if (best==0) printf("-\n");
        else {
            cout<<s.substr(p,best)<<"\n";
            printf("%d\n%d\n", p+1, q+1);
        }
        //break;
        //if (getline(cin,s) && s==";") printf(";\n");
        //else break;
    }

    return 0;

}
