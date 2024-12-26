#include <iostream>
#include <iomanip>
#include <string>
#include <exception>

using namespace std;

// Luokka, joka edustaa ajan ainoaan ominaisuudeksi tunteja ja minuutteja
class Aika {
private:
    int tunnit, minuutit;

public:
    // Konstruktori, joka asettaa aikan oletuksena nollaan
    Aika() : tunnit(0), minuutit(0) {}

    // Konstruktori, joka asettaa tunteja ja minuutteja
    Aika(const int t, const int m) : tunnit(t), minuutit(m) {
        if (tunnit < 0 || minuutit < 0 || minuutit > 59) {
            throw invalid_argument("Virheellinen aika: tunteja ja minuutteja tulee olla 0-59 välillä");
        }
    }

    // Metodi, joka tarkistaa, onko tämä aika aikaisempi kuin toinen aika
    bool aikaisempiKuin(const Aika &toinen) const {
        return (tunnit < toisen.tunnit) || (tunnit == toisen.tunnit && minuutit < toisen.minuutit);
    }

    // Metodi, joka laskee ajan eron tähän aikaan ja toiseen aikaan
    Aika vahenna(const Aika &toinen) const {
        const int kokonaisMinuutit1 = tunnit * 60 + minuutit;
        const int kokonaisMinuutit2 = toinen.tunnit * 60 + toinen.minuutit;

        int erotusMinuutit;

        if (kokonaisMinuutit1 >= kokonaisMinuutit2) {
            erotusMinuutit = kokonaisMinuutit1 - kokonaisMinuutit2;
        } else {
            erotusMinuutit = (24 * 60 - kokonaisMinuutit2) + kokonaisMinuutit1;
        }

        return Aika(erotusMinuutit / 60, erotusMinuutit % 60);
    }

    // Metodi, joka näyttää ajan muodossa hh:mm
    void nayta() const {
        cout << setiosflags(ios::right);
        cout << setfill('0') << setw(2) << tunnit << ":" << setfill('0') << setw(2) << minuutit;
    }
};

// Luokka, joka hoitaa syötteen lukemisen ja varmistaa, että se on oikeassa muodossa
class SyoteLukija {
public:
    // Metodi, joka pyytää käyttäjältä aikaa ja palauttaa sen
    Aika lueAika(const string &kehote) {
        string syote;
        Aika aika;

        while (true) {
            cout << kehote << " (hh:mm muodossa): ";
            getline(cin, syote);

            try {
                size_t pos = syote.find(':');
                if (pos == string::npos || pos + 1 == syote.length()) {
                    throw invalid_argument("Virheellinen aikamuoto: tarvitaan kaksoispiste hh:mm välillä");
                }

                int tunnit = stoi(syote.substr(0, pos));
                int minuutit = stoi(syote.substr(pos + 1));

                if (tunnit < 0 || minuutit < 0 || minuutit > 59) {
                    throw invalid_argument("Virheellinen aika: tunteja ja minuutteja tulee olla 0-59 välillä");
                }

                aika = Aika(tunnit, minuutit);
                break;
            } catch (const invalid_argument &e) {
                cout << e.what() << endl;
            }
        }

        return aika;
    }
};

// Luokka, joka hoitaa ohjelman suorituksen
class Ohjelma {
private:
    SyoteLukija syoteLukija;

public:
    void suorita() {
        Aika aika1, aika2, kesto;

        aika1 = syoteLukija.lueAika("Anna aika 1");
        aika2 = syoteLukija.lueAika("Anna aika 2");

        if (aika1.aikaisempiKuin(aika2)) {
            kesto = aika2.vahenna(aika1);
            cout << "Aloitusaika oli ";
            aika1.nayta();
        } else {
            kesto = aika1.vahenna(aika2);
            cout << "Aloitusaika oli ";
            aika2.nayta();
        }
        cout << "\nKesto oli ";
        kesto.nayta();
    }
};

int main() {
    Ohjelma ohjelma;
    ohjelma.suorita();
    return 0;
}