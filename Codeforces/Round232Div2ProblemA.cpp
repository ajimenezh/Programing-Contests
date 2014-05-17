#include <iostream>
using namespace std;

int n;
int l[110], r[110];

int main() {

    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>l[i]>>r[i];
    }

    int tot = 0;

    for (int i=0; i<100; i++) if (i>=l[0] && i+1<=r[0]) {
        bool good = 1;
        for (int j=1; j<n; j++) {
            if (i+1<=r[j] && i>=l[j]) good = 0;
        }
        tot += good;
    }

    cout<<tot<<endl;

    return 0;

}

