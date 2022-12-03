#include <iostream>
#include <cmath>
#include <vector>
using namespace::std;

 vector<long double> diffPolynom(vector<long double> polyArray){
    vector<long double> returnArray(polyArray.size()-1);
    for(int i = 0; i < polyArray.size(); i++){
        returnArray[i] = polyArray[i+1]*(i+1);
    }
    return returnArray;
}

long double calcPoynomAt(vector<long double> polyArray, long double x){ //{0, -4, 3}
    // Nimmt ein Array mit den Koeffiziente eines Polynoms bspw. {0, -4, 3} und den dazu passenden Polynomgrad bspw. 2 und x auf
    int polyDegree = polyArray.size()-1;
    long double output=0;
    for(int i=0; i < polyDegree+1; i++){
        output += pow(x, i)*polyArray[i];//multipliziert den im Array gespeicherten Koeffizienten mit der berechneten Potenz
    }
    return output;
}

long double numericIntegration(vector<long double> polyArray, double a, double b, int resolution){
    // Nimmt ein Array mit den Koeffiziente eines Polynoms bspw. {0, -4, 3} und den dazu passenden Polynomgrad bspw. 2 und sowie die Grenzen des Integrals wie die Auflösung auf   long double sum=0;
    int polyDegree = polyDegree;
    long double width= (b-a)/resolution;  //berechnet die intervallbereite in Abhängigkeit von der Auflösung
    long double sum=0; //Summe der Flächen unter der Funktion
    for(int k =1; k <= resolution; k++){
            sum += width*calcPoynomAt(polyArray, a+width*(k-0.5)); //Berechnet das aktuelle Rechteck und addiert diese auf die bisherige Gesamtsumme auf
    }
    return sum;
}

int main(){
    const int polyDegree=2;
    vector<long double> polyArray(3);
    polyArray[0]=0;
    polyArray[1]=-4;
    polyArray[2]=3;
    cout<<numericIntegration(polyArray,  0, 5, 1000);
    cout<<numericIntegration(diffPolynom(polyArray),  0, 5, 1000);
}