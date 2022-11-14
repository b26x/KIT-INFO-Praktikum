#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//set to true to show additional debug informations
const bool showDebug = false;

const int x_resolution = 512;
const int y_resolution = 512;
//Bearbeiten um entsprechende 
string dataFilePath = "C:\\Code\\Hauptflamme.txt";

double input_data[x_resolution][y_resolution];


void importFromFile(string filePath){
    string curInputVal;

    // Datei einlesen
    ifstream readMyFile(filePath);
    // Teste, ob die Datei öffnebar ist.
    if (readMyFile.is_open()){
        if (showDebug) cout<<"Starting import from file."<<endl;
        //Index des aktuell eingelesen Wertefeldes
        int input_index=0;
        //Liest die Datei Block fuer Block ein
        while (getline(readMyFile, curInputVal,' ')) {
            if(!curInputVal.empty()){
                if (showDebug) cout << input_index<<" : "<<stod(curInputVal)<<endl;
                input_index++;
                input_data[ input_index % x_resolution ][ input_index / x_resolution ]=stod(curInputVal);
            }

        }
        cout<<"Finished importing values from file.";
    }
    // Datei wird geschlossen
    readMyFile.close();
}

int main () {
    importFromFile(dataFilePath);
    return 0;
}
