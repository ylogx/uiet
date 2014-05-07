READ THIS BEFORE YOU MAKE ANY CHANGES TO THE FILES

This is a set of instructions you need to follow while developing as a team.

*   Think before you type
*   When in doubt, ASK. Don't assume anything to work itself.
*   change-logs are IMPORTANT, very Important, try to be as detailed as possible.
*   Seperate the sections with //*** or //--- or whatever you like.
*   Don't make any change in the section someone else wrote. If you do mention
    it seperatly in changelog.
*   Don't add useless new-lines because that will create problem
    while merging changes that you will submit.
*   Tab width is mentioned in everyfile. It's expected from you to follow same
    coding style as of surrounding.

--------------------------------- F A Q ----------------------------------------

Q.  Why there are three files?
A.  It's a standard, so we will follow it. You don't need to bother yourself with
    the details. Write contents in the files as mentioned in What goes Where section,
    and compile the canteen.cpp after saving all the files.

Q.  Where do I compile and run these files ?
A.  No matter what your OS is use of codeblocks (www.codeblocks.org) is highly recommended.
    Download or get one from your friend before making any change to any file.
    DON'T use a compiler which is not able to run these files as they are packed.

Q.  What goes Where ?
A.  => canteen.cpp - try to keep it as neat as possible
    => declarations.h - this will contain all the declarations for anything from a
       class to a structure,
    => definitions.cpp - this will contain all the definitions for "everything" you
       declared in declarations.h

Q.  I'm getting errors when I compile. What should I do ?
A.  You should not face this error in codeblocks.
    However I tried to correct that. Follow theese steps:
    1. There is a //#define WINDOWS in each file. Uncomment it.
    2. Uncomment #define LINUX and you will be able to run it on windows (codeblocks).
    XXX This isnot at all recommended. Pleaase get cfodeblocks.

Q.  When will I  get changes made by other team members?
A.  As soon as someone submits their codes I will merge them and mail all of you
    new files with a file containing change summary.

Q.  I've question that maybe useful for other also. What do I do?
A.  Simple - Add them here.
    Tell other, Ask other, Help other if you find something that isn't mentioned
    here.

______________________________ Happy Coding ______________________________________
