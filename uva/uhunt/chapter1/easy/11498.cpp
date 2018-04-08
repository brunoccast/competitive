#include <iostream>

using namespace std;

int main()
{
  int K, N, M, X, Y;

  while(true)
  {
    cin >> K;
    if(!K) break;

    cin >> N >> M;
    
    while(K)
    {
      cin >> X >> Y;

      if(X == N || Y == M)
	cout << "divisa";
      else if(X < N && Y > M)
	cout << "NO";
      else if(X > N && Y > M)
	cout << "NE";
      else if(X < N)
	cout << "SO";
      else
	cout << "SE";

      cout << endl;
      K--;
    }
  }
  
  return 0;
}
