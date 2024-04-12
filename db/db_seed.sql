insert into demo_apps (id, type, name, homepage, height, width, controls) values (
  1,
  "C99 Raylib Game", 
  "Conway's Game of Life", 
  "wasm/cgol/cgol.html", 
  "900px", 
  "752px",
  "Space to play / pause, [ ] to change simulation speed. When paused, C to clear, R to fill random, Left-click to toggle a cell."
);

insert into demo_apps (id, type, name, homepage, height, width, controls) values (
  2,
  "C++ Raylib Game", 
  "Space Invaders", 
  "wasm/space_invaders/space_invaders.html", 
  "948px", 
  "800px",
  "A and D to move, Space to un-pause and shoot, R to reset."
);

insert into demo_apps (id, type, name, homepage, height, width, controls) values (
  3,
  "Three.js WebGL Game", 
  "Blockgame ThreeJS", 
  "three/blockgame_three/blockgame_three.html", 
  "768px",
  "1080px",
  "First person controls with WASD and mouse, Left-click to interact, number keys to change selected block, F1 to save and F2 to load."
);

insert into projects (id, type, name, description) values (
  1,
  "ReasonML full-stack with radix-ui", 
  "This Website", 
  "Made with the fanciest tech I could think of even if it's not useful. I'm not much of a designer so I tend toward 'less is more' and lean on a UI library. The API is a native OCaml executable with astounding performance, ReasonReact is a joy to use, it makes TypeScript feel like a half-measure."
);


insert into projects (id, type, name, description, demo_id, link, link_text) values (
  2,
  "C99 Raylib Game", 
  "Conway's Game of Life", 
  "This was my first application in C++, and also my first in C. Raylib does the lifting for graphics and leaves me to think only about application code, it was great to make it first with OOP then refactor and optimise it.",
  1,
  "https://github.com/FoldLeft-lsb/raylib_game_of_life",
  "Github repo"
);

insert into projects (id, type, name, description, demo_id, link, link_text) values (
  3,
  "C++ Raylib Game", 
  "Space Invaders", 
  "This was my second game in C++ with a bit more dynamism than the game of life, textures, collisions. OOP is the main theme of this codebase, it could use some work, a bit of fun.",
  2,
  "https://github.com/FoldLeft-lsb/raylib_space_invaders",
  "Github repo"
);

insert into projects (id, type, name, description, demo_id, link, link_text) values (
  4,
  "Three.js WebGL Game", 
  "Blockgame ThreeJS", 
  "I made this one following a tutorial to get a feel for Three.js and play around with simple procedural generation. Three is relatively easy to get up and running, comes with useful addons and examples, and this project has opportunities for optimization.",
  3,
  "https://github.com/FoldLeft-lsb/blockgame_threejs",
  "Github repo"
);
