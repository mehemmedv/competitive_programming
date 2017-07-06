import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import static java.util.Arrays.stream;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.StringTokenizer;

/**
 *
 * @author Mahammad
 */
public class Main {

    public static class FastScanner {

        BufferedReader br;
        StringTokenizer st;

        public FastScanner(String s) {
            try {
                br = new BufferedReader(new FileReader(s));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(nextToken());
        }

        long nextLong() {
            return Long.parseLong(nextToken());
        }

        double nextDouble() {
            return Double.parseDouble(nextToken());
        }
    }

    public static int cur_cnt = 0;

    public static BigInteger N[] = new BigInteger[500000];
    public static BigInteger A[] = new BigInteger[500000];
    public static int cur_say = 0;

    public static BigInteger chineseRemainder(BigInteger[] n, BigInteger[] a, int len) {
        BigInteger prod = BigInteger.ONE;
        for (int i = 0; i < len; ++i) {
            prod = prod.multiply(n[i]);
        }
        BigInteger p, sm = BigInteger.ZERO;
        for (int i = 0; i < len; i++) {
            p = prod.divide(n[i]);
            sm = sm.add(a[i].multiply(mulInv(p, n[i])).multiply(p));
        }
        return sm.mod(prod);
    }

    private static BigInteger mulInv(BigInteger a, BigInteger b) {
        BigInteger b0 = b;
        BigInteger x0 = BigInteger.ZERO;
        BigInteger x1 = BigInteger.ONE;

        if (b == BigInteger.ONE) {
            return BigInteger.ONE;
        }

        while (a.compareTo(BigInteger.ONE) > 0) {
            BigInteger q = a.divide(b);
            BigInteger amb = a.mod(b);
            a = b;
            b = amb;
            BigInteger xqx = x1.subtract(q.multiply(x0));
            x1 = x0;
            x0 = xqx;
        }
        if (x1.compareTo(BigInteger.ZERO) < 0) {
            x1 = x1.add(b0);
        }
        return x1;
    }

    public static ArrayList<Integer> list = new ArrayList<Integer>();
    public static int which[] = new int[3100];
    public static int say[] = new int[3100];
    public static Map<BigInteger, Integer> big_which = new HashMap<BigInteger, Integer>();
    public static Map<BigInteger, Integer> big_say = new HashMap<BigInteger, Integer>();

    public static boolean prime[] = new boolean[3100];

    public static void eratosfen() {
        int n = 1000;
        prime[0] = prime[1] = true;
        for (int i = 2; i <= n; ++i) {
            if (prime[i] == false) {
                if (i * ((long) 1) * i <= n) {
                    for (int j = i * i; j <= n; j += i) {
                        prime[j] = true;
                    }
                }
            }
        }
        for (int i = 2; i <= n; ++i) {
            if (prime[i] == false) {
                list.add(i);
            }
        }
    }

    public static void add(BigInteger n, int idx) {
        idx -= 1;
        BigInteger temp = BigInteger.valueOf(idx);
        temp = temp.mod(n);
        temp = n.subtract(temp);
        N[cur_say] = n;
        A[cur_say] = temp;
        ++cur_say;
    }

    public static void main(String[] args) throws IOException {

        FastScanner sc = new FastScanner();
        eratosfen();
        int t = sc.nextInt();
        BigInteger nums[] = new BigInteger[1010];
        BigInteger nums_cpy[] = new BigInteger[1010];
        for (int c = 1; c <= t; ++c) {
            BigInteger lcm = BigInteger.ONE;
            cur_say = 0;
            Arrays.fill(say, 0);
            Arrays.fill(which, 0);

            int n = sc.nextInt();
            for (int j = 1; j <= n; ++j) {
                nums[j] = new BigInteger(sc.nextToken());
                nums_cpy[j] = nums[j];
                lcm = lcm.multiply(nums[j]).divide(lcm.gcd(nums[j]));
            }
            for (int j : list) {
                BigInteger cur_big = BigInteger.valueOf(j);
                for (int o = 1; o <= n; ++o) {
                    int cnt = 0;
                    while (nums_cpy[o].mod(cur_big).compareTo(BigInteger.ZERO) == 0 && nums_cpy[o].compareTo(BigInteger.ZERO) != 0) {
                        ++cnt;
                        nums_cpy[o] = nums_cpy[o].divide(cur_big);
                    }
                    if (say[j] < cnt) {
                        say[j] = cnt;
                        which[j] = o;
                    }
                }
            }
            for (int i : list) {
                if (say[i] > 0) {
                    add(BigInteger.valueOf(i).pow(say[i]), which[i]);
                }
            }
            for (int i = 1; i <= n; ++i) {
                if (nums_cpy[i].compareTo(BigInteger.ONE) > 0) {
                    add(nums_cpy[i], i);
                }
            }
            BigInteger ans = chineseRemainder(N, A, cur_say);
            System.out.println("Case #" + c + ": " + ans.toString() + " " + lcm);
        }

    }
}
