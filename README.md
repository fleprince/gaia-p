gaia
====

Générateur de planète
Le but de ce projet est de générer des "Terres" virtuelles en partant de zéro : un isocaèdre régulier divisé petit à petit pour obtenir une sphère composée de miliers de triangles. Puis regrouper ces triangles en plaques pour appliquer des forces tectoniques et créer du relief. Puis appliquer l'apparition de l'eau, l'érosion, des climats différents en fonction des latitudes et de la géographie. Le tout en continuant d'exercer la dérive des continents, la disparition de certains, la création d'autres, etc.
Le tout sous OpenGL & SDL en C++.

Statut
======

Actuellement la sphère se découpe à partir d'un isocaèdre régulier (cf. http://fr.wikipedia.org/wiki/Icosa%C3%A8dre).

Todo
====

* Définir un dispositif de pointage avec ray tracing/isobarycentre des triangles
* Annuler l'activité CPU sans mouvement de caméra
* Améliorer la découpe en plaques tectoniques
* Appliquer la structure usuelle dans le main pour OpenGL
* Activer l'anti-aliasing
* Améliorer les déplacements de la caméra
