SELECT book_id,
       title,
       author,
       genre,
       pages,
       MAX(session_rating) - MIN(session_rating) AS rating_spread,
       ROUND(1.0*SUM(IF(session_rating <= 2 OR session_rating >= 4, 1, 0)) / COUNT(*), 2) AS polarization_score
FROM books AS t1 JOIN reading_sessions AS t2 USING(book_id)
#WHERE t1.year = t2.min_year
GROUP BY book_id
HAVING COUNT(*) >= 5 AND MIN(session_rating) <= 2 AND MAX(session_rating) >= 4 AND polarization_score >= 0.6
ORDER BY polarization_score DESC, title DESC