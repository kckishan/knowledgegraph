#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int main()
{
    
    std::ofstream("merge.txt");
    std::ofstream("final_merged.txt");
    int i, j, k, n;
    system("type C:\\wamp\\www\\FinalCode\\Database\\*.txt >> merge.txt");  // Database is folder name where this c++ file is executed 
    string line;
    ofstream myfile;
    myfile.open ("final_merged.txt");
    ifstream infile;
    infile.open ("merge.txt");
    
    if (infile.is_open() && myfile.is_open() )
     { 
       while ( infile.good() ) 
       {
       getline (infile, line);
       if ( line[0] == ' ' )
       {
       } else 
       {
         myfile << line[0];
       }     
       for ( int i = 1; i < line.length(); i++ ) 
           {
             if ( line[i] == '?' || line[i] == '.' ) {
             myfile << endl;
             if ( i < line.length() - 1 && line[i+1] == ' ' )
                i++;
          }
          else myfile << line[i];           
       }
       myfile << " ";  
      } 
      infile.close();
      myfile.close();
    }
    
    system("pause");
    return 0;
}
