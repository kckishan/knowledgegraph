#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <fstream>
#define SW 29
using namespace std;


vector<string> input;
vector< vector<string> > tokens;
string stopwords[SW] = { "the", "of", "in", "and", "a", "an", "to", "with", "is", "was",
                         "were", "by", "that", "for", "be", "from", "as", "are", "on", "or",
                         "this", "an", "not", "it", "which", "with", "too", "at", "these" };
set<string> words;
map< string, vector<int> > index;
string input1, input2;

void read()
{
    std::ofstream("result.txt");
    ifstream infile;
    infile.open("final_merged.txt");

     //cout << "INPUT\n";
     string s;
     while( getline(infile,s) ) {
            if( s[0] == '#' ) {
                break;
            }
            cout << s << endl;
            input.push_back(s);
     }
     infile.close();
}

bool checkSW( string s )
{
     for( int a = 0; a < SW; a ++ ) {
          if( s.compare( stopwords[a] ) == 0 ) {
              return false;
          }
     }
     return true;
}

void tokenize()
{
     cout << "TOKENIZE\n";
     string s, s1;
     vector<string> temp;
     for( int a = 0; a < input.size(); a ++ ) {
          cout << a << " : ";
          s = input[a];
          s = s + " ";
          s1 = "";
          temp.clear();
          for( int b = 0; b < s.size(); b ++ ) {
               if( s[b] == ' ' ) {
                   if( checkSW(s1) ) {
                       temp.push_back(s1);
                       words.insert(s1);
                       cout << s1 << " , ";
                   }
                   s1 = "";
               } else {
                      if( s[b] >= 65 && s[b] <= 90 ) {
                          s[b] += 32;
                      }
                      s1 = s1 + s[b];
               }
          }
          tokens.push_back(temp);
          cout << "\b\b\b   \n";
     }
}

void createIndex()
{
     cout << "INDEX\n";
     set<string> :: iterator its;
     vector< int > temp;
     for( its = words.begin(); its != words.end(); its ++ ) {
          cout << *its << " : ";
          temp.clear();
          for( int a = 0; a < tokens.size(); a ++ ) {
                   if( find( tokens[a].begin(), tokens[a].end(), *its ) != tokens[a].end() ) {
                             cout << a << " , ";
                             temp.push_back(a);
                   }
          }
          index[*its] = temp;
          cout << "\b\b\b   \n";
     }
}

void userInput(string arg1 , string arg2)
{
     cout << "User Input\n";
     cout << "Word 1 : ";
     input1=arg1;
     //input1 = "ram";
     cout << "Word 2 : ";
     input2=arg2;
     //input2 = "nepal";
}

map< string, bool > visited;
int cost;
string final;

string getString(int a)
{
       string s = "";
       if( a == 0 ) {
            return "0";
}
       while( a != 0 ) {
            s = s + char((a%10)+'0');
            a = a / 10;
       }
       return s;
}

void dfs( string w, int level, string cs, string cd )
{
     if( visited[w] == true ) {
          return;
     }
     cs = cs + w;
     cs = cs + ",";
     visited[w] = true;
     vector<int> doc = index[w];
     string cs1;
     string cd1;
     int i;
     for( int a = 0; a < doc.size(); a ++ ) {
          i = doc[a];
          cd1 = cd + getString(i);
          cd1 = cd1 + ",";
          for( int b = 0; b < tokens[i].size(); b ++ ) {
                   if( visited[tokens[i][b]] == true ) {
                       continue;
                   } else if( input2.compare( tokens[i][b] ) == 0 ) {
                       cs1 = cs + tokens[i][b];
                       cout << a << " --- " << level << " --- " << cs1 << " --- " << cd1 << endl;
                       if( level < cost ) {
                            cost = level;
                            final = cd1;
                       }
                   } else {
                       dfs( tokens[i][b], level + 1, cs, cd1 );
                   }
          }
     }
     visited[w] = false;
}

void execute()
{
     set< string > :: iterator its;
     for( its = words.begin(); its != words.end(); its ++ ) {
          visited[*its] = false;
     }
     cost = input.size() + 1;
     final = "";
     string cs = "";
     string cd = "";
     dfs(input1,0,cs,cd);
}

void output()
{
    ofstream outfile;
    outfile.open("result.txt");
    cout << "FINAL\n";
    cout << cost << " , " << final << endl;

    string s;
    int i = 0, doc;
    for( int a = 0; a <= cost; a ++ ) {
         s = "";
         while( final[i] != ',' ) {
              s = s + final[i];
              i ++;
         }
         i ++;
         doc = atoi(s.c_str());
         cout << doc << " : " << input[doc] << endl;
         outfile<<input[doc]<<"\n";
    }
    outfile.close();
}

int main(int argc, char* argv[])
{
     for (int i = 0; i<argc; i++)
     printf("argv[%d] = %s\n", i, argv[i]);
    read();
    cout << endl;
    tokenize();
    cout << endl;
    createIndex();
    cout << endl;
    userInput(argv[1],argv[2]);
    cout << endl;
    execute();
    cout << endl;
    output();
    //system("pause");
    return 0;
}
