//src/services/FileHandler

package services;

import models.Task;

import java.io.*;
import java.util.List;

public class FileHandler {
    private static final String FILE_NAME = "tasks.dat";


    public static void saveTasks(List<Task> tasks) {
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(FILE_NAME))) {
            oos.writeObject(tasks);
            System.out.println("Tehtävät tallennettu onnistuneesti!");
        } catch (IOException e) {
            System.out.println("Virhe tallennettaessa tehtäviä: " + e.getMessage());
        }
    }


    @SuppressWarnings("unchecked")
    public static List<Task> loadTasks() {
        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(FILE_NAME))) {
            return (List<Task>) ois.readObject();
        } catch (FileNotFoundException e) {
            System.out.println("No existing task file found. Starting fresh.");
        } catch (IOException | ClassNotFoundException e) {
            System.out.println("Error loading tasks: " + e.getMessage());
        }
        return new java.util.ArrayList<>();
    }
}
