use strict;
use warnings;

print "Enter the num-1=";
chomp (my $n1=<STDIN>);
print "Enter the num-2=";
chomp (my $n2=<STDIN>);
print "Enter the num-3=";
chomp (my $n3=<STDIN>);

if ($n1>$n2 && $n1>$n3){
      print "$n1 is greatest number.";
}
elsif ($n2>$n1 && $n2>$n3){
      print "$n2 is greatest number.";
}
elsif ($n1==$n2 && $n1==$n3){
      print "All are equal.";
}
else{
      print "$n3 is greatest number.";
}