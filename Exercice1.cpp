
public class Main {

    // 1. Fonction de division
    public static int diviser(int a, int b) {

        if (b == 0) {
            throw new ArithmeticException(
                "Erreur : division par zéro impossible !"
            );
        }

        return a / b;
    }

    public static void main(String[] args) {

        // 2. Différents cas de test
        try {
            System.out.println("10 / 2 = " + diviser(10, 2));
            System.out.println("20 / 4 = " + diviser(20, 4));
            System.out.println("15 / 0 = " + diviser(15, 0));
            System.out.println("10 / 5 = " + diviser(10, 5));

        } catch (ArithmeticException e) {

            // 3. Gestion de l'exception
            System.out.println(e.getMessage());
        }

        System.out.println("Fin du programme.");
    }
}
