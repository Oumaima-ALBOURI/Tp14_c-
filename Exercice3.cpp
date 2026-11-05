
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// 1. Fonction de lecture du fichier
void lireFichier(string nomFichier) {

    ifstream fichier(nomFichier);

    // 2. Vérifier si le fichier est ouvert
    if (!fichier.is_open()) {

        // 3. Lever une exception
        throw runtime_error("Erreur : Impossible d'ouvrir le fichier !");
    }

    string ligne;

    // Lire le fichier ligne par ligne
    while (getline(fichier, ligne)) {
        cout << ligne << endl;
    }

    fichier.close();
}

// Fonction principale
int main() {

    try {

        lireFichier("test.txt");

    }
    catch (const exception& e) {

        cout << e.what() << endl;

    }

    cout << "Fin du programme." << endl;

    return 0;
}

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// 1. Fonction de lecture du fichier
void lireFichier(string nomFichier) {

    ifstream fichier(nomFichier);

    // 2. Vérifier si le fichier est ouvert
    if (!fichier.is_open()) {

        // 3. Lever une exception
        throw runtime_error("Erreur : Impossible d'ouvrir le fichier !");
    }

    string ligne;

    // Lire le fichier ligne par ligne
    while (getline(fichier, ligne)) {
        cout << ligne << endl;
    }

    fichier.close();
}

// Fonction principale
int main() {

    try {

        lireFichier("test.txt");

    }
    catch (const exception& e) {

        cout << e.what() << endl;

    }

    cout << "Fin du programme." << endl;

    return 0;
}
