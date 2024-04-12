# foldleft.co.uk 

Personal website for hosting the toy projects I've made that will run in a browser  

Honestly this site could be static html, it's quite bare and has a minimum of interactivity. The purpose of this project is to illustrate how I would make a proper webapp using my favourite tools. It is designed to scale up to quite a significant React application, it's one big main.js file now, OCaml's Dune build-system makes it easy to split code into separate libraries down the line. 


```
common/
  # Library for anything that can be shared by server and client 
radix_binding/
  # Library for FFI bindings to the @radix-ui/themes npm package
server/ 
  # API made in Reason(OCaml) with Dream and Caqti_lwt 
src/ 
  # Front-end source 
  api/ # Server interactions
  components/ 
  scss/ # Didn't really make use of this beyond `@use`ing radix styles 
db/ 
  # SQL files for schema and seed data 
public/ 
  index.html # is included 
  # Compiled front-end will go here 
  # Hosted apps in subirs 
```



### Server 

I have used the Dream framework for my API written in the Reason dialect of OCaml, it's as easy to use as express was on Node, but something like 20x more performant and genuinely type-safe. 

Caqti_lwt is used to interface with the DB, the syntax is quite arcane, but remember that in OCaml everything is an expression. The DB is just an sqlite3 file for now, it would be easy to substitute in Postgres or any other DB. 

### Client 

The client is also written in the Reason, it uses a different compiler called melange to produce javascript code. A simple React application using pre-made components, it's responsive, simple and concise, it contains only the information that matters. Less is more. 

I've written some simple bindings to the Radix UI component library. The accessibility is not bad, it auto-translates fairly well I think, I'm a little concerned about text that draws one character at a time, screen-readers might struggle with that so I've kept the scrolling text to a minimum also. 

I chose ReasonReact because I have real experience scaling a project like this up and supporting it in production. A few years into a project the type-system and compiler truly become a super-power. 

### The Toy Projects 

This site can host any kind of game that will run in a browser, in fact it's just an iframe so you could embed a youtube video or another website though I wouldn't recommend it. My projects will be hosted from the public/ directory with a main html file (not called index.html)

```
public/
  wasm/
    space_invaders/
      space_invaders.html 
      space_invaders.js 
      space_invaders.wasm 
```

The server aliases "static" to the public directory, the database entry for Space Invaders would include a path such as `wasm/space_invaders/space_invaders.html` and the html file will be able to find `./space_invaders.js` and so on

So far I have some games written in C or C++ and compiled with Emscripten for web, and one Three.js project also, there are an ever-increasing number of ways to target the web with high performance applications and I want to explore them. 