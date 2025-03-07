#variable in TCL------------------(1)
set a 12
set b "Jai"
set c 2.3
set a1 $a
set exp1 [expr $a+12]
puts $exp1
puts -nonewline " This is "
puts "Tcl Demo"

#if-else in TCL------------------(2)
set a2 5
if {$a2 > 10} {
    puts "Greater than 10" 
}else{
    puts "Lesser than 10"
}

#while in TCL--------------------(3)
set a3 0
while {$a3 < 10} {
    puts $a3
    # a3=$a3+2
    set a3 [expr $a3 + 2]
}

#for loop in TCL-----------------(4)
for {set a4 1} {$a4 < 11} {incr a4} {
     #puts $a4
}
for {set a4 1} {$a4 < 11} {set a4 [expr $a4+1]} {
    puts $a4
}

#Array & list in TCL-------------------(5)
set a5(0) 11
set a5(1) 12
set a5(2) 13
puts $a5(0)
puts $a5(1)
set salary("john") 20000
set salary("raj")  50000
puts  $salary("raj")

set List1 [list "apple" "banana" "cherry"]
lappend List1 "mango" "orange"
puts [llength $list1]
puts [lindex $list1 0]
set List1 [linsert $list1 1 lemon]
puts $List1
set List1 [lreplace $list1 1 banana]
puts $List1
set List1 [lsort $list1]
puts $List1
set List2 [split "grape-honeydew" -]
set concList [concat $List1 $List2]
puts "Concatenated list: $concList"


#procedure no return in TCL-----------------(6)
proc max {a b} {
if {$a > $b} {
    puts $a
}else{
    puts $b
 }    
}
max 23 45 

#procedure with return type in TCL-----------(7)
#CASE 1:Single Return values
proc sum {a b c} {
  set c [expr $a+$b+$c]
  return $c
}
set x [sum 12 23 34]
puts $x 

#CASE 2:Multiple Return values
proc fun {} {
  return [list 23 45 67 89]
}
set x [fun]
puts $x 

#global v/s local in TCL----------------(8)
set x 10
proc fun {} {
  global x  
  set x 12
  puts $x   
}
puts $x
fun
puts $x 

#File handling in TCL------------------(9)
#File Mode: r w a r+ w+
set f [open "one.txt" w+]
puts $f "Jntuh collage,Sultanpur"
close $f
puts "success to w+"
set f [open "one.txt" r]
gets $f d
puts $d
close $f  

//::Example:://
set f1 [open "one.txt" w]
puts "Enter the no of line:"
set num [gets stdin]
puts "Enter the Data:"
for {set i 1} {$i <= $num} {set i [expr $i+1]} {
    set line [gets stdin]
    puts $f1 $line
}
puts "success to written"
close $f1 
set f3 [open "one.txt" r]
set f2 [open "two.txt" w]
gets $f3 line
while {![eof $f3]} {
    puts $f2 $line
    gets $f3 line
}
puts "success to copied"
close $f2  
close $f3   

#Class & Object in TCL------------------(10)
Class Student 

Student instproc  show {} {
    $self instvar name roll city
    puts "Name:$name"
    puts "Rollno:$rollno"
    puts "City:$city"
}
Student Ob1
Ob1 set name "jai"
Ob1 set rollno 506
Ob1 set  city  "Hyd"
Ob1 show
puts [Ob1 set name]
puts [Ob1 set rollno]
puts [Ob1 set city]

#Constructor in TCL------------------(11)
Class Student 

Student instproc  show {} {
    $self instvar name roll city
    puts "Name:$name"
    puts "Rollno:$rollno"
    puts "City:$city"
}
Student instproc  init {} {
    set name "default"
    set rollno 000
    set  city  "nill"
}
Student Ob1
Ob1 show

#Destructor in TCL------------------(12)
Class Student 
Student instproc destroy {} {
    puts "Destructor called"
}
Student Ob1
Ob1 destroy
