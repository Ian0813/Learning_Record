#! /usr/bin/python3

''' 
modular arithmetic

Description : 
    The selling price of a beverage is 20, a dozen is 200. 
'''

amount = int(input("Please enter the number beverage : "))

if(amount >= 12):
    dozens = int(amount/12)
    number = amount%12 
    total = dozens * 200 + number * 20

    print("The total price is : " + str(total))
else:
    print("The total price is : %d" % int(amount * 20))


'''
Description : 
    A conversion for temperature between Celsius and Fahrenheit.  
'''

#temp_type : a type of temperature
temp_type = input("What type of temperature do you want to convert : ")
temperature = int(input("Please enter a temperature : "))

if(temp_type == 'C'):
    print("The Celsius convert to Fahrenheit is : " + str((temperature*9/5)+32), end='\n')
elif(temp_type == 'F'):
    print("The Fahrenheit convert to Celsius is : " + str((temperature-32)*5/9), end='\n')


'''
Description : 
    Is this year of a leap year?
'''

year = int(input("Please enter a number of a year : ")) 

isleapyear = (year%400 == 0) or (year%100 != 0 and year%4 == 0)

print("Is this year of a leap year ? " + str(isleapyear))

