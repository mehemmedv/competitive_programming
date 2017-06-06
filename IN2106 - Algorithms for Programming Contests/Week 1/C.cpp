#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;

int main()
{
    cin>>t;
    long long c = 299792458;
    for(int i = 1; i<= t; ++i){
        int n;
        cin>>n;
        char ch;
        cin>>ch;
        string str;
        getline(cin, str);

        cout<<"Case #"<<i<<": ";
        for(int i = n; i < str.size(); ++i)
            cout<<str[i];

        for(int i = 0; i < n; ++i)
            cout<<str[i];
        cout<<endl;
    }
    return 0;
}