import java.util.*;

public class RSA {
    public static double gcd(double a, double b) {
        while (b != 0) {
            double temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter values of p, q, e, k, m: ");
        double p = sc.nextDouble(), q = sc.nextDouble(), e = sc.nextDouble(), k = sc.nextDouble(), m = sc.nextDouble();
        
        double n = p * q, phi = (p - 1) * (q - 1);
        while (gcd(e, phi) != 1) e++;
        
        double d = (1 + k * phi) / e;
        double c = Math.pow(m, e) % n;
        double msg = Math.pow(c, d) % n;

        System.out.println("Encrypted data = " + c);
        System.out.println("Original Message Sent = " + m);
    }
}
