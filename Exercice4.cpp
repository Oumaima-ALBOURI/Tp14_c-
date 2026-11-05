
#include <iostream>
#include <exception>
using namespace std;

// 1. Exception : montant invalide
class MontantInvalideException : public exception {
public:
    const char* what() const noexcept override {
        return "Erreur : Le montant doit etre positif !";
    }
};

// 2. Exception : solde insuffisant
class SoldeInsuffisantException : public exception {
public:
    const char* what() const noexcept override {
        return "Erreur : Solde insuffisant !";
    }
};

// 3. Classe Compte
class Compte {
private:
    int solde;

public:
    // Constructeur
    Compte(int s) {
        solde = s;
    }

    // Methode deposer
    void deposer(int montant) {

        if (montant <= 0) {
            throw MontantInvalideException();
        }

        solde += montant;

        cout << "Depot reussi : " << montant << " DH" << endl;
        cout << "Nouveau solde : " << solde << " DH" << endl;
    }

    // Methode retirer
    void retirer(int montant) {

        if (montant <= 0) {
            throw MontantInvalideException();
        }

        if (montant > solde) {
            throw SoldeInsuffisantException();
        }

        solde -= montant;

        cout << "Retrait reussi : " << montant << " DH" << endl;
        cout << "Nouveau solde : " << solde << " DH" << endl;
    }
};

// 4. Fonction principale
int main() {

    Compte c(1000);

    // Premier bloc try-catch
    try {
        cout << "--- Depot ---" << endl;
        c.deposer(500);

        cout << "\n--- Depot invalide ---" << endl;
        c.deposer(-200);
    }
    catch (const MontantInvalideException& e) {
        cout << e.what() << endl;
    }

    // Deuxieme bloc try-catch
    try {
        cout << "\n--- Retrait ---" << endl;
        c.retirer(300);

        cout << "\n--- Retrait excessif ---" << endl;
        c.retirer(2000);
    }
    catch (const MontantInvalideException& e) {
        cout << e.what() << endl;
    }
    catch (const SoldeInsuffisantException& e) {
        cout << e.what() << endl;
    }

    cout << "\nFin du programme." << endl;

    return 0;
}

