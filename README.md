# Tetris
Made for fun with the intent of learning practical C++ & library/include file integration with Cmake.  

*February 2024 project meant for some fun before I step into something more serious like a graphics project that uses a specialization. If I need to learn more practical CPP I will probably try making a 3D game since Raylib seems nice & fun to use.*  

*Note after finishing this project: I will now probably move onto OpenGL and have some fun fiddling around in modern OpenGL just to dive into graphics properly, this project was mainly for refreshing my knowledge with CPP so in terms of making the game "juiced up" I didn't bother doing that but important ending functionality like score, game-over, restart, etc has all been done, not in the nicest visual way of course as I said previously. picture of the game will be put below!*  



enjoy the next project > [j-2k/opengl-trials](https://github.com/j-2k/OpenGL_Trials_1)
# Progress Pictures
The first tetris block + some colored blocks.
<img width="296" alt="Screenshot 2024-03-04 at 6 52 28 AM" src="https://github.com/j-2k/Tetris_RLCPP/assets/52252068/f8dd1973-f991-4cec-822b-990bfee7b3db">


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
3. copy below then paste it in the terminal & when you run it should boot up the game
```shell
cmake . && make && ./tetrisrlcpp
```
Thats it! if you know what you're doing just build it on your own whatever way, I'm using Cmake anyway.


# Learning Resources & Links
- [Raylib Website](https://www.raylib.com) Examples & Cheatsheet section is extremely helpful
- [Github Raylib](https://github.com/raysan5/raylib) Download important lib & include files (from releases) for your operating system
- [ChatGPT](https://chat.openai.com) ChatGPT helped with CMake configuration (specifically linking the libs & include dir)
- [Tetris C++ Raylib Youtube](https://www.youtube.com/watch?v=wVYKG_ch4yM) Youtube Guide for creating Tetris

# Closing Notes
1st Checkpoint - 50:10




