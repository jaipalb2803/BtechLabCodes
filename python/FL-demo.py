#python write
with open("file1.py",mode='w') as f:
  f.write("hello world ! I am python.")
f.close()
#python append
f=open("file1.txt",mode='a')
f.write("\nyou know ? I am easiest language.")
f.close()

#python read from file1
try:
  f=open("file1.py",mode='r')
  d=f.readlines()
  print(d)
finally:
  f.close()
#python read from file1
file_obj = open("file1.txt", "r", encoding="utf-8")
print(file_obj.read()) #read(5) char upto 5 char
file_obj.close()
#python read from file1
file_obj = open("file1.txt", "r")
for line in file_obj:
  print(line)
file_obj.close()

#python read from bin_file1
f = open("file.txt", "wb")
nums = [1, 2, 3, 4, 5]
arr = bytearray(nums)
f.write(arr)
f.close()





