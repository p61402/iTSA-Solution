#include <iostream> 
#include <string> 
using namespace std; 
 
bool is_legal(string expression) 
{ 
    bool is_first = true; 
    bool has_next = false; 
    bool pre_is_digit = false; 
    bool pre_is_open_brace = false; 
    bool pre_is_closed_brace = false; 
    bool pre_is_calc = false; 
    unsigned int pre_digit_index = 0; 
    int braces = 0; 
 
    for (unsigned int i = 0; i < expression.size(); i++) 
    { 
      if (expression[i] != ' ') 
      { 
          if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') 
          { 
              if (is_first || pre_is_calc || pre_is_open_brace) 
              { 
                  return false; 
              } 
              else 
               { 
                  pre_is_calc = true; 
                    pre_is_open_brace = false; 
                 pre_is_closed_brace = false; 
                   pre_is_digit = false; 
                  has_next = true; 
               } 
          } 

         if (expression[i] == '(') 
          { 
              if (pre_is_digit || pre_is_closed_brace) 
                   return false; 

             pre_is_calc = false; 
               pre_is_closed_brace = false; 
               pre_is_digit = false; 
              braces++; 
              pre_is_open_brace = true; 
              has_next = true; 
           } 

         if (expression[i] == ')') 
          { 
              if (braces == 0 || pre_is_calc) 
                    return false; 
              else 
                   braces--; 

             pre_is_calc = false; 
               has_next = false; 
              pre_is_open_brace = false; 
             pre_is_closed_brace = true; 
                pre_is_digit = false; 
          } 

         if (isdigit(expression[i])) 
            { 
              if (pre_is_closed_brace) 
                   return false; 
              else if (pre_is_digit && pre_digit_index != i - 1) 
                 return false; 

             pre_digit_index = i; 
               pre_is_calc = false; 
               pre_is_open_brace = false; 
             pre_is_digit = true; 
               has_next = false; 
          } 

         is_first = false; 
      } 
  } 

 if (!has_next && braces == 0) 
      return true; 
   else 
       return false; 
} 
 
int main() 
{ 
    int test_case; 
    string buffer; 
 
    cin >> test_case; 
    getline(cin, buffer); 
 
    while (test_case--) 
    { 
      string s; 
      getline(cin, s); 
 
      if (is_legal(s)) 
           cout << "legal\n"; 
       else 
           cout << "illegal\n"; 
} 
 
    return 0; 
}  
