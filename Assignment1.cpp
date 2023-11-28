#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    ifstream fin("sample.txt");

    if (fin.is_open()) {
        string line;
        int wordcount = 0;

        while (getline(fin, line)) {
            int cnt = 0;
            stringstream ss(line);
            string word;
            vector<string> v;

            while (ss >> word) { // Changed ">" to ">>"
                wordcount++;
                cnt++;
                v.push_back(word);
            }
            cout << "No. of words = " << cnt << endl;
            for (int i = 0; i < v.size(); i++) {
                cout << v[i] << ' ';
            }
            cout << endl; // Added a line break after printing each line's words
        }

        fin.close(); // Moved this line outside the while loop
        cout << "Total number of words in file = " << wordcount << endl;
    } else {
        cout << "Failed to open file" << endl; // Fixed the typo in "open"
    }

    return 0;
}
