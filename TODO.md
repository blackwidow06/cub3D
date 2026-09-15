# Cub3D TODO

## Parsing
- [ ] Valider map fermée
- [ ] Gérer erreurs

## Player
- [ ] Trouver position initiale
- [ ] Définir direction
- [ ] Déplacement avant/arrière
- [ ] Rotation gauche/droite
- [ ] Collision

## Raycasting
- [ ] Camera plane
- [ ] Ray direction
- [ ] DDA
- [ ] Distance perpendiculaire
- [ ] Hauteur des murs

## Rendering
- [ ] Initialiser MLX -> marco
- [ ] Créer image
- [ ] Dessiner pixels
- [ ] Textures
- [ ] Floor / ceiling

## Tests
- [ ] Map invalide
- [ ] Map ouverte
- [ ] Textures manquantes
- [ ] Mauvaises couleurs
- [ ] Déplacements contre murs
- [ ] Segfaults / leaks

raycasting()
│
├── Pour chaque colonne x
│   │
│   ├── init_ray()
│   │     └── Où part le rayon ?
│   │
│   ├── init_dda()
│   │     └── Quelle frontière est proche ?
│   │
│   ├── cast_single_ray()
│   │     └── Quel mur est touché ?
│   │
│   ├── calculate_wall()
│   │     └── Quelle hauteur à l'écran ?
│   │
│   └── draw_column()
│         └── Quels pixels dessiner ?
│
└── Fin