<h1 align="center">Computer Graphics Algorithms</h1>

## How to compile and run
- **Windows** (CMD or Powershell)
    ```CMD
        REM compile using the MinGW g++ compiler 
        g++ -mwindows -lgdi32 InputFile.cpp -o outputFile.exe

        REM Run the executable
        .\output.exe
    ```
- **Linux**
    - for me, i use Arch Linux btw, so the commands and steps might be different depending on your distro but it is the same concept
    1. Download the **MinGW toolchain** from your distro's repository, to compile C++ codes to Windows executables
        ```bash
            # Download MinGW toolchain
            sudo pacman -S mingw-w64-gcc mingw-w64-headers                                                                                              
        ```
    2. You will need [wine](https://www.winehq.org/) to be able to run the windows executables on linux
        -  wine is located in the **multilib repository**, 
        To enable multilib repository, uncomment the [multilib] section in **/etc/pacman.conf**:
        ```
        [multilib]
        Include = /etc/pacman.d/mirrorlist
        ```
        - Then Sync the repositories and upgrade the system with:
        ```bash
        sudo pacman -Syu
        sudo pacman -S wine
        ```
    3. compile the code and run the executable with wine64
         ```bash
            # compile to windows executable
               x86_64-w64-mingw32-g++ -mwindows -lgdi32 path/to/InputFile.cpp -o path/to/outputFile.exe
            
            # run with wine64  
               wine64 path/to/outputFile.exe
          ```
        - I created a simple **bash script** to automate the **compile and run** process at src/run, you can integrate it with any text editor of IDE
