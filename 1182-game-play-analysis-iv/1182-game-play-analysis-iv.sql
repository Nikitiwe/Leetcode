WITH p1 AS (
    SELECT DISTINCT player_id,
           IF(DATE_ADD(MIN(event_date), INTERVAL 1 DAY) IN (
                SELECT event_date
                FROM Activity AS t3
                WHERE t3.player_id = t2.player_id
            ), 1, 0) AS is_again
    FROM Activity AS t2
    GROUP BY player_id
)
SELECT ROUND(SUM(is_again) / (SELECT COUNT(DISTINCT player_id) FROM Activity), 2) AS fraction
FROM p1
#WHERE subquery.pos < subquery.neg
#GROUP BY player_id
#ORDER BY recovery_time ASC, patient_name ASC