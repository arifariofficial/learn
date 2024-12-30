// src/Tehtava.cpp

#include "../include/Tehtava.h"
#include <iostream>


Tehtava::Tehtava(int id, std::string  nimi, std::string  kuvaus)
    : id(id), nimi(std::move(nimi)), kuvaus(std::move(kuvaus)), suoritettu(false) {}

void Tehtava::merkitseSuoritetuksi() {
    suoritettu = true;
}

void Tehtava::merkitseTekemattomaksi() {
    suoritettu = false;
}

void Tehtava::naytaTiedot() const {
    std::cout << "ID: " << id << "\nNimi: " << nimi
              << "\nKuvaus: " << kuvaus
              << "\nTila: " << (suoritettu ? "Suoritettu" : "Tekemättä")
              << "\n" << std::endl;
}

int Tehtava::getId() const{
    return id;
}

std::string Tehtava::getNimi() const {
    return nimi;
}

std::string Tehtava::getKuvaus() const {
    return kuvaus;
}

bool Tehtava::onSuoritettu() const {
    return suoritettu;
}