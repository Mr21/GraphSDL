Ce projet utilise la **SDL** avec les extensions **SDL_image** et **SDL_ttf** ainsi que ma surcouche **[SDLazy](https://github.com/Mr21/SDLazy)**.

À *Epitech*, de nombreuses fois nous avons dù représenter des courbes, des droites et autres machins pour plusieurs projets de maths.  
Du coup jme suis dis que faire un graphique générique pour toussa serait une bonne idée!  

Pour le moment ce qu'il y a de près dans le code c'est un **quadrillage dynamique** avec les unités affichées le long de l'ordonné et de l'abscisse ou alors le long de l'écran si nous sommes loin du point 0.  
Il est possible de zoomer à l'infini (en fonction des possibilités des `double`), **l'affichage des unités est intélligent**, au début c'est de 1 en 1, si l'on zoom ça ira de 0.5 en 0.5 et vice versa :)  

Il est possible d'afficher des lignes dans n'importe quel sens, en spécifiant des coordonnées mathématique (avec des `double`).
Du coup les droites changeront de taille et de position en fonction du zoom et de l'endroit où nous sommes.  

L'ensemble du projet est encore en cours de dév. du coup ce n'est pas encore très utilisable :S

Pour pouvoir utiliser le projet il faut avoir (sous *Linux*)  

    /usr/include/SDL/SDL.h
    /usr/include/SDL/(ainsi que tous les autres .h de la SDL)
    mais vérifiez aussi que vous avez bien :
    /usr/include/SDL/SDL_image.h
    /usr/include/SDL/SDL_ttf.h

    /usr/lib/libSDL.so
    /usr/lib/libSDL_image.so
    /usr/lib/libSDL_ttf.so
    mais peut etre aussi des raccourcis, notamment :
    /usr/lib/libSDL_ttf-2.0.so.0 -> libSDL_ttf.so

Merci <3  
