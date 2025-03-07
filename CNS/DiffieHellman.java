import java.util.*;

public class DiffieHellman {

    public static int keyGenerate(int base, int privateKey, int mod) {
        return (int) Math.pow(base, privateKey) % mod;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter Public keys (P, G): ");
        int P = sc.nextInt(), G = sc.nextInt();

        System.out.print("Enter Private keys (a, b): ");
        int a = sc.nextInt(), b = sc.nextInt();

        int x = keyGenerate(G, a, P), y = keyGenerate(G, b, P);
        System.out.println("Generated keys: " + x + " " + y);

        int ka = keyGenerate(y, a, P), kb = keyGenerate(x, b, P);
        System.out.println(ka == kb ? "Generated secret keys: " + ka : "Failed to generate secret keys");
    }
}
