/**
 * ============================================================================
 *  Robot DJ — Projet de session S1 (Robus)
 * ============================================================================
 *  @file    securite.cpp
 *  @brief   Arrêt d'urgence et surveillance de la batterie.
 *
 *  @details Code des fonctions déclarées dans securite.h.
 *           Chaque fonction du .h doit être écrite ici, avec exactement la même
 *           signature. Les explications (paramètres, retour) sont dans le .h.
 *
 *  @author  Francois Mathieu (J5), Mathieu Guenette (J1)
 *  @date    2026-11-13
 * ============================================================================
 */

#include <securite/securite.h>

// Autres modules utilisés par les fonctions de ce fichier
#include <mouvement/mouvement.h> // stopMotors
#include <musique/musique.h> // ArreterMusique
#include <lumiere-disco/lumiere-disco.h> // EteindreBouleDisco
#include <bras-robotique/bras-robotique.h> // BrasAuRepos

// --- Variables globales (déclarées « extern » dans le .h) ---
bool arretUrgenceActif = false;
unsigned long derniereVerifBatterie = 0;

// TODO : écrire ici les fonctions déclarées dans securite.h
