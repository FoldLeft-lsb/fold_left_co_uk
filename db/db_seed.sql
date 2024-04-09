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
  "SharePoint augmentation", 
  "Atvero", 
  "Document management solution tailored for the AEC industry. A powerful front-end built with React in the ReasonML language, supported by a SP Site and a few Azure cloud services, leveraging MS Authentication, it's as scalable as SharePoint is. I worked on Atvero for 6 years before I decided it was time for something new."
);

insert into projects (id, type, name, description, demo_id) values (
  2,
  "C99 Raylib Game", 
  "Conway's Game of Life", 
  "This was my first application in C++, and also my first in C. The Raylib library does the lifting for graphics and leaves me to think only about application code, it was great to make it first with OOP then refactor and optimise it.",
  1
);

insert into projects (id, type, name, description, demo_id) values (
  3,
  "C++ Raylib Game", 
  "Space Invaders", 
  "This was my second game in C++ with a bit more dynamism than the game of life, textures, collisions. Running native it will save highscores to a file, this can likely be implemented in JS using localStorage, sounds also work for native and require some additional work for browser. It could do with some more work and a win-condition, great to produce something cohesive.",
  2
);

insert into projects (id, type, name, description, demo_id) values (
  4,
  "Three.js WebGL Game", 
  "Blockgame ThreeJS", 
  "I made this one following a tutorial to get a feel for Three.js and play around with procedural generation. It's relatively easy to get up and running, comes with useful addons and examples, and leaves opportunities for improvements and optimization. A good refresher writing JS without React also.",
  3
);

insert into projects (id, type, name, description) values (
  5,
  "ReasonML full-stack with radix-ui", 
  "This Website", 
  "Made with the fanciest tech I could think of even if it's not useful. I'm more-so an Engineer than a Designer, Radix makes looking good easy, as does React for interactivity. The API is a native OCaml executable with astounding performance. And ReasonReact, if you're a React dev and you've never tried it, take a look at the repo and imagine how much nicer your code could look than mine. It provides confidence I could only dream of making changes in a JS codebase, it makes TypeScript feel like a half-measure."
);
