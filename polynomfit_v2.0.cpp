#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

const int x_resolution =35;//512

//Gauß Eliminationsverfahren
vector<vector<long double>> swapRow(vector<vector<long double>> mtrx, int row1, int row2){
    for (int i = 0; i < mtrx[0].size(); i++){
        swap(mtrx[row1][i],mtrx[row2][i]);
    }
    return mtrx;  
   
}

vector<vector<long double>> subRowsByMulti(vector<vector<long double>> mtrx, int rowMinuent, int rowSubtra, int curColumn){
    if(mtrx[rowSubtra][curColumn]!=0&&mtrx[rowMinuent][curColumn]!=0){
        long double multi = mtrx[rowMinuent][curColumn]/mtrx[rowSubtra][curColumn];
        for (int i = 0; i < mtrx[0].size(); i++){
            mtrx[rowMinuent][i] -= mtrx[rowSubtra][i]*multi;
        }
    }
    return mtrx;   
}

vector<long double> returnResAsVector(vector<vector<long double>> mtrx){
    vector<long double> vec(mtrx.size());
    for (int i = 0; i < mtrx.size(); i++){
        vec[i] = mtrx[i][mtrx[0].size()-1];
    }
    
    return vec;
}

void printVector(vector<long double> vec){
    for (int j = 0; j < vec.size(); j++){
            cout<<vec[j]<<"\t";
    }
    cout<<endl;
}

void printMtrx(vector<vector<long double>> mtrx){
    //cout<<"\n-------\nResolution: "<<mtrx.size()<<" rows with "<< mtrx[0].size()<<" columns.\n-------\n";
    cout<<endl;
    for (int i = 0; i < mtrx.size(); i++){
        printVector(mtrx[i]);
    }
    
}

vector<vector<long double>> solveMtrx(vector<vector<long double>> mtrx){
    int rows = mtrx.size();
    int columns = mtrx[0].size();
    //sortiere Zeilen
    for (int i = 0; i < rows; i++){
        if(mtrx[i][i]==0&&i<rows-1){
            int j=i+1;
            while(mtrx[j][i]==0&&j<rows-1) j++;
            if(j>=rows) break;
            mtrx = swapRow(mtrx, i, j);
        }
        printMtrx(mtrx);
    }
    for (int i = 0; i < rows; i++){
        if (mtrx[i][i]!=0){
            long double normMulti = mtrx[i][i];
            for (int j = 0; j < columns; j++){
                if(mtrx[i][j]!=0) mtrx[i][j] /= normMulti;
            }
        }
        for (int j = i+1; j < rows; j++){
            mtrx = subRowsByMulti(mtrx, j, i, i);
        }
        printMtrx(mtrx);

    }
    for (int i = rows-1; i >= 0; i--){
        for (int j = i-1; j >= 0; j--){
            mtrx = subRowsByMulti(mtrx, j, i, i);
        }
        printMtrx(mtrx);
    }
    printMtrx(mtrx);
    return mtrx;
}

//ertsellen der Matrix für Polynomfitt
vector<vector<long double>> Polynomfitmtrx (int x_resolution, int n, vector<long double> y) {
    //setprecision(15);
    /*vector<long double> x;
    for (int i = 0; i < x_resolution; i++) {
        x.push_back (i+1);

    }
    */
    
    //anlegen eines vektors, der die Werte für sigma(xi),sigma(xi^2),sigma(xi^3)....sigma(xi^2n) speichert
    vector<long double> X(2*n+1);
    for (int i = 0; i < 2*n+1 ; i++) {
        X[i] = 0;
        for (int j = 1; j <=  y.size(); j++) {
            //X[i] += pow(x[j],i);
            X[i] += pow(j+1,i);
        }
    }
    printVector(X);
    //anlegen der Normalen Matrix, um die Werte abzuspeichern, bis auf die letzte Spalte
    vector<vector<long double>>B(n+1,vector<long double> (n+2));
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            B[i][j]= X[i+j];
        }     
    }
    //anlegen eines Vectors zum abspeichern der Werte für die letzte Spalte
    vector<long double> a(n+1);
    //anlegen eines vectors zum abspeichern ser Werte von sigma(yi),sigma(xi*yi),sigma(xi^2*yi)...sigma(xi^n*yi)
    vector<long double> Y(n+1);
    for (int i =0; i < n+1; i++) {
        Y[i] = 0;
        for (int j = 0; j < y.size(); j++)
        Y[i] = Y[i]+ pow(j+1,i)*y[j]; 
    }
    //abspeichern der Werte von Y in der letzten Spalte von B
    for (int i=0;i<=n;i++) {
        B[i][n+1]=Y[i];
    }
    return B;
}

int main () {
    int n;                        
    cout << "Geben sie den Grad des Polynoms an:" << endl;
    cin >> n;
    //vector<long double> y_werte = {8.75,7.36,5.73,3.92,1.99,0,-1.99,-3.92,-5.73,-7.36,-8.75};                  //muss nooch initialisiert werden
    vector<long double> y_werte = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35};  
    vector<vector<long double>> Polyresult = Polynomfitmtrx (x_resolution, n, y_werte);
    vector<long double> result = returnResAsVector(solveMtrx(Polyresult));
    cout<<endl;
    printVector(result);
    cout<<y_werte.size();
                
    return 0;
}