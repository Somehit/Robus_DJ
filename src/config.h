/**
 * ============================================================================
 *  Robot DJ — Projet de session S1 (Robus)
 * ============================================================================
 *  @file    config.h
 *  @brief   Configuration commune, incluse par tous les modules.
 *
 *  Tâches : J4 Normaliser le code, G1 Noter les pins utilisées
 *
 *  @author  Harjot Singh Dragneer, Yassine Ennaji
 *  @date    2026-11-13
 * ============================================================================
 */

#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>
#include <Wire.h>
#include <LibRobus.h>

// Broches déjà prises par LibRobus / Arduino-X (ne pas réutiliser) :
//   4, 7        servomoteurs LibRobus
//   5, 6        PWM des moteurs
//   12          batterie faible
//   14 à 17     Serial3 (audio MP3), Serial2 (Bluetooth)
//   20, 21      I2C : écran LCD (0x27), carte PCA9685 (0x40)
//   22 à 25     sonars
//   26 à 29     bumpers (avant, gauche, arrière, droit)
//   30, 31      direction des moteurs
//   34, 35      encodeurs
//   36          avertisseur sonore
//   37          récepteur infrarouge
//   46          DEL infrarouge (IRsend)
//   50 à 53     SPI
//   A0 à A3     télémètres infrarouges
//   A14, A15    encodeurs
// Broches libres : 2, 3, 8 à 11, 13, 38 à 45, 47 à 49, A4 à A13

/** @brief Bouton-poussoir avec anti-rebond. */
struct Bouton
{
    int broche;
    bool lecturePrecedente;
    bool etatStable;
    unsigned long dernierChangement; // en millisecondes
};

const unsigned long TEMPS_ANTI_REBOND = 50; // ms

#endif
