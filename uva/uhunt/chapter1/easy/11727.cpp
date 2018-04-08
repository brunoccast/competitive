#include <iostream>

using namespace std;

int main()
{
  int T, a, b, c;

  cin >> T;

  for(int i=1; i!=T+1; ++i)
  {
    cin >> a >> b >> c;

    cout << "Case " << i << ": ";
    
    if( (a>b && a<c) || (a<b && a>c) )
      cout << a;
    else if( (b>a && b<c) || (b<a && b>c) )
      cout << b;
    else
      cout << c;

    cout << endl;
  }
  
  return 0;
}
