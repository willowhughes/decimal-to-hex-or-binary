# decimal-to-hex-or-binary
This C program, convert.c, is designed to automate the conversion of decimal integers to either hexadecimal or binary representations. The program takes command-line arguments and prints the corresponding representations based on the specified format.

Command Line Arguments
The program uses argc and argv in the main function to handle command-line arguments. The first parameter, argv[0], is the name of the executable file.

int main(int argc, char* argv[])
Parsing Command Line Arguments
The program uses the getopt function for parsing command-line arguments. More information about getopt can be found by typing man 3 getopt in the Unix command line or following this link.
