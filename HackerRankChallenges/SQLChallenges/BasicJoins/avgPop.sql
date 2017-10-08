select COUNTRY.Continent, floor(avg(city.population)) from city, country 
where city.countrycode = country.code 
group by country.continent;
