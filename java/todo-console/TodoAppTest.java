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
        assertEquals(1, app.listAllTasks().size());
    }

    @Test
    public void testListAllTasks() {
        // Lisätään tehtävä
        app.addTask("Tehtävä 2", "Kuvaus 2", "Kategoria 2");
        // Testataan, että kaikki tehtävät näytetään oikein
        assertEquals("Tehtävä 2: Kuvaus 2 - Kategoria 2\n", app.listAllTasks().get(0));
    }

    @Test
    public void testListTasksByCategory() {
        // Lisätään tehtävä
        app.addTask("Tehtävä 3", "Kuvaus 3", "Kategoria 3");
        app.addTask("Tehtävä 4", "Kuvaus 4", "Kategoria 3");
        // Testataan, että tehtävät suodatetaan oikein kategorian mukaan
        assertEquals("Tehtävä 3: Kuvaus 3 - Kategoria 3\nTehtävä 4: Kuvaus 4 - Kategoria 3\n", app.listTasksByCategory("Kategoria 3"));
    }

    @Test
    public void testMarkTaskAsCompleted() {
        // Lisätään tehtävä
        app.addTask("Tehtävä 5", "Kuvaus 5", "Kategoria 5");
        // Merkitään tehtävä suorituksiin
        app.markTaskAsCompleted("Tehtävä 5");
        // Testataan, että tehtävän tila on muutettu oikein
        assertEquals("Tehtävä 5: Kuvaus 5 - Kategoria 5 (Valmis)\n", app.listAllTasks().get(0));
    }

    @Test
    public void testMarkTaskAsIncomplete() {
        // Lisätään tehtävä ja merkitään se suorituksiin
        app.addTask("Tehtävä 6", "Kuvaus 6", "Kategoria 6");
        app.markTaskAsCompleted("Tehtävä 6");
        // Merkitään tehtävä uudelleen kesken olevaksi
        app.markTaskAsIncomplete("Tehtävä 6");
        // Testataan, että tehtävän tila on muutettu oikein
        assertEquals("Tehtävä 6: Kuvaus 6 - Kategoria 6\n", app.listAllTasks().get(0));
    }
}