#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

int main() {
    map<string, string> opcode;
    opcode["LDX"] = "04";
    opcode["LDA"] = "00";
    opcode["TD"] = "E0";
    opcode["JEQ"] = "30";
    opcode["RD"] = "D8";
    opcode["COMP"] = "28";
    opcode["STCH"] = "54";
    opcode["TIX"] = "2C";
    opcode["RSUB"] = "4C";
    opcode["JLT"] = "38";

    map<string, int> table;

    fstream file;
    int count = 0;
    file.open("ans.txt", ios::in);
    string s = "";

    if (file.is_open()) {
        while (getline(file, s)) {
            stringstream word(s);
            string s1;
            vector<string> v;

            while (word >> s1) {
                v.push_back(s1);
            }

            int size = v.size();
            if (v[size - 2] == "START") {
                count = stoi(v[size - 1]);
                continue;
            }
            if (v[size - 2] == "END") {
                break;
            }
            if (v[size - 2] == "BYTE") {
                table[v[size - 3]] = count;
                count += 1;
            }
            else if (v[size - 2] == "RESB") {
                table[v[size - 3]] = count;
                count += stoi(v[size - 1]);
            } else if(v.size() == 3) {
                table[v[size - 3]] = count;
                count += 3;
            }
        }

        for (auto x : table) {
            cout << x.first << "  " << x.second << endl;
        }

        file.close();
    }

    return 0;
}
