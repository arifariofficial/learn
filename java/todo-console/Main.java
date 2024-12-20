import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        TodoApp app = new TodoApp();

        // Esimerkkivuorovaikutus sovelluksen kanssa
        while (true) {
            System.out.println("\nTehtävälista-sovelluksen valikko:");
            System.out.println("1. Lisää tehtävä");
            System.out.println("2. Näytä kaikki tehtävät");
            System.out.println("3. Näytä tehtävät kategorian mukaan");
            System.out.println("4. Merkitse tehtävä suorituksiin");
            System.out.println("5. Merkitse tehtävä kesken olevaksi");
            System.out.println("6. Poistu");
            System.out.print("Syötä valintasi: ");

            int choice = scanner.nextInt();
            scanner.nextLine();  // Kuluttaa rivinvaihtomerkin

            switch (choice) {
                case 1:
                    // Lisää tehtävä
                    System.out.print("Syötä tehtävän nimi: ");
                    String name = scanner.nextLine();
                    System.out.print("Syötä tehtävän kuvaus: ");
                    String description = scanner.nextLine();
                    System.out.print("Syötä tehtävän kategoria: ");
                    String category = scanner.nextLine();
                    app.addTask(name, description, category);
                    break;

                case 2:
                    // Näytä kaikki tehtävät
                    app.listAllTasks();
                    break;

                case 3:
                    // Näytä tehtävät kategorian mukaan
                    System.out.print("Syötä kategoria suodattamista varten: ");
                    String filterCategory = scanner.nextLine();
                    app.listTasksByCategory(filterCategory);
                    break;

                case 4:
                    // Merkitse tehtävä suorituksiin
                    System.out.print("Syötä tehtävän nimi, jonka haluat merkitä suorituksiin: ");
                    String taskNameComplete = scanner.nextLine();
                    app.markTaskAsCompleted(taskNameComplete);
                    break;

                case 5:
                    // Merkitse tehtävä kesken olevaksi
                    System.out.print("Syötä tehtävän nimi, jonka haluat merkitä kesken olevaksi: ");
                    String taskNameIncomplete = scanner.nextLine();
                    app.markTaskAsIncomplete(taskNameIncomplete);
                    break;

                case 6:
                    // Poistu ohjelmasta
                    System.out.println("Poistutaan...");
                    scanner.close();
                    return;

                default:
                    System.out.println("Virheellinen valinta, yritä uudelleen.");
            }
        }
    }
}
