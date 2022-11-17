#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

const int x_resolution = 512;
const int y_resolution = 512;

//anlegen der Matrix
double input_data [x_resolution][y_resolution];
// Speicherort der Datei
string filePath = "C:\\Code\\Hauptflamme.txt";

void importFromFile (string filePath) {
    string curInputVal;
    
    // Datei einlesen
    ifstream Datei(filePath);

    //Prüfen ob Datei offen ist
    if (Datei.is_open ()) {
        cout << "Startet das einlesen der Datei." << endl;
        string curInputVal;
        int i = 0;
        int j = 0;
    // Speichern der Werte in einer 512 x 512 
        while (getline(Datei, curInputVal,' ')) {
            double number = atof(curInputVal.c_str());  // string in double convertieren
            // Die Funktion atof übergibt bei falscher belegung 0. Dies wird damit übersprungen
            if (number == 0) {                          // Die Funktion atof übergibt bei falscher belegung 0. Dies wird damit übersprungen 
                continue;
            }
            input_data [i][j] = number;
            if (j < 511) {
                j++;
            }
            else {
                i++;
                j = 0;
            }   
    }
}

        
    else {
        cout << "Fehler beim oeffnen der Datei" << endl;
    } 
    // Datei wird geschlossen
    Datei.close();
}


int main () {
    importFromFile(filePath);
    printf ("%f", input_data[511][511]);                // bei cout werden die Nachkommastellen gekürzt
    return 0;
}