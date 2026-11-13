/**
 * ============================================================================
 *  Robot DJ — Projet de session S1 (Robus)
 * ============================================================================
 *  @file    musique.cpp
 *  @brief   Lecture de la musique (lecteur MP3 + enceinte).
 *
 *  @details Code des fonctions déclarées dans musique.h.
 *           Chaque fonction du .h doit être écrite ici, avec exactement la même
 *           signature. Les explications (paramètres, retour) sont dans le .h.
 *
 *  @author  Jérémy Drouin (B3, B4, B5, B7), Yassine Ennaji (B6)
 *  @date    2026-11-13
 * ============================================================================
 */

#include <musique/musique.h>

// --- Variables globales (déclarées « extern » dans le .h) ---

// Titres dans le même ordre que les fichiers sur la carte SD (tâche B6).
// Il doit y avoir exactement NB_MUSIQUES titres, de 20 caractères maximum.
const char *const TITRES_MUSIQUES[NB_MUSIQUES] = {
    "Musique 1",
    "Musique 2",
    "Musique 3",
    "Musique 4",
    "Musique 5",
};

uint8_t musiqueActuelle = AUCUNE_MUSIQUE;
uint8_t volumeActuel = VOLUME_DEFAUT;
bool musiqueEnCours = false;

// TODO : écrire ici les fonctions déclarées dans musique.h
