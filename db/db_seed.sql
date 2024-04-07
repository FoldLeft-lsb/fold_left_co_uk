insert into demo_apps (id, type, name, homepage, height, width) values (
  1,
  "C99 Emscripten App", 
  "Conway's Game of Life", 
  "wasm/cgol/cgol.html", 
  "900px", 
  "752px"
);

insert into demo_apps (id, type, name, homepage, height, width) values (
  2,
  "C++ Emscripten App", 
  "Space Invaders", 
  "wasm/space_invaders/space_invaders.html", 
  "948px", 
  "800px"
);

insert into demo_apps (id, type, name, homepage, height, width) values (
  3,
  "Three.js WebGL app", 
  "Blockgame ThreeJS", 
  "three/blockgame_three/blockgame_three.html", 
  "768px",
  "1080px"
);

insert into projects (id, type, name, description, controls, demo_id) values (
  1,
  "C99 Emscripten App", 
  "Conway's Game of Life", 
  "This was my first application in C++, and also my first in C. The Raylib library does the lifting for graphics and leaves me to think only about application code, it was great to make it first with OOP then refactor and optimise it.",
  "Space to play / pause, [ ] to change simulation speed. When paused, C to clear, R to fill random, Left-click to toggle a cell.",
  1
);

insert into projects (id, type, name, description, controls, demo_id) values (
  2,
  "C++ Emscripten App", 
  "Space Invaders", 
  "This was my second game in C++ with a bit more dynamism than the game of life, textures, collisions. Running native it will save highscores to a file, this can likely be implemented in JS using localStorage, sounds also work for native and require some additional work for browser. It could do with some more work and a win-condition, great to produce something cohesive.",
  "A and D to move, Space to un-pause and shoot, R to reset.",
  2
);

insert into projects (id, type, name, description, controls, demo_id) values (
  3,
  "Three.js WebGL app", 
  "Blockgame ThreeJS", 
  "I made this one following a tutorial to get a feel for Three.js and play around with procedural generation. It's relatively easy to get up and running, comes with useful addons and examples, and leaves opportunities for improvements and optimization. A good refresher writing JS without React also.",
  "First person controls with WASD and mouse, Left-click to interact, number keys to change selected block, F1 to save and F2 to load.",
  3
);