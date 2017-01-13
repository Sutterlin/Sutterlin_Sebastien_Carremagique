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
int i,j,k,nbr,trouve;


nbr=1; //Il s'agit de la variable qui se mettra dans le tableau. Elle commence à 1 et augmentera par la suite de 1 jusqu'à taille_tableau*2
trouve=0; //Sert de booléen. On vérifiera que la case suivante est valide, si oui, trouvé passe à 1.
Point position; //on crée un point que l'on nomme "position". Il servira à parcourir le carré magique dans les procédures.

carre[TAILLE_TABLEAU][TAILLE_TABLEAU]; //On crée un tableau de dimesion TAILLE_TABLEAU, soit de la constante défini en début de programme

int main()
{
init(); //On appelle la procédure init qui remplie le tableau.

avancer(); //On appelle la procédure avancer qui s'occupe d'avancer dans le tableau, de faire les tests et de "déposer" la valeur de nbr

afficher(); //On appelle la procédure qui s'occupe d'afficher le tableau.



}

void init(){

for(i=0;i<TAILLE_TABLEAU;i++){
for(j=0;j<TAILLE_TABLEAU;j++){
carre[i][j]=0;
//On initialise le tableau. On le parcourt entièrement et on rempli chaque cellule par un 0.

}

}



}


void afficher(){

for(i=0;i<TAILLE_TABLEAU;i++){
for(j=0;j<TAILLE_TABLEAU;j++){
if (j!=TAILLE_TABLEAU-1){
        printf("%d  ",carre[i][j]);
}
else {
 printf("%d\n",carre[i][j]); //on affiche les cellules en parcourant grâce aux boucles. Afin de garantir une affichage correct, à chaque fois qu'on affiche le nombre de cellules égal à la constante, on revient à la ligne. On test donc à chaque fois si la place en y n'est pas égale à la dimension-1. Si c'est le cas, on va à la ligne.
}


}

}
}


void avancer(){
position.x=((TAILLE_TABLEAU/2)-1); //On se place sur la première celle au nord du milieu.
position.y=(TAILLE_TABLEAU/2);

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











