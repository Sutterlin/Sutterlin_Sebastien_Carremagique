//BUT: Cr�er et afficher un carr� magique, carr� ou la somme de chaque ligne, chaque colonne et chaque diagonale est �gale. La dimension du carr� peut �tre modifi�e en modifiant une constante.
//ENTREE: L'utilisateur n'entre rien, mais vous pouvez modifier la constante TAILLE_TABLEAU
//SORTIE: On affiche le carr� magique


#include <stdio.h>
#include <stdlib.h>

#define TAILLE_TABLEAU 7
//on d�finit la constante qui repr�sente la taille du tableau.


typedef struct Point Point; // Point sera d�sormais �quivalent � �crire struct Point
struct Point
{
    int x;
    int y;
}; //On cr�e la structure "Point" avec deux valeurs enti�res: x et y






void init(int carre[TAILLE_TABLEAU][TAILLE_TABLEAU]);
void afficher(int carre[TAILLE_TABLEAU][TAILLE_TABLEAU]);

int main()
{
    int carre[TAILLE_TABLEAU][TAILLE_TABLEAU]; //On cr�e un tableau de dimesion TAILLE_TABLEAU, soit de la constante d�fini en d�but de programme

    init(carre); //On appelle la proc�dure init qui remplie le tableau.

    avancer(carre); //On appelle la proc�dure avancer qui s'occupe d'avancer dans le tableau, de faire les tests et de "d�poser" la valeur de nbr

   afficher(carre); //On appelle la proc�dure qui s'occupe d'afficher le tableau.


return 0;

}

void init(int carre[TAILLE_TABLEAU][TAILLE_TABLEAU]){
//BUT: Initialiser le tableau et remplir chaque cellule avec un 0, indiquant une case "vide"
//ENTREE: On fournit le tableau repr�sentant le carr�
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
//BUT: Afficher le carr� magique � la fin du prgramme
//ENTREE: On fournit le tableau repr�sentant le carr� rempli correctement
//SORTIE: On affiche probablement chaque cellule du tableau
int i,j;
for(i=0;i<TAILLE_TABLEAU;i++){
for(j=0;j<TAILLE_TABLEAU;j++){

printf("%d ",carre[i][j]);

//on affiche chaque cellule du tableau
}
printf("\n"); //quand une ligne est rempli, on revient � la ligne.

}
}


void avancer(int carre[TAILLE_TABLEAU][TAILLE_TABLEAU]){
//BUT: Remplir correctement le tableau du carr� magique
//ENTREE: On fournit le tableau  rempli correctement ainsi que sa dimension
//SORTIE: Le tableau repr�sentant le carr� magique est rempli correctement, c'est enfin un carr� magique.
    Point position; //on cr�e un point que l'on nomme "position". Il servira � parcourir le carr� magique dans les proc�dures.
position.x=((TAILLE_TABLEAU/2)-1); //On se place sur la premi�re celle au nord du milieu.
position.y=(TAILLE_TABLEAU/2);
int i,j,k,nbr;
nbr=1;
carre[position.x][position.y]=nbr; //On lui associe la valeur "1".
for(k=0;k<(TAILLE_TABLEAU*TAILLE_TABLEAU)-1;k++){
//Cette boucle recommence autant de fois qu'il faut "placer" un nombre dans le carr�, ce qui correspond � la (dimension du tableau)�

    nbr++;
    position.x--;
    position.y++;

//On ajoute 1 au nombre et on avance vers le nord est du tableau.
    if (position.x<0){
            position.x=TAILLE_TABLEAU-1;


    }
//Si l'on d�passe le tableau par le haut, on se retrouve en bas de nouveau.

    if (position.y>TAILLE_TABLEAU-1){
            position.y=0;



    }
//si l'on d�passe le tableau par la droite, on se retrouve � gauche.


    if (carre[position.x][position.y]==0){
    carre[position.x][position.y]=nbr;
//Si la case est valide, c'est � dire si un 0 si trouve, on y place le nombre.
    }
    else{
        do {
        position.x--;
        position.y--;

//sinon, si la case n'est pas valide, alors on se d�place vers le nord ouest jusq'� ce que l'on trouve une case valide (d'ou le do while)
         if (position.x<0){
            position.x=TAILLE_TABLEAU-1;
//Si l'on d�passe par le haut on revient en bas

    }


     else if (position.y<0){
            position.y=TAILLE_TABLEAU-1;

//Si l'on d�passe par la gauche, on revient � droite.

    }

        }while(carre[position.x][position.y]!=0);
    }






carre[position.x][position.y]=nbr;


//On remplit la case une fois que l'on s'est assur�s qu'elle est valide.



}






}











