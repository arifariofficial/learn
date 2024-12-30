// src/TehtavaLista.cpp

#include "../include/TehtavaLista.h"
#include <iostream>

TehtavaLista::TehtavaLista(const std::string& tiedosto)
    : seuraavaId(1), tiedostoPolku(tiedosto) {
    lataaTiedostosta();
}

void TehtavaLista::lisaaTehtava(const std::string& nimi, const std::string& kuvaus) {
    tehtavat.push_back(std::make_shared<Tehtava>(seuraavaId++, nimi, kuvaus));
    std::cout << "Tehtävä lisätty onnistuneesti!" << std::endl;
}

void TehtavaLista::poistaTehtava(int id) {
    auto it = std::remove_if(tehtavat.begin(), tehtavat.end(),
                             [id](const std::shared_ptr<Tehtava>& tehtava) {
                                 return tehtava->getId() == id;
                             });
    if (it != tehtavat.end()) {
        tehtavat.erase(it, tehtavat.end());
        std::cout << "Tehtävä poistettu onnistuneesti!" << std::endl;
    } else {
        std::cout << "Tehtävää ei löytynyt annetulla ID:llä." << std::endl;
    }
}

void TehtavaLista::naytaKaikkiTehtavat() const {
    if (tehtavat.empty()) {
        std::cout << "Tehtävälista on tyhjä." << std::endl;
        return;
    }
    for (const auto& tehtava : tehtavat) {
        tehtava->naytaTiedot();
    }
}

void TehtavaLista::merkitseSuoritetuksi(int id) {
    for (auto& tehtava : tehtavat) {
        if (tehtava->getId() == id) {
            tehtava->merkitseSuoritetuksi();
            std::cout << "Tehtävä merkitty suoritetuksi." << std::endl;
            return;
        }
    }
    std::cout << "Tehtävää ei löytynyt annetulla ID:llä." << std::endl;
}

void TehtavaLista::merkitseTekemattomaksi(int id) {
    for (auto& tehtava : tehtavat) {
        if (tehtava->getId() == id) {
            tehtava->merkitseTekemattomaksi();
            std::cout << "Tehtävä merkitty tekemättömäksi." << std::endl;
            return;
        }
    }
    std::cout << "Tehtävää ei löytynyt annetulla ID:llä." << std::endl;
}



void TehtavaLista::tallennaTiedostoon() const {
    json j;
    for (const auto& tehtava : tehtavat) {
        j["tehtavat"].push_back({
            {"id", tehtava->getId()},
            {"nimi", tehtava->getNimi()},
            {"kuvaus", tehtava->getKuvaus()},
            {"suoritettu", tehtava->onSuoritettu()}
        });
    }

    std::ofstream tiedosto(tiedostoPolku);
    if (tiedosto.is_open()) {
        tiedosto << j.dump(4); // Kaunis JSON-muotoilu
        std::cout << "Tehtävät tallennettu tiedostoon." << std::endl;
    } else {
        std::cerr << "Virhe: Tiedostoon tallentaminen epäonnistui." << std::endl;
    }
}

void TehtavaLista::lataaTiedostosta() {
    std::ifstream tiedosto(tiedostoPolku);
    if (tiedosto.is_open()) {
        json j;
        tiedosto >> j;

        if (j.contains("tehtavat")) {
            for (const auto& item : j["tehtavat"]) {
                tehtavat.push_back(std::make_shared<Tehtava>(
                    item["id"].get<int>(),
                    item["nimi"].get<std::string>(),
                    item["kuvaus"].get<std::string>()
                ));
                if (item["suoritettu"].get<bool>()) {
                    tehtavat.back()->merkitseSuoritetuksi();
                }
                seuraavaId = std::max(seuraavaId, item["id"].get<int>() + 1);
            }
        }
        std::cout << "Tehtävät ladattu tiedostosta." << std::endl;
    } else {
        std::cout << "Tallennustiedostoa ei löytynyt. Luodaan uusi." << std::endl;
    }
}