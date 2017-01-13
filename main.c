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
int i,j,k,nbr,trouve;


nbr=1; //Il s'agit de la variable qui se mettra dans le tableau. Elle commence � 1 et augmentera par la suite de 1 jusqu'� taille_tableau*2
trouve=0; //Sert de bool�en. On v�rifiera que la case suivante est valide, si oui, trouv� passe � 1.
Point position; //on cr�e un point que l'on nomme "position". Il servira � parcourir le carr� magique dans les proc�dures.

carre[TAILLE_TABLEAU][TAILLE_TABLEAU]; //On cr�e un tableau de dimesion TAILLE_TABLEAU, soit de la constante d�fini en d�but de programme

int main()
{
init(); //On appelle la proc�dure init qui remplie le tableau.

avancer(); //On appelle la proc�dure avancer qui s'occupe d'avancer dans le tableau, de faire les tests et de "d�poser" la valeur de nbr

afficher(); //On appelle la proc�dure qui s'occupe d'afficher le tableau.



}

void init(){

for(i=0;i<TAILLE_TABLEAU;i++){
for(j=0;j<TAILLE_TABLEAU;j++){
carre[i][j]=0;
//On initialise le tableau. On le parcourt enti�rement et on rempli chaque cellule par un 0.

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
 printf("%d\n",carre[i][j]); //on affiche les cellules en parcourant gr�ce aux boucles. Afin de garantir une affichage correct, � chaque fois qu'on affiche le nombre de cellules �gal � la constante, on revient � la ligne. On test donc � chaque fois si la place en y n'est pas �gale � la dimension-1. Si c'est le cas, on va � la ligne.
}


}

}
}


void avancer(){
position.x=((TAILLE_TABLEAU/2)-1); //On se place sur la premi�re celle au nord du milieu.
position.y=(TAILLE_TABLEAU/2);

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











