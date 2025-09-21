SELECT session_id,
       user_id,
       TIMESTAMPDIFF(MINUTE, MIN(event_timestamp), MAX(event_timestamp)) AS session_duration_minutes,
       SUM(IF(event_type = 'scroll', 1, 0)) AS scroll_count/*,
       1.0*(IF(SUM(IF(event_type = 'click', 1, 0)) > 0, SUM(IF(event_type = 'click', 1, 0)), 0))/SUM(IF(event_type = 'scroll', 1, 0)) AS ttt,
       SUM(IF(event_type = 'purchase', 1, 0)) AS qqq*/
FROM app_events AS t1
GROUP BY 1, 2
HAVING session_duration_minutes > 30 AND
       scroll_count >= 5 AND
       1.0*(IF(SUM(IF(event_type = 'click', 1, 0)) > 0, SUM(IF(event_type = 'click', 1, 0)), 0)) / SUM(IF(event_type = 'scroll', 1, 0)) < 0.2 AND
       SUM(IF(event_type = 'purchase', 1, 0)) = 0
ORDER BY scroll_count DESC, session_id ASC