#include <bits/stdc++.h>

using namespace std;

struct rational{
    long long x, y;
    rational(long long x, long long y){
        this->x = x;
        this->y = y;
    }
    rational(){
        this->x = 0;
        this->y = 1;
    }
};

long long gcd(long long l, long long r){
    if(r == 0)
        return l;
    return gcd(r, l % r);
}


rational absrat(rational l){
    l.x = abs(l.x);
    l.y = abs(l.y);
    return l;
}

rational mult(rational l, rational r){
    rational res = rational(l.x*r.x, l.y*r.y);
    long long ebob = gcd(res.x, res.y);
    res.x /= ebob;
    res.y /= ebob;
    return res;
}

rational sub(rational l, rational r){
    long long num = l.x*r.y - r.x*l.y;
    long long denum = l.y*r.y;
    long long ebob = gcd(num, denum);
    num /= ebob;
    denum /= ebob;
    return rational(num, denum);
}

rational add(rational l, rational r){

    long long num = l.x*r.y + r.x*l.y;
    long long denum = l.y*r.y;
    long long ebob = gcd(num, denum);
    num /= ebob;
    denum /= ebob;
    //cout<<"****************************------"<<endl;

    //cout<<l.x<<" "<<l.y<<" "<<r.x<<" "<<r.y<<endl;
    //cout<<num<<" "<<denum<<endl;
    //cout<<ebob<<endl;

    //cout<<"****************************+++++++"<<endl;

    return rational(num, denum);
}

rational div(rational l, rational r){
    rational res = rational(l.x*r.y, l.y*r.x);
    long long ebob = gcd(res.x, res.y);
    res.x /= ebob;
    res.y /= ebob;
    return res;
}

rational mult(rational l, long long r){
    rational res = l;
    res.x *= r;
    long long ebob = gcd(res.x, res.y);
    res.x /= ebob;
    res.y /= ebob;
    return res;
}

rational div(rational l, long long r){
    rational res = l;
    res.y *= r;
    long long ebob = gcd(res.x, res.y);
    res.x /= ebob;
    res.y /= ebob;
    return res;
}

long long n, m;

struct point{
    rational x, y;
    point(rational x, rational y){
        this->x = x;
        this->y = y;
    }
    point(){
        this->x = rational(0, 1);
        this->y = rational(0, 1);
    }
    point(long long x, long long y){
        this->x = rational(x, 1);
        this->y = rational(y, 1);
    }
};

point get_point(point l, point r){
    rational x = sub(r.x, l.x);
    rational y = sub(r.y, l.y);
    rational newx = div(x, m);
    rational newy = div(y, m);

    point pnew = l;
    pnew.x = add(l.x, newx);
    pnew.y = add(l.y, newy);
    return pnew;
}



rational get_tri(point l, point r, point z){
    rational area = rational(0, 1);
    //cout<<"-------------------"<<endl;

    area = add(area, mult(l.x, r.y));
    //cout<<area.x<<" "<<area.y<<endl;
    area = add(area, mult(r.x, z.y));
    //cout<<area.x<<" "<<area.y<<endl;
    area = add(area, mult(z.x, l.y));
    //cout<<area.x<<" "<<area.y<<endl;



    area = sub(area, mult(r.x, l.y));
    //cout<<area.x<<" "<<area.y<<endl;
    area = sub(area, mult(z.x, r.y));
    //cout<<area.x<<" "<<area.y<<endl;
    area = sub(area, mult(l.x, z.y));
    //cout<<area.x<<" "<<area.y<<endl;
/*
    cout<<"+++++++++++++++++++++++++++++++++"<<endl;
    cout<< mult(l.x, r.y).x<<" "<< mult(l.x, r.y).y<<endl;
    cout<< mult(r.x, z.y).x<<" "<< mult(r.x, z.y).y<<endl;
    cout<< mult(z.x, l.y).x<<" "<< mult(z.x, l.y).y<<endl;
    cout<< mult(r.x, l.y).x<<" "<< mult(r.x, l.y).y<<endl;
    cout<< mult(z.x, r.y).x<<" "<< mult(z.x, r.y).y<<endl;
    cout<< mult(l.x, z.y).x<<" "<< mult(l.x, z.y).y<<endl;
*/
    area.x = abs(area.x);
    area.y = abs(area.y);
    //cout<<"area: "<<area.x<<" "<<area.y<<endl;
    //cout<<"-------------------"<<endl;
    //area = mult(area, rational(1, 2));
    return area;
}

long long x[1010], y[1010];

rational get_area(){
    rational area = rational(0, 1);
    for(int i = 0; i < n; ++i){
        area = add(area, rational(x[i] * y[i + 1], 1));
        area = sub(area, rational(y[i] * x[i + 1], 1));
    }
    area.x = abs(area.x);
    area.y = abs(area.y);
    return area;
    //return mult(area, rational(1, 2));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for(int c = 1; c <= t; ++c)
    {
        cout<<"Case #"<<c<<": ";
        cin>>n>>m;
        for(int i = 0; i < n; ++i)
            cin>>x[i]>>y[i];
        x[n] = x[0];
        y[n] = y[0];
        x[n+1] = x[1];
        y[n+1] = y[1];

        rational area = get_area();

        //cout<<area.x<<" "<<area.y<<endl;

        rational cur = rational(0, 1);
        rational v = mult(rational(186985, 207), rational(7318, 69)); // 12901965
        //cout<<v.x<<" "<<v.y<<endl;
        for(int i = 1; i <= n; ++i){
            point k1 = point(x[i], y[i]);
            point k2 = point(x[i+1], y[i+1]);
            point k3 = point(x[i-1], y[i-1]);
            point newk2 = get_point(k1, k2);
            point newk3 = get_point(k1, k3);
            /*
            cout<<endl;
            cout<<newk2.x.x<<" "<<newk2.x.y<<" "<<newk2.y.x<<" "<<newk2.y.y<<endl;
            cout<<newk3.x.x<<" "<<newk3.x.y<<" "<<newk3.y.x<<" "<<newk3.y.y<<endl;
            cout<<k1.x.x<<" "<<k1.x.y<<" "<<k1.y.x<<" "<<k1.y.y<<endl;
            rational temp = get_tri(k1, newk2, newk3);
            cout<<temp.x<<" "<<temp.y<<endl;
            cout<<endl;
            */
            cur = add(cur, get_tri(k1, newk2, newk3));
        }
        area = div(cur, area);
        cout<<area.x<<"/"<<area.y<<endl;
    }

    return 0;
}
