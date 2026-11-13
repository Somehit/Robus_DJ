/**
 * ============================================================================
 *  Robot DJ — Projet de session S1 (Robus)
 * ============================================================================
 *  @file    microphone.cpp
 *  @brief   Microphone MAX9814 : démarrer la musique en tapant des mains.
 *
 *  @details Code des fonctions déclarées dans microphone.h.
 *           Chaque fonction du .h doit être écrite ici, avec exactement la même
 *           signature. Les explications (paramètres, retour) sont dans le .h.
 *
 *  @author  Yassine Ennaji
 *  @date    2026-11-13
 * ============================================================================
 */

#include <microphone/microphone.h>

// --- Variables globales (déclarées « extern » dans le .h) ---
bool microActif = true;
unsigned long dernierClap = 0;

// TODO : écrire ici les fonctions déclarées dans microphone.h
