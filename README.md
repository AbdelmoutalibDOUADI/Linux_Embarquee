# Linux Embarqué — ESIX Normandie (MeSE)

Travaux pratiques du module **Linux Embarqué** de 5ᵉ année Mécatronique et Systèmes
Embarqués (MeSE), ESIX Normandie — Université de Caen Normandie.

**Auteur :** Abdelmoutalib DOUADI
**Encadrant :** Léo Magadoux
**Carte cible :** BeagleBone Black (processeur ARM Cortex-A8, AM335x)
**Toolchain :** cross-compilateur Linaro `arm-linux-gnueabihf` (GCC 12.2.1)

---

## Arborescence

```
.
├── TP/
│   ├── TP1/                     # Environnement de développement
│   │   ├── jeux/                # Projet C « jeu du plus/moins »
│   │   ├── reverse/             # Binaires de rétro-ingénierie (partie 4)
│   │   └── screenTP1/           # Captures d'écran
│   └── TP2/                     # Création de sa propre distribution
│       ├── configs/            # Configs noyau et BusyBox (kernel.config, busybox.config)
│       └── myrootfs/etc/       # Fichiers de configuration du rootfs
├── autre/                       # Sauvegardes diverses (U-Boot…)
└── .gitignore
```

> **Remarque :** les sources volumineuses (noyau Linux, BusyBox, toolchain Linaro) et
> les binaires générés ne sont **pas** versionnés (voir `.gitignore`). Seuls le code,
> les fichiers de configuration et les comptes rendus le sont. Les `.config` suffisent
> à reproduire la compilation.

---

## TP1 — Mise en place de l'environnement de développement

Chaîne de développement complète autour du projet C « jeu du plus/moins ».

- **Compilation & automatisation :** compilation manuelle (dynamique / statique),
  puis automatisée avec un **Makefile** (cibles `dynamic`, `static`, `debug`,
  `all`, `clean`).
- **Débogage :** inspection et modification de l'exécution avec **GDB** (points
  d'arrêt, lecture/écriture de variables).
- **Analyse mémoire :** **Valgrind** — détection et correction d'une variable non
  initialisée et d'une fuite mémoire.
- **Compilation croisée :** génération d'exécutables **ARM** avec la toolchain
  Linaro, puis validation sur la **BeagleBone Black**.
- **Rétro-ingénierie :** extraction de mots de passe cachés dans des binaires à
  l'aide de `file`, `strings`, `objdump`, GDB et **Ghidra** (scénarios : chaîne en
  clair, construction octet par octet en x86 et ARM, offuscation).

---

## TP2 — Création de sa propre distribution

Construction d'un mini-système Linux complet pour la BeagleBone Black.

**Parties 1 à 3 réalisées :**

- **Cross-compilateur :** mise en place du PATH et des variables `ARCH=arm` et
  `CROSS_COMPILE=arm-linux-gnueabihf-`.
- **Noyau Linux 5.4 :** configuration `bb.org_defconfig` (BeagleBoard.org), support
  TCP/IPv4 (`CONFIG_INET`), compilation de la **zImage** et des **device trees**
  (`am335x-boneblack.dtb`), compilation et installation des **modules** dans le rootfs.
- **Rootfs (BusyBox 1.36) :** un binaire unique fournissant toutes les commandes via
  des liens symboliques ; ajout de la **glibc ARM**, des répertoires système
  (`dev`, `etc`, `proc`, `sys`, `boot`) et des fichiers de configuration
  (`passwd`, `shadow`, `fstab`, `init.d/rcS`).

**Partie 4 (installation sur carte SD et test) :** à réaliser en séance.

**Fichiers versionnés :**
- `configs/kernel.config` — configuration du noyau
- `configs/busybox.config` — configuration de BusyBox
- `myrootfs/etc/` — fichiers de configuration du système (`passwd`, `shadow`,
  `fstab`, `init.d/rcS`)

### Reproduire la compilation (TP2)

```bash
# Variables d'environnement
export ARCH=arm
export CROSS_COMPILE=arm-linux-gnueabihf-

# Noyau (depuis les sources linux-5.4)
cp <repo>/TP/TP2/configs/kernel.config .config
make -j$(nproc) zImage dtbs modules
make modules_install INSTALL_MOD_PATH=<rootfs>

# BusyBox (depuis les sources busybox-1.36)
cp <repo>/TP/TP2/configs/busybox.config .config
make -j$(nproc)
make CONFIG_PREFIX=<rootfs> install
```

---

## Prérequis (machine de développement)

```bash
sudo apt install build-essential gdb valgrind binutils \
                 flex bison libssl-dev libncurses-dev bc lzop
```
Plus le cross-compilateur **Linaro `arm-linux-gnueabihf`**.
