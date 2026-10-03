#ifndef PILETABLEAU_H
#define PILETABLEAU_H
#include <stdexcept>

template <class T>
class PileTableau
{
    T* tableau; int capacite; int taille; long long compteur;
    void agrandir()
    {
        int nouvelle = capacite * 2;
        T* nt = new T[nouvelle];
        for (int i = 0; i < taille; i++) { nt[i] = tableau[i]; compteur++; }
        delete[] tableau; tableau = nt; capacite = nouvelle;
    }
public:
    PileTableau(int cap = 4) : capacite(cap), taille(0), compteur(0) { tableau = new T[capacite]; }
    ~PileTableau() { delete[] tableau; }
    PileTableau(const PileTableau&) = delete;
    PileTableau& operator=(const PileTableau&) = delete;
    void empiler(const T& v) { if (taille == capacite) agrandir(); tableau[taille++] = v; compteur++; }
    T depiler() { if (taille == 0) throw std::runtime_error("Pile (tableau) vide : impossible de depiler"); return tableau[--taille]; }
    const T& sommet() const { if (taille == 0) throw std::runtime_error("Pile (tableau) vide : pas de sommet"); return tableau[taille-1]; }
    bool estVide() const { return taille == 0; }
    int getTaille() const { return taille; }
    long long getCompteur() const { return compteur; }
};
#endif
