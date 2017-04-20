#include <iostream> 
#include <vector> 
using namespace std; 
 
int a[1001][1001]; 
 
int main() 
{ 
   int num_of_case; 
   cin >> num_of_case; 
  int n; 
 while (num_of_case--) 
  { 
      cin >> n; 
 
       for (int i = 0; i < n; i++) 
         for (int j = 0; j < n; j++) 
             cin >> a[i][j]; 
 
     int triangle_count = 0; 
        int point; 
     for (int i = 0; i < n; i++) 
     { 
          for (int j = i; j < n; j++) 
         { 
              if (a[i][j]) 
               { 
                  for (int x = j; x < n; x++) 
                 { 
                      if (a[j][x]) 
                       { 
                          if (a[x][i]) 
                               triangle_count++; 
                      } 
                  } 
              } 
          } 
      } 
      cout << triangle_count << endl; 
    } 
 
 return 0;
}
