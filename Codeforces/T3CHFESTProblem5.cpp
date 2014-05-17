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

int dp[31][2];
int sparse_binary_count ( int A,int B ) {
    if (A>B) return sparse_binary_count(B,A);

    dp[0][0] = 1;
    dp[0][1] = 0;

    for (int i=1; i<31; i++) {
        dp[i][0] = dp[i-1][1]+dp[i-1][0];
        dp[i][1] = dp[i-1][0];
        //cout<<dp[i][0]<<endl;
    }

    int c = 0;
    bool sparseB = true;
    bool vis = false;
    for (int i=30; i>=0; i--) {
        if ((1<<i)&B) {
            c += dp[i+1][0];
            if (vis && ((1<<(i+1))&B==0)) {
                c += dp[i+1][1];
                if (!vis) break;
            }
            else if (vis && ((1<<(i+1))&B)) {
                break;
            }
            vis = true;
        }
        //cout<<i<<" "<<c<<endl;
        if (i>0 && ((1<<i)&B) && (((1<<(i-1))&B)))
            sparseB = false;
    }
    c += sparseB;
    //cout<<c<<endl;
    if (A==0) return c;
    bool sparseA = true;
    vis = true;
    for (int i=30; i>=0; i--) {
        if ((1<<i)&(A-1)) {
            c -= dp[i+1][0];
            if (vis && ((1<<(i+1))&(A-1)==0)) {
                c -= dp[i+1][1];
                if (!vis) break;
                vis = false;
            }
            else if (vis && ((1<<(i+1))&(A-1))) {
                break;
            }
            vis = true;
        }
        if (i>0 && ((1<<i)&(A-1)) && (((1<<(i-1))&(A-1))))
            sparseA = false;
    }

    c -= sparseA;

    return c;
}

bool sparse(int a) {
    if (a==0) return true;
    for (int i=30; i>=0; i--) {
        if (i>0 && ((1<<i)&(a)) && ((1<<(i-1))&(a)))
            return false;
    }
    return true;
}
int f(int a, int b) {
    int c = 0;
    for (int i=a; i<=b; i++) c += sparse(i);
    return c;
}


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);


    for (int i=0; i<30; i++) {
        cout<<f(100,10000+i)<<" "<<sparse_binary_count(100,10000+i)<<endl;
    }


    return 0;

}
