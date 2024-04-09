create table dream_session (
  id text primary key,
  label text not null,
  expires_at real not null,
  payload text not null
);

create table demo_apps(
  id text not null primary key,
  type text,
  name text,
  homepage text,
  height text,
  width text,
  controls text
);

create table projects(
  id text not null primary key,
  type text,
  name text,
  description text,
  demo_id int,
  foreign key (demo_id) references demo_apps(id)
);