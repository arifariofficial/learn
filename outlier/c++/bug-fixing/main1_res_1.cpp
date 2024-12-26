#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdexcept>

using namespace std;

// Luokka Aika, joka vastaa ajan hallinnasta
class Aika {
private:
    int tunnit;
    int minuutit;

public:
    Aika() { tunnit = minuutit = 0; }
    Aika(int t, int m) {
        if (t < 0 || t > 23 || m < 0 || m > 59) {
            throw invalid_argument("Virheellinen aika: tunnit ja minuutit täytyvät olla 0-23 ja 0-59 välillä.");
        }
        tunnit = t;
        minuutit = m;
    }

    bool aikaisempiKuin(const Aika& toinen) const {
        return (tunnit < toinen.tunnit) || (tunnit == toinen.tunnit && minuutit < toinen.minuutit);
    }

    Aika vahenna(const Aika& toinen) const {
        const int kokonaisMinuutit1 = tunnit * 60 + minuutit;
        const int kokonaisMinuutit2 = toinen.tunnit * 60 + toinen.minuutit;
        int erotusMinuutit = (kokonaisMinuutit1 < kokonaisMinuutit2)
            ? (24 * 60 + kokonaisMinuutit1 - kokonaisMinuutit2)
            : (kokonaisMinuutit1 - kokonaisMinuutit2);
        return Aika(erotusMinuutit / 60, erotusMinuutit % 60);
    }

    void nayta() const {
        cout << setiosflags(ios::right) << setfill('0') << setw(2) << tunnit << ":" << setfill('0') << setw(2) << minuutit;
    }
};

// Luokka SyotteenLukija, joka vastaa käyttäjän syötteen lukemisesta
class SyotteenLukija {
private:
    string stream;

public:
    SyotteenLukija(string s) : stream(s) {}

    Aika lueAika(const string &kehote) {
        cout << kehote << " (hh:mm muodossa): ";
        getline(cin, stream);

        istringstream parseri(stream);
        int tunnit, minuutit;
        char erotin;

        if ((parseri >> tunnit) && (parseri >> erotin) && (parseri >> minuutit) && (erotin == ':')) {
            return Aika(tunnit, minuutit);
        } else {
            throw invalid_argument("Virheellinen aikamuoto! Anna aika muodossa hh:mm.");
        }
    }
};

// Luokka OhjelmanOhjaus, joka koordinoi ohjelman toimintoja
class OhjelmanOhjaus {
private:
    SyotteenLukija lukija;

public:
    OhjelmanOhjaus() : lukija(cin) {}

    void ajaOhjelma() {
        Aika aika1, aika2, kesto;

        try {
            aika1 = lukija.lueAika("Anna aika 1");
            aika2 = lukija.lueAika("Anna aika 2");
            if (aika1.aikaisempiKuin(aika2)) {
                kesto = aika2.vahenna(aika1);
                cout << "Aloitusaika oli ";
            } else {
                kesto = aika1.vahenna(aika2);
                cout << "Aloitusaika oli ";
            }
            cout << setiosflags(ios::right) << setfill('0') << setw(2) << aika1.tunnit
                 << ":" << setfill('0') << setw(2) << aika1.minuutit << endl;
            cout << "Kesto oli ";
            kesto.nayta();
            cout << endl;

        } catch (const invalid_argument &e) {
            cout << "Virhe: " << e.what() << endl;
        }
    }
};

int main() {
    OhjelmanOhjaus ohjelma;
    ohjelma.ajaOhjelma();
    return 0;
}