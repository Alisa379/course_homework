INSERT INTO Performers(name_alias)
VALUES('FACE');

INSERT INTO Performers(name_alias)
VALUES('Melanie Martinez');

INSERT INTO Performers(name_alias)
VALUES('Twenty one pilots');

INSERT INTO Performers(name_alias)
VALUES('Jaymes Young');

INSERT INTO Performers(name_alias)
VALUES('JVKE');

-------------------

INSERT INTO Genres(title)
VALUES('Rap');

INSERT INTO Genres(title)
VALUES('Electropop');

INSERT INTO Genres(title)
VALUES('Rock');

INSERT INTO Genres(title)
VALUES('Indie pop');

INSERT INTO Genres(title)
VALUES('Alternative');

INSERT INTO Genres(title)
VALUES('Pop');

--------------------

INSERT INTO Performers_and_Genres(performer, genre)
VALUES('FACE', 1);

INSERT INTO Performers_and_Genres(performer, genre)
VALUES('Melanie Martinez', 2);

INSERT INTO Performers_and_Genres(performer, genre)
VALUES('Twenty one pilots', 3);

INSERT INTO Performers_and_Genres(performer, genre)
VALUES('Twenty one pilots', 5);

INSERT INTO Performers_and_Genres(performer, genre)
VALUES('Jaymes Young', 4);

INSERT INTO Performers_and_Genres(performer, genre)
VALUES('JVKE', 6);

-------------------

INSERT INTO Albums(title, est)
VALUES('12', 2019);

INSERT INTO Albums(title, est)
VALUES('Cry Baby', 2015);

INSERT INTO Albums(title, est)
VALUES('Scaled And Icy', 2021);

INSERT INTO Albums(title, est)
VALUES('Feel Something', 2017);

INSERT INTO Albums(title, est)
VALUES('SLIME', 2019);

INSERT INTO Albums(title, est)
VALUES('Trench', 2018);

INSERT INTO Albums(title, est)
VALUES('this is what_____feels like', 2022);

--------------------

INSERT INTO Performers_and_Albums(performer, album)
VALUES('FACE', 1);

INSERT INTO Performers_and_Albums(performer, album)
VALUES('Melanie Martinez', 2);

INSERT INTO Performers_and_Albums(performer, album)
VALUES('Twenty one pilots', 3);

INSERT INTO Performers_and_Albums(performer, album)
VALUES('Jaymes Young', 4);

INSERT INTO Performers_and_Albums(performer, album)
VALUES('FACE', 5);

INSERT INTO Performers_and_Albums(performer, album)
VALUES('Twenty one pilots', 6);

INSERT INTO Performers_and_Albums(performer, album)
VALUES('JVKE', 7);

--------------------

INSERT INTO Tracks(title, duration, album)
VALUES('ВОСХИТИТЕЛЬНО', 193, 1);

INSERT INTO Tracks(title, duration, album)
VALUES('ЛАБИРИНТ', 169, 1);

INSERT INTO Tracks(title, duration, album)
VALUES('Pacify Her', 220, 2);

INSERT INTO Tracks(title, duration, album)
VALUES('Cake', 200, 2);

INSERT INTO Tracks(title, duration, album)
VALUES('Saturday', 172, 3);

INSERT INTO Tracks(title, duration, album)
VALUES('Redecorate', 246, 3);

INSERT INTO Tracks(title, duration, album)
VALUES('Infinity', 238, 4);

INSERT INTO Tracks(title, duration, album)
VALUES('Don''t You Know', 248, 4);

INSERT INTO Tracks(title, duration, album)
VALUES('мой калашников', 148, 5);

INSERT INTO Tracks(title, duration, album)
VALUES('Jumpsuit', 239, 6);

INSERT INTO Tracks(title, duration, album)
VALUES('Nico_And_The_Niners', 225, 6);

INSERT INTO Tracks(title, duration, album)
VALUES('This Is What Falling Out of Love Feels Like', 141, 7);

INSERT INTO Tracks(title, duration, album)
VALUES('Catch Me', 177, 7);

INSERT INTO Tracks(title, duration, album)
VALUES('I Can''t Help It', 178, 7);

INSERT INTO Tracks(title, duration, album)
VALUES('This Like Sadness Feels Like', 192, 7);

INSERT INTO Tracks(title, duration, album)
VALUES('Wonder If She Loves Me', 161, 7);

INSERT INTO Tracks(title, duration, album)
VALUES('Save Your Breath', 166, 7);

INSERT INTO Tracks(title, duration, album)
VALUES('this is what heartbreak feels like', 158, 7);

--------------------

INSERT INTO Collections(title, est)
VALUES('Jumpsuit', 2018);

INSERT INTO Collections(title, est)
VALUES('this is what falling out of love feels like', 2022);

INSERT INTO Collections(title, est)
VALUES('this is what sadness feels like', 2022);

INSERT INTO Collections(title, est)
VALUES('this is what heartbreak feels like', 2022);

--------------------

INSERT INTO Collections_and_Tracks(collection, track)
VALUES(1, 10);

INSERT INTO Collections_and_Tracks(collection, track)
VALUES(1, 11);

INSERT INTO Collections_and_Tracks(collection, track)
VALUES(2, 12);

INSERT INTO Collections_and_Tracks(collection, track)
VALUES(2, 13);

INSERT INTO Collections_and_Tracks(collection, track)
VALUES(2, 14);

INSERT INTO Collections_and_Tracks(collection, track)
VALUES(3, 15);

INSERT INTO Collections_and_Tracks(collection, track)
VALUES(3, 16);

INSERT INTO Collections_and_Tracks(collection, track)
VALUES(3, 17);

INSERT INTO Collections_and_Tracks(collection, track)
VALUES(4, 18);




