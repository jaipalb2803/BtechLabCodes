use strict;
use warnings;
#The quick brown fox jumps over the lazy dog


print "enter the string=";
my $org=<>;
print "enter the word=";
my $word=<>;
print "enter the replace=";
my $replace=<>;
chomp($o,$w,$r);
$org=~s/$word/$replace/g;
print $o;

