/*

Problem Statement
Create a class named Person with a string variable 'name' and an integer variable 'age,' such that these variables are not accessible outside the class and implement a way to initialize the variables and print the variables.
Functions:
1.SetValue- That Sets The Variables Value.
2.GetValue- That Prints The Variables Value.
Input Format:
The first line of input contains a single string Name, representing the name of the person. 

The second line of input contains a single integer Age, representing the age of the person.
Output Format:
The only line of output prints the name and age by sticking to the sample input format. Mind that the output string won't have preceding or trailing spaces.
Sample Input 1:
Afzal
67
Sample Output 1:
The name of the person is Afzal and the age is 67.
Sample Input 2:
Ali
30
Sample Output 2:
The name of the person is Ali and the age is 30.
Explanation Of Sample Input 1:
The input name is Ali and the input age is 30 which is printed in the specified format.

*/


class Person:

   def SetValue(self,name,age):

       self.name=name

       self.age=age

   def GetValue(self):

       print("The name of the person is {} and the age is {}.".format(self.name,self.age))

       

name = input()

age=int(input())              

P=Person()

P.SetValue(name,age)

P.GetValue()