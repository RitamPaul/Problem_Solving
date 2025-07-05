# Write your MySQL query statement below
select sp.name
from
(SalesPerson sp) left join (Orders o join Company c on o.com_id=c.com_id)
on
sp.sales_id=o.sales_id
where c.name is null or not exists (
    select 1 
    from
    (SalesPerson sp1) join (Orders o join Company c on o.com_id=c.com_id)
    on
    sp1.sales_id=o.sales_id
    where sp1.name=sp.name and c.name="RED"
)
group by sp.name;