
--------------------

SELECT title, duration FROM Tracks
ORDER BY duration DESC
LIMIT 1;

---------------------

SELECT title FROM Tracks
WHERE duration >= 210;

---------------------

SELECT title FROM Collections
WHERE est >= 2018 AND est <= 2020;

---------------------

SELECT name_alias FROM Performers
WHERE NOT name_alias LIKE '% %';

---------------------

SELECT title FROM Tracks
WHERE title LIKE '%my%' OR title LIKE '%мой%';

---------------------

select title, count(p.name_alias) from genres as g
left join Performers_and_Genres as peg on g.id = peg.genre
left join performers as p on peg.performer  = p.name_alias
group by title;

---------------------

select t.title, a.est from albums as a
left join tracks as t on t.album = a.id
where (a.est >= 2019) and (a.est <= 2020);

---------------------

select a.title, AVG(t.duration) from albums as a
left join tracks as t on t.album = a.id
group by a.title
order by AVG(t.duration);

---------------------

select distinct p.name_alias  from performers as p
where p.name_alias  not in (
    select distinct p.name_alias 
    from performers as p
    left join performers_and_albums as paa on p.name_alias  = paa.performer 
    left join albums as a on a.id = paa.album 
    where est = 2020
)
order by p.name_alias 

---------------------

select distinct c.title from collections as c
left join collections_and_tracks as cat on c.id = cat.collection
left join tracks as t on t.id = cat.track
left join albums as a on a.id = t.album
left join performers_and_albums paa on paa.album = a.id
left join performers  on performers.name_alias  = paa.performer 
where performers.name_alias  LIKE 'JVKE';

---------------------