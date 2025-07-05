# Write your MySQL query statement below
select customer_number
from (
    select customer_number, count(*)
    from Orders
    group by customer_number
    order by count(*) desc
    limit 1
) as temp1;