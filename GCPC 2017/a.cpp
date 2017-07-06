// Team 56 Lambda
#include <bits/stdc++.h>
using namespace std;

int n, x, y, c;
vector<pair<int, int> > point[2], tmp;
vector<pair<double, double> > ans;

int main() {
  //ios::sync_with_stdio(false);
  cin >> n;
  while (n--) {
    cin >> x >> y >> c;
    if (c == 1) point[0].push_back({x, y});
    if (c == 2) point[1].push_back({x, y});
  }
  sort(point[0].begin(), point[0].end());
  sort(point[1].begin(), point[2].end());
  

  ans.push_back({-2000, -2000});
  for (auto p: point[0]) {
    if (tmp.empty() || tmp[0].first == p.first) tmp.push_back(p);
    else {
      double xx = tmp[0].first;
      sort(tmp.begin(), tmp.end());
      reverse(tmp.begin(), tmp.end());
      ans.push_back({xx - 0.4, -2000});
      ans.push_back({xx - 0.4, tmp[0].second + 0.1});
      for (auto pp: tmp) {
        double yy = pp.second;
        ans.push_back({xx - 0.3, yy + 0.1});
        ans.push_back({xx + 0.1, yy + 0.1});
        ans.push_back({xx + 0.1, yy - 0.1});
        ans.push_back({xx - 0.3, yy - 0.1});
      }
      ans.push_back({xx - 0.3, -2000});
      tmp.clear();
      tmp.push_back(p);
    }
  }
  double xx = tmp[0].first;
  sort(tmp.begin(), tmp.end());
  reverse(tmp.begin(), tmp.end());
  ans.push_back({xx - 0.4, -2000});
  ans.push_back({xx - 0.4, tmp[0].second + 0.1});
  for (auto pp: tmp) {
    double yy = pp.second;
    ans.push_back({xx - 0.3, yy + 0.1});
    ans.push_back({xx + 0.1, yy + 0.1});
    ans.push_back({xx + 0.1, yy - 0.1});
    ans.push_back({xx - 0.3, yy - 0.1});
  }
  ans.push_back({xx - 0.3, -2000});

  ans.push_back({2000, -2000});
  ans.push_back({2000, -2001});
  ans.push_back({-2000, -2001});
  cout << ans.size() << endl;
  for (auto p: ans) printf("%.3f %.3f\n", p.first, p.second);
  ans.clear();

  ans.push_back({-2000, 2000});
  tmp.clear();
  for (auto p: point[1]) {
    if (tmp.empty() || tmp[0].first == p.first) tmp.push_back(p);
    else {
      xx = tmp[0].first;
      sort(tmp.begin(), tmp.end());
      reverse(tmp.begin(), tmp.end());
      ans.push_back({xx + 0.3, 2000});
      for (auto pp: tmp) {
        double yy = pp.second;
        ans.push_back({xx + 0.3, yy + 0.1});
        ans.push_back({xx - 0.1, yy + 0.1});
        ans.push_back({xx - 0.1, yy - 0.1});
        ans.push_back({xx + 0.3, yy - 0.1});
      }
      ans.push_back({xx + 0.4, tmp.back().second - 0.1});
      ans.push_back({xx + 0.4, 2000});
      tmp.clear();
      tmp.push_back(p);
    }
  }
  xx = tmp[0].first;
  sort(tmp.begin(), tmp.end());
      reverse(tmp.begin(), tmp.end());
  ans.push_back({xx + 0.3, 2000});
  for (auto pp: tmp) {
    double yy = pp.second;
    ans.push_back({xx + 0.3, yy + 0.1});
    ans.push_back({xx - 0.1, yy + 0.1});
    ans.push_back({xx - 0.1, yy - 0.1});
    ans.push_back({xx + 0.3, yy - 0.1});
  }
  ans.push_back({xx + 0.4, tmp.back().second - 0.1});
  ans.push_back({xx + 0.4, 2000});
  ans.push_back({2000, 2000});
  ans.push_back({2000, 2001});
  ans.push_back({-2000, 2001});
  cout << ans.size() << endl;
  for (auto p: ans) printf("%.3f %.3f\n", p.first, p.second);
  ans.clear();
}
