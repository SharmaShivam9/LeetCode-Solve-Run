select v.customer_id, count(v.customer_id) as count_no_trans 
from visits v
where v.visit_id not in(
    select t.visit_id from transactions t
)
group by v.customer_id;