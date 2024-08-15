######################   Tested Configurations  ##########################

        +----------------+-----------------------------------------------------------------------+
        | Platform       | Versions                                                              |
        +----------------+-----------------------------------------------------------------------+
        | Linux          | Ubuntu 18.04                                                          |
        |                | Ubuntu 16.04 Kernel version 3.13.5-031305-generic gcc version 4.8.5   |
        |                | Ubuntu 14.04                                                          |
        |                | Ubuntu 12.04                                                          |
        | Windows        | Windows 7 (64-bit)                                                    |
        | Mac            | OS X 10.10 (Yosemite)                                                 |
        +----------------+-----------------------------------------------------------------------+

######################      Linux      ##########################

--> Pre-installation instructions:

    1. Tested PIN versions: pin-2.14-67254-gcc.4.4.7-linux, pin-2.14-62732, pin version 3.7 kit 9761.
    2. Run the command "echo 0 > /proc/sys/kernel/yama/ptrace_scope" as the root user. You need to run this command each time you reboot the system.
    3. Install 
         a. Java: Install both: JDK and JRE (openjdk8)
         b. ant: Used to compile Java files
         c. python 3.x
         d. zlib library (can install using apt-get utility on Ubuntu)
         e. hg (if you want to use the repository)

--> Trouble shooting:

    1. If you get an error saying "jni.h/jni_md.h not found", the installation script is not able to locate the folder where these two files are stored. 
       Locate and add this folder to the jniInclude variable (line number 152) in install_tejas.py. 
       Hint: "jni.h" and "jni_md.h" are generally stored in the "include" folder of your JDK's home directory.
    2. If the error message is of the form:
           E: Attach to pid XXYYZZ failed.
           E: The Operating System configuration prevents Pin from using the default (parent) injection mode.
           E: To resolve this, either execute the following (as root):
           E: $ echo 0 >/proc/sys/kernel/yama/ptrace_scope
           E: Or use the "-injection child" option.
           E: For more information, regarding child injection, see Injection section in the Pin User Manual.
        Run the command "echo 0 > /proc/sys/kernel/yama/ptrace_scope" as the root user (see Step 2 of Pre-installation instructions).

######################      Windows      ##########################

--> Pre-installation instructions

    1. Tested PIN version: pin-2.14-71313-msvc11-windows.
    2. Install: 
          a. Cygwin with the packages for the following : tar, jar, make, objdump, ant.
          b. Python
          c. Java: Set the JAVA_HOME environment variable
             Note that the folder specified by the JAVA_HOME variable must contain a directory named include which internally contains jni.h file.
          d. mercurial (can use the mercurial files that are bundled with TortoiseHg)
    3. Install .NET framework.
    4. Visual Studio (Tested configuration: Visual Studio-12 and commmand prompt VS2012 x64 native).

    IMPORTANT: On Windows, Tejas installation will work only on the Visual Studio Command Prompt.

######################        Mac        ##########################

--> Pre-installation instructions for Mac
    
    1. Tested PIN version: pin-2.13-62732-clang.4.2-mac
    2. Install 
         a. Java: Install both: JDK and JRE
         b. ant: Used to compile Java files
         c. python
         d. zlib library (can install using the homebrew utility)
         e. hg (if you want to use the repository)
