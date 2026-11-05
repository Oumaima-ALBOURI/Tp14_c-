
#include <iostream>
#include <string>
#include <exception>
using namespace std;

// 1. Exception personnalisée
class StockInsuffisantException : public exception {
public:
    const char* what() const noexcept override {
        return "Erreur : Stock insuffisant !";
    }
};

// 2. Classe Produit
class Produit {
private:
    string nom;
    int stock;

public:
    // Constructeur
    Produit(string n, int s) {
        nom = n;
        stock = s;
    }

    // Méthode vendre
    void vendre(int quantite) {

        if (quantite > stock) {
            throw StockInsuffisantException();
        }

        stock = stock - quantite;

        cout << "Vente reussie : " << quantite
             << " unites." << endl;

        cout << "Stock restant : " << stock << endl;
    }
};

// 3. Fonction main
int main() {

    Produit p("Ordinateur", 10);

    try {
        cout << "Vente 1 :" << endl;
        p.vendre(3);

        cout << "\nVente 2 :" << endl;
        p.vendre(4);

        cout << "\nVente 3 :" << endl;
        p.vendre(5);

    }
    catch (StockInsuffisantException& e) {
        cout << "Erreur : " << e.what() << endl;
    }

    cout << "\nFin du programme." << endl;

    return 0;
}
