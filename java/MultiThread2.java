
import java.util.Random;

public class MultiThread2 {
    public static void main(String[] args) {
        RandomNumberGenerator gen = new RandomNumberGenerator();
        NumberSquareCalculator squareCalculator = new NumberSquareCalculator();
        NumberCubeCalculator cubeCalculator = new NumberCubeCalculator();

        gen.start();
        squareCalculator.start();
        cubeCalculator.start();
    }

public static class RandomNumberGenerator extends Thread {
        public void run() {
            Random random = new Random();

            while (true) {
                int number = random.nextInt(100);

                if (number % 2 == 0) {
                    NumberSquareCalculator.addNumber(number);
                } else {
                    NumberCubeCalculator.addNumber(number);
                }

                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    public static class NumberSquareCalculator extends Thread {
        private static int number;

        public static synchronized void addNumber(int num) {
            number = num;
            System.out.println("Random : " +num);
        }

        public void run() {
            while (true) {
                if (number % 2 == 0) {
                    int square = number * number;
                    System.out.println("Square: " + square);
                }

                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }

public static class NumberCubeCalculator extends Thread {
        private static int number;

        public static synchronized void addNumber(int num) {
            number = num;
          System.out.println("Random : " +num);

        }

        public void run() {
            while (true) {
                if (number % 2 != 0) {
                    int cube = number * number * number;
                    System.out.println("Cube: " + cube);
                }

                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
