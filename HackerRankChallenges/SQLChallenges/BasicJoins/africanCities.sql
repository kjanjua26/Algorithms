select city.name 
from city, country 
where CITY.CountryCode = COUNTRY.Code and Continent = 'Africa';
