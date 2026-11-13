/**
 * ============================================================================
 *  Robot DJ — Projet de session S1 (Robus)
 * ============================================================================
 *  @file    mouvement.h
 *  @brief   Chorégraphies du robot et sécurité des déplacements.
 *
 *  Tâches :
 *    C1 Chorégraphie 1
 *    C2 Chorégraphie 2
 *    C3 Chorégraphie 3
 *    C4 Détecter la présence de l'audience
 *    C5 Empêcher le robot de sortir de la zone (2 x 2 mètres)
 *
 *  @author  Charles Croteau
 *  @date    2026-11-13
 * ============================================================================
 */

#ifndef MOUVEMENT_H
#define MOUVEMENT_H

#include <config.h>
#include <mouvement/motor/motor.h>

const uint8_t NB_CHOREGRAPHIES = 3;

// Zone de danse (C5)
const float ZONE_LARGEUR_M = 2.0f;
const float ZONE_LONGUEUR_M = 2.0f;
const float MARGE_ZONE_M = 0.25f; // à ajuster

// Détection de l'audience (C4)
const uint8_t SONAR_AVANT = 0; // à confirmer
const float DISTANCE_OBSTACLE_M = 0.30f;

/** @brief Position du robot. (0, 0) est le centre de la zone. */
struct PositionRobot
{
    float x;           // mètres, + vers la droite
    float y;           // mètres, + vers l'avant
    float angleDegres; // 0 = face à l'avant, + vers la droite
};

extern PositionRobot position;

/** @brief Prépare les moteurs et remet la position à zéro. */
void MouvementInit();

/** @brief Chorégraphie 1 (C1). */
void Choregraphie1();

/** @brief Chorégraphie 2 (C2). */
void Choregraphie2();

/** @brief Chorégraphie 3 (C3). */
void Choregraphie3();

/**
 * @brief Lance une chorégraphie selon son numéro.
 * @param numero Numéro de la chorégraphie (1 à NB_CHOREGRAPHIES).
 */
void LancerChoregraphie(uint8_t numero);

/**
 * @brief Lance une chorégraphie au hasard.
 * @return Numéro de la chorégraphie lancée.
 */
uint8_t LancerChoregraphieAuHasard();

/**
 * @brief Vérifie s'il y a un obstacle devant le robot (C4).
 * @return true si un obstacle est à moins de DISTANCE_OBSTACLE_M.
 */
bool ObstacleDevant();

/**
 * @brief Vérifie si un point est dans la zone permise (C5).
 * @param x Position gauche/droite en mètres.
 * @param y Position avant/arrière en mètres.
 * @return true si le point est dans la zone.
 */
bool EstDansZone(float x, float y);

/**
 * @brief Vérifie si le robot peut avancer sans danger (C4, C5).
 * @param distanceMetres Distance prévue (négative = reculer).
 * @return true si l'arrivée est dans la zone et sans obstacle.
 */
bool PeutAvancer(float distanceMetres);

/**
 * @brief Avance seulement si c'est sécuritaire (C5).
 * @param distanceMetres Distance en mètres (négative = reculer).
 * @return true si le déplacement a été fait, false s'il a été refusé.
 */
bool AvancerDansZone(float distanceMetres);

/**
 * @brief Tourne sur place et met à jour l'orientation.
 * @param degres Angle en degrés (positif = droite, négatif = gauche).
 */
void TournerDansZone(float degres);

#endif
