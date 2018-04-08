#include <iostream>

#define MAX_MONTH 105

using namespace std;

double deprec[MAX_MONTH]; // depreciation p/month

int main()
{
  int month, old_m, m;
  double payment, loan, records, old_p, p;

  while(true)
  {
    cin >> month >> payment >> loan >> records;
    
    if(month < 0)
      break;

    cin >> old_m >> old_p;

    for(int rec=1; rec!=records; ++rec)
    {
      cin >> m >> p;
      
      for(int i=old_m; i!=m; ++i)
	deprec[i] = old_p;

      old_m = m;
      old_p = p;
    }

    for(int i=old_m; i!=month+1; ++i)
      deprec[i] = old_p;

    for(int i=0; i!=month+1; ++i)
      cout << deprec[i] << " ";
    cout << endl;
    
    double buyer = loan;
    double car = loan+payment;
    car -= car*deprec[0];

    int i=1;
    for(; i!=month+1 && buyer>=car; ++i)
    {
      car -= car*deprec[i];
      buyer -= payment;
    }

    cout << i << (i==1 ? " month" : " months") << endl;
  }
  
  return 0;
}
