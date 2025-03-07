use strict;
use warnings;

sub print_multiplication_table {
    my ($num) = @_;
    for my $i (1..10) {
        my $res=$num*$i;
        print "$num x $i = $res\n";
    }
}

for my $i (1..10) {
    print_multiplication_table($i);
    print "\n";
}
