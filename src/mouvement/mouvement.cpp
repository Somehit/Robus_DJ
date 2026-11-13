/**
 * ============================================================================
 *  Robot DJ — Projet de session S1 (Robus)
 * ============================================================================
 *  @file    mouvement.cpp
 *  @brief   Chorégraphies du robot et sécurité des déplacements.
 *
 *  @details Code des fonctions déclarées dans mouvement.h.
 *           Chaque fonction du .h doit être écrite ici, avec exactement la même
 *           signature. Les explications (paramètres, retour) sont dans le .h.
 *
 *  @author  Charles Croteau
 *  @date    2026-11-13
 * ============================================================================
 */

#include <mouvement/mouvement.h>

// Autres modules utilisés par les fonctions de ce fichier
#include <securite/securite.h> // VerifierArretUrgence() pendant les chorégraphies

// --- Variables globales (déclarées « extern » dans le .h) ---
PositionRobot position = {0.0f, 0.0f, 0.0f}; // au centre de la zone, face à l'avant

// TODO : écrire ici les fonctions déclarées dans mouvement.h
