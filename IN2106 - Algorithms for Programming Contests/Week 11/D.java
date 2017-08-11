/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.math.BigInteger;
import java.util.Scanner;

/**
 *
 * @author Mahammad
 */

class frac{
    BigInteger num, denum;
    frac(BigInteger l, BigInteger r){
        num = l;
        denum = r;
    }
    
    frac(int l, int r){
        num = BigInteger.valueOf(l);
        denum = BigInteger.valueOf(r);
    }
    
    frac mul(frac cur){
        BigInteger l = this.num.multiply(cur.num);
        BigInteger r = this.denum.multiply(cur.denum);
        BigInteger gcd = l.gcd(r);
        l = l.divide(gcd);
        r = r.divide(gcd);
        return new frac(l, r);
    }
    
    frac sub(frac cur){
        BigInteger lnum = this.num.multiply(cur.denum);
        BigInteger rnum = this.denum.multiply(cur.num);
        lnum = lnum.subtract(rnum);
        BigInteger denum = this.denum.multiply(cur.denum);
        BigInteger gcd = lnum.gcd(denum);
        lnum = lnum.divide(gcd);
        denum = denum.divide(gcd);
        return new frac(lnum, denum);
    }
    
    frac add(frac cur){
        BigInteger lnum = this.num.multiply(cur.denum);
        BigInteger rnum = this.denum.multiply(cur.num);
        lnum = lnum.add(rnum);
        BigInteger denum = this.denum.multiply(cur.denum);
        BigInteger gcd = lnum.gcd(denum);
        lnum = lnum.divide(gcd);
        denum = denum.divide(gcd);
        return new frac(lnum, denum);
    }
    
    frac divide(frac cur){
        BigInteger l = this.num.multiply(cur.denum);
        BigInteger r = this.denum.multiply(cur.num);
        BigInteger gcd = l.gcd(r);
        l = l.divide(gcd);
        r = r.divide(gcd);
        return new frac(l, r);
    }
    
}


public class Main {

    /**
     * @param args the command line arguments
     */
    
    
    public static int[] say = new int[100];
    public static int[] tip = new int[100];
    
    public static int strtoint(String str, int idx1, int idx2){
        int t = 0;
        for(int i = idx1; i <= idx2; ++i){
            t = t * 10 + str.charAt(i) - '0';
        }
        return t;
    }
    
    public static frac dp[][] = new frac[1010][1010];
    
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner sc = new Scanner(System.in);
        int t, n;
        t = sc.nextInt();
        String str = "";
        for(int c = 1; c <= t; ++c){
            int cnt = 0;
            n = sc.nextInt();
            str = sc.nextLine();
            
            //System.out.println(n + " " + str);
            
            
            int len = str.length();
            int j = 0;
            for(int i = 1; i < len; ){
                j = i;
                
                for(; j < len; ++j){
                    if(str.charAt(j) == 'd')
                        break;
                }
                say[++cnt] = strtoint(str, i, j - 1);
                
                j++;
                i = j;
                for(; j < len; ++j){
                    if(str.charAt(j) == '+')
                        break;
                }
                
                tip[cnt] = strtoint(str, i, j-1);
                ++j;
                
                //System.out.println(say[cnt] + " " + tip[cnt]);
                
                //i = j + 1
                i = j;
            }
            
            
            for(int i = 0; i <= 1000; ++i)
            for(int o = 0; o < 1000; ++o)
                dp[i][o] = new frac(0, 1);
            
            dp[0][0] = new frac(1, 1);
            
            int cur = 0;
            
            for(int i = 1; i <= cnt; ++i){
                for(int k = 1; k <= say[i]; ++k){
                    
                    frac temp = new frac(1, tip[i]);
                    
                    for(int o = 0; o <= n; ++o)
                        for(int p = 1; p <= tip[i]; ++p)
                            dp[o + p][cur + 1] = dp[o + p][cur + 1].add(dp[o][cur].mul(temp));
                    
                    ++cur;
                }
            }
            
            
            frac res = new frac(1, 1);
            frac ans = new frac(0, 1);
            
            for(int i = 1; i < n; ++i)
                ans = ans.add(dp[i][cur]);
            ans = res.sub(ans);
            System.out.println("Case #" + c + ": " + ans.num + "/" + ans.denum);
        }
        
        
    }
    
}
