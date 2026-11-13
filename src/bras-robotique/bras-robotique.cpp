/**
 * ============================================================================
 *  Robot DJ — Projet de session S1 (Robus)
 * ============================================================================
 *  @file    bras-robotique.cpp
 *  @brief   Commande des bras du robot (servomoteurs sur carte PCA9685).
 *
 *  @details Code des fonctions déclarées dans bras-robotique.h.
 *           Chaque fonction du .h doit être écrite ici, avec exactement la même
 *           signature. Les explications (paramètres, retour) sont dans le .h.
 *
 *  @author  Samit Adelyar
 *  @date    2026-11-13
 * ============================================================================
 */

#include <bras-robotique/bras-robotique.h>

// --- Variables globales (déclarées « extern » dans le .h) ---
Adafruit_PWMServoDriver pca9685 = Adafruit_PWMServoDriver(ADRESSE_PCA9685);
uint8_t anglesActuels[NB_SERVOS_BRAS] = {ANGLE_REPOS, ANGLE_REPOS, ANGLE_REPOS, ANGLE_REPOS};

// TODO : écrire ici les fonctions déclarées dans bras-robotique.h
