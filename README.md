<h1 align="center">Computer Graphics Algorithms</h1>

## How to compile and run
- **Windows** (CMD or Powershell)
    ```CMD
       REM compile using the MinGW g++ compiler 
       g++ InputFile.cpp -o outputFile.exe -mwindows -lgdi32 (for normal Windows API App)
       g++ InputFile.cpp -o outputFile.exe -mwindows -lopengl32 (for Windows API App with OpenGL)


       REM Run the executable
       .\output.exe
    ```
- ### **Linux**
    - for me, i use Arch Linux btw, so the commands and steps might be different depending on your distro but it is the same concept
    1. Download the **MinGW toolchain** from your distro's repository, to compile C++ codes to Windows executables
        ```bash
           # Download MinGW toolchain
           sudo pacman -S mingw-w64-gcc mingw-w64-headers
           sudo pacman -S lib32-glm lib32-glu # Optional, just for use of OpenGL                                                                                             
        ```
    2. You will need [wine](https://www.winehq.org/) to be able to run the windows executables on linux
        -  wine is located in the **multilib repository**, 
        To enable multilib repository, uncomment the [multilib] section in **/etc/pacman.conf**:
        ```
        [multilib]
        Include = /etc/pacman.d/mirrorlist
        ```
        - Update the system and install wine with:
        ```bash
        # to sync the repositories and update the system 
        sudo pacman -Syu
        # install wine
        sudo pacman -S wine
        ```
    3. Compile the code and run the executable with wine64:
         ```bash
            # compile to windows executable (without OpenGL)
            x86_64-w64-mingw32-g++  paths/to/InputFiles.cpp -o path/to/outputFile.exe -mwindows -lgdi32
            # compile to windows executable (with OpenGL)
            x86_64-w64-mingw32-g++  paths/to/InputFiles.cpp -o path/to/outputFile.exe -mwindows -lopengl32
            
            # run with wine64  
            wine64 path/to/outputFile.exe
          ```
        - I created a simple **bash script** to automate the **compile and run** process, you can integrate it with any text editor or IDE
        - There is also a **Makefile** if you want to use **make** with **make run** | **make clean** | **make**  

    4.  #### LSP Support:
        If u are using the Clangd language server, replace the src/compile_flags.txt file into the root directory where your clangd operate

        
