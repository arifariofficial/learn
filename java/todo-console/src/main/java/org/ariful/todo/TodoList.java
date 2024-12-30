package org.ariful.todo;

import java.io.*;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

public class TodoList {
    private List<Task> tehtavat;
    private final String TIEDOSTO_POLKU = "tasks.txt";

    public TodoList() {
        this.tehtavat = new ArrayList<>();
        lataaTehtavat();
    }

    public void lisaaTehtava(String kuvaus) {
        tehtavat.add(new Task(kuvaus));
        System.out.println("✅ Tehtävä lisätty: " + kuvaus);
        tallennaTehtavat();
    }

    public void asetaMaaraAika(int index, LocalDate maaraAika) {
        if (index >= 0 && index < tehtavat.size()) {
            tehtavat.get(index).asetaMaaraAika(maaraAika);
            System.out.println("📅 Määräaika asetettu: " + maaraAika);
            tallennaTehtavat();
        } else {
            System.out.println("❌ Virheellinen tehtävän numero.");
        }
    }

    public void asetaPrioriteetti(int index, String prioriteetti) {
        if (index >= 0 && index < tehtavat.size()) {
            tehtavat.get(index).asetaPrioriteetti(prioriteetti);
            tallennaTehtavat();
        } else {
            System.out.println("❌ Virheellinen tehtävän numero.");
        }
    }

    public void etsiTehtava(String avainsana) {
        System.out.println("\n🔍 Haetaan tehtäviä avainsanalla: " + avainsana);
        boolean found = false;
        for (Task tehtava : tehtavat) {
            if (tehtava.getKuvaus().toLowerCase().contains(avainsana.toLowerCase())) {
                System.out.println(tehtava);
                found = true;
            }
        }
        if (!found) {
            System.out.println("❌ Ei löytynyt tehtäviä avainsanalla: " + avainsana);
        }
    }

    public void vieCSV() {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter("tasks.csv"))) {
            writer.write("Kuvaus,Valmis,Määräaika,Prioriteetti");
            writer.newLine();
            for (Task tehtava : tehtavat) {
                writer.write(
                        tehtava.getKuvaus() + "," +
                                tehtava.onValmis() + "," +
                                (tehtava.getMaaraAika() != null ? tehtava.getMaaraAika() : "") + "," +
                                tehtava.getPrioriteetti()
                );
                writer.newLine();
            }
            System.out.println("✅ Tehtävät viety tasks.csv-tiedostoon.");
        } catch (IOException e) {
            System.out.println("❌ Virhe vietäessä CSV-tiedostoon: " + e.getMessage());
        }
    }

    public void naytaTehtavat() {
        if (tehtavat.isEmpty()) {
            System.out.println("📭 Tehtävälista on tyhjä.");
        } else {
            System.out.println("\n📋 ===== TEHTÄVÄT =====");
            for (int i = 0; i < tehtavat.size(); i++) {
                System.out.println((i + 1) + ". " + tehtavat.get(i));
            }
        }
    }

    public void merkitseTehtavaValmiiksi(int index) {
        if (index >= 0 && index < tehtavat.size()) {
            tehtavat.get(index).merkitseValmiiksi();
            System.out.println("✅ Tehtävä merkitty valmiiksi: " + tehtavat.get(index).getKuvaus());
            tallennaTehtavat();
        } else {
            System.out.println("❌ Virheellinen tehtävän numero.");
        }
    }

    public void poistaTehtava(int index) {
        if (index >= 0 && index < tehtavat.size()) {
            System.out.println("🗑️ Tehtävä poistettu: " + tehtavat.get(index).getKuvaus());
            tehtavat.remove(index);
            tallennaTehtavat();
        } else {
            System.out.println("❌ Virheellinen tehtävän numero.");
        }
    }

    private void tallennaTehtavat() {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(TIEDOSTO_POLKU))) {
            for (Task tehtava : tehtavat) {
                writer.write(
                        tehtava.getKuvaus() + ";" +
                                tehtava.onValmis() + ";" +
                                (tehtava.getMaaraAika() != null ? tehtava.getMaaraAika() : "") + ";" +
                                tehtava.getPrioriteetti()
                );
                writer.newLine();
            }
        } catch (IOException e) {
            System.out.println("❌ Virhe tallennettaessa tehtäviä: " + e.getMessage());
        }
    }

    private void lataaTehtavat() {
        try (BufferedReader reader = new BufferedReader(new FileReader(TIEDOSTO_POLKU))) {
            String rivi;
            while ((rivi = reader.readLine()) != null) {
                String[] osat = rivi.split(";");
                if (osat.length == 4) {
                    Task tehtava = new Task(osat[0]);
                    if (Boolean.parseBoolean(osat[1])) {
                        tehtava.merkitseValmiiksi();
                    }
                    if (!osat[2].isEmpty()) {
                        tehtava.asetaMaaraAika(LocalDate.parse(osat[2]));
                    }
                    tehtava.asetaPrioriteetti(osat[3]);
                    tehtavat.add(tehtava);
                }
            }
        } catch (IOException e) {
            System.out.println("📁 Tehtävälista ladattu. (Uusi tiedosto luotu, jos ei löytynyt)");
        }
    }
}
