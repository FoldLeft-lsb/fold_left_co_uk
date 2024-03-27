# GameGoblin server (working title, think Gringotts)

This project is meant to be a specialised website server for hosting WebAssembly games 

#### Intended features 
- Homepage 
- Portfolio page 
  - Probably tiles with name and description
  - A generated page for each game 
  - Customising the pages 
  - Games are iframes so can be hosted local or remote, or loaded on other sites 
- Admin interface 
  - Login with 2fa and good security
  - Add new games 
- Server architecture 
  - Modular database, sqlite for now but designed for Postgres 
  - Sanitized inputs and login timeout  
  - Controlled API routes generated from the db 
  - Reverse proxy or some equivalent
  - Maybe release as a docker image? 
  - Multithreading with OCaml? 

### Tech Choices 

It's one codebase with one language, the regular OCaml compiler for the server and melange for the client 

#### Server 
- Made with OCaml
- For Linux 
- Hopefully with interfaces for different DBs 
- Generate API routes on the fly based on the DB 
- Should be a systemd service with a user that owns it's working directory

#### Client 
- React, or rather ReasonReact 
  - Maybe a bit excessive but I'm showing off with this project.. 
- As much as possible should be in the DB so it's configurable

#### The Games 

The server should support drag & drop game files into the Admin interface to add new entries and the server will create a DB entry, folders in public directory, and generate new API routes to serve them

Because I'm using iframes to load the games up, they can be hosted remotely on some other server, so instead of drag & drop you can enter a URL, for this reason I guess you could point it to a webpage of any kind and it'll be loaded up as an iframe 

For that reason perhaps I should localhost only rather than allow users to point it at reddit or something 