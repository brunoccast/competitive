#include <iostream>
#include <algorithm>

#define MAXN 105

using namespace std;

int students[MAXN];

int main()
{
  int T, N;

  cin >> T;
  
  for(int t=1; t!=T+1; ++t)
  {
    cin >> N;

    for(int i=0; i!=N; ++i)
      cin >> students[i];

    sort(students, students+N);

    cout << "Case " << t << ": " << students[N-1] << endl;
  }
  
  return 0;
}
