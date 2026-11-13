/**
 * ============================================================================
 *  Robot DJ — Projet de session S1 (Robus)
 * ============================================================================
 *  @file    microphone.h
 *  @brief   Microphone MAX9814 : démarrer la musique en tapant des mains.
 *
 *  Tâches :
 *    F1 Installation d'un microphone MAX9814
 *    F2 Détecter le son ambiant et démarrer la musique quand on tape des mains
 *
 *  @author  Yassine Ennaji
 *  @date    2026-11-13
 * ============================================================================
 */

#ifndef MICROPHONE_H
#define MICROPHONE_H

#include <config.h>

const int BROCHE_MICRO = A4; // à confirmer

// Détection du clap (à calibrer)
const int SEUIL_CLAP = 300; // niveau sonore, 0 à 1023
const unsigned long FENETRE_MESURE_MS = 50;
const unsigned long DELAI_ENTRE_CLAPS_MS = 500;

extern bool microActif;
extern unsigned long dernierClap; // en millisecondes

/** @brief Configure la broche du microphone et active l'écoute. */
void MicroInit();

/**
 * @brief Mesure le niveau sonore ambiant.
 * @return Niveau sonore, de 0 (silence) à 1023.
 */
int LireNiveauSonore();

/**
 * @brief Détecte si quelqu'un vient de taper des mains (F2).
 * @return true si un clap vient d'être détecté.
 */
bool ClapDetecte();

/**
 * @brief Active ou désactive l'écoute du microphone.
 * @param actif true pour écouter, false pour ignorer les sons.
 */
void ActiverMicro(bool actif);

#endif
