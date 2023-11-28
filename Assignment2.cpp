#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include<map>

using namespace std;
int main() {
  ifstream inputFile("assembly.txt");
  map<string, string> opcode;
   opcode["LDX"] = "04";
    opcode["LDA"] = "00";
    opcode["TD"] = "E0";
    opcode["JEQ"] = "30";
    opcode["RD"] = "D8";
    opcode["COMP"] = "28";
    opcode["STCH"] = "54";
    opcode["TIX"] = "2C";
    opcode["JLT"] = "38";
    opcode["RSUB"] = "4C";
    opcode["JLT"] = "38";
    opcode["JLT"] = "38";

  if (inputFile.is_open()) {
    string line;
    while (getline(inputFile, line)) {
    	int count=0;
      stringstream ss(line);
      string word;
      while (ss >> word) {
        count++;
        if(count==1){
        	if(opcode.find(word)!=opcode.end()){
        		cout<<opcode[word]<<" ";
			}
			else{
				cout<<word<<" ";
			}
		}
		else{
			cout<<word<<" ";
		}
      }
      cout<<endl;
    }
    inputFile.close();
  } else {
    cout << "Failed to open the file.";
  }
  return 0;
}