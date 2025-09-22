SELECT student_id,
       subject,
       (
        SELECT score
        FROM Scores AS t2
        WHERE t2.student_id = t1.student_id AND t2.subject = t1.subject
        ORDER BY t2.exam_date ASC
        LIMIT 1
       ) AS first_score,
       (
        SELECT score
        FROM Scores AS t3
        WHERE t3.student_id = t1.student_id AND t3.subject = t1.subject
        ORDER BY t3.exam_date DESC
        LIMIT 1
       ) AS latest_score
FROM Scores AS t1 #JOIN eff AS t2 USING(driver_id)
GROUP BY 1, 2
HAVING first_score < latest_score
ORDER BY student_id ASC, subject ASC