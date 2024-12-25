#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string find_field(const string &xml, const string &tag_name);

int main() {
    string page, line, location, temperature;

    // Avaa XML-tiedosto ja lue sen sisältö merkkijonoon
    ifstream inputFile("/Users/ari/Desktop/cplusplus/metropolia/lab-02a/weather.xml");

    // Tarkista, onnistuiko tiedoston avaaminen
    if (!inputFile.is_open()) {
        cerr << "Virhe: Tiedoston 'weather.xml' avaaminen epäonnistui." << endl;
        return 1; // Poistu ohjelmasta virhekoodilla
    }

    // Lue tiedosto rivi riviltä ja liitä se 'page'-merkkijonoon
    while (getline(inputFile, line)) {
        page.append(line);
        line.erase();
    }

    location = find_field(page, "location");
    temperature = find_field(page, "temp_c");

    // Sulje tiedosto
    inputFile.close();

    cout << "Sijainti: " << location << endl;
    cout << "Lämpötila: " << temperature << endl;
}

string find_field(const string &xml, const string &tag_name) {

    const string start_tag = "<" + tag_name + ">";
    const string end_tag = "</" + tag_name + ">";

    size_t pos1 = xml.find(start_tag); // Etsii start_tag:ia, palauttaa string::npos jos ei löydy
    if (size_t pos2 = xml.find(end_tag); pos1 != string::npos && pos2 != string::npos) {
        string inner;
        pos1 += start_tag.size(); // Positio start_tag:n jälkeen
        pos2 -= pos1; // Merkkien määrä tagien välissä
        return inner = xml.substr(pos1, pos2); // Merkkijono tagien väliltä, substr(start, pituus)
    }

    return "ei löydy"; // Palauta tämä, jos tagia ei löydy
}
