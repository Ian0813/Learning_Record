#! /usr/bin/python3


'''

Problem : 
    Compute the price of ex-rights or ex-dividend.

Description : 
    After ex-rights or ex-dividend, the share price must subtract to a value of ex-rights or a value of e    x-dividend.
'''

share_price = int(input("Please enter a current share price : "))

par_value = int(input("Plese enter the par value : "))



#exclude rights
stock_dividend = float(input("Please enter the stock dividend value : "))

#exclude dividend
cash_dividend = float(input("Please enter the dividend value : "))

print("After ex-dividend : " + str(share_price - cash_dividend))

print("After ex-rights : " + str(share_price/(1+stock_dividend/par_value)))

print("After ex-rights and ex-dividend : " + str((share_price-cash_dividend)/(1+stock_dividend/par_value)))
