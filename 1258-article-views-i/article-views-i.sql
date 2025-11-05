select author_id as id 
from views 
where author_id=viewer_id
GROUP BY author_id
order by author_id asc;