// include/Tehtava.h
#ifndef TEHTAVA_H
#define TEHTAVA_H

#include <string>

// Yksittäinen tehtävä
class Tehtava {
private:
    int id;                // Tehtävän tunniste
    std::string nimi;      // Tehtävän nimi
    std::string kuvaus;    // Tehtävän kuvaus
    bool suoritettu;       // Onko tehtävä suoritettu

public:
    Tehtava(int id, std::string  nimi, std::string  kuvaus);
    void merkitseSuoritetuksi();
    void merkitseTekemattomaksi();
    void naytaTiedot() const;
    int getId() const;
    std::string getNimi() const;
    std::string getKuvaus() const;
    bool onSuoritettu() const;
};

#endif // TEHTAVA_H
