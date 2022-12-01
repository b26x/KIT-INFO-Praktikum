#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<long double>> swapRow(vector<vector<long double>> mtrx, int row1, int row2){
    for (int i = 0; i < mtrx[0].size(); i++){
        swap(mtrx[row1][i],mtrx[row2][i]);
    }
    return mtrx;  
   
}

vector<vector<long double>> subRowsByMulti(vector<vector<long double>> mtrx, int rowMinuent, int rowSubtra, int curColumn){
    long double multi = mtrx[rowMinuent][curColumn]/mtrx[rowSubtra][curColumn];
    for (int i = 0; i < mtrx[0].size(); i++){
        mtrx[rowMinuent][i] -= mtrx[rowSubtra][i]*multi;
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
    cout<<"Die Ausgangsmatrix:";
    printMtrx(mtrx);
    cout<<"Und jetzt einmal Lösen :)";
    vector<long double> result = returnResAsVector(solveMtrx(mtrx));
    cout<<endl;
    printVector(result);
    
}
