import datetime as dt 
t=dt.date.today() 
y=t-dt.timedelta(days=1) 
to=t+dt.timedelta(days=1) 
print("Today:",t,"\nYesterday:",y,"\nTomorrow:",to) 
