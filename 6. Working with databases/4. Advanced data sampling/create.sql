create table if not exists Performers (
	name_alias VARCHAR(80) primary key
);

create table if not exists Genres (
	id SERIAL primary key,
	title VARCHAR(80) not null
);

create table if not exists Performers_and_Genres (
	id SERIAL primary key,
	performer VARCHAR(80) references Performers(name_alias),
	genre integer not null references Genres(id)
);

create table if not exists Albums (
	id SERIAL primary key,
	title VARCHAR(80) not null,
	est integer not null
);

create table if not exists Performers_and_Albums (
	id SERIAL primary key,
	performer VARCHAR(80) not null references Performers(name_alias),
	album integer not null references Albums(id)
);

create table if not exists Tracks (
	id SERIAL primary key,
	title VARCHAR(80) not null,
	duration dec not null,
	album integer not null references Albums(id)
);

create table if not exists Collections (
	id SERIAL primary key,
	title VARCHAR(80) not null,
	est integer not null
);

create table if not exists Collections_and_Tracks (
	id SERIAL primary key,
	collection integer not null references Collections(id),
	track integer not null references Tracks(id)
);



