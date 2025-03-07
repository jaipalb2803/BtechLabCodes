use strict;
use warnings;

print "Enter email:";
my $email=<STDIN>;
my @username=split '@',$email;
if(($username[1])=~/gmail.com/){
    print "Valid email\n";
}else{
    print "Email not valid\n";
}

print "Enter ip address:";
my $ip=<STDIN>;
my $ipValid = 1;
foreach my $octet (split(/\./, $ip)) {
    if ($octet < 0 || $octet > 255) {
        $ipValid = 0;
        last;
    }
}
if ($ipValid) {
    print "Valid IP address\n";
} else {
    print "Not a valid IP address\n";
}

#script-2
#!/usr/bin/perl
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

print "Enter ip address=";
my $ip=<STDIN>;
if ($ip=~m/^(\d\d?\d?)\.(\d\d?\d?)\.(\d\d?\d?)\.(\d\d?\d?)$/){
      if($1<=255 && $2<=255 && $3<=255 && $4 <=255){
            print "valid\n";
      }else{
            print "invalid\n";
     }
}
else{
      print "invalid\n";
}