/* 
===================================================================================================
Exercice 1 : Implémentation basique

Déclarez un std::stack<int>.
Ajoutez les nombres de 1 à 5 dans la stack.
Affichez et retirez les éléments un par un jusqu'à ce que la stack soit vide.
Exercice 2 : Vérifier une expression parenthésée

Écrivez une fonction qui vérifie si une chaîne de caractères contenant des parenthèses est correctement équilibrée (ex. (a + b) est valide, mais (a + b)) ne l'est pas).
Utilisez un std::stack<char> pour résoudre cet exercice.
Exercice 3 : Réverser une chaîne

Écrivez une fonction qui prend une chaîne de caractères et utilise une stack pour inverser la chaîne.
Exemple : stack devient kcats.
Exercice 4 : Évaluation d'expressions postfixées

Écrivez un programme qui évalue une expression postfixée (notation polonaise inversée) en utilisant une stack.
Exemple : L'entrée "5 1 2 + 4 * + 3 -" renvoie 14.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//ajouter stack
#include <stack>

using namespace std;

//cout<< v2[i] <<" ";
int main(){
    //ex1
    stack<int> s1;
    for(int i = 0 ; i<5 ; i++){s1.push(i+1);}
    //pop
    while(!s1.empty()){s1.pop();}
    //vide ou pas
    cout<<"la pile s1 est : "<< (s1.empty()? "vide": "non vide")<<  endl;
    
    return 0;
}












