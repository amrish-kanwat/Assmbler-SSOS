#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<map>
using namespace std;
int main(){
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
  
  map<string,int>table;
   
    fstream file;
    int loc = 0;
    file.open("a4.txt",ios::in);
        string s = "";
     if(file.is_open()){ 
        while(getline(file,s)){  // taking one line
        stringstream word(s);//words from line
        string s1;
        vector<string>v;
        while(word >> s1){ // extract words
          v.push_back(s1);
        }
        int size=v.size();
        if(v[size-2]=="START"){
          loc=stoi(v[size-1]);
          table["START"]=loc;
        // cout<<"START"<<" ";
        }else if(v[size-2]=="END"){
            continue;
        }else if(v[size-2]=="BYTE"){
            // opcode[]
            table[v[size-3]]=loc;
            // cout<<v[size-3]<<" "<<loc<<endl;
            loc+=1;
            
        }else if(v[size-2]=="RESB"){
            table[v[size-3]]=loc;
            // cout<<v[size-3]<<" "<<loc<<endl;
            loc+=stoi(v[size-1]);
        }
        else{
            table[v[size-1]]=loc;
            //   cout<<v[size-1]<<" "<<loc<<endl;
            loc+=3;
        }
        // cout<<loc<<endl;
        } 
        // for(auto x:table){
        //     cout<<x.first<<"  "<<x.second<<endl;
        // }
        // file.close(); 
        
        
     }
     
  fstream file1;
    // int loc = 0;
    file1.open("a4.txt",ios::in);
        string sp = "";
     if(file1.is_open()){ 
        while(getline(file1,sp)){  // taking one line
        stringstream word(sp);//words from line
        string s1;
        vector<string>v;
        while(word >> s1){ // extract words
          v.push_back(s1);
        }
        int size=v.size();
        if(v[size-2]!="START"&&v[size-2]!="END"&&v[size-2]!="BYTE"&&v[size-2]!="RESB"){
            string m=opcode[v[size-2]]+to_string(table[v[size-1]]);
       // string n=table[]
        cout<<m<<endl;
       
        }
    
        file.close(); 
        
        
     }}
     return 0;
}