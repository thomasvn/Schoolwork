#!/usr/bin/perl
use strict;
use vars qw ($foo); # declares $foo as package global in the current package.

$foo = "a";

print "\$foo = $foo\n"; # prints "global value"

# Whenever called, forces $foo to be variable from global frame
print "staticScope result '", staticScope(), "'\n"; # prints "a"

# Whenever called, allows $foo to be variable from caller's frame
print "dynamicScope result '", dynamicScope(), "'\n"; # prints "b"


sub staticScope {
    my $foo = "b";
    showfoo();
}

sub dynamicScope {
    local $foo = "c";
    showfoo(); # ALWAYS prints "local value"
}

sub showfoo {
    return $foo;
}


# ---- Dynamic Scoping in this chapter vs Dynamic Scoping in Perl ----
# Chapter:
#       - Dynamic scoping is based on the calling sequence of subprogram,
#         not on their spatial relationship to each other. Thus, scope can
#         only be determined at run time
#
# Perl:
#       - When you declare a variable to be "local", you save away the old value
#         of the global variable and assign it a new value for the duration
#         of the subroutine.
#
