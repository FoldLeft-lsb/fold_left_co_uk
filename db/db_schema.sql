create table dream_session (
  id text primary key,
  label text not null,
  expires_at real not null,
  payload text not null
);

create table wasm_apps(
  id text primary key,
  type text,
  name text,
  homepage text,
  height text,
  width text
);
