import datetime

localtime= datetime.datetime.now()
print('local time: ', localtime)

import datetime

print("today's date: ", datetime.date.today())
import datetime

todaydatetime = datetime.datetime.now()

print('current date and time: ', todaydatetime)
print('fetched out year from current date: ', todaydatetime.strftime('%Y'))
print('fetched out month from current date: ', todaydatetime.strftime('%B'))
print('fetched out day from current date: ', todaydatetime.strftime('%A'))
print('formatted the time from above generated date time: ', todaydatetime.strftime('%H:%M:%S'))
print('formatted both date and time: ',todaydatetime.strftime("%d/%m/%Y, %H:%M:%S"))
print("")
import datetime

currentdate = datetime.date.today()
print('current date: ', currentdate)
import datetime

currentdate = datetime.datetime.now()

print('raw current date and time generated', currentdate)
print('current date formatted from date and time', 
currentdate.strftime("%d/%m/%Y"))
import datetime

timestamp = datetime.datetime.now()

print('current date and time', timestamp)
print('current timestamp', timestamp.timestamp())
