/**
 * ============================================================================
 *  Robot DJ — Projet de session S1 (Robus)
 * ============================================================================
 *  @file    lumiere-disco.h
 *  @brief   Commande de la boule disco.
 *
 *  Tâches :
 *    E1 Installation de la boule disco
 *    E2 Allumer / fermer la boule disco
 *    E3 La boule disco joue quand une musique se lance
 *    E9 Faire réagir la boule disco à la musique (BPM)
 *
 *  @author  Benjamin Dorion
 *  @date    2026-11-13
 * ============================================================================
 */

#ifndef LUMIERE_DISCO_H
#define LUMIERE_DISCO_H

#include <config.h>

const int BROCHE_BOULE_DISCO = 38; // à confirmer

// Rythme en battements par minute (E9)
const uint16_t BPM_DEFAUT = 120;
const uint16_t BPM_MIN = 60;
const uint16_t BPM_MAX = 200;

extern bool bouleDiscoAllumee;
extern uint16_t bpmActuel;

/** @brief Configure la broche de la boule disco et l'éteint. */
void LumiereDiscoInit();

/** @brief Allume la boule disco (E2). */
void AllumerBouleDisco();

/** @brief Éteint la boule disco (E2). */
void EteindreBouleDisco();

/**
 * @brief Allume la boule si une musique joue, l'éteint sinon (E3).
 * @return true si la boule disco est allumée.
 */
bool SynchroniserBouleDisco();

/**
 * @brief Change le rythme du clignotement (E9).
 * @param bpm Battements par minute (BPM_MIN à BPM_MAX).
 */
void ReglerRythme(uint16_t bpm);

/** @brief Fait clignoter la boule au rythme de bpmActuel, sans bloquer (E9). */
void ActualiserBouleDisco();

#endif
