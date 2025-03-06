import datetime
import calendar
import os
while(1):
   today=datetime.datetime.now()
   yy=int(today.strftime('%Y'))
   mm=int(today.strftime('%m'))
   dd=int(today.strftime('%d'))
   print(calendar.month(yy,mm)) 
   print("today's date           :", datetime.date.today())
   print('month from current date:', today.strftime('%B'))
   print('day from current date  :', today.strftime('%A'))
   print("current time is        :",end="")
   print(today.strftime('%I:%M:%S'))
   os.system('cls')

