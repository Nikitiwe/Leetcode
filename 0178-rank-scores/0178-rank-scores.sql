SELECT score, DENSE_RANK() OVER(ORDER BY score DESC) AS 'rank'
FROM Scores AS t1 #JOIN Employee USING(employee_id)
#WHERE count_no_trans != 0
#GROUP BY project_id
ORDER BY score DESC