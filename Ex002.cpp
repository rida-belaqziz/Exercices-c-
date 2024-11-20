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



//Réverser une chaîne
void reverser(string &mot){
    stack<char> sch;
    for (char ch : mot) {
        sch.push(ch);
    }
    int i = 0;
    while (!sch.empty()) {
        mot[i++] = sch.top();
        sch.pop();
    }
}



//fonction pour vérifier une expression parenthésée
bool parenthese(const string &mot) {
    stack<char> sch;

    for (char ch : mot) {
        if (ch == '(') {
            sch.push(ch);
        } else if (ch == ')') {
            if (!sch.empty() && sch.top() == '(') {  
                sch.pop();
            } else {
                return false;
            }
        }
    }
    return sch.empty();
}

int main(){
    //ex1
    stack<int> s1;
    for(int i = 0 ; i<5 ; i++){s1.push(i+1);}
    //pop
    while(!s1.empty()){s1.pop();}
    //vide ou pas
    cout<<"la pile s1 est : "<< (s1.empty()? "vide": "non vide")<<  endl;

    //ex2
    string mot1 = "(a + b)";
    string mot2 = "(a + b))";
    cout<<parenthese(mot1)<<endl;
    cout<<parenthese(mot2)<<endl;

    //ex3
    string mot3 = "stack";
    reverser(mot3);
    cout<<"reverser :"<<mot3<<endl;
    
    return 0;
}












