# Write your MySQL query statement below
-- select name, (
--     select population, area
--     from World
--     group by population
--     having population>=25000000 or area>=3000000
-- ) 
-- from World;


select name, population, area
from World
where area>=3000000 or population>=25000000;