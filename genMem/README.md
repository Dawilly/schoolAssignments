# schoolAssignments

## Old software assignments when studying at The University of Alabama.

### GenMem

Generates memory files for the Memory Cache Simulator assignment in Embedded System.

### Usage

The command syntax is:  
./genMem -A LINEAMOUNT -O=FILENAME -M MMBYTES [-s SEED]  
  
-A LINEAMOUNT sets the amount of commands to generate.  
-O=FILENAME targets the provided FILENAME to save the generated memory.  
-M MMBYTES sets the Main Memory size. (Must be to the power of 2)  
-s SEED (Optional) sets the seed for generation.  
