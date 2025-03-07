import sqlite3

#Open database
conn=sqlite3.connect("record.db") 

#create table 
c=conn.cursor()
#c.execute("CREATE TABLE person(pid INTEGER PRIMARY KEY,pname VARCHAR(50),age INTEGER)")

#insert record
"""c.execute("INSERT INTO person VALUES(01,'Ram',19)")
c.execute("INSERT INTO person VALUES(02,'Raj',20)")
c.execute("INSERT INTO person VALUES(03,'Roy',21)")"""

#extract record
c.execute("SELECT * FROM person")
print("Extracted Data:")
for row in c.fetchall():
    print(row)
conn.commit()
conn.close()    
