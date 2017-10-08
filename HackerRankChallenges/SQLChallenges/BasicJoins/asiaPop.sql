select sum(city.population)
from city, country 
where city.CountryCode = country.Code and continent = 'Asia';
