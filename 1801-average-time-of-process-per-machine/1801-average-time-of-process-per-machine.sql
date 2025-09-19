SELECT machine_id, ROUND(SUM(IF(activity_type = 'start', -1*timestamp, timestamp))/SUM(IF(activity_type = 'start', 1, 0)), 3) AS processing_time 
FROM Activity AS t1
GROUP BY machine_id
#ORDER BY transaction_date ASC