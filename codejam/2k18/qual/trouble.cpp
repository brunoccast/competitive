#include <iostream>
#include <algorithm>

#define MAXN 100005

using namespace std;

int T, N, an, bn, a[MAXN], b[MAXN];

int main()
{
  cin >> T;

  for(int i=1; i!=T+1; ++i)
  {
    cin >> N;

    an = bn = 0;
    for(int i=0; i!=N; ++i)
    {
      if(!(i%2))
	cin >> a[an++];
      else
	cin >> b[bn++];
    }

    sort(a, a+an);
    sort(b, b+bn);

    int error=-1;
    for(int i=0; i<N-1 && error<0; ++i)
    {
      if( (i%2==0 && a[i/2]>b[i/2]) || (i%2!=0 && b[i/2]>a[i/2+1]) )
	error = i;
    }

    if(error<0)
      cout << "Case #" << i << ": OK" << endl;
    else
      cout << "Case #" << i << ": " << error << endl;
  }
  
  return 0;
}
