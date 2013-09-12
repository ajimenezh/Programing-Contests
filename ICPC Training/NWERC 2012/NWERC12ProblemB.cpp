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

int N,K;
float dp[50][50][50][50][2];
int a[5];
float b[5];

int main() {

    //freopen("C:\\Users\\Alex\\Documents\\ProgrammingContests\\NWERC12\NWERC_2012_ProblemSet_TestCases_Solutions\\NWERC_2012_ProblemSet_TestCases_Solutions\\B\\Beer","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>N>>K;
    for (int i=0; i<N; i++) cin>>a[i];
    int sum = 0;
    for (int i=0; i<N; i++) sum += a[i];

    fo(i,K) fo(j,K) fo(k,K) fo(m,K) dp[i][j][k][m][0] = 0.0;
    fo(i,K) fo(j,K) fo(k,K) fo(m,K) dp[i][j][k][m][1] = 0.0;

    if (N==1) {
        printf("pub 1: %.2f %\n",100.0);
    }
    else if (N==2) {
        dp[a[0]][0][0][0][1-sum%2] = 1.0;
        for (int c=sum; c<K; c++) {
            fo(i,50) {
                if (i>c) break;
                dp[i][0][0][0][c%2] = 0.0;
            }
            fo(i,50) {
                if (i>c) break;
                if (i>0) dp[i][0][0][0][c%2] += dp[i-1][0][0][0][1-c%2]*(1.0*(i-1))/(1.0*(c));
                dp[i][0][0][0][c%2] += dp[i][0][0][0][1-c%2]*(1.0*(c-i))/(1.0*(c));
            }
        }

        for (int i=0; i<50; i++) {
            if (i>K) break;
            if (i>K-i) b[0] += dp[i][0][0][0][1-K%2];
            else if (i==K-i) {
                b[0] += dp[i][0][0][0][1-K%2]/2;
                b[1] += dp[i][0][0][0][1-K%2]/2;
            }
            else {
                b[1] += dp[i][0][0][0][1-K%2];
            }
        }

        printf("pub 1: %.2f %\n",100.0*b[0]);
        printf("pub 2: %.2f %\n",100.0*b[1]);
    }
    else if (N==3) {
        dp[a[0]][a[1]][0][0][1-sum%2] = 1.0;
        for (int c=sum; c<K; c++) {
            fo(i,50) {
                if (i>c) break;
                fo(j,50) {
                    if (i+j>c) break;
                    dp[i][j][0][0][c%2] = 0.0;
                }
            }
            fo(i,50) {
                if (i>c) break;
                fo(j,50) {
                    if (i+j>c) break;
                    if (i>0) dp[i][j][0][0][c%2] += dp[i-1][j][0][0][1-c%2]*(1.0*(i-1))/(1.0*(c));
                    if (j>0) dp[i][j][0][0][c%2] += dp[i][j-1][0][0][1-c%2]*(1.0*(j-1))/(1.0*(c));
                    dp[i][j][0][0][c%2] += dp[i][j][0][0][1-c%2]*(1.0*(c-i-j))/(1.0*(c));
                }
            }
        }

        for (int i=0; i<50; i++) {
            if (i>K) break;
            for (int j=0; j<50; j++) {
                if (i+j>K) break;
                if (i>K-i-j && i>j) b[0] += dp[i][j][0][0][1-K%2];
                else if (j>K-i-j && i<j) b[1] += dp[i][j][0][0][1-K%2];
                else if (i==K-i-j && j==i) {
                    b[0] += dp[i][j][0][0][1-K%2]/3;
                    b[1] += dp[i][j][0][0][1-K%2]/3;
                    b[2] += dp[i][j][0][0][1-K%2]/3;
                }
                else if (i==K-i-j && j<i) {
                    b[0] += dp[i][j][0][0][1-K%2]/2;
                    b[2] += dp[i][j][0][0][1-K%2]/2;
                }
                else if (i==j && j>K-i-j) {
                    b[0] += dp[i][j][0][0][1-K%2]/2;
                    b[1] += dp[i][j][0][0][1-K%2]/2;
                }
                else if (K-i-j==j && j>i) {
                    b[2] += dp[i][j][0][0][1-K%2]/2;
                    b[1] += dp[i][j][0][0][1-K%2]/2;
                }
                else {
                    b[2] += dp[i][j][0][0][1-K%2];
                }
            }
        }

        printf("pub 1: %.2f %\n",100.0*b[0]);
        printf("pub 2: %.2f %\n",100.0*b[1]);
        printf("pub 3: %.2f %\n",100.0*b[2]);
    }
    else if (N==4) {
        dp[a[0]][a[1]][a[2]][0][1-sum%2] = 1.0;
        for (int c=sum; c<K; c++) {
            fo(i,50) {
                if (i>c) break;
                fo(j,50) {
                    if (i+j>c) break;
                    fo(k,50) {
                        if (i+j+k>c) break;
                        dp[i][j][k][0][c%2] = 0.0;
                    }
                }
            }
            fo(i,50) {
                if (i>c) break;
                fo(j,50) {
                    if (i+j>c) break;
                    fo(k,50) {
                        if (i+j+k>c) break;
                        if (i>0) dp[i][j][k][0][c%2] += dp[i-1][j][k][0][1-c%2]*(1.0*(i-1))/(1.0*(c));
                        if (j>0) dp[i][j][k][0][c%2] += dp[i][j-1][k][0][1-c%2]*(1.0*(j-1))/(1.0*(c));
                        if (k>0) dp[i][j][k][0][c%2] += dp[i][j][k-1][0][1-c%2]*(1.0*(k-1))/(1.0*(c));
                        dp[i][j][k][0][c%2] += dp[i][j][k][0][1-c%2]*(1.0*(c-i-j-k))/(1.0*(c));
                    }
                }
            }
        }

        for (int i=0; i<50; i++) {
            if (i>K) break;
            for (int j=0; j<50; j++) {
                if (i+j>K) break;
                for (int k=0; k<50; k++) {
                    if (i+j+k>K) break;
                    int maximo = max(max(i,j),max(k,K-i-j-k));
                    int cnt = 0;
                    if (i==maximo) cnt++;
                    if (j==maximo) cnt++;
                    if (k==maximo) cnt++;
                    if (K-i-j-k==maximo) cnt++;

                    if (i==maximo) b[0] += dp[i][j][k][0][1-K%2]/(1.0*cnt);
                    if (j==maximo) b[1] += dp[i][j][k][0][1-K%2]/(1.0*cnt);
                    if (k==maximo) b[2] += dp[i][j][k][0][1-K%2]/(1.0*cnt);
                    if (K-i-j-k==maximo) b[3] += dp[i][j][k][0][1-K%2]/(1.0*cnt);
                }
            }
        }

        printf("pub 1: %.2f %\n",100.0*b[0]);
        printf("pub 2: %.2f %\n",100.0*b[1]);
        printf("pub 3: %.2f %\n",100.0*b[2]);
        printf("pub 4: %.2f %\n",100.0*b[3]);
    }
    else if (N==5) {
        dp[a[0]][a[1]][a[2]][a[3]][1-sum%2] = 1.0;
        for (int c=sum; c<K; c++) {
            fo(i,50) {
                if (i>c) break;
                fo(j,50) {
                    if (i+j>c) break;
                    fo(k,50) {
                        if (i+j+k>c) break;
                        fo(m,50) {
                            if (i+j+k+m>c) break;
                            dp[i][j][k][m][c%2] = 0.0;
                        }
                    }
                }
            }
            fo(i,50) {
                if (i>c) break;
                fo(j,50) {
                    if (i+j>c) break;
                    fo(k,50) {
                        if (i+j+k>c) break;
                        fo(m,50) {
                            if (i+j+k+m>c) break;
                            if (i>0) dp[i][j][k][m][c%2] += dp[i-1][j][k][m][1-c%2]*(1.0*(i-1))/(1.0*(c));
                            if (j>0) dp[i][j][k][m][c%2] += dp[i][j-1][k][m][1-c%2]*(1.0*(j-1))/(1.0*(c));
                            if (k>0) dp[i][j][k][m][c%2] += dp[i][j][k-1][m][1-c%2]*(1.0*(k-1))/(1.0*(c));
                            if (m>0) dp[i][j][k][m][c%2] += dp[i][j][k][m-1][1-c%2]*(1.0*(m-1))/(1.0*(c));
                            dp[i][j][k][m][c%2] += dp[i][j][k][m][1-c%2]*(1.0*(c-i-j-k-m))/(1.0*(c));
                        }
                    }
                }
            }
        }

        for (int i=0; i<50; i++) {
            if (i>K) break;
            for (int j=0; j<50; j++) {
                if (i+j>K) break;
                for (int k=0; k<50; k++) {
                    if (i+j+k>K) break;
                    for (int m=0; m<50; m++) {
                        if (i+j+k+m>K) break;
                        int maximo = max(max(i,j),max(k,K-i-j-k-m));
                        maximo = max(maximo,m);
                        int cnt = 0;
                        if (i==maximo) cnt++;
                        if (j==maximo) cnt++;
                        if (k==maximo) cnt++;
                        if (m==maximo) cnt++;
                        if (K-i-j-k-m==maximo) cnt++;

                        if (i==maximo) b[0] += dp[i][j][k][m][1-K%2]/(1.0*cnt);
                        if (j==maximo) b[1] += dp[i][j][k][m][1-K%2]/(1.0*cnt);
                        if (k==maximo) b[2] += dp[i][j][k][m][1-K%2]/(1.0*cnt);
                        if (m==maximo) b[3] += dp[i][j][k][m][1-K%2]/(1.0*cnt);
                        if (K-i-j-k-m==maximo) b[4] += dp[i][j][k][m][1-K%2]/(1.0*cnt);
                    }
                }
            }
        }

        printf("pub 1: %.2f %\n",100.0*b[0]);
        printf("pub 2: %.2f %\n",100.0*b[1]);
        printf("pub 3: %.2f %\n",100.0*b[2]);
        printf("pub 4: %.2f %\n",100.0*b[3]);
        printf("pub 5: %.2f %\n",100.0*b[4]);
    }


    return 0;

}
