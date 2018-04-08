#include <iostream>

using namespace std;

int T, A, I, J, column;

int main()
{
  cin >> T;
  while(T)
  {
    cin >> A;
    
    column = 100;
    do
    {
      if(column>104) column = 100;
      cout << "100 " << column << endl;
      cin >> I >> J;
      column++;
    } while( !((I==0 && J==0) || (I==-1 && J==-1)) );
    
    if(I==-1 && J==-1)
      return 0;
    
    T--;	
  }
  
  return 0;
}
