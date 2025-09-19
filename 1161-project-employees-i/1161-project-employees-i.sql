SELECT project_id, ROUND(AVG(experience_years), 2) AS average_years
FROM Project AS t1 JOIN Employee USING(employee_id)
#WHERE count_no_trans != 0
GROUP BY project_id
#ORDER BY transaction_date ASC