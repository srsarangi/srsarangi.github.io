#!/usr/bin/perl

use strict;
use Data::Dumper;

# usage
my $len = $#ARGV + 1;
if($len < 2) {
    die ("Usage sub.pl <name of the file> <replacement file> [highlight] [output_file] \n");
}

my $main_file = $ARGV[0];
my $repl_file = $ARGV[1];

print "The main file is $main_file \n";
print "The replacement file is $repl_file \n";

# check for extra arguments
my ($highlight, $write_file, $write_file_exists);
$write_file_exists = 0;
$highlight = -1;
if($len >= 3) {
  $highlight = $ARGV[2]; 
}
if($len >= 4) {
    $write_file = $ARGV[3];
    $write_file_exists = 1;
}

## check if the main file is correct
if($main_file !~ m/template/) {
    die("$main_file should have a template keyword inside it \n");
}

## read the entire replacement file
open(FH, "<$repl_file") or die("$repl_file does not exist \n");
my $repl_text = "";
my $line;
while($line = <FH>) {
    $repl_text = $repl_text.$line; 
}
close(FH);

## create the name of the file to write to
if($write_file_exists == 0) {
    $write_file = $main_file;
    $write_file =~ s/template\.//g;
}
print "write file is ".$write_file."\n";

## scan the template
my $SIDEBAR = "sidebar goes here";
my $HIGHLIGHT = "highlight";
my $write_str = "";
open(FH, "<$main_file") or die ("$main_file does not exist");
my $side_flag = 0;
while(my $line = <FH>) {
    if($line =~ m/$SIDEBAR/) {
        $side_flag = 1;
# find the highlight marker
        if($line =~m/$HIGHLIGHT[ ]*([0-9]+)/) {
            $highlight = $1 if ($highlight == -1);
            # change the text
            my @parts = split(/\n/, $repl_text);
            my $part;
            my $new_text= "";
            my $changed = 0;
            foreach $part (@parts) {
                if($part =~ m/accesskey=\"$highlight\"/) {
                    $changed = 1;
                    my $new_part = $part;
                    $new_part =~ s/<li>/<li class="first active">/g;
                    $new_text = $new_text.$new_part."\n";
                } else {
                    $new_text = $new_text.$part."\n";
                }
            }
            $repl_text = $new_text if ($changed == 1);
        }
# write the text
        $write_str = $write_str.$repl_text."\n";
    } else {
        $write_str = $write_str.$line;
    }
}
close(FH);

## see if the marker was found
if($side_flag == 0) {
    die("$SIDEBAR : text was not found in $main_file \n");
}

## write the flag
open(FH, ">$write_file");
print FH $write_str."\n";
close(FH);
print "Finished writing to file $write_file \n";
