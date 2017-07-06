import java.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author Mahammad
 */
public class Main {

    public static int t;
    public static BigInteger n, ans;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        t = sc.nextInt();
        
        for(int i = 1; i <= t; ++i){
            ans = BigInteger.valueOf(0);
            n = sc.nextBigInteger();
            BigInteger l = BigInteger.ZERO;
            BigInteger r = n;
            while(l.compareTo(r) <= 0){
                BigInteger mid = l.add(r).divide(BigInteger.valueOf(2));
                if(mid.multiply(mid.add(BigInteger.ONE)).multiply((mid.multiply(BigInteger.valueOf(2)).add(BigInteger.ONE))).divide(BigInteger.valueOf(6)).compareTo(n) <= 0){
                    ans = mid;
                    l = mid.add(BigInteger.ONE);
                } else{
                    r = mid.subtract(BigInteger.ONE);
                }
            }
            System.out.println("Case #" + i + ": " + ans.add(BigInteger.valueOf(2)).toString());
        }
    }

}
