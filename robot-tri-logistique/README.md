# Système de Tri Logistique (Bras Robotisé)

Ce projet implémente un système automatisé de tri logistique utilisant un bras robotisé. Il est conçu pour identifier, saisir et orienter des colis ou des pièces vers leurs zones de destination respectives en fonction de critères définis (taille, couleur, code-barres, etc.).

## 🚀 Fonctionnalités

*   **Détection automatique** : Identification des objets arrivant sur la zone de tri.
*   **Cinématique inverse** : Calcul des trajectoires du bras pour une saisie précise.
*   **Tri intelligent** : Routage des objets vers différentes stations de sortie.
*   **Mode Pick-and-Place** : Cycle optimisé de prise et dépose de pièces.

## 🛠️ Technologies & Matériel

*   **Langages** : Python / C++ (ROS2 recommandé pour la gestion des nœuds)
*   **Contrôle Robotique** : [Ex: Arduino, Raspberry Pi, ou contrôleur dédié]
*   **Actionneurs** : Servomoteurs / Moteurs pas-à-pas / Système d'aspiration ou pince
*   **Vision (Optionnel)** : OpenCV pour la reconnaissance d'objets via caméra

## 📁 Structure du Projet

```text
├── config/             # Fichiers de configuration (paramètres des moteurs, ports, etc.)
├── docs/               # Cahier des charges, schémas électroniques et plans de CAO
├── src/                # Code source du projet
│   ├── control/        # Algorithmes de trajectoire et cinématique
│   ├── hardware/       # Interface avec les moteurs et capteurs
│   └── main.py         # Point d'entrée principal de l'application
└── README.md           # Documentation principale
```

## ⚙️ Installation & Lancement

### Prérequis

Assurez-vous d'avoir installé les dépendances nécessaires (exemple pour l'environnement de contrôle) :

```bash
pip install -r requirements.txt
```

### Exécution du système

1. Connectez le bras robotisé à votre machine de contrôle.
2. Lancez le script principal pour initialiser les moteurs et démarrer la boucle de tri :

```bash
python src/main.py
```

## 📝 Licence

Ce projet est sous licence MIT. Voir le fichier `LICENSE` pour plus de détails.
