#include <iostream>  
#include <algorithm>  
using namespace std; 
 
int main() 
{ 
  int test_case; 
 
    cin >> test_case; 
 
   int num_of_matrix; 
 int r[505], c[505]; 
 
   while (test_case--) 
    { 
      cin >> num_of_matrix; 
 
       for (int i = 0; i < num_of_matrix; i++) 
     { 
          cin >> r[i] >> c[i]; 
       } 
 
     int p[505]; 
        p[0] = r[0]; 
       for (int i = 0; i < num_of_matrix; i++) 
     { 
          p[i + 1] = c[i]; 
       } 
 
     int f[505][505]; 
 
      memset(f, 0, sizeof(f)); 
 
      for (int L = 2; L < num_of_matrix + 1; L++) 
     { 
          for (int i = 1; i < num_of_matrix - L + 2; i++) 
         { 
              int j = i + L - 1; 
             f[i][j] = INT_MAX; 
             for (int k = i; k <= j - 1; k++) 
                { 
                  int q = f[i][k] + f[k + 1][j] + p[i - 1] * p[k] * p[j]; 
                    if (q < f[i][j]) 
                        f[i][j] = q; 
               } 
          } 
      } 
 
     cout << f[1][num_of_matrix] << endl; 
   } 
 
 return 0; 
}  
