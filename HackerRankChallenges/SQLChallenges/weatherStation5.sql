/*
  Query the two cities in STATION with the shortest and longest CITY names.
  As well as their respective lengths (i.e.: number of characters in the name). 
  If there is more than one smallest or largest city, choose the one that comes first when ordered alphabetically.
*/

select CITY, LENGTH(CITY) from STATION where city like "%a%" order by Length(CITY) asc LIMIT 1;
select CITY, LENGTH(CITY) from STATION order by Length(CITY) desc  LIMIT 1;
