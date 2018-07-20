/*
 * C: Three Parts of the Array
 * - 2 pointers
 */

#include <iostream>
#define MAXN 200005
#define LL long long

using namespace std;

int n, seq[MAXN];
LL sum_left, sum_right, best;

int main()
{
    cin >> n;
    for(int i=0; i!=n; ++i)
        cin >> seq[i];

    int l=0, r=n-1;
    sum_left = seq[l];
    sum_right = seq[r];

    while(l < r)
    {
        if(sum_left == sum_right)
        {
            best = sum_left;
            sum_left += seq[++l];
            sum_right += seq[--r];
        }
        else if(sum_left < sum_right)
            sum_left += seq[++l];
        else
            sum_right += seq[--r];
    }

    cout << best << endl;

    return 0;
}
