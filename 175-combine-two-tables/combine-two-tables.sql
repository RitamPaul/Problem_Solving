# Write your MySQL query statement below
select
    p.firstName,
    p.lastname,
    a.city,
    a.state
from
    person p left join address a on p.personId=a.personId
;