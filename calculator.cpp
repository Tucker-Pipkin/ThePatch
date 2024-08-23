//this code is written c++ to create a scientific calculator
#include <iostream>
#include <stdlib.h>//standard library for c++
#include <cmath>//math functions library
using namespace std;//workaround for not having to use std:: everywhere and give me ptsd
//declaring functions
void key();
void numcheck(int num);
void clear();
float first_num=0;//floating point variable for first input
float second_num=0;//floating point variable for second input
string solution;//string variable that holds the solution
int main(){
string first;//variable for string version of first number
string second;//variable for string version of second number
string o="";//operator variable
string equation="";
bool exit=false;
  //this is the main loop that insures that the program will run until the user exits by choice.
while(!exit){
numcheck(1);
first=to_string(first_num);
equation=first;
bool run=false;
clear();
  //this second loop makes sure the code will run until the user enters a valid operator.
while(!run){
cout<<equation<<endl;
cout<<"Please select which operation you would like to use \n";
key();
cout<<"operater: ";
cin>>o;
equation=first+o;
clear();
cout<<equation<<endl;
  //the next eleven 'if' statements determine how the code will react based on the operator input as a result some are slightly different while others differ greatly, the first four check for a second input while the rest do not. Some have specific exclusions written into them in order to prevent the code from crashing.
if(o=="/"){
numcheck(2);
while(second_num==0){
clear();
cout<<"You cannot divide by 0, try again\n";
numcheck(2);
second=second_num;
}
second=to_string(second_num);
clear();
solution=to_string(first_num/second_num);
cout<<"your equation is: "+first+o+second+'='+ solution;
run=true;
}
else if(o=="*"){
numcheck(2);
second=to_string(second_num);
clear();
solution=to_string(first_num*second_num);
cout<<"your equation is: "+first+o+second+"="+solution;
run=true;
}
else if(o=="+"){
numcheck(2);
second=to_string(second_num);
clear();
solution=to_string(first_num+ second_num);
cout<<"your equation is: "+first+o+second+"="+solution;
run=true;
}
else if(o=="-"){
numcheck(2);
second=to_string(second_num);
clear();
solution=to_string(first_num-second_num);
cout<<"your equation is: "+first+o+second+"="+solution;
run=true;
}
else if(o=="sq"){
solution=to_string(first_num*first_num);
cout<<"your equation is: "+first+"²="+solution;
run=true;
}
else if(o=="sqr"){
while(first_num<0){
clear();
cout<<"You cannot square_root a negative, try again\n";
numcheck(1);
first=to_string(first_num);
}
solution=to_string(sqrt(first_num));
cout<<"your equation is: √"+first+"="+solution;
run=true;
}
else if(o=="c"){
solution=to_string(cos(first_num));
cout<<"your equation cos("+first+")="+solution;
run=true;
}
else if(o=="s"){
solution=to_string(sin(first_num));
cout<<"your equation sin("+first+")="+solution;
run=true;
}
else if(o=="t"){
solution=to_string(tan(first_num));
cout<<"your equation tan("+first+")="+solution;
run=true;
}
else if(o=="e"){
solution=to_string(exp(first_num));
cout<<"your equation e^"+first+"="+solution;
run=true;
}
else if(o=="ln"){
while(first_num<0){
clear();
cout<<"You cannot take a natrual log of a negative, try again\n";
numcheck(1);
first=to_string(first_num);
}
solution=to_string(log(first_num));
cout<<"your equation ln"+first+"="+solution;
run=true;
}
else{
clear();
cout<<"invalid operator choose a new operator: "<<endl;
}
}
//asks the user if they would like to exit the program or continue with another equation.
cout<<"\nwould you like to exit? ('y' for yes): ";
string ans;
cin>>ans;
if(ans=="y"){
exit=true;
clear();
cout<<"                              ok";
}
else{
clear();
}
}
return 0;
}
//this function is used to take in a input as a float and check if it is a valid number, and if so set the predetermined variables based on the intended index, second number inputs use index two.
void numcheck(int ind){
string nums;
float num;
bool check=false;
cout<<"Please enter a number: ";
do{
cin>>nums;
try{
num=stof(nums);
check=true;
}
catch(exception num){
cout<<"invalid number! try again: ";
}
}while(!check);
if(ind==1){
first_num=num;}
else{
second_num=num;}
}
//this function print the key to every input that correlates to every operator
void key(){
cout<<"key for operations\n";
cout<<"[+] add,    [-] subtract, [*] multiply\n";
cout<<"[/] divide, [sq] square,  [sqr] square_root\n";
cout<<"[c] cosine, [s] sine,     [t] tangent\n";
cout<<"[e] exponential_e,        [ln] natrual_logarithm\n";
}
//this function clears the console
void clear(){
cout << "\x1B[2J\x1B[H";
}
