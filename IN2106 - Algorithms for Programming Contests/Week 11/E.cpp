#include <bits/stdc++.h>

using namespace std;

int ans[1010][110], mini[1010][110];
int w[1010];

int sum[1010];

int main(){
	int t, n, a, b;

	cin>>t;
	for(int c = 1; c <= t; ++c){
		for(int i = 0; i <= 1005; ++i)
		for(int j = 0; j <= 105; ++j)
			ans[i][j]=mini[i][j]=1000000000;
		cin>>n>>a>>b;
		for(int i = 1; i <= n; ++i)
			cin>>w[i];

        for(int i = 1; i <= n; ++i)
            sum[i] = sum[i-1] + w[i];

		ans[0][0] = mini[0][0] = 0;
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= 100 && j <= i; ++j){
			    if(sum[i] - sum[i-j] > b)
                    break;

				for(int k = 0; k <= 100 && k <= i-j; ++k){
					if(mini[i-j][k] < 1000000000){

                        if(mini[i][j] > mini[i-j][k] + 1){
                            mini[i][j] = mini[i-j][k] + 1;

                            if(sum[i] - sum[i-j] > a)
                                ans[i][j] = ans[i-j][k] + (sum[i] - sum[i-j] - a)*(sum[i] - sum[i-j] - a);
                            else
                                ans[i][j] = ans[i-j][k];

                            //cout<<i<<" "<<j<<" "<<i-j<<" "<<k<<" "<<ans[i][j]<<" "<<mini[i][j]<<endl;
                        } else if(mini[i][j] == mini[i-j][k] + 1){
                            //ans[i][j] = min(ans[i][j], ans[i-j][k] + (sum[i] - sum[i-j])*(sum[i] - sum[i-j]));
                            if(sum[i] - sum[i-j] > a)
                                ans[i][j] = min(ans[i][j], ans[i-j][k] + (sum[i] - sum[i-j] - a)*(sum[i] - sum[i-j] - a));
                            else
                                ans[i][j] = min(ans[i][j], ans[i-j][k]);
                            //cout<<i<<" "<<j<<" "<<i-j<<" "<<k<<" "<<ans[i][j]<<" "<<mini[i][j]<<endl;
                        }
					}
				}
			}
		}

		int res = INT_MAX;

        int cur = 1000000000;

		for(int i = 1; i <= 100; ++i)
            if(mini[n][i] < cur)
                res = ans[n][i], cur = mini[n][i];
            else if(mini[n][i] == cur)
                res = min(res, ans[n][i]), cur = mini[n][i];

        cout<<"Case #"<<c<<": ";
        if(res > 500000000)
            cout<<"impossible\n";
        else
            cout<<res<<"\n";

	}

	return 0;
}
