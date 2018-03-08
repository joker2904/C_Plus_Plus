// trie_DP.cpp : Defines the entry point for the console application.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

class TrieNode
{
   public:
   char value; // can assume @, \0 , \n values 
   class TrieNode* ChildNodes[26];
 
   TrieNode(char flag)
   {
     value = flag;
     for( int i = 0; i <26; i++)
         ChildNodes[i] = NULL;
   }
   
   bool insert(char* S)
   {
     TrieNode* current = this; 
     char flag;
     int length = strlen(S);
     for( int i = 0; i < length; i++)
     {
       flag = '7';
       if( i == length-1 )
           flag = '\0';
       if( current -> ChildNodes[ S[i] - 'a' ]  == NULL )
           current -> ChildNodes[ S[i] - 'a' ] = new TrieNode(flag);
       else
           current -> ChildNodes[ S[i] - 'a' ] -> value = flag;
                 
       current =  current -> ChildNodes[ S[i] - 'a' ];
     }
     return true;
   }
    
   bool find(char* S)
   {
     TrieNode* current = this;
     int length = strlen(S);
     for( int i = 0; i < length; i++)
     {
         if( i == length-1 && current -> ChildNodes[ S[i] - 'a' ] == NULL )
             return false;
         if( i == length-1 && current -> ChildNodes[ S[i] - 'a' ] -> value == '\0' )
             return true;
		 if( i < length && current -> ChildNodes[ S[i] - 'a' ] == NULL ) 
             return false;
        
         current =  current -> ChildNodes[ S[i] - 'a' ];
  
     }
       return false;
   }
    
};



char* construct( char* login, int s, int e )
{
    char* x = new char[e-s+1]; 
    int j = 0;
    for( int i = s; i <=e; i++)
        x[j++] = login[i];
    x[j] = '\0';
    return x;
}

bool** allocate(int m,int n)
{
	bool** p = (bool**)malloc( sizeof(bool*) * m);
	for( int i = 0 ; i < m ;++i)
		p[i] = (bool*)malloc( sizeof(bool) * n );

	return p;
}


bool TryDP(TrieNode* Dictionary, char* login,int length) 
{
  bool Path[200][200][2];
   for( int i = 0; i < length; ++i)
      for( int j = i; j < length; ++ j)
       {
   //       Path[i][j][0] = false;
     //     Path[i][j][1] = false;
       }
    /*
   for( int i = 0; i < length; ++i)
     for( int j = i; j < length; ++ j)
     {
       bool p = false;
       for( int k = i ; k < j ; ++k )
       {
        if( Path[i][k][1] == false )
        {
            Path[i][k][0] = k-i <= 10 ? Dictionary->find( construct(login,i,k) ) : false ;
            Path[i][k][1] = true;    
        }
        if( Path[k+1][j][1] == false )
        {
            Path[k+1][j][0] = j-k-1 <= 10 ? Dictionary->find( construct(login,k+1,j) ) : false ;
            Path[k+1][j][1] = true; 
        }
        p += Path[i][k][0] * Path[k+1][j][0] ;
       }
        Path[i][j][0] = p;
        Path[i][j][1] = true;
     }  
   if( Path[0][length-1] == false )
       return false;
       
   int row = 0, col = 0;
   while( col < length )
   {
     do {
         cout<<login[col];
         col++;
     }while( Path[row][col][0] == 0 );
     cout<<login[col]; col++;
     if( Path[col][length-1][0] == 1)
     {
       cout<<" "; row = col;   
     }
       
   }*/
    
   return true; 
}


int main() {

	char temp[3][5] = { "ab", "abcd", "cd"  };
    TrieNode* Dictionary = new TrieNode('@');
    
    for( int i= 0; i < 3 ;++i )
       Dictionary->insert(temp[i]);
   
   char login[2009] = "abcd";
   if(!TryDP(Dictionary,login, strlen(login) ))
     cout<<"WRONG PASSWORD\n";
   delete Dictionary;
  
   return 0;
}

