// Client de test de PileGenerique.dll (liaison implicite : on lie avec libPileGenerique.a)
#include <iostream>
#include "PileDLL.h"
using namespace std;

int main()
{
    void* liste   = creerPileListe();
    void* tableau = creerPileTableau();

    for (int i = 1; i <= 5; i++)
    {
        empilerPileListe(liste, i * 10);
        empilerPileTableau(tableau, i * 10);
    }

    cout << "Depilage (attendu : 50 40 30 20 10)\n";
    cout << "liste   : ";
    while (!estVidePileListe(liste))     cout << depilerPileListe(liste) << " ";
    cout << "\ntableau : ";
    while (!estVidePileTableau(tableau)) cout << depilerPileTableau(tableau) << " ";
    cout << "\n";

    // le compteur compte les empilages (1 par element + copies pour le tableau)
    cout << "compteur liste   = " << compteurPileListe(liste)   << "  (attendu 5)\n";
    cout << "compteur tableau = " << compteurPileTableau(tableau) << "  (attendu 5 + 4 copies = 9)\n";

    detruirePileListe(liste);
    detruirePileTableau(tableau);
    return 0;
}
