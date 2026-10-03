#ifndef PILELISTE_H
#define PILELISTE_H
#include <stdexcept>

template <class T>
class PileListe
{
    struct Noeud { T valeur; Noeud* suivant; Noeud(const T& v, Noeud* s) : valeur(v), suivant(s) {} };
    Noeud* sommetPile; int taille; long long compteur;
public:
    PileListe() : sommetPile(nullptr), taille(0), compteur(0) {}
    ~PileListe() { while (sommetPile) { Noeud* n = sommetPile; sommetPile = sommetPile->suivant; delete n; } }
    PileListe(const PileListe&) = delete;
    PileListe& operator=(const PileListe&) = delete;
    void empiler(const T& v) { sommetPile = new Noeud(v, sommetPile); taille++; compteur++; }
    T depiler() { if (!sommetPile) throw std::runtime_error("Pile (liste) vide : impossible de depiler");
                  Noeud* n = sommetPile; T v = n->valeur; sommetPile = n->suivant; delete n; taille--; return v; }
    const T& sommet() const { if (!sommetPile) throw std::runtime_error("Pile (liste) vide : pas de sommet"); return sommetPile->valeur; }
    bool estVide() const { return sommetPile == nullptr; }
    int getTaille() const { return taille; }
    long long getCompteur() const { return compteur; }
};
#endif
