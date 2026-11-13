/**
 * ============================================================================
 *  Robot DJ — Projet de session S1 (Robus)
 * ============================================================================
 *  @file    ecran-lcd.cpp
 *  @brief   Affichage sur l'écran LCD et boutons de navigation de musique.
 *
 *  @details Code des fonctions déclarées dans ecran-lcd.h.
 *           Chaque fonction du .h doit être écrite ici, avec exactement la même
 *           signature. Les explications (paramètres, retour) sont dans le .h.
 *
 *  @author  Mathieu Guenette
 *  @date    2026-11-13
 * ============================================================================
 */

#include <ecran-lcd/ecran-lcd.h>

// --- Variables globales (déclarées « extern » dans le .h) ---
Bouton boutonPrecedent = {BROCHE_BOUTON_PRECEDENT, LOW, LOW, 0};
Bouton boutonSuivant = {BROCHE_BOUTON_SUIVANT, LOW, LOW, 0};
Bouton boutonVolumeMoins = {BROCHE_BOUTON_VOLUME_MOINS, LOW, LOW, 0};
Bouton boutonVolumePlus = {BROCHE_BOUTON_VOLUME_PLUS, LOW, LOW, 0};

unsigned long debutAffichageBouton = 0;

// TODO : écrire ici les fonctions déclarées dans ecran-lcd.h
