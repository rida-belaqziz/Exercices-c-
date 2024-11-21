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

//Ex2
void renverser(list<int> &liste){
    liste.reverse();
  
} 


//Ex4: Créer une file d'attente circulaire
    void FileAttenteCirculaire(list<int>& mylist) {
    if (!mylist.empty()) {
        // Retirer le premier élément
        int first = mylist.front();
        mylist.pop_front();

        // Ajouter cet élément à la fin
        mylist.push_back(first);
    }
}

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

    //Ex2
    list<int> liste2 = {10,20,30,40,50,60,70,80};
    // Affichage
    cout << "Afficher liste2 : ";
    for (int elt : liste2) {
        cout << elt << " ";
    }
    cout << endl;
    renverser(liste2);
    // Affichage
    cout << "Afficher liste2 apres renverser: ";
    for (int elt : liste2) {
        cout << elt << " ";
    }

    


cout<<""<<endl;
cout<<""<<endl;
    cout << ":::::::::::::::::EX3 "<<endl;
    //Fusionner deux listes
    list<int> l1 = {8,7,6,400,63,54,41,90,2,4,5,4,38,24,123,4,6};
    list<int> l2 = {0,2,1,83,7,6,5,64,5,3,335,23,12,50,5,4,3};

    //affichage liste
    for(auto it : l1){
        cout<<it<<" ";
    }
    cout<<endl;

    cout<<""<<endl;
    for(auto it : l2){
        cout<<it<<" ";
    }
    cout<<endl;

    cout<<""<<endl;

    //afficahge apres tri
    l1.sort();
    l2.sort();
    
    for(auto it : l1){
        cout<<it<<" ";
    }
    cout<<endl;

    cout<<""<<endl;
    for(auto it : l2){
        cout<<it<<" ";
    }
    cout<<endl;

    cout<<""<<endl;
    //Fusionner 
    //l1.splice(l1.end(), l2); //Fusionner deux listes sans les trier
    cout<<"Fusionner :"<<endl;
    l1.merge(l2);
    for(auto it : l1){
        cout<<it<<" ";
    }
    cout<<endl;

    cout<<""<<endl;


    //EX4
    list<int> mylist = {1, 2, 3};

    cout << "Avant : ";
    for (int x : mylist) {
        cout << x << " ";
    }
    cout << endl;

    // Effectuer un tour de file d'attente circulaire
    FileAttenteCirculaire(mylist);

    cout << "Après un tour : ";
    for (int x : mylist) {
        cout << x << " ";
    }
    cout << endl;


    return 0;
}












