package org.ariful.todo;

import java.time.LocalDate;

public class Task {
    private String kuvaus; // Task description
    private boolean valmis; // Task completion status
    private LocalDate maaraAika; // Task due date
    private String prioriteetti; // Task priority (High, Medium, Low)

    // Constructor
    public Task(String kuvaus) {
        this.kuvaus = kuvaus;
        this.valmis = false;
        this.maaraAika = null; // Default: No due date
        this.prioriteetti = "Medium"; // Default priority
    }

    // Set due date
    public void asetaMaaraAika(LocalDate maaraAika) {
        this.maaraAika = maaraAika;
    }

    // Set priority
    public void asetaPrioriteetti(String prioriteetti) {
        if (prioriteetti.equalsIgnoreCase("High") || prioriteetti.equalsIgnoreCase("Medium") || prioriteetti.equalsIgnoreCase("Low")) {
            this.prioriteetti = prioriteetti;
        } else {
            System.out.println("❌ Virheellinen prioriteetti! Käytä: High, Medium tai Low.");
        }
    }

    public String getKuvaus() {
        return kuvaus;
    }

    public boolean onValmis() {
        return valmis;
    }

    public LocalDate getMaaraAika() {
        return maaraAika;
    }

    public String getPrioriteetti() {
        return prioriteetti;
    }

    public void merkitseValmiiksi() {
        this.valmis = true;
    }

    @Override
    public String toString() {
        String status = (valmis ? "[✓]" : "[ ]");
        String date = (maaraAika != null) ? " | Määräaika: " + maaraAika : "";
        return status + " " + kuvaus + " | Prioriteetti: " + prioriteetti + date;
    }
}
