/**
 * ============================================================================
 *  Robot DJ — Projet de session S1 (Robus)
 * ============================================================================
 *  @file    lumiere-disco.cpp
 *  @brief   Commande de la boule disco (lumières du robot).
 *
 *  @details Code des fonctions déclarées dans lumiere-disco.h.
 *           Chaque fonction du .h doit être écrite ici, avec exactement la même
 *           signature. Les explications (paramètres, retour) sont dans le .h.
 *
 *  @author  Benjamin Dorion
 *  @date    2026-11-13
 * ============================================================================
 */

#include <lumiere-disco/lumiere-disco.h>

// Autres modules utilisés par les fonctions de ce fichier
#include <musique/musique.h> // musiqueEnCours (tâche E3)

// --- Variables globales (déclarées « extern » dans le .h) ---
bool bouleDiscoAllumee = false;
uint16_t bpmActuel = BPM_DEFAUT;

// TODO : écrire ici les fonctions déclarées dans lumiere-disco.h
