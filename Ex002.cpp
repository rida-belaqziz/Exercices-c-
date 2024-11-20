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





//Évaluation d'expressions postfixées
// Fonction pour vérifier si une chaîne est un opérateur
bool isOperator(const string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

// Fonction pour évaluer une opération donnée deux opérandes
int evaluateOperation(int operand1, int operand2, const string& op) {
    if (op == "+") return operand1 + operand2;
    if (op == "-") return operand1 - operand2;
    if (op == "*") return operand1 * operand2;
    if (op == "/") {
        if (operand2 == 0) throw invalid_argument("Division par zéro !");
        return operand1 / operand2;
    }
    throw invalid_argument("Opérateur invalide !");
}

// Fonction pour évaluer une expression postfixée
int evaluatePostfix(const string& expression) {
    stack<int> sch;
    stringstream ss(expression);
    string token;

    // Parcourir les tokens de l'expression
    while (ss >> token) {
        if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1)) {
            // Si le token est un nombre, on le pousse dans la pile
            sch.push(stoi(token));
        } else if (isOperator(token)) {
            // Si le token est un opérateur
            if (sch.size() < 2) throw invalid_argument("Expression postfixée invalide !");
            
            int operand2 = sch.top(); sch.pop();
            int operand1 = sch.top(); sch.pop();

            // Effectuer l'opération et pousser le résultat
            int result = evaluateOperation(operand1, operand2, token);
            sch.push(result);
        } else {
            throw invalid_argument("Token invalide !");
        }
    }

    // Le résultat doit être le seul élément restant dans la pile
    if (sch.size() != 1) throw invalid_argument("Expression postfixée invalide !");
    return sch.top();
}






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

    //Ex4
    string expression = "5 1 2 + 4 * + 3 -";
    try {
        int result = evaluatePostfix(expression);
        cout << "Résultat : " << result << endl;
    } catch (const exception& e) {
        cerr << "Erreur : " << e.what() << endl;
    }
    
    return 0;
}












