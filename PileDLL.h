#ifndef PILEDLL_H
#define PILEDLL_H

/*  Interface C de PileGenerique.dll
 *  - Compilation de la DLL : definir PILEDLL_BUILD  (-> dllexport)
 *  - Utilisation par un client : ne rien definir     (-> dllimport)
 *  Les piles sont manipulees via un pointeur opaque (void*).            */

#if defined(_WIN32)
    #ifdef PILEDLL_BUILD
        #define PILE_API __declspec(dllexport)
    #else
        #define PILE_API __declspec(dllimport)
    #endif
#else
    #define PILE_API __attribute__((visibility("default")))
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* ---- Pile basee sur une liste chainee (PileListe<int>) ---- */
PILE_API void*     creerPileListe();
PILE_API void      detruirePileListe(void* pile);
PILE_API void      empilerPileListe(void* pile, int valeur);
PILE_API int       depilerPileListe(void* pile);      /* appeler estVide avant ! */
PILE_API int       estVidePileListe(void* pile);      /* 1 = vide, 0 = non vide  */
PILE_API long long compteurPileListe(void* pile);

/* ---- Pile basee sur un tableau dynamique (PileTableau<int>) ---- */
PILE_API void*     creerPileTableau();
PILE_API void      detruirePileTableau(void* pile);
PILE_API void      empilerPileTableau(void* pile, int valeur);
PILE_API int       depilerPileTableau(void* pile);    /* appeler estVide avant ! */
PILE_API int       estVidePileTableau(void* pile);
PILE_API long long compteurPileTableau(void* pile);

#ifdef __cplusplus
}
#endif

#endif /* PILEDLL_H */
