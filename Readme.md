\# Project-X : Développement d'un jeu vidéo | Moteur Perso en C++

\-

\-

\-

\-

\-

\-

\---

\## Moteur Perso | Fonctionnement :



Un jeu peu être entièrement fait à partit de fichier \*\*JSON\*\*.  

Ils sont dans le chemin suivant : \*Project-X\\Project-X\\Data\*.  

Le 1er fichier contient la liste des scènes, il suffi de rajoute le nom du fichier de la scène qu'on veut rajouter.

&#x20; 

\*\*Exemple pour rajouter une scène :\*\*  

&#x20; 

\- Créé un fichier "NewScene.json" et mets le dans le dossier "Scène".  

\- Dans le fichier "Scène.json", ajoute la scène que tu viens de créer. Ça doit ressembler à ça : "Scène : \[NewScene,...]".  

\- Ensuite, tu créés ta scène en suivant ce modèle :  



```json

{

&#x20;   "ID" : 0,                                                                                  // ID de la scène, il ne doit pas en avoir 2 identiques.

&#x20;   "Layer" : 2,                                                                               // Nombre de layer de ta scène, pour gérer l'affichage



&#x20;   "Objects" : \[                                                                              // Liste des objets de ta scène

&#x20;       {

&#x20;           "LayerPosition" : 0,                                                               // Layer de l'objet

&#x20;           "Position" : \[0,0],                                                                // Position de l'objet

&#x20;           "Size" : \[50,50],                                                                  // Taille de l'objet

&#x20;           "Type" : {                                                                         // Type de l'objet (Pour le moment, uniquement les transitions sont dispo, sinon mets rien)

&#x20;               "TypeName" : "Transition",

&#x20;               "Transition" : \[ 1, "Click"]                                                   // \[ID de la scène que tu vises pour la transition, type de transition sur l'object (Que le click dispo pour l'instant)].

&#x20;           },

&#x20;           "ECS" : \[                                                                          // Liste des components de mon objet, tableau des components en dessous. 

&#x20;               {"Component" : "Render", "args" : \["Assets/Debug/Collider\_DebugTX.png"]},

&#x20;               {"Component" : "Mouse", "args" : \[]}

&#x20;           ]

&#x20;       }

&#x20;   ]

}

```

Le tableau suivant contient la liste des components disponibles, ainsi que les arguments nécessaire pour ce components.  



| Component |   Args   | 

|-----------|----------|

|  Render   | Chemin vers la textures |

|  Mouse   | Rien |

|  Input   | Rien |

|  Movement | Vitesse de déplacement |













