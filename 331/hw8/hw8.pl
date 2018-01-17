#!/usr/bin/perl

my $beginCheck = <STDIN>;
my $ident = '[:_A-Za-z][:A-Za-z0-9\._]*';
chomp $beginCheck;
#checks to make sure its a baby-xml file or dies
if(not ($beginCheck eq "<\?xml version=\"1.0\"\?>")){
    print "$beginCheck";
    die("Not a baby-XML file");
}
my $lineCount = 2;
my $input = "";
my @stack = ();
my $size = @stack;
my $bool = 0;
#looping through inputs
while($input = <STDIN>){
    $size = @stack;
    #ends input when the input is a newline character
    if($input eq "\n"){
	last;
    }
    chomp $input;
    #start tag
    if($input =~ m/<($ident)>/){
	#indents lines
	for(my $i = 0; $i < ($size); $i++){
	    print "  ";
	}
	$bool = 1;
	print "$lineCount: OPEN $1\n";
	push(@stack, $1);
    }
    $size = @stack;
    #end tag
    if($input =~ m/<\/($ident)>/){
	#indents lines
	for(my $i = 0; $i < ($size-1); $i++){
	    print "  ";
	}
	#check if correct tag is being popped
	my $check = pop(@stack);
        if(not($check eq $1)){
	    die("$lineCount: close tag \"$1\" doesn't match current open tag \"$check\".\n");
	   
	}
	print "$lineCount: CLOSE $1\n";
	$bool = 1;
    }
    #if input doesn't match anything
    if(not($bool)){
	$bool = 0;
	print "Not Valid Input\n";
    }    
    $lineCount += 1;
}
$size = @stack;
my $tags = "";
#if there are open tags left in the stack, dies with output
if($size){
    $tags = "End of file with still-open tags: ";
    for(my $i = 0; $i < $size; $i++){
	$tags = $tags . "$stack[$i]";
	if($i == ($size-1)){
	    $tags = $tags . ".\n";
	}
	else{
	    $tags = $tags . ", ";
	}
    }
    die("$tags");
}



