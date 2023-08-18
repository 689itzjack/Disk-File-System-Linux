Author: Ytzhak Ariel Armoni 

I simulated the role of the disk management system in the operating system Linux, that is, 
to map all parts of the file that are stored on the disk. The parts of the file are saved 
in small units which are called 'blocks' and are organized into one logical unit, that is the file. 
 
The parts of the file are not directly and continuously on the disk but are scattered over the 
surface of the disk. 

I have simulated this action programming with the C++ language in the VMware using the OS Linux, 
executing the cpp file and using the command line to use the program. 

The commands are the next: PRESS THE NEXT BUTTONS ON YOUR KEYBOARD WHEN THE PROGGRAM ITS RUNNING:

0: WHEN YOU PUSH THE NUMBER 0 DELETE ALLL THE DISK
1: WHEN YOU PUSH THE NUMBER 1 YOU PRINT ALL THE FILES ACCORDING THE FILES, EVERY ONE.
2: WHEN YOU PUSH THE NUMBER 2 START THE DISK AND THEN PUT IN THE BLOCK SIZE THAT YOU WANT
3: WHEN YOU PUSH THE NUMBER 3 CREATE A NEW FILE 
4: WHEN YOU PUSH THE NUMBER 4 THE WILL OPEN A FILE THAT YOU CLOSED BEFORE
5: WHEN YOU PUSH THE NUMBER 5 THE WILL CLOSE A FILE ACCORDING THE FILE NAME THAT YOU GIVED 
6: WHEN YOU PUSH THE NUMBER 6 THE WILL WRITE DATA TO THE DISK
7: WHEN YOU PUSH THE NUMBER 7 THE WILL READ DATA FROM THE DISK ACOORDING THE SIZE YOU GIVED
8: WHEN YOU PUSH THE NUMBER 8 THE WILL CLOSE A FILE DEFINITIVELY

Instructions:
Every time that we run the program, we will put in every time data according the instructions 
that every step its idicated in the program.

How to compile the ṕrogram: 

when you access to the main program push the button green hammer, and then will be compiled.

In the terminal:

g++ Disk.cpp -o Disk

Terminal will be reused by tasks, press any key to close it.

>>means that the program was compiled successfully!.

How to run the program:
WITH: ./Disk (at the terminal)

Press the green play button and then will appears an screen where the output will appear there.

The programm is distributed in JUST ONE FILE. 

Output expected:(The input must to do it in the terminal)the number pointed out with >> are the output the other numberes are the input.

Starting Program...
Disk started, please format the Disk.
2
4
FORMAT DISK: number of blocks: 64
3
JAYA 
CreateFile: JAYA with File Descriptor #: 0
3
MIRI
CreateFile: MIRI with File Descriptor #: 1
3
IMA
CreateFile: IMA with File Descriptor #: 2
3
PAPA
CreateFile: PAPA with File Descriptor #: 3
3
KORKI
CreateFile: KORKI with File Descriptor #: 4
3
ZURI
CreateFile: ZURI with File Descriptor #: 5
3
MARIO
CreateFile: MARIO with File Descriptor #: 6
3
PEPA
CreateFile: PEPA with File Descriptor #: 7
3
TINITO
CreateFile: TINITO with File Descriptor #: 8
3
SULLY
CreateFile: SULLY with File Descriptor #: 9
3
ABU
CreateFile: ABU with File Descriptor #: 10
3
BOND
CreateFile: BOND with File Descriptor #: 11
3
FANY
CreateFile: FANY with File Descriptor #: 12
6
0
QUIEROIRMEDECASA
==150789== Conditional jump or move depends on uninitialised value(s)
==150789==    at 0x10ACA9: seek_free_block_in_BitVector(int*, int) (in /home/student/Desktop/marajot afala shana dalet/ExFinal/Disk)
==150789==    by 0x10D527: fsDisk::writing_to_DISK(int, int, char*, int) (in /home/student/Desktop/marajot afala shana dalet/ExFinal/Disk)
==150789==    by 0x10DA00: fsDisk::WriteToFile(int, char*, int) (in /home/student/Desktop/marajot afala shana dalet/ExFinal/Disk)
==150789==    by 0x10B392: main (in /home/student/Desktop/marajot afala shana dalet/ExFinal/Disk)
==150789== 
Written 16 Chars into file descriptor #: 0
6
1
ELLESBOLBASAUR
Written 14 Chars into file descriptor #: 1
6
2
MAMIESMIYUMOTO
Written 14 Chars into file descriptor #: 2
6
3
PAPAESTASUPERFAT
Written 16 Chars into file descriptor #: 3
6
4
SOYSUPERCHIDO
Written 13 Chars into file descriptor #: 4
6
5
TEQUIERONINATERCA
WARNING! The space is not enough to write all the data.
Space enough just for: 16 chars of data.
Written 16 Chars into file descriptor #: 5
6
6
SOSUNACHICALEY
Written 14 Chars into file descriptor #: 6
6
7
MARIANAHEURTAERDA
WARNING! The space is not enough to write all the data.
Space enough just for: 16 chars of data.
Written 16 Chars into file descriptor #: 7
6
8
TASBIENIDOHERMANOS
WARNING! The space is not enough to write all the data.
Space enough just for: 16 chars of data.
Written 16 Chars into file descriptor #: 8
6
9
LAABUELAESRECODA
Written 16 Chars into file descriptor #: 9
6
10
MATAALOSAGENTES
Written 15 Chars into file descriptor #: 10
1
index: 0: FileName: JAYA , isInUse: 1
index: 1: FileName: MIRI , isInUse: 1
index: 2: FileName: IMA , isInUse: 1
index: 3: FileName: PAPA , isInUse: 1
index: 4: FileName: KORKI , isInUse: 1
index: 5: FileName: ZURI , isInUse: 1
index: 6: FileName: MARIO , isInUse: 1
index: 7: FileName: PEPA , isInUse: 1
index: 8: FileName: TINITO , isInUse: 1
index: 9: FileName: SULLY , isInUse: 1
index: 10: FileName: ABU , isInUse: 1
index: 11: FileName: BOND , isInUse: 1
index: 12: FileName: FANY , isInUse: 1
Disk content: '
(=)(>)(?)(@)(A)(B)(C)(D)(E)(F)(G)(H)(I)(J)(K)(L)(M)(N)(O)(P)(Q)(R)(S)(T)(U)(V)(W)(X)(Y)(Z)([)(\)(])(^)(_)(`)(a)(b)(c)(d)(e)(f)(g)(h)()()()()()()()()(Q)(U)(I)(E)(R)(O)(I)(R)(M)(E)(D)(E)(C)(A)(S)(A)(E)(L)(L)(E)(S)(B)(O)(L)(B)(A)(S)(A)(U)(R)()()(M)(A)(M)(I)(E)(S)(M)(I)(Y)(U)(M)(O)(T)(O)()()(P)(A)(P)(A)(E)(S)(T)(A)(S)(U)(P)(E)(R)(F)(A)(T)(S)(O)(Y)(S)(U)(P)(E)(R)(C)(H)(I)(D)(O)()()()(T)(E)(Q)(U)(I)(E)(R)(O)(N)(I)(N)(A)(T)(E)(R)(C)(S)(O)(S)(U)(N)(A)(C)(H)(I)(C)(A)(G)(A)(Y)()()(M)(A)(R)(R)(A)(N)(A)(P)(U)(E)(R)(C)(A)(C)(E)(R)(T)(A)(S)(B)(I)(E)(N)(M)(A)(M)(I)(T)(A)(N)(E)(N)(L)(A)(A)(B)(U)(E)(L)(A)(E)(S)(R)(E)(C)(O)(D)(A)(M)(A)(T)(A)(A)(L)(O)(S)(A)(G)(E)(N)(T)(E)(S)()()()()()()()()()()()()()()()()()()()()()()()()()()()()()'
6
11
VETECONLOSPOLLOS
Written 16 Chars into file descriptor #: 11
1
index: 0: FileName: JAYA , isInUse: 1
index: 1: FileName: MIRI , isInUse: 1
index: 2: FileName: IMA , isInUse: 1
index: 3: FileName: PAPA , isInUse: 1
index: 4: FileName: KORKI , isInUse: 1
index: 5: FileName: ZURI , isInUse: 1
index: 6: FileName: MARIO , isInUse: 1
index: 7: FileName: PEPA , isInUse: 1
index: 8: FileName: TINITO , isInUse: 1
index: 9: FileName: SULLY , isInUse: 1
index: 10: FileName: ABU , isInUse: 1
index: 11: FileName: BOND , isInUse: 1
index: 12: FileName: FANY , isInUse: 1
Disk content: '
(=)(>)(?)(@)(A)(B)(C)(D)(E)(F)(G)(H)(I)(J)(K)(L)(M)(N)(O)(P)(Q)(R)(S)(T)(U)(V)(W)(X)(Y)(Z)([)(\)(])(^)(_)(`)(a)(b)(c)(d)(e)(f)(g)(h)(i)(j)(k)(l)()()()()(Q)(U)(I)(E)(R)(O)(I)(R)(M)(E)(D)(E)(C)(A)(S)(A)(E)(L)(L)(E)(S)(B)(O)(L)(B)(A)(S)(A)(U)(R)()()(M)(A)(M)(I)(E)(S)(M)(I)(Y)(U)(M)(O)(T)(O)()()(P)(A)(P)(A)(E)(S)(T)(A)(S)(U)(P)(E)(R)(F)(A)(T)(S)(O)(Y)(S)(U)(P)(E)(R)(C)(H)(I)(D)(O)()()()(T)(E)(Q)(U)(I)(E)(R)(O)(N)(I)(N)(A)(T)(E)(R)(C)(S)(O)(S)(U)(N)(A)(C)(H)(I)(C)(A)(G)(A)(Y)()()(M)(A)(R)(R)(A)(N)(A)(P)(U)(E)(R)(C)(A)(C)(E)(R)(T)(A)(S)(B)(I)(E)(N)(M)(A)(M)(I)(T)(A)(N)(E)(N)(L)(A)(A)(B)(U)(E)(L)(A)(E)(S)(R)(E)(C)(O)(D)(A)(M)(A)(T)(A)(A)(L)(O)(S)(A)(G)(E)(N)(T)(E)(S)()(V)(E)(T)(E)(C)(O)(N)(L)(O)(S)(P)(O)(L)(L)(O)(S)()()()()()()()()()()()()'
6
12
CHEWEROTAMAMITA
The Disk is full, please delete files
Written 12 Chars into file descriptor #: 12
1
index: 0: FileName: JAYA , isInUse: 1
index: 1: FileName: MIRI , isInUse: 1
index: 2: FileName: IMA , isInUse: 1
index: 3: FileName: PAPA , isInUse: 1
index: 4: FileName: KORKI , isInUse: 1
index: 5: FileName: ZURI , isInUse: 1
index: 6: FileName: MARIO , isInUse: 1
index: 7: FileName: PEPA , isInUse: 1
index: 8: FileName: TINITO , isInUse: 1
index: 9: FileName: SULLY , isInUse: 1
index: 10: FileName: ABU , isInUse: 1
index: 11: FileName: BOND , isInUse: 1
index: 12: FileName: FANY , isInUse: 1
Disk content: '
(=)(>)(?)(@)(A)(B)(C)(D)(E)(F)(G)(H)(I)(J)(K)(L)(M)(N)(O)(P)(Q)(R)(S)(T)(U)(V)(W)(X)(Y)(Z)([)(\)(])(^)(_)(`)(a)(b)(c)(d)(e)(f)(g)(h)(i)(j)(k)(l)(m)(n)(o)()(Q)(U)(I)(E)(R)(O)(I)(R)(M)(E)(D)(E)(C)(A)(S)(A)(E)(L)(L)(E)(S)(B)(O)(L)(B)(A)(S)(A)(U)(R)()()(M)(A)(M)(I)(E)(S)(M)(I)(Y)(U)(M)(O)(T)(O)()()(P)(A)(P)(A)(E)(S)(T)(A)(S)(U)(P)(E)(R)(F)(A)(T)(S)(O)(Y)(S)(U)(P)(E)(R)(C)(H)(I)(D)(O)()()()(T)(E)(Q)(U)(I)(E)(R)(O)(N)(I)(N)(A)(T)(E)(R)(C)(S)(O)(S)(U)(N)(A)(C)(H)(I)(C)(A)(G)(A)(Y)()()(M)(A)(R)(R)(A)(N)(A)(P)(U)(E)(R)(C)(A)(C)(E)(R)(T)(A)(S)(B)(I)(E)(N)(M)(A)(M)(I)(T)(A)(N)(E)(N)(L)(A)(A)(B)(U)(E)(L)(A)(E)(S)(R)(E)(C)(O)(D)(A)(M)(A)(T)(A)(A)(L)(O)(S)(A)(G)(E)(N)(T)(E)(S)()(V)(E)(T)(E)(C)(O)(N)(L)(O)(S)(P)(O)(L)(L)(O)(S)(C)(H)(E)(W)(E)(R)(O)(T)(A)(M)(A)(M)'
6
4
WEY
Written 3 Chars into file descriptor #: 4
6
12
RICOTA
WARNING! The space is not enough to write all the data.
Space enough just for: 4 chars of data.
The Disk is full, please delete files
5
4
CloseFile: KORKI with File Descriptor #: 4
1
index: 0: FileName: JAYA , isInUse: 1
index: 1: FileName: MIRI , isInUse: 1
index: 2: FileName: IMA , isInUse: 1
index: 3: FileName: PAPA , isInUse: 1
index: 4: FileName: KORKI , isInUse: 0
index: 5: FileName: ZURI , isInUse: 1
index: 6: FileName: MARIO , isInUse: 1
index: 7: FileName: PEPA , isInUse: 1
index: 8: FileName: TINITO , isInUse: 1
index: 9: FileName: SULLY , isInUse: 1
index: 10: FileName: ABU , isInUse: 1
index: 11: FileName: BOND , isInUse: 1
index: 12: FileName: FANY , isInUse: 1
Disk content: '
(=)(>)(?)(@)(A)(B)(C)(D)(E)(F)(G)(H)(I)(J)(K)(L)(M)(N)(O)(P)(Q)(R)(S)(T)(U)(V)(W)(X)(Y)(Z)([)(\)(])(^)(_)(`)(a)(b)(c)(d)(e)(f)(g)(h)(i)(j)(k)(l)(m)(n)(o)()(Q)(U)(I)(E)(R)(O)(I)(R)(M)(E)(D)(E)(C)(A)(S)(A)(E)(L)(L)(E)(S)(B)(O)(L)(B)(A)(S)(A)(U)(R)()()(M)(A)(M)(I)(E)(S)(M)(I)(Y)(U)(M)(O)(T)(O)()()(P)(A)(P)(A)(E)(S)(T)(A)(S)(U)(P)(E)(R)(F)(A)(T)(S)(O)(Y)(S)(U)(P)(E)(R)(C)(H)(I)(D)(O)(W)(E)(Y)(T)(E)(Q)(U)(I)(E)(R)(O)(N)(I)(N)(A)(T)(E)(R)(C)(S)(O)(S)(U)(N)(A)(C)(H)(I)(C)(A)(G)(A)(Y)()()(M)(A)(R)(R)(A)(N)(A)(P)(U)(E)(R)(C)(A)(C)(E)(R)(T)(A)(S)(B)(I)(E)(N)(M)(A)(M)(I)(T)(A)(N)(E)(N)(L)(A)(A)(B)(U)(E)(L)(A)(E)(S)(R)(E)(C)(O)(D)(A)(M)(A)(T)(A)(A)(L)(O)(S)(A)(G)(E)(N)(T)(E)(S)()(V)(E)(T)(E)(C)(O)(N)(L)(O)(S)(P)(O)(L)(L)(O)(S)(C)(H)(E)(W)(E)(R)(O)(T)(A)(M)(A)(M)'
8
KORKI
Deleting Finished Successfully
DeletedFile: KORKI with Index Main Directory #: 4
6
12
MAMITA
WARNING! The space is not enough to write all the data.
Space enough just for: 4 chars of data.
Written 4 Chars into file descriptor #: 12
1
index: 0: FileName: JAYA , isInUse: 1
index: 1: FileName: MIRI , isInUse: 1
index: 2: FileName: IMA , isInUse: 1
index: 3: FileName: PAPA , isInUse: 1
index: 4: FileName: ZURI , isInUse: 1
index: 5: FileName: MARIO , isInUse: 1
index: 6: FileName: PEPA , isInUse: 1
index: 7: FileName: TINITO , isInUse: 1
index: 8: FileName: SULLY , isInUse: 1
index: 9: FileName: ABU , isInUse: 1
index: 10: FileName: BOND , isInUse: 1
index: 11: FileName: FANY , isInUse: 1
Disk content: '
(=)(>)(?)(@)(A)(B)(C)(D)(E)(F)(G)(H)(I)(J)(K)(L)(M)(A)(M)(I)(Q)(R)(S)(T)(U)(V)(W)(X)(Y)(Z)([)(\)(])(^)(_)(`)(a)(b)(c)(d)(e)(f)(g)(h)(i)(j)(k)(l)(m)(n)(o)(4)(Q)(U)(I)(E)(R)(O)(I)(R)(M)(E)(D)(E)(C)(A)(S)(A)(E)(L)(L)(E)(S)(B)(O)(L)(B)(A)(S)(A)(U)(R)()()(M)(A)(M)(I)(E)(S)(M)(I)(Y)(U)(M)(O)(T)(O)()()(P)(A)(P)(A)(E)(S)(T)(A)(S)(U)(P)(E)(R)(F)(A)(T)()()()()()()()()()()()()()()()()(T)(E)(Q)(U)(I)(E)(R)(O)(N)(I)(N)(A)(T)(E)(R)(C)(S)(O)(S)(U)(N)(A)(C)(H)(I)(C)(A)(G)(A)(Y)()()(M)(A)(R)(R)(A)(N)(A)(P)(U)(E)(R)(C)(A)(C)(E)(R)(T)(A)(S)(B)(I)(E)(N)(M)(A)(M)(I)(T)(A)(N)(E)(N)(L)(A)(A)(B)(U)(E)(L)(A)(E)(S)(R)(E)(C)(O)(D)(A)(M)(A)(T)(A)(A)(L)(O)(S)(A)(G)(E)(N)(T)(E)(S)()(V)(E)(T)(E)(C)(O)(N)(L)(O)(S)(P)(O)(L)(L)(O)(S)(C)(H)(E)(W)(E)(R)(O)(T)(A)(M)(A)(M)'
1
index: 0: FileName: JAYA , isInUse: 1
index: 1: FileName: MIRI , isInUse: 1
index: 2: FileName: IMA , isInUse: 1
index: 3: FileName: PAPA , isInUse: 1
index: 4: FileName: ZURI , isInUse: 1
index: 5: FileName: MARIO , isInUse: 1
index: 6: FileName: PEPA , isInUse: 1
index: 7: FileName: TINITO , isInUse: 1
index: 8: FileName: SULLY , isInUse: 1
index: 9: FileName: ABU , isInUse: 1
index: 10: FileName: BOND , isInUse: 1
index: 11: FileName: FANY , isInUse: 1
Disk content: '
(=)(>)(?)(@)(A)(B)(C)(D)(E)(F)(G)(H)(I)(J)(K)(L)(M)(A)(M)(I)(Q)(R)(S)(T)(U)(V)(W)(X)(Y)(Z)([)(\)(])(^)(_)(`)(a)(b)(c)(d)(e)(f)(g)(h)(i)(j)(k)(l)(m)(n)(o)(4)(Q)(U)(I)(E)(R)(O)(I)(R)(M)(E)(D)(E)(C)(A)(S)(A)(E)(L)(L)(E)(S)(B)(O)(L)(B)(A)(S)(A)(U)(R)()()(M)(A)(M)(I)(E)(S)(M)(I)(Y)(U)(M)(O)(T)(O)()()(P)(A)(P)(A)(E)(S)(T)(A)(S)(U)(P)(E)(R)(F)(A)(T)()()()()()()()()()()()()()()()()(T)(E)(Q)(U)(I)(E)(R)(O)(N)(I)(N)(A)(T)(E)(R)(C)(S)(O)(S)(U)(N)(A)(C)(H)(I)(C)(A)(G)(A)(Y)()()(M)(A)(R)(R)(A)(N)(A)(P)(U)(E)(R)(C)(A)(C)(E)(R)(T)(A)(S)(B)(I)(E)(N)(M)(A)(M)(I)(T)(A)(N)(E)(N)(L)(A)(A)(B)(U)(E)(L)(A)(E)(S)(R)(E)(C)(O)(D)(A)(M)(A)(T)(A)(A)(L)(O)(S)(A)(G)(E)(N)(T)(E)(S)()(V)(E)(T)(E)(C)(O)(N)(L)(O)(S)(P)(O)(L)(L)(O)(S)(C)(H)(E)(W)(E)(R)(O)(T)(A)(M)(A)(M)'
0

PROGRAM FINISHED!!!


