/**
 * ============================================================================
 *  Robot DJ — Projet de session S1 (Robus)
 * ============================================================================
 *  @file    bras-robotique.h
 *  @brief   Commande des bras du robot (servomoteurs sur carte PCA9685).
 *
 *  Tâches :
 *    A4 Mouvement de bras 1
 *    A5 Mouvement de bras 2
 *    A6 Mouvement de bras 3
 *    A7 Tenir la télécommande dans les mains
 *
 *  @author  Samit Adelyar
 *  @date    2026-11-13
 * ============================================================================
 */

#ifndef BRAS_ROBOTIQUE_H
#define BRAS_ROBOTIQUE_H

#include <config.h>
#include <Adafruit_PWMServoDriver.h>

// Carte PCA9685 (I2C)
const uint8_t ADRESSE_PCA9685 = 0x40;
const uint8_t FREQUENCE_SERVO_HZ = 50;

// Calibration des servos (à mesurer)
const uint16_t IMPULSION_MIN = 150; // 0 degré
const uint16_t IMPULSION_MAX = 600; // 180 degrés

// Angles en degrés
const uint8_t ANGLE_MIN = 0;
const uint8_t ANGLE_MAX = 180;
const uint8_t ANGLE_REPOS = 90;
const uint8_t ANGLE_TENIR_TELECOMMANDE = 45; // à ajuster

const unsigned long DELAI_PAR_DEGRE_MS = 5;
const uint8_t NB_MOUVEMENTS_BRAS = 3;

/** @brief Servos des bras. La valeur est le canal sur la carte PCA9685. */
enum ServoBras : uint8_t
{
    EPAULE_GAUCHE = 0,
    COUDE_GAUCHE = 1,
    EPAULE_DROITE = 2,
    COUDE_DROIT = 3,
    NB_SERVOS_BRAS = 4
};

extern Adafruit_PWMServoDriver pca9685;
extern uint8_t anglesActuels[NB_SERVOS_BRAS]; // dernier angle de chaque servo

/** @brief Démarre la carte PCA9685 et place les bras au repos. */
void BrasInit();

/**
 * @brief Envoie un servo à un angle.
 * @param servo Servo à bouger.
 * @param angle Angle en degrés (0 à 180).
 */
void BougerServo(ServoBras servo, uint8_t angle);

/**
 * @brief Amène un servo à un angle doucement (bloquante).
 * @param servo Servo à bouger.
 * @param angle Angle final en degrés (0 à 180).
 */
void BougerServoDoucement(ServoBras servo, uint8_t angle);

/** @brief Replace tous les servos à ANGLE_REPOS. */
void BrasAuRepos();

/** @brief Mouvement de bras 1 (A4). */
void MouvementBras1();

/** @brief Mouvement de bras 2 (A5). */
void MouvementBras2();

/** @brief Mouvement de bras 3 (A6). */
void MouvementBras3();

/**
 * @brief Lance un mouvement de bras selon son numéro.
 * @param numero Numéro du mouvement (1 à NB_MOUVEMENTS_BRAS).
 */
void LancerMouvementBras(uint8_t numero);

/** @brief Place les mains pour tenir la télécommande (A7). */
void TenirTelecommande();

/** @brief Relâche la télécommande et retourne au repos. */
void LacherTelecommande();

#endif
