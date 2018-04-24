
# Knowledge Graph
## A search engine

##### Kishan K.C. 

Steps: 

1. Tokenizing Web Documents
2. Indexing
3. Forming Knowledge Graph
4. Performing Search and Constructing Information.
5. Displaying Information

The project uses c++. There are two C++ programs , main.cpp and merge.cpp.

1. Merge.cpp
It merges all the content from different documents in a single text file named final_merged.txt.
Then it splits the whole document into individual sentences so that there is single sentence in
each line. It is necessary for indexing because sentences act as edges in the graph. So during
indexing sentence number is necessary.


System command “type *.txt >> merge.txt” is used to merge all the text files from folder
Database. After merging all the text documents into merge.txt, each sentences are arranged in a
single line. Whenever a full stop or question mark is found , the sentence is printed in new line.

2. Main.cpp

There are several functions in it. They are described briefly below:

* read ();
This function opens the text document final_merged.txt and reads individual strings from the
file then it performs vector operation push_back to store the strings in vector of string named
vector<string> input.

 
* checkSW( string s )
This function checks whether the strings from input file final_merged.txt are useful for
tokenizing or not. The words that can be ignored are defined in an array called string
stopwords[SW].
```
string stopwords[SW] = { "the", "of", "in", "and", "a", "an", "to", "with", "is", "was",
"were", "by", "that", "for", "be", "from", "as", "are", "on", "or", "this", "an", "not", "it", "which",
"with", "too", "at", "these" };
```

The function checks the strings are one of these stop words or not.


* tokenize()

This function tokenizes the strings contained in final_merged.txt if they are not one of
the stop words defined above.

* createIndex()

After tokenization it is necessary to index the tokens , this function tags each token with
the sentence number it belongs to.

* userInput(string arg1 , string arg2)

This function takes input from the user. User is provided with two fields in search engines.

He can provide his query which must be a string in these fields.

* dfs( string w, int level, string cs, string cd )

Using tokens as nodes and sentences where they occur as edges a graph is made.

* execute()

This function executes dfs and finds the path between two search words in the graph.

* output()

This function provides the result in result.txt. The result is the path between two search
words provided by the user.


This function calls all the functions discussed above.
```
int main(int argc, char* argv[]) { 

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
   return 0;
}
```
