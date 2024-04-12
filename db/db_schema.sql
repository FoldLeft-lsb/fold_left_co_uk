create table dream_session (
  id text primary key,
  label text not null,
  expires_at real not null,
  payload text not null
);

create table demo_apps(
  id text not null primary key,
  type text not null,
  name text not null,
  homepage text not null,
  height text,
  width text,
  controls text
);

create table projects(
  id text not null primary key,
  type text not null,
  name text not null,
  description text,
  demo_id int,
  link text,
  link_text text,
  foreign key (demo_id) references demo_apps(id)
);