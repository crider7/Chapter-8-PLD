// Pseudocode PLD Chapter 8 #7a pg. 366
// Start
// Declarations
// num MAXADS = 100
// num adcatcode[MAXADS]
// num adwords[MAXADS]
// num curCode
// num numads
// num i
// num j
// num k
// num subtotal
// num temp
// output "Please enter the number of ads: "
// input numads
// if ((numads > 0) and (numads <= MAXADS))
// for i = 0 to numads - 1
// output "Please enter Advertisement Category Code (1 - 15): "
// input adcatcode[i]
// output "Please enter number of words for the advertisement: "
// input adwords[i]
// endfor
// for i = 0 to numads - 2
// for j = 0 to numads - 2
// if (adcatcode[j] > adcatcode[j+1])
// temp = adcatcode[j]
// adcatcode[j] = adcatcode[j+1]
// adcatcode[j+1] = temp
// temp = adwords[j]
// adwords[j] = adwords[j+1]
// adwords[j+1] = temp
// endif
// endfor
// endfor
// output "Total Word Counts Sorted By Category Code"
// output "========================================="
// k = 0
// while k <= numads - 1
// subtotal = 0
// curCode = adcatcode[k]
// while ( (curCode == adcatcode[k]) and (k <= numads - 1) )
// subtotal = subtotal + adwords[k]
// k = k + 1
// endwhile
// output "Category: ",adcatcode[k - 1], " ","Word Count: ",
//subtotal
// endwhile
// else
// output "Number adds requested less than 1 or is too large; ad
//limit is ", MAXADS
// endif
// Stop


#include <iostream>

using namespace std;

int main() {
    const int MAXADS = 100;
    int adcatcode[MAXADS];
    int adwords[MAXADS];
    int curCode;
    int numads;
    int i, j, k;
    int subtotal;
    int temp;

    cout << "Please enter the number of ads: ";
    cin >> numads;

    if (numads > 0 && numads <= MAXADS) {
        for (i = 0; i < numads; ++i) {
            cout << "Please enter Advertisement Category Code (1 - 15): ";
            cin >> adcatcode[i];
            cout << "Please enter number of words for the advertisement: ";
            cin >> adwords[i];
        }
        for (i = 0; i < numads - 1; ++i) {
            for (j = 0; j < numads - 1; ++j) {
                if (adcatcode[j] > adcatcode[j + 1]) {
                    temp = adcatcode[j];
                    adcatcode[j] = adcatcode[j + 1];
                    adcatcode[j + 1] = temp;
                    temp = adwords[j];
                    adwords[j] = adwords[j + 1];
                    adwords[j + 1] = temp;
                }
            }
        }

        cout << "Total Word Counts Sorted By Category Code" << endl;
        cout << "=========================================" << endl;
        k = 0;
        while (k <= numads - 1) {
            subtotal = 0;
            curCode = adcatcode[k];
            while ((curCode == adcatcode[k]) && (k <= numads - 1)) {
                subtotal += adwords[k];
                k++;
            }
            cout << "Category: " << adcatcode[k - 1] << " " << "Word Count: " << subtotal << endl;
        }
    } else {
        cout << "Number adds requested less than 1 or is too large; ad limit is " << MAXADS << endl;
    }
    return 0;
}
