#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <algorithm> // for count
#include <cstddef> // for t_size
using namespace std;

bool is_logical(string dec) // checks if a string is logical
{
    for (int i=0;i<dec.size();i++)
        if(dec[i]<=31 || dec[i]>=126) return false; // check if chars are logical
    if(dec.find("to")==string::npos) return false; // check for common words
    if(dec.find("a")==string::npos) return false;
    if(dec.find("his")==string::npos) return false;
    if(dec.find("the")==string::npos) return false;
    if(dec.find(' ')==string::npos) return false;
    if(dec.find('.')==string::npos) return false;
    int c = count(dec.begin(),dec.end(),' ');
    if(c<dec.size()/7) return false;
    int sum = 0;
    for (int i=0;i<dec.size();i++) sum+=(int)dec[i];
    cout<<sum<<endl;
    return true;
}

int main()
{
    // getting the file into a vector of ints
    string line, dec;
    ifstream cypher("enc.txt");
    vector<int> cipher;
    if(cypher.is_open()) getline(cypher,line);
    cypher.close();
    int start = 0;
    int _end = line.find(',');
    while(start<line.size())
    {
        cipher.push_back(atoi((line.substr(start+1,_end-start-1).c_str())));
        start = _end;
        _end = line.find(',',_end+1);
    }
    char key[4];
    // --------------------------------------------------------
    for(int x = 'a';x<='z';x++)
        for(int y = 'a';y<='z';y++)
            for(int z = 'a';z<='z';z++)
    {
        dec = ""; // initializing dec
        key[0] = x; key[1] = y; key[2] = z; key[3] = '\0'; // generating key
        for(int i=0;i<cipher.size();i++)
           dec+= (char)(cipher.at(i)^(int)key[i%3]); // generalizing output
       is_logical(dec);
    }
    return 0;
}
