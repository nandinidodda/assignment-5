#include <iostream>
#include <vector>
#include <string>
using namespace std;

// function
string lcs(string b1, string b2)
{
    // storing strings' length
    int len_b1=b1.length(); 
    int len_b2=b2.length();

    
    vector<vector<int>> nad(len_b1 + 1, vector<int>(len_b2 + 1, 0));

    // Tracking common substring's maximum length 
    int len_max=0;
    // Tracking it's end index
    int lastIndex=0;

    // Fill DP Table
    for (int g = 1; g <= len_b1; g++) {
        for (int h = 1; h <= len_b2; h++) {
            // Check matching character
            if (b1[g - 1] == b2[h - 1]) {
                nad[g][h] = nad[g - 1][h - 1] + 1;
                if (nad[g][h] > len_max) {
                    // update maximum length
                    len_max = nad[g][h];
                    // Update the end index
                    lastIndex = g - 1;
                }
            }
        }
    }

    // 2D grid
    cout << "\nDynamic Programming Table:\n";
    for (int x = 0; x <= len_b1; x++) {
        for (int c = 0; c <= len_b2; c++) {
            // prints table values
            cout << nad[x][c] << " ";
        }
        cout << endl;
    }
    
    return b1.substr(lastIndex - len_max + 1, len_max);
}

int main() {
    string l1, l2;

    // for user given inputs
    cout << "Enter content of first string: ";
    cin >> l1;
    cout << "Enter content of second string: ";
    cin >> l2;
    
    // executing lcs()
    string result = lcs(l1, l2);

    // shows final result
    cout << "Longest Common Substring: " << result << endl;
    
    return 0;
}