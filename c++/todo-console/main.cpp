// main.cpp
#include <iostream>
#include "include/TehtavaLista.h"

int main() {
  TehtavaLista lista;
  int valinta;

  do {
    std::cout << "\n1. Lisää tehtävä\n"
              << "2. Näytä kaikki tehtävät\n"
              << "3. Poista tehtävä\n"
              << "4. Merkitse tehtävä suoritetuksi\n"
              << "5. Merkitse tehtävä tekemättömäksi\n"
              << "0. Lopeta\n"
              << "Valitse toiminto: ";
    std::cin >> valinta;

    switch (valinta) {
      case 1: {
        std::string nimi, kuvaus;
        std::cout << "Anna tehtävän nimi: ";
        std::cin.ignore();
        std::getline(std::cin, nimi);
        std::cout << "Anna tehtävän kuvaus: ";
        std::getline(std::cin, kuvaus);
        lista.lisaaTehtava(nimi, kuvaus);
        break;
      }
      case 2:
        lista.naytaKaikkiTehtavat();
      break;
      case 3: {
        int id;
        std::cout << "Anna poistettavan tehtävän ID: ";
        std::cin >> id;
        lista.poistaTehtava(id);
        break;
      }
      case 4: {
        int id;
        std::cout << "Anna suoritettavan tehtävän ID: ";
        std::cin >> id;
        lista.merkitseSuoritetuksi(id);
        break;
      }
      case 5: {
        int id;
        std::cout << "Anna tekemättömäksi merkittävän tehtävän ID: ";
        std::cin >> id;
        lista.merkitseTekemattomaksi(id);
        break;
      }
      case 0:
        std::cout << "Ohjelma suljetaan. Hei hei!" << std::endl;
      break;
      default:
        std::cout << "Virheellinen valinta, yritä uudelleen." << std::endl;
    }
  } while (valinta != 0);

  return 0;
}
