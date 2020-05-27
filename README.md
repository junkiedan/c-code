# C programming language paradigms #

### How to ###
You need to compile the main.c file to check how the program works.  
#### Linux ####  
You must install GNU C/C++ compiler.  
If you are using Fedora, Red Hat, CentOS, or Scientific Linux, use the following yum command to install GNU c/c++ compiler:    
\# yum groupinstall 'Development Tools'.
If you are using Debian or Ubuntu Linux, type the following apt-get command to install GNU c/c++ compiler:  
$ sudo apt-get update
$ sudo apt-get install build-essential manpages-dev

#### Example 1 ####
Create a struct for books (author, title, price).
User enters books into the virtual library.  
User asks if there are books with a given price.  

#### Example 2 ####
Simple program that creates a matrix of 2 dimensions.  
Then fills the matrix with data.  
Finally find the maximum and the minimum value and print them.  

#### Example 3 ####
Create a program which calculates the equation f(n) = n^2 + f(n-1).  
The n is given by the user.  
Use recursion.  

#### Example 4 ####
Create a program which prints on screen how many words there are in a given word.  
The word is given by the user.  

#### Example 5 ####
Calculate the i on which the sum of 5i^2 exceeds 2000.  
Answer: 11  

#### Example 6 ####
Calculate F(t) = exp(-5t) * cos(0.2+4t) t = [1, 20] sec  
step = a) 1 sec, b) 0.2 sec  

#### Example 7 ####
Calculate the sum of (1/i)^2, i = [1, n]  
n is given from the user.  

#### Example 8 ####
Calculate the y for:  
y(x) = -5x if x < 0  
y(x) = 7x^2 + 16x if 0 <= x < 20  
y(x) = 3x^1/2 + 6 if x >= 20  
x is given from the user  

#### Example 9 ####
User gives random real numbers and the program calculates  
how many of them are > 34.  

#### Example 10 ####
Read 100 numbers and put them in one dimension array.  
Print array's data.  
Print the minimum value and its index.  
Print the number of odd numbers in the array.  

#### Example 11 ####
kWh charging:  
0 - 500 -> 0.02 per kwh  
501 - 800 -> 0.015 per kWh  
801 or more -> 0.01 per kWh  

charging is scaled  
User gives the number of kWh and program calculates the charge.  

#### Example 12 ####
User inputs positive integers and the program calculates the average.  
The user input is being checked.  

#### Example 13 ####
ONOMA[50] has student names.  
BATHMOS[50] has student grades.  
Data is filled by user.  
Print the name and the grade of the best student.  
Print the number of students that had lower grade than 5.0 (didn't pass).  
Print the name of the students with grades more than 6.5.  
Print the average number of grades.  
Print the average without the grades of them who didn't pass.  

#### Example 14 ####
2D matrix: electric charges of 12 months out of 10 appartments  
Data is filled by user.  
Print and save in one dimension matrix the annual electric consumption  
per appartment.  
Print the minimum annual consumption within the appartments.  
Print the maximum monthly consumption for every month.  
Sort the consumptions and print the number of appartments which have  
maximum consumption.  

#### Example 15 ####
1D matrix has the names of 10 cities.  
2D matrix has the temperatures of these 10 cities over 30 days.  
Data is filled by user.  
Print average temperature for every city.  
Print for each city for hoe many days the temperature was less than the average.  
Print the max temperature between the 10 cities for each day.  
Print the name and the number of the cities which for each day had the same value of temperature as the maximum.  

