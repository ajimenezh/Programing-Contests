#include <iostream>
using namespace std;

int m;

int main() {

    cin>>m;
    for (int i=0; i<m; i++) {
        int n,l,r;
        cin>>n>>l>>r;
        if (n>=l && n<=r) cout<<"Yes\n";
        else if (n<l) cout<<"No\n";
        else {
            bool done = 0;
            for (int i=l; i<=min(l+32000, r); i++) {
                int k = n%i;
                if (k==0 || k>=l) {
                    cout<<"Yes\n";
                    done = 1;
                    break;
                }
                else {
                    k += i;
                    if (k<=r) {
                        cout<<"Yes\n";
                        done = 1;
                        break;
                    }
                }
            }
            if (!done) {
                for (int i=r; i>=max(r-32000, l); i--) {
                    int k = n%i;
                    if (k==0 || k>=l) {
                        cout<<"Yes\n";
                        done = 1;
                        break;
                    }
                    else {
                        k += i;
                        if (k<=r) {
                            cout<<"Yes\n";
                            done = 1;
                            break;
                        }
                    }
                }
            }
            if (!done) {
                for (int i=2; (long long)i*i<=n; i++) if (n%i==0) {
                    if (i>=l && i<=r) {
                        cout<<"Yes\n";
                        done = 1;
                        break;
                    }
                    if (n/i>=l && n/i<=r) {
                        cout<<"Yes\n";
                        done = 1;
                        break;
                    }
                }
            }
            if (!done) cout<<"No\n";
        }
    }

    return 0;

}
