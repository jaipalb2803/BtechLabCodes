use strict;
use warnings;

my $filename = $ARGV[0];

open(my $fh, "<", $filename) or die "Could not open file '$filename' $!";

my @lines = <$fh>;
close($fh);

for my $line (reverse @lines) {
    print scalar reverse("$line");
}
