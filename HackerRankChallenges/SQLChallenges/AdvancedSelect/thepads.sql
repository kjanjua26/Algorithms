select concat(Name, concat('(', LEFT(Occupation, 1), ')')) from OCCUPATIONS order by Name ;
select concat('There are a total of',' ',count(occupation),' ',lower(Occupation),'s','.') from occupations group by Occupation order by count(Name), Occupation;
