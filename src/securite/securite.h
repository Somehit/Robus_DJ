/**
 * ============================================================================
 *  Robot DJ — Projet de session S1 (Robus)
 * ============================================================================
 *  @file    securite.h
 *  @brief   Arrêt d'urgence et surveillance de la batterie.
 *
 *  Tâches :
 *    J1 Surveiller la batterie et arrêter si la tension est trop basse
 *    J5 Bouton 3 : arrêt d'urgence sur la télécommande (+ bumper)
 *
 *  @author  Francois Mathieu (J5), Mathieu Guenette (J1)
 *  @date    2026-11-13
 * ============================================================================
 */

#ifndef SECURITE_H
#define SECURITE_H

#include <config.h>

const float TENSION_BATTERIE_FAIBLE_V = 10.0f; // à valider
const unsigned long INTERVALLE_VERIF_BATTERIE_MS = 1000;
const uint32_t FREQUENCE_ALERTE_HZ = 1000;

extern bool arretUrgenceActif;
extern unsigned long derniereVerifBatterie; // en millisecondes

/** @brief Prépare le module de sécurité. */
void SecuriteInit();

/** @brief Arrête tout : moteurs, musique, lumières et bras (J5). */
void ArretUrgence();

/** @brief Sort de l'arrêt d'urgence. */
void ReprendreApresArretUrgence();

/**
 * @brief Active l'arrêt d'urgence, ou le désactive s'il est déjà actif.
 * @return true si le robot est maintenant en arrêt d'urgence.
 */
bool BasculerArretUrgence();

/**
 * @brief Indique si un bumper vient d'être appuyé.
 * @return true au moment où un bumper est appuyé.
 */
bool BumperAppuye();

/**
 * @brief Vérifie les bumpers et bascule l'arrêt d'urgence au besoin.
 * @return true si le robot est en arrêt d'urgence.
 */
bool VerifierArretUrgence();

/**
 * @brief Lit la tension de la batterie.
 * @return Tension en volts.
 */
float LireTensionBatterie();

/**
 * @brief Indique si la batterie est trop faible.
 * @return true si la tension est sous TENSION_BATTERIE_FAIBLE_V.
 */
bool BatterieFaible();

/**
 * @brief Arrête le robot si la batterie est trop faible, sans bloquer (J1).
 * @return true si la batterie est correcte, false si le robot a été arrêté.
 */
bool SurveillerBatterie();

#endif
