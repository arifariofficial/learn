import static org.junit.Assert.*;
import org.junit.Test;

public class TodoAppTest {

    // Luodaan testattava TodoApp-olio
    private TodoApp app = new TodoApp();

    @Test
    public void testAddTask() {
        // Lisätään tehtävä
        app.addTask("Tehtävä 1", "Kuvaus 1", "Kategoria 1");
        // Testataan, että tehtävä on lisätty
        assertTrue(app.listAllTasks().contains("Tehtävä 1: Kuvaus 1 - Kategoria 1"));
    }

    @Test
    public void testListAllTasks() {
        // Lisätään tehtävä
        app.addTask("Tehtävä 2", "Kuvaus 2", "Kategoria 2");
        // Testataan, että kaikki tehtävät näytetään oikein
        assertTrue(app.listAllTasks().contains("Tehtävä 2: Kuvaus 2 - Kategoria 2"));
    }

    @Test
    public void testListTasksByCategory() {
        // Lisätään tehtävät
        app.addTask("Tehtävä 3", "Kuvaus 3", "Kategoria 3");
        app.addTask("Tehtävä 4", "Kuvaus 4", "Kategoria 3");
        // Testataan, että tehtävät suodatetaan oikein kategorian mukaan
        String result = app.listTasksByCategory("Kategoria 3");
        assertTrue(result.contains("Tehtävä 3: Kuvaus 3 - Kategoria 3"));
        assertTrue(result.contains("Tehtävä 4: Kuvaus 4 - Kategoria 3"));
    }

    @Test
    public void testMarkTaskAsCompleted() {
        // Lisätään tehtävä
        app.addTask("Tehtävä 5", "Kuvaus 5", "Kategoria 5");
        // Merkitään tehtävä suorituksiin
        app.markTaskAsCompleted("Tehtävä 5");
        // Testataan, että tehtävän tila on muutettu oikein
        assertTrue(app.listAllTasks().contains("Tehtävä 5: Kuvaus 5 - Kategoria 5 (Valmis)"));
    }

    @Test
    public void testMarkTaskAsIncomplete() {
        // Lisätään tehtävä ja merkitään se suorituksiin
        app.addTask("Tehtävä 6", "Kuvaus 6", "Kategoria 6");
        app.markTaskAsCompleted("Tehtävä 6");
        // Merkitään tehtävä uudelleen kesken olevaksi
        app.markTaskAsIncomplete("Tehtävä 6");
        // Testataan, että tehtävän tila on muutettu oikein
        assertTrue(app.listAllTasks().contains("Tehtävä 6: Kuvaus 6 - Kategoria 6"));
    }
}