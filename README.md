# Robot DJ

Projet de session S1 (Université de Sherbrooke) : un robot **Robus** transformé en DJ. Il joue de la musique, danse dans une zone de 2 m × 2 m, bouge ses bras, allume sa boule disco et affiche ce qu'il fait sur un écran LCD. On le contrôle avec une télécommande infrarouge faite maison.

| Bouton de la télécommande | Effet sur le robot |
|---|---|
| Bouton 1 | Lance une danse : chorégraphie + bras + musique au hasard + lumières |
| Bouton 2 | Allume / éteint le robot |
| Bouton 3 | Arrêt d'urgence (un bumper fait la même chose). Un 2ᵉ appui relance le robot |

Sur le robot, des boutons de navigation changent la musique (précédente / suivante) et le volume. Taper des mains démarre aussi la musique (microphone).

Le suivi des tâches (qui fait quoi, priorités, heures, broches, bilan de puissance) est dans le Google Sheets de l'équipe **« Tableau de fonctionnalités - Robot DJ »**. Les codes de tâche (A4, B3, J5...) écrits dans les fichiers viennent de là.

---

## Structure du projet

```text
Robus_DJ/
├── platformio.ini            # Configuration PlatformIO (Arduino Mega 2560)
├── README.md
└── src/
    ├── main.cpp              # setup() et loop() — vide pour l'instant (tâche J3)
    ├── config.h              # Inclus partout : bibliothèques, broches réservées, type Bouton
    │
    ├── bras-robotique/       # Bras (servos sur carte PCA9685)
    ├── musique/              # Lecteur MP3, volume, musique au hasard
    ├── mouvement/            # Chorégraphies, zone de 2 x 2 m, détection d'obstacle
    │   └── motor/            # Avancer / tourner avec PID (code déjà fonctionnel)
    ├── telecommande/         # Envoi et réception des codes infrarouges
    ├── lumiere-disco/        # Boule disco
    ├── ecran-lcd/            # Écran LCD et boutons de navigation
    ├── microphone/           # Détection des claps (MAX9814)
    └── securite/             # Arrêt d'urgence et surveillance de la batterie
```

Chaque dossier contient un `.h` (la liste des fonctions, déjà écrite) et un `.cpp` (le code, à écrire).

---

## Qui fait quoi

| Module | Responsable | Tâches | Testeur |
|---|---|---|---|
| `bras-robotique/` | Samit Adelyar | A4 à A7 | Benjamin Dorion |
| `musique/` | Jérémy Drouin (code), Yassine Ennaji (choix des musiques, B6) | B3 à B7 | Harjot Singh Dragneer |
| `mouvement/` | Charles Croteau | C1 à C5 | Samit Adelyar |
| `mouvement/motor/` | Francois Mathieu (calibration du PID) | C6 | Harjot Singh Dragneer |
| `telecommande/` | Naguy Cantin | D3 à D6 | Harjot Singh Dragneer |
| `lumiere-disco/` | Benjamin Dorion | E2, E3, E9 | Harjot Singh Dragneer |
| `ecran-lcd/` | Mathieu Guenette | E5 à E8 | Samit Adelyar |
| `microphone/` | Yassine Ennaji | F2 | à déterminer |
| `securite/` | Francois Mathieu (arrêt d'urgence, J5), Mathieu Guenette (batterie, J1) | J1, J5 | Harjot Singh Dragneer |
| `main.cpp`, `config.h` | Harjot Singh Dragneer | J3, J4 | — |

---

## Comment coder ta partie

1. Ouvre le `.h` de ton module. Chaque fonction y est déjà déclarée, avec un commentaire qui dit **ce qu'elle reçoit** (`@param`) et **ce qu'elle doit retourner** (`@return`).
2. Ouvre le `.cpp` du même dossier. Les variables globales y sont déjà. Écris tes fonctions sous la ligne `// TODO`, en recopiant exactement la signature du `.h` :

   ```cpp
   // Dans musique.h (déjà écrit) :
   void ReglerVolume(uint8_t pourcentage);

   // Dans musique.cpp (à écrire) :
   void ReglerVolume(uint8_t pourcentage)
   {
       // ton code ici
   }
   ```

3. Compile souvent (`✔ Build`). Une erreur « undefined reference to ... » veut dire qu'une fonction est déclarée dans un `.h` mais pas encore écrite dans le `.cpp`.
4. Pour tester ta partie seule, appelle tes fonctions dans `setup()` / `loop()` de `main.cpp` **sans committer ce test** : la vraie boucle principale est la tâche J3.
5. Si tu dois changer une signature (ajouter un paramètre, changer le retour), change-la dans le `.h` **et** préviens ceux qui appellent ta fonction.

---

## Conventions de code

- **Noms en français.** Fonctions en `MajusculeAChaqueMot` (`JouerMusique`), variables en `minusculePuisMajuscules` (`volumeActuel`), constantes en `MAJUSCULES_AVEC_TIRETS_BAS` (`VOLUME_MAX`).
- **Le `.h` contient** : l'en-tête du fichier, les gardes d'inclusion, les constantes, les variables `extern` et les déclarations de fonctions documentées en Doxygen.
- **Le `.cpp` contient** : le code des fonctions, la définition des variables globales et les fonctions d'aide privées (celles que les autres n'ont pas besoin d'appeler).
- **Tous les `.h` incluent `<config.h>`**, qui apporte déjà `Arduino.h`, `Wire.h` et `LibRobus.h`. Un `.cpp` qui appelle un autre module inclut le `.h` de ce module (ex. : `#include <musique/musique.h>`).
- **Pas de `delay()` dans les fonctions appelées à chaque tour de `loop()`** (celles qui s'appellent `Actualiser...`, `Surveiller...`, `Verifier...`). Utiliser `millis()`, sinon le robot ne voit plus la télécommande ni l'arrêt d'urgence pendant l'attente.
- **Une valeur à mesurer ou à confirmer est marquée `À CONFIRMER`, `À AJUSTER` ou `À CALIBRER`** dans les `.h`. Retirer la mention quand c'est fait.

Modèle de commentaire Doxygen :

```cpp
/**
 * @brief Brève description de ce que fait la fonction.
 * @param numero Ce que la fonction reçoit, avec les valeurs permises.
 * @return Ce que la fonction retourne (ou « Rien. »).
 */
uint8_t MaFonction(uint8_t numero);
```

---

## Broches

### Déjà prises par LibRobus / Arduino-X — ne pas réutiliser

| Broche(s) | Utilisation |
|---|---|
| 4, 7 | Servomoteurs LibRobus (connecteurs J6 / J7) |
| 5, 6 | PWM des moteurs de roues |
| 12 | Détection batterie faible |
| 14, 15 | Serial3 : lecteur audio MP3 |
| 16, 17 | Serial2 : Bluetooth |
| 20, 21 | I2C (SDA, SCL) : écran LCD (0x27) et carte PCA9685 (0x40) |
| 22 à 25 | Sonars 1 et 2 |
| 26 à 29 | Bumpers (avant 26, gauche 27, arrière 28, droit 29) |
| 30, 31 | Direction des moteurs de roues |
| 34, 35, 50 à 53 | Encodeurs (SPI) |
| 36 | Avertisseur sonore |
| 37 | Récepteur infrarouge (télécommande) |
| 46 | DEL infrarouge en émission (`IRsend`) |
| A0 à A3 | Télémètres infrarouges |
| A14, A15 | Encodeurs |

Broches libres : 2, 3, 8 à 11, 13, 38 à 45, 47 à 49, A4 à A13.

### Proposées pour nos composantes — à confirmer

Ces valeurs sont des propositions écrites dans les `.h`. Quand une composante est réellement branchée, corriger le `.h` au besoin **et** l'inscrire dans l'onglet « Pins » du Google Sheets (tâche G1).

| Carte | Broche | Composante | Fichier |
|---|---|---|---|
| Robot | 38 | Boule disco | `lumiere-disco.h` |
| Robot | 39, 40 | Boutons musique précédente / suivante | `ecran-lcd.h` |
| Robot | 41, 42 | Boutons volume − / + | `ecran-lcd.h` |
| Robot | A4 | Microphone MAX9814 | `microphone.h` |
| Robot | I2C 0x40 | Carte PCA9685 (servos des bras, canaux 0 à 3) | `bras-robotique.h` |
| Télécommande | 3, 4, 5 | Boutons urgence, danse, marche/arrêt | `telecommande.h` |
| Télécommande | 6, 7 | DEL rouge, DEL verte | `telecommande.h` |
| Télécommande | 46 | DEL infrarouge | `telecommande.h` |

---

## Matériel et alimentation

Résumé des deux manuels fournis pour le projet : *Manuel d'assemblage et d'utilisation de Robus* (Faculté de génie, automne 2026) et le manuel du chargeur Makita DC10SB. En cas de doute, les manuels ont priorité sur ce résumé.

### Batterie

- Robus utilise une batterie d'outils **Makita lithium-ion 12 V max** (10,8 V nominal, 3 cellules).
- Le bouton sur la batterie affiche le niveau de charge. **Une seule barre rouge ou plus rien = recharger.**
- **Si le voyant bleu « Low Bat » s'allume ou que l'avertisseur sonne : débrancher la batterie tout de suite et la recharger.** Une batterie lithium-ion vidée trop bas perd de la capacité et finit par ne plus fonctionner.
- Ne pas court-circuiter la batterie, ne pas l'exposer à l'eau.

### Chargeur Makita DC10SB

- Utiliser **seulement** ce chargeur, et seulement avec les batteries Makita. Un chargeur sert pour deux robots.
- Charger à l'intérieur, entre **10 °C et 40 °C**. Ne rien poser sur les évents du chargeur.
- Après la charge : retirer la batterie et débrancher le chargeur.

| Témoin | Signification |
|---|---|
| Vert clignotant | Prêt, aucune batterie en charge |
| Rouge fixe | Charge en cours, 0 à 80 % |
| Rouge + vert fixes | Charge en cours, 80 à 100 % |
| Vert fixe | Charge terminée |
| Rouge clignotant | Charge retardée : batterie trop chaude ou trop froide |
| Vert et rouge en alternance | Charge impossible : bornes sales, batterie usée ou endommagée |
| Jaune clignotant | Problème de refroidissement (ventilateur ou évents bouchés) |

Temps de charge approximatif sur le DC10SB : 22 min (BL1016), 30 min (BL1021B), 60 min (BL1041B).

### Mise sous tension du robot

1. Vérifier que l'interrupteur **S2** de l'Arduino-X est à « OFF ».
2. Brancher la batterie dans le connecteur rond **« +12VDC » (J2)** de l'Arduino-X.
3. Mettre S2 à « ON ». Les DEL D3 et D9 de l'Arduino-X s'allument.
4. La carte d'interface (demi-lune) a son propre interrupteur **S1**.

### Tensions disponibles sur la carte d'interface

| Point de test | Tension attendue | Sert à |
|---|---|---|
| TP3 (Vboard) | au moins 12 V, batterie chargée | Alimentation générale |
| TP2 (+5V) | environ 5,2 V | Logique, capteurs |
| TP1 (Vservo) | environ 5 V, réglable avec le potentiomètre R3 | Servos branchés sur J6 / J7 |

Les servos des bras ne passent pas par J6 / J7 : ils sont commandés par la carte PCA9685 et alimentés par le convertisseur Buck (tâches G6 et G7). Le bilan de puissance (onglets « Composantes » et « Bilan de puissance ») sert à vérifier que chaque rail fournit assez de courant.

### Amplificateur audio de la carte d'interface

- Amplificateur LM386. Entrée par le connecteur **J3** (GND / IN) ou la prise 3,5 mm **J2**, haut-parleur sur **J15**.
- Volume matériel : potentiomètre **R22**. Le baisser avant un premier test.
- Un signal trop fort ne sonne pas plus fort : il sature, se déforme et peut endommager le haut-parleur.

### Si un circuit ne fonctionne pas

1. Comparer les branchements avec le plan (en dessiner un s'il n'existe pas).
2. Vérifier les alimentations au multimètre.
3. **Une pièce qui chauffe : débrancher l'alimentation tout de suite**, puis corriger le branchement.
4. Mesurer le signal de l'entrée vers la sortie pour trouver où il devient mauvais.
5. Si la DEL +5V s'éteint quand on branche ou appuie sur un bumper, ce bumper est branché à l'envers.

---

## Compilation et téléversement

1. Ouvrir le dossier `Robus_DJ/` dans **VS Code** avec l'extension **PlatformIO**.
2. Compiler avec la coche (`✔ Build`) dans la barre du bas. Les bibliothèques (LibRobus, Adafruit PWM Servo Driver) se téléchargent toutes seules la première fois.
3. Brancher l'Arduino Mega du robot par USB et téléverser avec la flèche (`➡ Upload`).
4. Le moniteur série est à **9600 bauds**.

---

## Références

- LibRobus (fonctions `MOTOR_`, `AUDIO_`, `DISPLAY_`, `ROBUS_`, `AX_`...) : https://github.com/UdeS-GRO/LibRobUS/wiki
- *Manuel d'assemblage et d'utilisation de Robus* et manuel du chargeur Makita DC10SB : site de session.
