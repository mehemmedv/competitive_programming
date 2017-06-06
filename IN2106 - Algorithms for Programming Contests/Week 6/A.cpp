#include <bits/stdc++.h>

using namespace std;

int t, n;

int s1[6][100];
char ch;

int known[10][10];

vector<int> nums[100];
vector<int> subset[100];
bool check(int st1, int st2, int dq1, int dq2, int sttt1, int sttt2, int dqqq1, int dqqq2){
    if(find(subset[st1].begin(), subset[st1].end(), sttt1) == subset[st1].end())
        return false;
    if(find(subset[st2].begin(), subset[st2].end(), sttt2) == subset[st2].end())
        return false;
    if(find(subset[dq1].begin(), subset[dq1].end(), dqqq1) == subset[dq1].end())
        return false;
    if(find(subset[dq2].begin(), subset[dq2].end(), dqqq2) == subset[dq2].end())
        return false;
    return true;
}

bool check_pos(int saat, int deq){
    for(int i = 0; i < 5; ++i)
        for(int j = 0; j < 8; ++j)
            known[i][j] = 0;
    int sss[4];
    sss[0] = saat / 10;
    sss[1] = saat % 10;
    sss[2] = deq / 10;
    sss[3] = deq % 10;

    for(int i = 0; i < n; ++i){

        sss[0] = saat / 10;
        sss[1] = saat % 10;
        sss[2] = deq / 10;
        sss[3] = deq % 10;

        if(check(sss[0], sss[1], sss[2], sss[3], s1[0][i], s1[1][i], s1[2][i], s1[3][i]) == true){
            for(int j = 0; j < 4; ++j){
                for(int k : nums[s1[j][i]]){
                    if(known[j][k] == 2)
                        return false;
                    known[j][k] = 1;
                }
                for(int k : nums[sss[j]]){
                    if(find(nums[s1[j][i]].begin(), nums[s1[j][i]].end(), k) == nums[s1[j][i]].end()){
                        if(known[j][k] == 1)
                            return false;
                        known[j][k] = 2;
                    }
                }
            }
        }
        else
            return false;

        ++deq;
        if(deq == 60)
            deq = 0, ++saat;
        if(saat == 24)
            saat = 0;
    }


    return true;
}



int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    nums[1].push_back(1);
    nums[1].push_back(2);

    nums[2].push_back(1);
    nums[2].push_back(7);
    nums[2].push_back(4);
    nums[2].push_back(3);
    nums[2].push_back(6);

    nums[3].push_back(1);
    nums[3].push_back(2);
    nums[3].push_back(7);
    nums[3].push_back(3);
    nums[3].push_back(6);

    nums[4].push_back(1);
    nums[4].push_back(7);
    nums[4].push_back(2);
    nums[4].push_back(5);

    nums[5].push_back(2);
    nums[5].push_back(7);
    nums[5].push_back(3);
    nums[5].push_back(5);
    nums[5].push_back(6);

    nums[6].push_back(2);
    nums[6].push_back(7);
    nums[6].push_back(4);
    nums[6].push_back(3);
    nums[6].push_back(5);
    nums[6].push_back(6);

    nums[7].push_back(6);
    nums[7].push_back(1);
    nums[7].push_back(2);

    nums[8].push_back(1);
    nums[8].push_back(2);
    nums[8].push_back(3);
    nums[8].push_back(4);
    nums[8].push_back(5);
    nums[8].push_back(6);
    nums[8].push_back(7);

    nums[9].push_back(1);
    nums[9].push_back(2);
    nums[9].push_back(3);
    nums[9].push_back(5);
    nums[9].push_back(6);
    nums[9].push_back(7);

    nums[0].push_back(1);
    nums[0].push_back(2);
    nums[0].push_back(3);
    nums[0].push_back(4);
    nums[0].push_back(5);
    nums[0].push_back(6);

    for(int i = 0; i < 10; ++i)
        for(int j = 0; j < 10; ++j){
            bool flag = true;
            for(int k : nums[i])
                if(find(nums[j].begin(), nums[j].end(), k) == nums[j].end()){
                    flag = false;
                    break;
                }
            if(flag == true)
                subset[j].push_back(i);
        }

    cin>>t;
    char ch;
    vector<int> res1, res2;
    for(int c = 1; c <= t; ++c){
        cin>>n;
        res1.clear();
        res2.clear();

        for(int i = 0; i < n; ++i){
            cin>>ch;
            s1[0][i] = ch - '0';
            cin>>ch;
            s1[1][i] = ch - '0';
            cin>>ch;
            cin>>ch;
            s1[2][i] = ch - '0';
            cin>>ch;
            s1[3][i] = ch - '0';
        }

        for(int i = 0; i < 24; ++i)
            for(int j = 0; j < 60; ++j){
                if(check_pos(i, j) == true){
                    res1.push_back(i);
                    res2.push_back(j);
                }
            }

        cout<<"Case #"<<c<<":"<<endl;
        for(int i = 0; i < res1.size(); ++i)
            cout<<res1[i]/10<<res1[i]%10<<":"<<res2[i]/10<<res2[i]%10<<endl;
        if(res1.size() == 0)
            cout<<"none"<<endl;
    }

    return 0;
}