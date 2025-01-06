package org.ariful.todo;

import java.time.LocalDate;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        TodoList todoList = new TodoList();
        boolean running = true;

        while (running) {
            try {
                System.out.println("\n===== TEHTÄVÄLISTA VALIKKO =====");
                System.out.println("1. Lisää tehtävä");
                System.out.println("2. Näytä tehtävät");
                System.out.println("3. Merkitse tehtävä valmiiksi");
                System.out.println("4. Poista tehtävä");
                System.out.println("5. Poistu");
                System.out.println("6. Aseta määräaika tehtävälle");
                System.out.println("7. Aseta prioriteetti tehtävälle");
                System.out.println("8. Etsi tehtäviä avainsanalla");
                System.out.println("9. Vie tehtävät CSV-tiedostoon");
                System.out.print("Valitse vaihtoehto: ");

                int choice = scanner.nextInt();
                scanner.nextLine(); // Kuluta rivinvaihto

                switch (choice) {
                    case 1:
                        System.out.print("Anna tehtävän kuvaus: ");
                        String kuvaus = scanner.nextLine().trim();
                        if (!kuvaus.isEmpty()) {
                            todoList.lisaaTehtava(kuvaus);
                        } else {
                            System.out.println("❌ Tehtävän kuvaus ei voi olla tyhjä!");
                        }
                        break;

                    case 2:
                        todoList.naytaTehtavat();
                        break;

                    case 3:
                        System.out.print("Anna tehtävän numero, joka merkitään valmiiksi: ");
                        int valmisIndex = scanner.nextInt() - 1;
                        todoList.merkitseTehtavaValmiiksi(valmisIndex);
                        break;

                    case 4:
                        System.out.print("Anna poistettavan tehtävän numero: ");
                        int poistaIndex = scanner.nextInt() - 1;
                        todoList.poistaTehtava(poistaIndex);
                        break;

                    case 5:
                        running = false;
                        System.out.println("👋 Ohjelma suljetaan...");
                        break;

                    case 6:
                        System.out.print("Anna tehtävän numero, jolle asetetaan määräaika: ");
                        int dateIndex = scanner.nextInt() - 1;
                        scanner.nextLine(); // Kuluta rivinvaihto
                        System.out.print("Anna määräaika (YYYY-MM-DD): ");
                        LocalDate maaraAika = LocalDate.parse(scanner.nextLine());
                        todoList.asetaMaaraAika(dateIndex, maaraAika);
                        break;

                    case 7:
                        System.out.print("Anna tehtävän numero, jolle asetetaan prioriteetti: ");
                        int priorityIndex = scanner.nextInt() - 1;
                        scanner.nextLine(); // Kuluta rivinvaihto
                        System.out.print("Anna prioriteetti (High, Medium, Low): ");
                        String priority = scanner.nextLine();
                        todoList.asetaPrioriteetti(priorityIndex, priority);
                        break;

                    case 8:
                        System.out.print("Anna hakusana: ");
                        String keyword = scanner.nextLine();
                        todoList.etsiTehtava(keyword);
                        break;

                    case 9:
                        todoList.vieCSV();
                        break;

                    default:
                        System.out.println("❌ Virheellinen valinta. Yritä uudelleen.");
                }
            } catch (Exception e) {
                System.out.println("❌ Virhe: " + e.getMessage());
                scanner.nextLine(); // Kuluta virheellinen syöte
            }
        }

        scanner.close();
    }
}
