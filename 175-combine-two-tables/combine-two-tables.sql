# Write your MySQL query statement below
select
    p.firstName,
    p.lastname,
    IFNULL(a.city,null) as city,
    IFNULL(a.state,null) as state
from
    person p left join address a on p.personId=a.personId
;