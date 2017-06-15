#include <bits/stdc++.h>
using namespace std;

struct Point
{

    long double x, y;
    Point(long double x = 0, long double y = 0)
    {
        this->x = x;
        this->y = y;
    }
    long double len2() const
    {
        return x*x + y*y;
    }
};

Point operator+ (Point a, Point b)
{
    return Point(a.x+b.x,a.y+b.y);
}

Point operator- (Point a, Point b)
{
    return Point(a.x-b.x,a.y-b.y);
}


int TurnLeft(Point a, Point b, Point c)
{
    Point p = b - a, q = c - b;
    return p.x * q.y - q.x * p.y;
}
Point v[100100];

long double A, Cx, Cy;

bool check(Point l, Point r, Point cen){
    long double k = ((r.y-l.y) * (cen.x-l.x) - (r.x-l.x) * (cen.y-l.y)) / ((r.y-l.y)*(r.y-l.y) + (r.x-l.x)*(r.x-l.x));
    long double x4 = cen.x - k * (r.y-l.y);
    long double y4 = cen.y + k * (r.x-l.x);
    //cout<<x4<<" "<<y4<<endl;
    if(x4 >= min(l.x, r.x) && x4 <= max(l.x, r.x))
        if(y4 >= min(l.y, r.y) && y4 <= max(l.y, r.y))
            return true;
    return false;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    long double a, b;
    int n;

    for(int cc = 1; cc <= t; ++cc)
    {
        int ans = 0;
        cin>>n;
        for(int i = 0; i < n; ++i){
            cin>>a>>b;
            v[i] = Point(a, b);
        }
        A = Cx = Cy = 0.0;
        v[n] = v[0];
        /*
        for(int i = 0; i < n; ++i)
            A += 0.5 * (v[i].x * v[i+1].y - v[i+1].x * v[i].y);
        for(int i = 0; i < n; ++i){
            Cx += (v[i].x + v[i+1].x) * (v[i].x * v[i+1].y - v[i+1].x * v[i].y);
            Cy += (v[i].y + v[i+1].y) * (v[i].x * v[i+1].y - v[i+1].x * v[i].y);
        }
        Cx = Cx / (6.0 * A);
        Cy = Cy / (6.0 * A);
        cout<<Cx<<" "<<Cy<<endl;*/
        for(int i = 0; i < n; ++i)
            Cx += v[i].x, Cy += v[i].y;
        Cx = Cx / (1.0 * n), Cy = Cy / (1.0 * n);
        Point center = Point(Cx, Cy);

        for(int i = 0; i < n; ++i){
            int l = i, r = (i + 1) % n;
            Point ll = v[l];
            Point rr = v[r];

            int val = 0;

            for(int j = 0; j < n; ++j){
                if(j != l && j != r){
                    Point temp = v[j];
                    int tt = TurnLeft(ll, rr, temp);
                    if(tt == 0){
                        val = 0;
                        break;
                    }
                    if(val == 0)
                        val = tt;
                    else{
                        if(val < 0 && tt > 0){
                            val = 0;
                            break;
                        }
                        if(val > 0 && tt < 0){
                            val = 0;
                            break;
                        }
                    }
                }
            }

            if(val != 0){
                //cout<<ll.x<<" "<<ll.y<<endl;
                //cout<<rr.x<<" "<<rr.y<<endl;
                //cout<<"bb"<<endl;
                if(check(ll, rr, center) == true){
                    ++ans;
                    //cout<<ll.x<<" "<<ll.y<<" "<<rr.x<<" "<<rr.y<<endl;
                }
            }
            else{
                //cout<<ll.x<<" "<<ll.y<<endl;
                //cout<<rr.x<<" "<<rr.y<<endl;
                //cout<<"aa"<<endl;
            }
        }

        cout<<"Case #"<<cc<<": "<<ans<<endl;

    }
    return 0;
}
