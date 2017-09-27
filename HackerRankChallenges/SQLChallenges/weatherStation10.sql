/*
  Query the list of CITY names from STATION that do not end with vowels. Your result cannot contain duplicates.
*/
select distinct city from station WHERE not city RLIKE '^.*[aeiouAEIOU]$'

