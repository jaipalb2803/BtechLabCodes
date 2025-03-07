use strict;
use warnings;

#push operation
print "Enter no.of the push ele=";
my $n1=<STDIN>;
my @a=();
for(my $i=1;$i<=$n1;$i++){
    print "push ele=";
    my $ele=<STDIN>;
    push(@a,$ele);
}
print "Original list:\n";
print @a;

#pop operation
print "Enter no.of the pop ele=";
my $n2=<STDIN>;
for(my $i=1;$i<=$n2;$i++){
    print "pop ele=",pop(@a);
}
print "Updated list:\n";
print @a;

#unshift operation
print "Enter no.of the unshift ele=";
my $n3=<STDIN>;
for(my $i=1;$i<=$n3;$i++){
    print "push ele=";
    my $ele=<STDIN>;
    unshift(@a,$ele);
}
print "Updated list:\n";
print @a;

#shift operation
print "Enter no.of the shift ele=";
my $n4=<STDIN>;
for(my $i=1;$i<=$n4;$i++){
    print "shift ele=",shift(@a);
}
print "Updated list:\n";
print @a;

#sort operation
@a= sort @a;
print "sorted list:\n";
print @a;

my $size=@a;
my $maxIndex=$#a;
print"size::$size\n";
print"MaxIndex=$maxIndex\n";

splice(@a,1,2,1..2);
print"splice:\n";
print @a;

print "Enter the input string=";
my $s1=<STDIN>;
my @str1 = split('-', $s1);
print "spitted::@str1";

my $str2=join('-',@str1);  
print "joined::$str2";

my @merge=(@a,@str1);
print "merged::\n";
print @merge;
