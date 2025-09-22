WITH t0 AS (
    SELECT employee_id, 
           WEEK(meeting_date, 1) AS w,
           IF(SUM(duration_hours) > 40/2, 1, 0) AS is_heavy
    FROM employees AS t3 JOIN meetings AS t4 USING(employee_id)
    GROUP BY 1, 2
)
SELECT employee_id,
       employee_name,
       department,
       SUM(is_heavy) AS meeting_heavy_weeks
FROM employees AS t1 JOIN t0 USING(employee_id)
GROUP BY 1
HAVING meeting_heavy_weeks >= 2
ORDER BY meeting_heavy_weeks DESC, employee_name ASC