/*

Problem Statement
Implement Fraction Class with the following properties and functions.
Properties :
1.Numerator
2.Denominator
Functions :
1. Parametrized Constructor-
Sets the numerator and denominator values.
2. Add-
This function adds the two fraction following the adding up of two fraction rules and updates the first fractional number.
e.g.
if f1 = 1/4 and f2 = 3/5
f1.add(f2); results in: 
f1 = 17/20 and f2 = 3/5
3.Multiply-
This function multiplies the two fraction and updates the first fractional number.
e.g.
if f1 = 1/4 and f2 = 3/5
f1.multiply(f2); results in: 
f1 = 3/20 and f2 = 3/5
4.Simplify
This function simplifies the fractional value. Use inbuilt __gcd() function.
e.g.
if f1=5/20, which can be further simplified as 1/4 so this 
simplify will perform this.
8. Print() -
Prints the final answer in numerator/denominator form.
Input Format:
The first line of input contains two space-separated integer values, which represent numerator and denominator.

The second line of input contains an integer N representing queries to define how many times the operation must occur.

Next, N lines contain 3 space-separated integers representing the type of query, numerator, and denominator.
Output Format:
Print the value of the fraction after every query in a separate line.
Input Constraints:
 1 <= numerator <= 100
 1 <=denominator <= 100
 1 <= N <= 15
 type = 1 or 2
Sample Input 1:
67 14
1
2 7 78
Sample Output 1:
67/156
Explanation Of Sample Input 1:
Fist fraction is 67/14 and no. of queries is 1. So now 
in the next line 2 7 8 means type=2 which defines 
multiplication and second fraction is 7/78 so 67/74 * 7/78=67/156.
Sample Input 2:
47 71
3
1 91 78
2 67 75
1 36 74
Sample Output 2:
779/426
52193/31950
2506241/1182150
Explanation Of Sample Input 2:
Given fraction is 47/71 and no. of queries is 3. So now in the next 3 lines 1 91 78 means type = 1 which defines addition and second fraction is 91/78 so 47/71 + 91/78= 779/426.   
Next query is 2 67 75 means type=2 which defines multiplication and second fraction is 67/75 so 52193/31950 * 67/75= 52193/31950.  
Last query is 1 36 74 means type=1 which defines addition and second fraction is 36/74 so 52193/31950 + 36/74 = 2506241/1182150.

*/

#include <iostream>
#include <algorithm>
using namespace std;

class Fraction
{
    int n, d;

public:
    Fraction(int, int);
    void add(Fraction);
    void multiply(Fraction);
    void simplify(void);
    void print(void)
    {
        cout << n << "/" << d << endl;
    }
};
Fraction::Fraction(int x, int y)
{
    n = x;
    d = y;
}
void Fraction::add(Fraction f)
{
    n = n * f.d + f.n * d;
    d = d * f.d;
    simplify();
}
void Fraction::multiply(Fraction f)
{
    n = n * f.n;
    d *= f.d;
    this->simplify();
}
void Fraction::simplify(void)
{
    int x = __gcd(n, d);
    d /= x;
    n /= x;
}
int main()
{
    int numer, denom, N, q;
    cin >> numer >> denom;
    Fraction f(numer, denom);
    cin >> N;
    while (N > 0)
    {
        cin >> q >> numer >> denom;
        Fraction g(numer, denom);
        if (q == 1)
        {
            f.add(g);
        }
        else if (q == 2)
        {
            f.multiply(g);
        }
        else
        {
            cout << "Enter 1 or 2 as query type\n";
        }
        f.print();
        N--;
    }
    return 0;
}