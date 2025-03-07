use strict;
use warnings;

print "Enter the email=";
my $email=<STDIN>;
if ($email=~m/^[a-zA-Z0-9]+@[a-zA-Z0-9]*\.[a-zA-z]{2,}$/){
      print "valid\n";
}
else{
      print "invalid\n";
}