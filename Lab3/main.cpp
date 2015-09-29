// Sean Clancy
// CS235 Lab3

#include <iostream>
#include <set>
#include <vector>
#include <fstream>
#include <locale>
#include <math.h>
using namespace std;

// get the dictionary file and eliminate lowercase letters

void GetDictionary(set<string>& Dictionary,string filename)
{
    string word;
    string NewWord;
    ifstream infile;
    locale loc;
    infile.open(filename.c_str());
    if(infile.is_open()) {
       while(getline(infile,word)){
        for (auto c : word)
        {
            NewWord += std::tolower(c, loc);
        } 
        Dictionary.insert(NewWord);
        word="";
        NewWord="";
    }
}
}

int GetBoard(vector<vector<string> >& BoggleBoard,string filename)
{
    vector <string> BoggleLetters;
    string letter;
    ifstream infile;
    locale loc;
    infile.open(filename.c_str());
    if(infile.is_open())
    {
        while (infile >> letter)
        {
            for (auto& c : letter) 
            {
                if ((isalpha(c))) 
               {
                   c = std::tolower(c);
               }
           }
           BoggleLetters.push_back(letter);
       }
   }

   infile.close();
   int h=0;
   int BoardSize = sqrt(BoggleLetters.size());
   for(int j=0;j<BoardSize;j++)
   {
       vector <string> row;
       for(int i=0;i<BoardSize;i++)
       {
           row.push_back(BoggleLetters[h]);
           h++;
       }
       BoggleBoard.push_back(row);
   }
   return BoardSize;
}
bool WordChecker( const set<string>& Dictionary, string& WordCheck, set <string>& foundWords)
{
    std::set<std::string>::const_iterator iterator = Dictionary.lower_bound(WordCheck) ;
    if( iterator == Dictionary.end() ) { /* no match */ return false ; }
    if( *iterator == WordCheck && WordCheck.length()>=4) { 
      foundWords.insert(WordCheck);
      return true;
     } 
    else
    {
        /* check for prefix match */
        const std::string& candidate = *iterator;
        if(candidate.substr( 0, WordCheck.size() ) == WordCheck )
        { /* found closest match */ return true; } 
        else { /* no match */ return false; } 
    }
}

bool inbounds(vector<vector<string>>& BoggleBoard, int row, int column)
{
  return row>=0 && column>=0 && row<BoggleBoard.size() && column< BoggleBoard.size();
}

void PlayBoggle(vector<vector<string>>& BoggleBoard, set <string>& foundWords, set <string>& Dictionary,
  vector<vector<bool>>& boardCheck,int row, int column, string WordCheck)
{

  if (!inbounds(BoggleBoard,row,column) || boardCheck[row][column]) 
  {
    return;
  }
  WordCheck += BoggleBoard[row][column];
  if(!WordChecker(Dictionary, WordCheck, foundWords))
  {
    return;
  }
 
  boardCheck[row][column]= true;
  for (int i=row-1; i<=row+1 /*&& i<BoggleBoard.size()*/; i++)
  {
    for (int j=column-1; j<=column+1/*&& j<BoggleBoard.size()*/; j++)
    {
      PlayBoggle(BoggleBoard,foundWords,Dictionary,boardCheck,i,j, WordCheck);
    }
  }
  boardCheck[row][column]=false;
}
void FillBoardCheck(vector<vector<bool>>& boardCheck, int BoardSize)
{
  vector<bool> temp;
  for(int i=0; i<BoardSize;i++)
  {
    for(int i=0; i<BoardSize;i++)
    {
      temp.push_back(false);
    }
  boardCheck.push_back(temp);
  }
}
int main(int argc, char* argv[]) {
    ofstream out;
    out.open(argv[3]);
    int row=0;
    int column=0;
    string WordCheck;
    set<string> Dictionary;
    vector<vector<string> > BoggleBoard;
    vector<vector<bool>> boardCheck;
    set <string>foundWords;
    GetDictionary(Dictionary,argv[1]);
    int BoardSize=GetBoard(BoggleBoard,argv[2]);
    FillBoardCheck(boardCheck,BoardSize);
    for(int i=0;i<BoardSize;i++)
    {
      for(int j=0;j<BoardSize;j++)
      {
        PlayBoggle(BoggleBoard,foundWords,Dictionary,boardCheck,i,j, WordCheck);
      }
    }
    for(int i=0;i< BoggleBoard.size();i++)
    {
        for(int j=0;j< BoggleBoard[i].size();j++)
        {
            out << BoggleBoard[i][j] << " ";
        }
        out << endl;
    }
    out<<endl;
    for(set<string>::iterator it=foundWords.begin();it!=foundWords.end();++it)
    {
    out << *it<<endl;
    }
    return 0;
}
