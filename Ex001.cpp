/* 
===================================================================================================
1. Exercice sur les Vectors
**Exercice 1 : Ajouter et parcourir un vector
Déclarez un std::vector<int>.
Ajoutez les nombres de 1 à 10 dans le vector.
Parcourez le vector et affichez chaque élément.
**Exercice 2 : Rechercher un élément
Demandez à l'utilisateur d'entrer un nombre.
Recherchez ce nombre dans le vector.
Indiquez si le nombre a été trouvé ou non, ainsi que son index (s'il est trouvé).
**Exercice 3 : Opérations avancées
Écrivez un programme qui :
Supprime tous les nombres pairs du vector.
Insère le double des nombres impairs après chaque nombre impair.
**Exercice 4 : Tri et insertion
Écrivez un programme qui :
Trie un vector de manière ascendante.
Demande à l'utilisateur d'entrer un nouveau nombre.
Insère le nombre dans le vector trié à la bonne position (sans utiliser sort()).
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;


int main(){
    //ex1
    vector<int> monvect;
    //remplissage
    for (int i = 0 ; i<10; i++ ){monvect.push_back (i+1);}
    cout<< "------------------------- "<<endl;
    cout<< monvect[9]<<endl;
    monvect.pop_back();
    cout<< monvect.back()<<endl;
    cout<< "------------------------- "<<endl;
    cout<< "Affichage: "<<endl;
    cout<< "------------------------- "<<endl;
    //affichage
    for (int i = 0 ; i<10; i++ ){cout<< monvect[i]<<" ";}
    cout<<""<<endl;
    cout<< "------------------------- "<<endl;
    cout<< "Ex2: "<<endl;
    cout<< "------------------------- "<<endl;
    //ex2
    vector<int> v2 = {5,4,7,6,2,3,0};
    cout<< "------------------------- "<<endl;
    cout<< "Affichage: "<<endl;
    cout<< "------------------------- "<<endl;
    //affichage
    for (int i = 0 ; i<v2.size(); i++ ){cout<< v2[i] <<" "; }
    int z;
    cout<< " "<<endl;
    cout<< "Entrer un nombre svp: "<<endl;
    cin>>z;
    bool trouve = false;
    for(int a : v2){
        if(a==z)
        { 
            trouve = true;
            break;
        }
    }

        if(trouve){cout<<"Super ! le nombre "<<z<<" existe bien dans le vecteur ";}
        else{cout<<"le nombre "<<z<<" n'existe PAS dans le vecteur ";}
    cout<<""<<endl;
    //ex3
    vector<int> v3 = {5,5,4,7,7,6,2,3,3,8,8};
    cout<< "------------------------- "<<endl;
    cout<< "Affichage: "<<endl;
    cout<< "------------------------- "<<endl;
    vector<int> v3d;
    sort(v3.begin(),v3.end());
    v3.erase(unique(v3.begin(), v3.end()), v3.end());
    for( int v : v3){
        if(v%2==0){v3d.push_back(v);}
    }
    for(int v : v3d){cout<< v <<" ";}
    cout<<""<<endl;

    //Ex4
    vector<int> v4 = {1,5,4,7,6,2,3,8};
    cout<< "------------------------- "<<endl;
    cout<< "Affichage: "<<endl;
    cout<< "------------------------- "<<endl;
    for (int i = 0 ; i<v4.size(); i++ ){cout<< v4[i] <<" "; }
    cout<<"apres le tri !"<<endl;
    sort(v4.begin(), v4.end());
    for (int i = 0 ; i<v4.size(); i++ ){cout<< v4[i] <<" "; }
    cout<<" "<<endl;
    int e, e1;
    cout<<"entrer un nombre svp :"<<endl;
    cin>>e;
    v4.push_back(e);
    sort(v4.begin(), v4.end());
    v4.erase(unique(v4.begin(), v4.end()), v4.end());
    cout<< "------------------------- "<<endl;
    cout<< "Affichage: "<<endl;
    cout<< "------------------------- "<<endl;
    for (int i = 0 ; i<v4.size(); i++ ){cout<< v4[i] <<" "; }
    cout<<" "<<endl;
    //sans utiliser sort ?
    cout<<"entrer un autre nombre svp :"<<endl;
    cin>>e1;
    if(find(v4.begin(),v4.end(),e1) == v4.end() ){v4.push_back(e1);}
    cout<< "Affichage: "<<endl; 
    cout<< "------------------------- "<<endl;
    for (int i = 0 ; i<v4.size(); i++ ){cout<< v4[i] <<" "; }
    cout<<" "<<endl;



    return 0;
}












