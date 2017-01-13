//BUT: Créer et afficher un carré magique, carré ou la somme de chaque ligne, chaque colonne et chaque diagonale est égale. La dimension du carré peut être modifiée en modifiant une constante.
//ENTREE: L'utilisateur n'entre rien, mais vous pouvez modifier la constante TAILLE_TABLEAU
//SORTIE: On affiche le carré magique


#include <stdio.h>
#include <stdlib.h>

#define TAILLE_TABLEAU 7
//on définit la constante qui représente la taille du tableau.


typedef struct Point Point; // Point sera désormais équivalent à écrire struct Point
struct Point
{
    int x;
    int y;
}; //On crée la structure "Point" avec deux valeurs entières: x et y






void init(int carre[TAILLE_TABLEAU][TAILLE_TABLEAU]);
void afficher(int carre[TAILLE_TABLEAU][TAILLE_TABLEAU]);

int main()
{
    int carre[TAILLE_TABLEAU][TAILLE_TABLEAU]; //On crée un tableau de dimesion TAILLE_TABLEAU, soit de la constante défini en début de programme

    init(carre); //On appelle la procédure init qui remplie le tableau.

    avancer(carre); //On appelle la procédure avancer qui s'occupe d'avancer dans le tableau, de faire les tests et de "déposer" la valeur de nbr

   afficher(carre); //On appelle la procédure qui s'occupe d'afficher le tableau.


return 0;

}

void init(int carre[TAILLE_TABLEAU][TAILLE_TABLEAU]){
//BUT: Initialiser le tableau et remplir chaque cellule avec un 0, indiquant une case "vide"
//ENTREE: On fournit le tableau représentant le carré
//SORTIE: Tableau rempli de 0.
    int i=0;
    int j=0;

    for(i=0;i<TAILLE_TABLEAU;i++){
        for(j=0;j<TAILLE_TABLEAU;j++){
            carre[i][j]=0;
//on remplit chaque cellule de 0
        }

    }


}


void afficher(int carre[TAILLE_TABLEAU][TAILLE_TABLEAU]){
//BUT: Afficher le carré magique à la fin du prgramme
//ENTREE: On fournit le tableau représentant le carré rempli correctement
//SORTIE: On affiche probablement chaque cellule du tableau
int i,j;
for(i=0;i<TAILLE_TABLEAU;i++){
for(j=0;j<TAILLE_TABLEAU;j++){

printf("%d ",carre[i][j]);

//on affiche chaque cellule du tableau
}
printf("\n"); //quand une ligne est rempli, on revient à la ligne.

}
}


void avancer(int carre[TAILLE_TABLEAU][TAILLE_TABLEAU]){
//BUT: Remplir correctement le tableau du carré magique
//ENTREE: On fournit le tableau  rempli correctement ainsi que sa dimension
//SORTIE: Le tableau représentant le carré magique est rempli correctement, c'est enfin un carré magique.
    Point position; //on crée un point que l'on nomme "position". Il servira à parcourir le carré magique dans les procédures.
position.x=((TAILLE_TABLEAU/2)-1); //On se place sur la première celle au nord du milieu.
position.y=(TAILLE_TABLEAU/2);
int i,j,k,nbr;
nbr=1;
carre[position.x][position.y]=nbr; //On lui associe la valeur "1".
for(k=0;k<(TAILLE_TABLEAU*TAILLE_TABLEAU)-1;k++){
//Cette boucle recommence autant de fois qu'il faut "placer" un nombre dans le carré, ce qui correspond à la (dimension du tableau)²

    nbr++;
    position.x--;
    position.y++;

//On ajoute 1 au nombre et on avance vers le nord est du tableau.
    if (position.x<0){
            position.x=TAILLE_TABLEAU-1;


    }
//Si l'on dépasse le tableau par le haut, on se retrouve en bas de nouveau.

    if (position.y>TAILLE_TABLEAU-1){
            position.y=0;



    }
//si l'on dépasse le tableau par la droite, on se retrouve à gauche.


    if (carre[position.x][position.y]==0){
    carre[position.x][position.y]=nbr;
//Si la case est valide, c'est à dire si un 0 si trouve, on y place le nombre.
    }
    else{
        do {
        position.x--;
        position.y--;

//sinon, si la case n'est pas valide, alors on se déplace vers le nord ouest jusq'à ce que l'on trouve une case valide (d'ou le do while)
         if (position.x<0){
            position.x=TAILLE_TABLEAU-1;
//Si l'on dépasse par le haut on revient en bas

    }


     else if (position.y<0){
            position.y=TAILLE_TABLEAU-1;

//Si l'on dépasse par la gauche, on revient à droite.

    }

        }while(carre[position.x][position.y]!=0);
    }






carre[position.x][position.y]=nbr;


//On remplit la case une fois que l'on s'est assurés qu'elle est valide.



}






}











