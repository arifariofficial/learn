#include <string>
#include <chrono>
#include <ctime>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>


using namespace std;
using namespace std::chrono;

class Tehtava {
public:
    string otsikko;
    string kuvaus;
    string luoja;
    string päivitysaja;
    string kategoria;

    Tehtava(string otsikko, string kuvaus, string luoja, string kategoria) {
        this->otsikko = otsikko;
        this->kuvaus = kuvaus;
        this->luoja = luoja;
        this->kategoria = kategoria;
        *this->päivitysaja = get_current_time();
    }

    void päivitä(string päivitysaja) {
        this->päivitysaja = päivitysaja;
    }

    static string get_current_time() {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        char buf[80];
        strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", ltm);
        return buf;
    }
};



class Tehtavalista {
private:
    vector<Tehtava> tehtävät;

public:
    void lisää_tehtävä(string otsikko, string kuvaus, string luoja, string kategoria) {
        tehtävät.push_back(Tehtava(otsikko, kuvaus, luoja, kategoria));
    }

    void päivitä_tehtävä(int id, string otsikko, string kuvaus, string päivitysaja, string kategoria) {
        if (id >= 0 && id < tehtävät.size()) {
            tehtävät[id].otsikko = otsikko;
            tehtävät[id].kuvaus = kuvaus;
            tehtävät[id].päivitysaja = päivitysaja;
            tehtävät[id].kategoria = kategoria;
        } else {
            cout << "Tehtävää ei löytynyt." << endl;
        }
    }

    void poista_tehtävä(int id) {
        if (id >= 0 && id < tehtävät.size()) {
            tehtävät.erase(tehtävät.begin() + id);
        } else {
            cout << "Tehtävää ei löytynyt." << endl;
        }
    }

    void näytä_tehtävät() {
        if (tehtävät.empty()) {
            cout << "Ei tehtäviä löytynyt." << endl;
            return;
        }

        cout << "ID\tOtsikko\tLuoja\tLuomisaika\tPäivitysaja\tKategoria\n";
        cout << "---\t-------\t------\t------------\t-------------\t---------\n";
        for (int i = 0; i < tehtävät.size(); ++i) {
            cout << i << "\t" << tehtävät[i].otsikko << "\t"
                 << tehtävät[i].luoja << "\t" << tehtävät[i].luomisaika << "\t"
                 << tehtävät[i].päivitysaja << "\t" << tehtävät[i].kategoria << "\n";
        }
    }

    void suodata_tehtävät(string kategoria) {
        if (tehtävät.empty()) {
            cout << "Ei tehtäviä löytynyt." << endl;
            return;
        }

        cout << "Otsikko\tLuoja\tLuomisaika\tPäivitysaja\tKategoria\n";
        cout << "-------\t------\t------------\t-------------\t---------\n";
        for (const auto& tehtävä : tehtävät) {
            if (tehtävä.kategoria == kategoria) {
                cout << tehtävä.otsikko << "\t" << tehtävä.luoja << "\t"
                     << tehtävä.luomisaika << "\t" << tehtävä.päivitysaja << "\t"
                     << tehtävä.kategoria << "\n";
            }
        }
    }
};

int main() {
    Tehtavalista lista;

    lista.lisää_tehtävä("Osta maito", "Osta maito kaupasta", "Jussi", "Ostokset");
    lista.lisää_tehtävä("Tehtävä 2", "Kuvaus tehtävälle 2", "Aliisa", "Töitä");
    lista.lisää_tehtävä("Tehtävä 3", "Kuvaus tehtävälle 3", "Jussi", "Ostokset");

    lista.näytä_tehtävät();

    cout << "\nPäivitä tehtävä 1:\n";
    string uusi_otsikko, uusi_kuvaus, uusi_päivitysaja, uusi_kategoria;
    cin >> uusi_otsikko >> uusi_kuvaus >> uusi_päivitysaja >> uusi_kategoria;
    lista.päivitä_tehtävä(0, uusi_otsikko, uusi_kuvaus, uusi_päivitysaja, uusi_kategoria);

    lista.näytä_tehtävät();

    cout << "\nPoista tehtävä 2:\n";
    lista.poista_tehtävä(1);

    lista.näytä_tehtävät();

    cout << "\nSuodata tehtävät kategorian 'Ostokset' mukaan:\n";
    lista.suodata_tehtävät("Ostokset");

    return 0;
}