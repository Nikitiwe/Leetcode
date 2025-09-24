SELECT results
FROM
(
    (SELECT t1.name AS results
    FROM Users AS t1 JOIN MovieRating AS t2 USING(user_id) JOIN Movies AS t3 USING(movie_id)
    GROUP BY t1.user_id
    ORDER BY COUNT(*) DESC, t1.name ASC
    LIMIT 1)
    UNION ALL
    (SELECT t3.title AS results
    FROM Users AS t1 JOIN MovieRating AS t2 USING(user_id) JOIN Movies AS t3 USING(movie_id)
    WHERE YEAR(t2.created_at) = 2020 AND MONTH(t2.created_at) = 2
    GROUP BY t3.movie_id
    ORDER BY AVG(t2.rating) DESC, t3.title ASC
    LIMIT 1)
) AS t0