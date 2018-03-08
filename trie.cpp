// trie.cpp : Defines the entry point for the console application.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
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
   
   bool insert(string S)
   {
     TrieNode* current = this; 
     char flag;
     int length = S.length();
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
    
   bool find(string S)
   {
     TrieNode* current = this;
     for( int i = 0; i < S.length(); i++)
     {
         if( current -> ChildNodes[ S[i] - 'a' ] == NULL ) 
             return false;
         if( i == S.length()-1 && current -> ChildNodes[ S[i] - 'a' ] -> value == '\0' )
             return true;
         current =  current -> ChildNodes[ S[i] - 'a' ];
  
     }
       return false;
   }
    
};



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



void printvector(vector<string>& V)
{
  for( vector<string>::iterator itr = V.begin(); itr != V.end(); ++itr )
  {
     cout<<*itr<<" ";
  }
  cout<<endl;
}

bool Try(TrieNode* Dictionary,vector<string>& V, string& login)
{
   string temp;
   bool flag=false;
   for( int i = 0; i< login.length(); ++i)
   {
     temp.push_back(login[i]);
     if( Dictionary->find(temp) != true )
     {
        V.push_back(temp); 
        if( i == login.length() - 1 )
        {
           printvector(V);
           return true;
        }
        string remaining = login.substr(i+1);
        flag = Try(Dictionary,V,remaining);
         if(flag)
             return true;
        V.pop_back();
   
     }       
       
   }
   return flag;
}


void printVector(vector<char*>& V)
{
  for( vector<char*>::iterator itr = V.begin(); itr != V.end(); ++itr )
  {
     cout<<*itr<<" ";
  }
  cout<<endl;
}

bool Try(TrieNode* Dictionary,vector<char*>& V, char* login,int length, int start) //,int end)
{
   char temp[2500];
   bool flag=false; int j = 0;
   for( int i = start; i < length ; ++i)
   {
     temp[j] = login[i] ; j++;
     temp[j] = '\0';
     if( Dictionary->find(temp) == true )
     {
        V.push_back(temp); 
        if( i == length - 1 )
        {
           printVector(V);
           return true;
        }
        //string remaining = login.substr(i+1);
        flag = Try(Dictionary,V,login,length,i+1) ;
        if(flag)
          return true;
        V.pop_back();
   
     }       
       
   }
   return flag;
}





void printVSector(vector<int>& V,char* login,int length)
{
  int start = 0;
  for( vector<int>::iterator itr = V.begin(); itr != V.end(); ++itr )
  {
     for( int i = start; i <= *itr; ++i )
         cout<<login[i];
     cout<<" ";
     start = 1 + *itr; 
  }
  cout<<endl;
}

bool TryTrie(TrieNode* Dictionary,vector<char*>& V, char* login,int length) 
{
   vector<int> S; 
   S.push_back(-1);
   bool flag = false;
   while( ------ )
   { 
      char temp[12];
      int start = 1 + S.back();
      if( !flag )
          S.pop_back();
	  if( 

      int j = 0;
      for( int i = start; i < length ; ++i)
      {
	    if( i-start >= 11 ) // code specific 
			continue;

        temp[j] = login[i] ; j++;
        temp[j] = '\0';
        if( Dictionary->find(temp) == true )
        {
           S.push_back(i); 
           if( i == length - 1 )
           {
             printVSector(S,login,length);
             return true;
           }
           flag = true;
           continue;
        }       
      }
    }
   return flag;
}






int main() {
    
       //int n;
       //cin>>n;
	   char temp[10][10] = { "solo", "love", "vest", "stop" ,"open","ends", "dsso", "endsopen", "opendsso", "vestopen" };
               
       TrieNode* Dictionary = new TrieNode('@');
       vector<char*> V;
       for( int i= 0; i < 10 ;++i )
          Dictionary->insert(temp[i]);
       
     //  char login[2009] = "gadacadagaaaiaaabiabagagajadacafaiacaaajacahaiahahacagacabaaahabacajajaaagafaaabaeagaaacahahadaiagahaeacaaaeacaiaaaiagagadagaeaeadahahagagabaeagaeaeajaeabaaagagabaeadagafabaaajafadaiaaahahaiacaeafabaeahaaaaabaeafaiajabaiadafajaiajaaabafadacafaaahaeajahabacacadacaaaaagajaiacaeajaiadabadahagafaaagagajaaaiahajacacafajadaiaaacaiadahaeafadajaaahagaeadaaadaaadahadaeadafagabahacafaiagafagacahahadagajagaeabahaaahacahaaafagajaeahagaaaaabjafahacagagaaaaaeaeafabaeaeafaiabadaiajaeahadagadahacajaaaiafabaeahahadaiadafafacabaeajaiahaaagabajaiabahajabaiagaiacacaaabcabafaiafaaacabaaajagacadagagabacajajaeagajacaiaiaiabafagaaadafadafaiaiahagaiaiadadabaaacaeaiaeafaaaeaaabaiahagagabagacabacafaeahahaeabaeaaaeaaacababaiagacahadaeadababajafaeababaiahaaabadafaiahahagaaaaacafabaaabagaaacajajahadaeaaabhaaabfaaahacaeaiaiaiaaadabaaacaiafahahaeaaaiacacabaaaaaaaaaaagaiahacabafadahaaajahaiacadafacajaeagaaafahaaagadabaaabdagadacafadadaeaeaeajaiahajaeaeaeagaaabcaaagahagagaeabaiaeaeadajaaagaiadahajacagaiacajaiacaaadahacahadabacafagafahahababaaaaaaagafadafabaaagajadaiajafagaaabadajajahaiaeaeababadabahagabacaiaiahagaeaeahabagadafabacaiaeahaiaeaaagabagafaaacahacajajagacaaaaaeahafaeagabagababadacabagaiagadaeaiajagabajacahahacacafaiagabafahahaaahadacafaaabcadahahajagacaaaiadaaaaacabagagabajadagajadahajacajacaaagahabagaeafaaagacacagahafaeadahaeacabadafagahafacagabafaiahacabacadahafaaahafabaaaiacafabaaaeabaaaaadaaagafacagaaaiahafajaiaaadacacadajabaaaeacaaagadafahajahaaaaaaabadaiadaaababahababajajaiadacahabadagajafaiajaiadahafahaeaaabfaeabafaaaaabiadaeajaeacafahacagafaaabcaaaaaiaaabeaaaeabaaahaiaaaaadabajadaaaeajafajahaaadababaeabaaacaaaaadaaafadaaadajajahafafahaiahabahacajafaeaeahajagaaabcabacaeajaeabaaadahacafaaagababaeagaeabahagafahajajagafafagabaaacaaacagabagahabafahaaaaacaaabjajafadahacaiacahaaajabacahacabaiagahaiahajacadafaiabaaadajagaaajacaaafafacababafaiabaaaeadaaaaaeacajabaaabaaaaiafabaeafaaaaacabajadaaafacaiaiafaeafacajafajadaiacagahabadacaeagafagababadabadagabafafaeaaabcahagadabagadajadahaeagagaha";
	   char login[2009] = "vestloveendsvestloveopenendsopenopenlovesolostopvestlovesololovestopdssoopenvestdssovestendsopenstopstopendsopenloveendsopensolosoloopenendsendsopendssostopvestdssolovevestopendssosolosolosolosolosolosololovevestvestopenstopsolovestopenopenendsopendssodssostopopenopenendsopenvestlovestopvestopensoloendsdssosoloendsendsdssoendssolosoloopenopendssosoloendsopenveststopvestopenendsopenopendssoopenopendssoendsendsstopvestsololoveloveendsopenopendssosoloendsopenvestopenstopdssodssovestopenopenendsopendssovestopenendsendsdssostopopenendsvestsoloendsopenstopendsopenendsopenendssololovevestopenendsopenloveopendssodssoopenendsopenendsdssodssolovedssolovesolosolostopstopvestopenvestdssodssoopendssostopsoloopenloveendsopenstopvestvestopendssodssoveststopopenendsopenlovedssovestopenloveloveopendssovestopendssoendsopenopenopendssoendsopendssodssovestopenvestendsopendssoopendssovestopenopenvestopenvestopensolovestsoloendsvestopenopendssoendssololovevestopenvestsoloopendssostopopendssoendsopenopenendsopendssostopendsopenstoplovelovelovedssoloveopensoloendsvestopenendsvestopenvestvestvestopenvestopensolodssoopendssoendsvestdssoopendssoopendssoendsopensolostopsolodssoendsvestopendssostopdssoopendssoendsopendssoendsopenendsstopdssoendsopensololoveopendssodssoopenstopendsopendssolovelovesoloveststopdssostopopendssodssodssoopenstopopendssoopendssoopendssoloveopendssovestopensoloendsopenendsopenvestopenstopstopvestdssosoloendsopenendsopenstopsoloopendssolovevestendssolostopopenopenvestloveopenopendssovestopensolovestopenvestopendssovestloveopenstopopenvestendsopenstopdssovestopenopenstopopenloveopendssoopendssodssoendsopenvestopendssovestlovevestendsopenendsdssostopstopendsopenstopvestopenopendssoloveopenopendssoendsendsopenvestendsopensolovestvestopenvestopenvestopenvestvestopenopendssoloveendsdssolovestopendslovevestopenvestloveopenendsloveopenvestsolosolovestopenopenlovesolovestopenendsopenvestopenendsopenopenvestopenvestendsopenopendssoopendssovestsoloendsopenendsvestloveendsvestopen";
	   // cout<<Dictionary->find(login);
       //cin>>login;

       if( !TryTrie(Dictionary,V,login,strlen(login)) )
        cout<<"WRONG PASSWORD\n";
       delete Dictionary;
     
    
    return 0;
}
*/



#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <deque>
using namespace std;
class TrieNode
{
public:
	char value; // can assume @, \0 , 7 values 
	class TrieNode* ChildNodes[26];
	int Number;
	TrieNode(char flag, int x)
	{
		value = flag;
		Number = x;
		for (int i = 0; i <26; i++)
			ChildNodes[i] = NULL;
	}

	bool insert(char* S)
	{
		TrieNode* current = this;
		char flag;
		int length = strlen(S);
		for (int i = 0; i < length; i++)
		{
			flag = (i == length - 1) ? '\0' : '7';
			if (current->ChildNodes[S[i] - 'a'] == NULL)
				current->ChildNodes[S[i] - 'a'] = new TrieNode(flag, 0); //flag == '\0'? 0 : 1);
			else if (current->ChildNodes[S[i] - 'a']->value == '7')
				current->ChildNodes[S[i] - 'a']->value = flag;

			current->ChildNodes[S[i] - 'a']->Number += 1;
			current = current->ChildNodes[S[i] - 'a'];
		}
		return true;
	}

	bool find(char* S)
	{
		TrieNode* current = this;
		int length = strlen(S);
		for (int i = 0; i < length; i++)
		{
			if (i == length - 1 && current->ChildNodes[S[i] - 'a'] == NULL)
				return false;
			if (i == length - 1 && current->ChildNodes[S[i] - 'a']->value == '\0')
				return true;
			if (i < length && current->ChildNodes[S[i] - 'a'] == NULL)
				return false;

			current = current->ChildNodes[S[i] - 'a'];

		}
		return false;
	}

	int countPrefix(char* S)
	{
		TrieNode* current = this;
		int length = strlen(S);

		for (int i = 0; i < length; i++)
		{
			printf("%d =\n", current->Number);
			if (i == length - 1 && current->ChildNodes[S[i] - 'a'] == NULL)
				return 0;
			if (i < length && current->ChildNodes[S[i] - 'a'] == NULL)
				return 0;

			current = current->ChildNodes[S[i] - 'a'];
		}

		if (!current)
			return 0;
		return current->Number;
		// return CountLeaves(current,'@');
	}

	int CountLeaves(TrieNode* node, char t)
	{
		int count = 0;
		deque< pair<TrieNode*, char> > Q;
		Q.push_back(pair<TrieNode*, char>(node, t));

		while (!Q.empty())
		{
			pair<TrieNode*, char> temp = Q.front();
			TrieNode* currentNode = temp.first;
			Q.pop_front();
			if (currentNode->value == '\0')
			{
				count++;
				//  printf("%c <=>\n",temp.second);
			}
			//else
			//printf("%c =\n",temp.second);
			for (int i = 0; i < 26; i++)
			{
				if (currentNode->ChildNodes[i])
				{
					// printf("%c <> \n",'a' + char(i) );
					Q.push_back(pair<TrieNode*, char>(currentNode->ChildNodes[i], 'a' + char(i)));
				}
			}
		}

		return count;

	}

};

int main() {
	int n;
	//scanf("%d", &n);
	TrieNode T('@',0);
	char* s = (char*)malloc(sizeof(char) * 27);

	T.insert("abcd");
	T.insert("efgh");
	T.insert("efghyu");
	T.insert("abcdef");
	T.insert("abd");
	
	printf("%d\n", T.CountLeaves(&T,'@'));
	T.countPrefix("abcdef");
	free(s);
	getchar();
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	return 0;
}
