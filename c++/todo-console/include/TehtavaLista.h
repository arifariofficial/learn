// include/TehtavaLista.h
#ifndef TEHTAVALISTA_H
#define TEHTAVALISTA_H

#include "Tehtava.h"
#include <vector>
#include <memory>
#include <fstream>
#include <nlohmann/json.hpp> // JSON-kirjasto

using json = nlohmann::json;

class TehtavaLista {
private:
    std::vector<std::shared_ptr<Tehtava>> tehtavat;
    int seuraavaId; // Seuraavan tehtävän ID
    std::string tiedostoPolku; // Tallennustiedoston polku

public:
    TehtavaLista(const std::string& tiedosto = "tehtavat.json");

    void lisaaTehtava(const std::string& nimi, const std::string& kuvaus);
    void poistaTehtava(int id);
    void naytaKaikkiTehtavat() const;
    void merkitseSuoritetuksi(int id);
    void merkitseTekemattomaksi(int id);

    void tallennaTiedostoon() const;
    void lataaTiedostosta();
};

#endif // TEHTAVALISTA_H
