#include <cmath>
#include <iostream>
#include <vector>

using namespace std;


//tauscht Zeilen einer Matrix und gibt die bearbeitete Matrix zurück
vector<vector<long double>> swapRow(vector<vector<long double>> mtrx, int row1, int row2){
    for (int i = 0; i < mtrx[0].size(); i++){
        swap(mtrx[row1][i],mtrx[row2][i]);
    }
    return mtrx;  
   
}
//zieht das vielfache einer Zeile (Substrahenten-Zeile) von einer andern Zeile ab (Minueten-Zeile), 
//sodass 0 an einer definierten Stelle entsteht (Index der Stelle muss durch das letzte Argument angegeben werden)
vector<vector<long double>> subRowsByMulti(vector<vector<long double>> mtrx, int rowMinuent, int rowSubtra, int curColumn){
    long double multi = mtrx[rowMinuent][curColumn]/mtrx[rowSubtra][curColumn];
    for (int i = 0; i < mtrx[0].size(); i++){
        mtrx[rowMinuent][i] -= mtrx[rowSubtra][i]*multi;
    }
    return mtrx;    
}

//gibt die Matrix in 2dimenionaler Form im Terminal zurück
void printMtrx(vector<vector<long double>> mtrx){
    //cout<<"\n-------\nResolution: "<<mtrx.size()<<" rows with "<< mtrx[0].size()<<" columns.\n-------\n";
    cout<<endl;
    for (int i = 0; i < mtrx.size(); i++){
        for (int j = 0; j < mtrx[i].size(); j++){
            cout<<mtrx[i][j]<<"\t";
        }
        cout<<endl;
    }
    
}

//löst ein LGS in Form einer Matrix und gibt diese als Einheitsmatrix mit Lösungsspalte zurück
vector<vector<long double>> solveMtrx(vector<vector<long double>> mtrx){
    int rows = mtrx.size();
    int columns = mtrx[0].size();
    //sortiere Zeilen
    for (int i = 0; i < rows; i++){
        if(mtrx[i][i]==0){
            int j=i+1;
            while(mtrx[j][i]==0&&j<rows) j++;
            if(j>=rows) break;
            mtrx = swapRow(mtrx, i, j);
        }
        printMtrx(mtrx);
    }
    for (int i = 0; i < rows; i++){
        long double normMulti = mtrx[i][i];
        for (int j = 0; j < columns; j++){
            if(mtrx[i][j]!=0) mtrx[i][j] /= normMulti;
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
    }
    printMtrx(mtrx);
    return mtrx;
}

int main(){
    //test data: {{0,2,0,4},{1,1,2,6},{2,1,1,7}}
    
    vector< vector<long double> > mtrx(3, vector<long double>(4,0));
    mtrx={{0,2,0,4},{1,1,2,6},{2,1,1,7}};
    printMtrx(mtrx);
    solveMtrx(mtrx);

}
