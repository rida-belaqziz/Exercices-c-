/* 
===================================================================================================
3. Exercice sur les Listes
------------------------------------
*Exercice 1 : Manipulations de base
Déclarez un std::list<int>.
Ajoutez les nombres 10, 20, 30, 40, et 50.
Supprimez les éléments multiples de 20.
Affichez les éléments restants.
*Exercice 2 : Inverser une liste
Écrivez une fonction qui prend une std::list<int> et la renverse (vous pouvez utiliser std::list::reverse() ou l'implémenter manuellement).
*Exercice 3 : Fusionner deux listes
Écrivez un programme qui :
Déclare deux listes triées de manière ascendante.
Fusionne les deux listes dans une nouvelle liste triée.
*Exercice 4 : Créer une file d'attente circulaire
Implémentez une file d'attente circulaire en utilisant une std::list.
Les éléments qui sortent à l'avant sont ajoutés à l'arrière.
Exemple : {1, 2, 3} devient {2, 3, 1} après un tour.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <list>

using namespace std;


int main(){
    //Ex1
    list<int> liste1 = {10,20,30,40,50};
    // Supprimer multiples de 20
    for (auto it = liste1.begin(); it != liste1.end();) {
        if (*it % 20 == 0) {
            it = liste1.erase(it); 
        } else {
            ++it; 
        }
    }
    // Affichage
    cout << "supprimer multiples de 20 : ";
    for (int elt : liste1) {
        cout << elt << " ";
    }
    cout << endl;


    return 0;
}












