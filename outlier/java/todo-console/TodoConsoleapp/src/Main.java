// src/Main.java

import services.TaskManager;
import java.time.LocalDate;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        TaskManager taskManager = new TaskManager();
        Scanner scanner = new Scanner(System.in);
        boolean running = true;

        while (running) {
            System.out.println("\nTehtävälista-Sovellusvalikko:");
            System.out.println("1. Lisää tehtävä");
            System.out.println("2. Näytä tehtävät");
            System.out.println("3. Muokkaa tehtävää");
            System.out.println("4. Poista tehtävä");
            System.out.println("5. Merkitse tehtävä valmiiksi");
            System.out.println("6. Etsi tehtäviä");
            System.out.println("7. Suodata tehtäviä");
            System.out.println("8. Poistu ja tallenna");
            System.out.print("Valitse vaihtoehto: ");

            int choice = scanner.nextInt();
            scanner.nextLine();

            switch (choice) {
                case 1:
                    System.out.print("Anna otsikko: ");
                    String title = scanner.nextLine();
                    System.out.print("Anna kuvaus: ");
                    String description = scanner.nextLine();
                    System.out.print("Anna kategoria: ");
                    String category = scanner.nextLine();
                    System.out.print("Anna määräpäivä (VVVV-KK-PP): ");
                    LocalDate dueDate = LocalDate.parse(scanner.nextLine());
                    System.out.print("Anna prioriteetti (1-Korkea, 2-Keskitaso, 3-Matala): ");
                    int priority = scanner.nextInt();
                    scanner.nextLine();
                    taskManager.addTask(title, description, category, dueDate, priority);
                    break;
                case 2:
                    taskManager.viewTasks();
                    break;
                case 3:
                    System.out.print("Anna muokattavan tehtävän ID: ");
                    int editId = scanner.nextInt();
                    scanner.nextLine(); // Tyhjennä puskuri

                    System.out.print("Anna uusi otsikko: ");
                    String newTitle = scanner.nextLine();

                    System.out.print("Anna uusi kuvaus: ");
                    String newDescription = scanner.nextLine();

                    System.out.print("Anna uusi kategoria: ");
                    String newCategory = scanner.nextLine();

                    System.out.print("Anna uusi määräpäivä (VVVV-KK-PP): ");
                    LocalDate newDueDate = LocalDate.parse(scanner.nextLine());

                    System.out.print("Anna uusi prioriteetti (1-Korkea, 2-Keskitaso, 3-Matala): ");
                    int newPriority = scanner.nextInt();
                    scanner.nextLine(); // Tyhjennä puskuri

                    taskManager.editTask(editId, newTitle, newDescription, newCategory, newDueDate, newPriority);
                    break;
                case 4:
                    System.out.print("Anna poistettavan tehtävän ID: ");
                    int deleteId = scanner.nextInt();
                    scanner.nextLine(); // Tyhjennä puskuri
                    taskManager.deleteTask(deleteId);
                    break;

                case 5:
                    System.out.print("Anna valmiiksi merkittävän tehtävän ID: ");
                    int completeId = scanner.nextInt();
                    scanner.nextLine(); // Tyhjennä puskuri
                    taskManager.markTaskAsCompleted(completeId);
                    break;

                case 6:
                    System.out.print("Anna hakusana: ");
                    String keyword = scanner.nextLine();
                    taskManager.searchTasks(keyword);
                    break;
                case 7:
                    System.out.println("Suodata seuraavasti: 1. Prioriteetti  2. Kategoria  3. Tila");
                    int filterChoice = scanner.nextInt();
                    scanner.nextLine();
                    if (filterChoice == 1) {
                        System.out.print("Anna prioriteetti (1-Korkea, 2-Keskitaso, 3-Matala): ");
                        taskManager.filterByPriority(scanner.nextInt());
                    } else if (filterChoice == 2) {
                        System.out.print("Anna kategoria: ");
                        taskManager.filterByCategory(scanner.nextLine());
                    } else {
                        System.out.print("Anna tila (true = valmis, false = kesken): ");
                        taskManager.filterByStatus(scanner.nextBoolean());
                    }
                    break;
                case 8:
                    taskManager.saveTasks();
                    running = false;
                    System.out.println("Tehtävät tallennettu. Näkemiin!");
                    break;
                default:
                    System.out.println("Virheellinen valinta. Yritä uudelleen.");
            }
        }
        scanner.close();
    }
}
