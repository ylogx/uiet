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
*   Tab width is mentioned in everyfile. Use spaces instead of tabs, 4 spaces in place of one tab.
    Also keep removing trailing whitespaces.
    CodeBlocks: Setting > Editor > General Setting:
        1. Untick use tab
        2. set tab size as 4 spaces
        3. tick strips trailing spaces
    It's expected from you to follow same coding style as of surrounding code.
*   CodeBlocks: Setting > Editor > Margin & Crates:
        1. Right Margin Hint > visible line
    Try to keep your code shorter than this line.
*   Please use this international notation for function 
        void foo ( char ch ) {
            //bla bla
        }//end foo
        
        if ( cond ) {
            //bla bla
        }else{
            //bla2 bla2
        }//end if
    instead of
        void foo(char ch)
        {
            //bla bla
        }
        
        if(cond)
        {
        }
        else
        {
        }
    or anything else.
    Easy to read and stops wastage of lines and scrolling.
*   The name of a class will always start with a capital letter e.g Student, Account.   //NEW
*   Use '\n' for newline instead of endl. WHY: endl slows the program
*   Please Please Please set tab width in your editor as 4 spaces
    & tick the 'use spaces instead of tab' option also

--------------------------------- F A Q ----------------------------------------

//NEW
Q.  Why there are so many files?
A.  It's a standard, so we will follow it. You don't need to bother yourself with
    the details. Write contents in the files as mentioned in What goes Where section,
    and compile the canteen.cpp after saving all the files.

Q.  Where do I compile and run these files ?
A.  No matter what your OS is use of codeblocks (www.codeblocks.org) is highly recommended.
    Download or get one from your friend before making any change to any file.
    DON'T use a compiler which is not able to run these files as they are packed.

//NEW
Q.  What goes Where ?
A.  => main.cpp     -   try to keep it as neat as possible. 
                        this is the file you need to compile, build and run.
    => function.h   -   this will contain all the declarations for any function
    => function.cpp -   this will contain all the definitions for all independent functions
    
    Moreover there will be two files for "each and every class". for example
    => Student.h    -   this will contain the class declaration
    => Student.cpp  -   this will constain definition of all the class's functions
    remember class names start with a capital letter.

//NEW
Q.  I'm getting errors when I compile. What should I do ?   
A.  You should not face this error in codeblocks no matter what you're using linux or windows.
    You don't need to read any more of this question if you're using codeblocks.
    However I tried to correct that. Follow these steps for compiler other than codeblocks:
    1. There is a //#define WINDOWS in each file. Uncomment it.
    2. Uncomment #define LINUX and you will be able to run it on windows (codeblocks).
    XXX This is not at all recommended. Pleaase get codeblocks.

Q.  When will I  get changes made by other team members?
A.  As soon as someone submits their codes I will merge them and mail all of you
    new files with a file containing change summary.
    NOTE: Please make sure that you're working on the LATEST available files, if you submit
          changes that you made in an older version, it will be really difficult to merge them
          with the current version. So stay up-to-date when adding something new.

Q.  I've question that maybe useful for other also. What do I do?
A.  Simple - Add them here.
    Tell other, Ask other, Help other if you find something that isn't mentioned
    here.

______________________________ Happy Coding ______________________________________
