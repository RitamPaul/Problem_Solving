# Write your MySQL query statement below
delete from Person
where email in (
    select * from 
    (select distinct email from Person) as temp1
)
and id not in (
    select * from
    (select min(id) from Person group by email) as temp2
);



-- delete from Person
-- where id in (
--     select p2.id 
--     from Person p1 join Person p2
--     on p1.email=p2.email and p1.id<>p2.id
-- );



-- select min(id) from (
--     select email from Person group by email
-- ) as temp



-- delete from Person
-- where id not in (
--     select * from
--     (
--         select min(id) from Person
--         group by email
--     ) as temp
-- );