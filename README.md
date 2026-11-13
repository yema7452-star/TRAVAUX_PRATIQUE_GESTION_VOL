# Application de Gestion des Vols et des Réservations (Projet C++)

## Présentation du projet

Ce projet a été réalisé dans le cadre d'un **Travail Pratique (TP) en langage C++** (Licence 3 Mathématiques-Informatique). Il s'agit d'une application console orientée objet destinée à informatiser les opérations quotidiennes d'une agence de voyage à Cotonou : gestion des vols, enregistrement des passagers, suivi des réservations et traçabilité des paiements.

### Informations académiques
* **Auteur :** AKAKPO Yéma
* **Niveau :** Licence 3 — Mathématiques-Informatique
* **Type de projet :** Travaux Pratiques (TP) — Programmation Orientée Objet en C++
* **Date :** Novembre 2026

---

## Fonctionnalités principales

L'application repose sur un menu interactif en console permettant d'exécuter les opérations suivantes :

1. **Gestion des passagers :**
   * Enregistrer un nouveau passager avec un identifiant unique.
   * Modifier ou afficher les informations d'un passager.
2. **Gestion des vols :**
   * Ajouter un nouveau vol (numéro, origine, destination, date, capacité maximale).
   * Afficher la liste des vols disponibles et le nombre de places restantes.
   * Rechercher un vol selon des critères de trajet ou de numéro.
3. **Gestion des réservations :**
   * Créer une réservation en associant un passager existant à un vol disponible.
   * Vérifier automatiquement le respect de la capacité maximale du vol.
   * Consulter l'ensemble des réservations ou afficher les détails d'une réservation précise.
   * Annuler une réservation existante et libérer la place correspondante.
4. **Gestion des paiements :**
   * Enregistrer un paiement unique associé à une réservation (montant, date, mode de règlement).
   * Valider ou rembourser un paiement en cas d'annulation.
5. **Contrôle de l'exécution :**
   * **Quitter le programme :** Option dédiée (`0`) dans le menu principal permettant de fermer proprement l'application.

---

## Architecture du code

Le projet respecte les principes de la programmation orientée objet (encapsulation, séparation des responsabilités) à travers cinq classes métier principales :

* `Passager` (`Passager.h` / `Passager.cpp`) : Gestion de l'identité et des coordonnées des clients.
* `Vol` (`Vol.h` / `Vol.cpp`) : Gestion des trajets, dates et calcul des places disponibles.
* `Reservation` (`Reservation.h` / `Reservation.cpp`) : Association entre un passager, un vol et un éventuel paiement.
* `Paiement` (`Paiement.h` / `Paiement.cpp`) : Suivi financier et statut des règlements.
* `Agence` (`Agence.h` / `Agence.cpp`) : Classe centrale orchestrant les collections de données et les règles métier.
* `main.cpp` : Point d'entrée du programme gérant la boucle d'interaction utilisateur et l'option de sortie.

---

## Prérequis et instructions de compilation

### Prérequis
* Un compilateur C++ prenant en charge la norme **C++17** ou supérieure (ex. : `g++` via GCC/MinGW, ou `clang++`).
* Un terminal ou invite de commandes (Linux, macOS ou Windows).

### Compilation en ligne de commande (avec `g++`)

Placez-vous dans le répertoire racine contenant les fichiers sources (`.cpp` et `.h`), puis exécutez la commande suivante :

```bash
g++ -std=c++17 -Wall -Wextra main.cpp Agence.cpp Passager.cpp Vol.cpp Reservation.cpp Paiement.cpp -o gestion_vols
```

*(Sous Windows avec MinGW, l'exécutable généré se nommera `gestion_vols.exe`).*

### Exécution du programme

* **Sur Linux / macOS :**
  ```bash
  ./gestion_vols
  ```

* **Sur Windows (CMD ou PowerShell) :**
  ```cmd
  gestion_vols.exe
  ```

---

## Utilisation rapide

Au lancement, le programme affiche le menu principal dans la console. Saisissez le numéro correspondant à l'action souhaitée et validez avec la touche **Entrée**. Pour fermer l'application à tout moment depuis le menu principal, saisissez **`0`** (*Quitter le programme*).
