# Tetris
Made for fun with the intent for learning practical C++ & library/include file integration with Cmake  

# Build Instructions
***YOU NEED TO HAVE A LIB FOLDER WITH THE RAYLIB LIBRARIES IN THE PROJECT DIRECTORY***  
*Below img has an example of the project dir including a lib folder with raylib library files. (currently not in git because of gitignore)*  

<div align="center">
  <img alt="project dir with a lib folder containing raylib library files" 
    src="https://github.com/j-2k/Tetris_RLCPP/assets/52252068/521318e8-8ec1-44d6-869e-57b9f051523d"
    height="600" width="180">
  <img alt="project dir with a lib folder containing raylib library files" 
    src="https://github.com/j-2k/Tetris_RLCPP/assets/52252068/521318e8-8ec1-44d6-869e-57b9f051523d"
    height="600" width="180">
  <img alt="project dir with a lib folder containing raylib library files" 
    src="https://github.com/j-2k/Tetris_RLCPP/assets/52252068/521318e8-8ec1-44d6-869e-57b9f051523d"
    height="600" width="180">
</div>

Getting raylib lib files:   
1. https://github.com/raysan5/raylib > go to releases
2. scroll down to whatever os your using & download the files
3. once you find the lib folder drop it in this project directory (see the CMakeLists.txt for more info) 
4. (Note for myself Ignore this!) I can have the make file fetch this I believe, but I learn that later.

Actual build instructions now:
1. Enter the build file through terminal
2. Make a empty folder & go into it
3. paste below & hit enter
```shell
cmake . && make && ./tetrisrlcpp
```
Thats it! if you know what you're doing just build it on your own whatever way, I'm using Cmake anyway.


# Learning Resources & Links
- [Raylib Website](https://www.raylib.com) Examples & Cheatsheet section is extremely helpful
- [Github Raylib](https://github.com/raysan5/raylib) Download important lib & include files (from releases) for your operating system
- [ChatGPT](https://chat.openai.com) ChatGPT helped with CMake configuration (specifically linking the libs & include dir)
- [Tetris C++ Raylib Youtube](https://www.youtube.com/watch?v=wVYKG_ch4yM) Youtube Guide for creating Tetris




