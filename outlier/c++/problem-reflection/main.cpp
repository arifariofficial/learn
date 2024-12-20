#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

class Tyontekija {
public:
    int tunnus;
    string nimi;

    Tyontekija(int tunnus, string nimi) : tunnus(tunnus), nimi(nimi) {}

    virtual ~Tyontekija() = default;

    virtual void KysyPalkka() = 0;

    virtual int LaskePalkka() const = 0;
};

class Kuukausipalkkainen : public Tyontekija {
public:
    int kuukausipalkka;

    Kuukausipalkkainen(int tunnus, string nimi, int kuukausipalkka)
        : Tyontekija(tunnus, nimi), kuukausipalkka(kuukausipalkka) {}

    void KysyPalkka() override {
        cout << "Anna kuukausipalkka: ";
        cin >> kuukausipalkka;
    }

    int LaskePalkka() const override {
        return kuukausipalkka;
    }
};

class Tuntipalkkainen : public Tyontekija {
public:
    int tuntipalkka;
    int tyotunnit;

    Tuntipalkkainen(int tunnus, string nimi) : Tyontekija(tunnus, nimi), tuntipalkka(0), tyotunnit(0) {}

    void KysyPalkka() override {
        cout << "Anna tuntipalkka: ";
        cin >> tuntipalkka;

        cout << "Anna tyotuntien määrä: ";
        cin >> tyotunnit;
    }

    int LaskePalkka() const override {
        return tuntipalkka * tyotunnit;
    }
};

class ProvisionPalkkainen : public Kuukausipalkkainen {
public:
    int provisio;

    ProvisionPalkkainen(int tunnus, string nimi, int kuukausipalkka)
        : Kuukausipalkkainen(tunnus, nimi, kuukausipalkka), provisio(0) {}

    void KysyPalkka() override {
        Kuukausipalkkainen::KysyPalkka();
        cout << "Anna provisio: ";
        cin >> provisio;
    }

    int LaskePalkka() const override {
        return Kuukausipalkkainen::LaskePalkka() + provisio;
    }
};

class Palkkajarjestelma {
public:
    static void LaskePalkat(const vector<Tyontekija *> &tyontekijat);
};

void Palkkajarjestelma::LaskePalkat(const vector<Tyontekija *> &tyontekijat) {
    for (const auto &tyontekija : tyontekijat) {
        cout << "Tyontekijan palkka" << endl;
        cout << "==================" << endl;
        cout << "Tunnus: " << tyontekija->tunnus << " - Nimi: " << tyontekija->nimi << endl;
        cout << "- Summa: " << tyontekija->LaskePalkka() << endl;
        cout << "\n";
    }
}

int main() {
    vector<Tyontekija *> tyontekijat;
    int valinta;

    while (true) {
        cout << "Palkkatyyppi" << endl;
        cout << "------------" << endl;
        cout << "(1) Kuukausipalkka" << endl;
        cout << "(2) Tuntipalkka" << endl;
        cout << "(3) Provisio" << endl;
        cout << "(0) Lopeta" << endl;
        cout << "Anna palkkatyyppi: ";
        cin >> valinta;

        if (valinta == 0) {
            cout << "\n";
            break;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // pienellä korjauksella voidaan hoitaa kaikki cin-syötön ongelmat tässä
        string nimi;
        cout << endl << "Anna tyontekijan nimi: ";

        getline(cin, nimi);

        Tyontekija *tyontekija = nullptr;

        switch (valinta) {
            case 1:
                tyontekija = new Kuukausipalkkainen(tyontekijat.size() + 1, nimi, 0);
                break;
            case 2:
                tyontekija = new Tuntipalkkainen(tyontekijat.size() + 1, nimi);
                break;
            case 3:
                tyontekija = new ProvisionPalkkainen(tyontekijat.size() + 1, nimi, 0);
                break;
            default:
                cout << "Virheellinen valinta." << endl;
                continue;
        }

        tyontekija->KysyPalkka();
        tyontekijat.push_back(tyontekija);
    }

    Palkkajarjestelma::LaskePalkat(tyontekijat);

    for (auto tyontekija : tyontekijat) {
        delete tyontekija;
    }

    return 0;
}