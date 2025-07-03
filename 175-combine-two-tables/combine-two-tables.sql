# Write your MySQL query statement below
select
    firstName,
    lastname,
    city,
    state
from
    person p left join address a on p.personId=a.personId
;