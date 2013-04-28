Ce projet utilise la **SDL** avec les extensions **SDL_image** et **SDL_ttf**.

À *Epitech*, de nombreuses fois nous avons dù représenter des courbes, des droites et autres machins pour plusieurs projets de maths.  
Du coup jme suis dis que faire un graphique générique pour toussa serait une bonne idée!  

Pour le moment ce qu'il y a de près dans le code c'est un quadrillage dynamique avec les unités affichées le long de l'ordonné et de l'abscisse ou alors le long de l'écran si nous sommes loin du point 0.  
Il est possible de zoomer à l'infini (en fonction des possibilités des `double`), les unités s'affichent de manière intélligentes, au début c'est de 1 en 1, si l'on zoom ça ira de 0.5 en 0.5 et vice versa :)  

Il est possible d'afficher des lignes dans n'importe quel sens, en spécifiant des coordonnées mathématique (avec des `double`).
Du coup les droites changeront de taille et de position en fonction du zoom et de l'endroit où nous sommes.  

L'ensemble du projet est encore en cours de dév. du coup ce n'est pas encore très utilisable :S

Merci <3  
