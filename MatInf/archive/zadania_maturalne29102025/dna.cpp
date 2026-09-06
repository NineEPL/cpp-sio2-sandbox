#include<iostream>
#include<vector>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string dna;
    cin >> dna;
    int countA = 0, countC = 0, countG = 0, countT = 0;

    for (char nucleotide : dna) {
        if (nucleotide == 'A') countA++;
        else if (nucleotide == 'C') countC++;
        else if (nucleotide == 'G') countG++;
        else if (nucleotide == 'T') countT++;
    }

    int maxCount =  countA;
    char maxNucleotide = 'A';
    if (countC > maxCount) {
        maxCount = countC;
        maxNucleotide = 'C';
    }
    if (countG > maxCount) {
        maxCount = countG;
        maxNucleotide = 'G';
    }
    if (countT > maxCount) {
        maxCount = countT;
        maxNucleotide = 'T';
    }

    //cout << maxCount << "\n";
    cout << maxNucleotide << "\n";

    return 0;
}
